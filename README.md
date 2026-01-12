# chisel-tpu

A Tensor Processing Unit (TPU) hardware design implemented in Chisel HDL with parameterized N×N systolic array for matrix multiplication.

## Architecture Overview

### System Architecture Diagram

```mermaid
graph TB
    subgraph TPUTop["TPUTop Module"]
        subgraph Control["TPU Control Unit (FSM)"]
            FSM["State Machine<br/>5 states: IDLE, IDLE2,<br/>CALCULATE, WRITE, FINISH<br/><br/>Counters:<br/>• cnt: 12-bit<br/>• addrA/B/C: 8-bit<br/>• writeCnt: 3-bit"]
        end

        subgraph Buffers["Global Buffers"]
            BufA["Buffer A<br/>256 × 32-bit<br/>(Input Matrix A)<br/><br/>4 × 8-bit elements<br/>per word"]
            BufB["Buffer B<br/>256 × 32-bit<br/>(Input Matrix B)<br/><br/>4 × 8-bit elements<br/>per word"]
            BufC["Buffer C<br/>256 × 64-bit<br/>(Output Matrix)<br/><br/>4 × 16-bit results<br/>per word"]
        end

        subgraph SysArray["Systolic Array (4×4)"]
            subgraph FIFOs["Input FIFOs"]
                FIFOA["4× FIFO A<br/>(Depth: 4)<br/>8-bit signed data"]
                FIFOB["4× FIFO B<br/>(Depth: 4)<br/>8-bit signed data"]
            end

            subgraph MACGrid["MAC Grid"]
                MAC00["MAC[0,0]"]
                MAC01["MAC[0,1]"]
                MAC02["MAC[0,2]"]
                MAC03["MAC[0,3]"]
                MAC10["MAC[1,0]"]
                MAC11["MAC[1,1]"]
                MAC12["MAC[1,2]"]
                MAC13["MAC[1,3]"]
                MAC20["MAC[2,0]"]
                MAC21["MAC[2,1]"]
                MAC22["MAC[2,2]"]
                MAC23["MAC[2,3]"]
                MAC30["MAC[3,0]"]
                MAC31["MAC[3,1]"]
                MAC32["MAC[3,2]"]
                MAC33["MAC[3,3]"]
            end

            FIFOA -->|"8-bit signed<br/>(horizontal)"| MAC00
            FIFOA -->|"8-bit signed"| MAC10
            FIFOA -->|"8-bit signed"| MAC20
            FIFOA -->|"8-bit signed"| MAC30

            FIFOB -->|"8-bit signed<br/>(vertical)"| MAC00
            FIFOB -->|"8-bit signed"| MAC01
            FIFOB -->|"8-bit signed"| MAC02
            FIFOB -->|"8-bit signed"| MAC03

            MAC00 -->|rightward| MAC01
            MAC01 -->|rightward| MAC02
            MAC02 -->|rightward| MAC03

            MAC10 -->|rightward| MAC11
            MAC11 -->|rightward| MAC12
            MAC12 -->|rightward| MAC13

            MAC20 -->|rightward| MAC21
            MAC21 -->|rightward| MAC22
            MAC22 -->|rightward| MAC23

            MAC30 -->|rightward| MAC31
            MAC31 -->|rightward| MAC32
            MAC32 -->|rightward| MAC33

            MAC00 -->|downward| MAC10
            MAC10 -->|downward| MAC20
            MAC20 -->|downward| MAC30

            MAC01 -->|downward| MAC11
            MAC11 -->|downward| MAC21
            MAC21 -->|downward| MAC31

            MAC02 -->|downward| MAC12
            MAC12 -->|downward| MAC22
            MAC22 -->|downward| MAC32

            MAC03 -->|downward| MAC13
            MAC13 -->|downward| MAC23
            MAC23 -->|downward| MAC33
        end

        FSM -->|"rdData (32-bit)"| Control
        FSM -->|"addr (8-bit)"| BufA
        FSM -->|"addr (8-bit)"| BufB
        FSM -->|"addr (8-bit),<br/>wrEn, wrData (64-bit)"| BufC

        BufA -->|"rdData<br/>32-bit"| FIFOA
        BufB -->|"rdData<br/>32-bit"| FIFOB

        FSM -->|"rdEnA[3:0],<br/>rdEnB[3:0],<br/>stopRead,<br/>sysReset"| SysArray

        MACGrid -->|"matOut[3:0][3:0]<br/>16× 21-bit accumulators"| FSM
    end

    ExtIO["External Interface<br/><br/>Inputs:<br/>• start: 1-bit<br/>• m, k, n: 4-bit each<br/><br/>Output:<br/>• done: 1-bit"] <-->|"Control signals"| FSM

    style TPUTop fill:#e1f5ff
    style Control fill:#fff4e1
    style Buffers fill:#f0f0f0
    style SysArray fill:#e8f5e9
    style FIFOs fill:#fff9c4
    style MACGrid fill:#c8e6c9
```

### MAC Unit Architecture

Each MAC (Multiply-Accumulate) unit contains:
- **Input registers**: 2× 8-bit signed (upReg, leftReg)
- **Accumulator**: 21-bit signed
- **Operation**: `accumulator += upIn × leftIn`
- **Data flow**: Systolic (inputs forwarded to neighboring MACs)

```mermaid
graph LR
    subgraph MACUnit["MAC Unit"]
        upIn["upIn<br/>8-bit signed"] -->|register| upReg["upReg<br/>8-bit"]
        leftIn["leftIn<br/>8-bit signed"] -->|register| leftReg["leftReg<br/>8-bit"]

        upIn --> mult["Multiplier<br/>8×8 bit"]
        leftIn --> mult

        mult -->|"product<br/>16-bit"| add["Adder<br/>21-bit"]
        accReg["Accumulator<br/>21-bit signed"] --> add
        add --> accReg

        upReg --> upOut["upOut<br/>8-bit signed"]
        leftReg --> leftOut["leftOut<br/>8-bit signed"]
        accReg --> matOut["matOut<br/>21-bit signed"]

        sysReset["sysReset"] -.->|clear| accReg
        sysReset -.->|clear| upReg
        sysReset -.->|clear| leftReg
    end

    style MACUnit fill:#c8e6c9
```

## TPU Control State Machine

The TPUControl FSM orchestrates the entire computation pipeline:

```mermaid
stateDiagram-v2
    [*] --> sIdle

    sIdle --> sIdle2: start asserted<br/><br/>Actions:<br/>• cnt ← 0<br/>• addrA/B/C ← 0

    sIdle2 --> sCalculate: Unconditional<br/><br/>Actions:<br/>• cnt ← 1<br/>• sysReset ← 0

    sCalculate --> sCalculate: cnt ≠ k+7<br/><br/>Control signals:<br/>• stopRead = (cnt>k ∨ cnt=0)<br/>• startFifo = (cnt=2)<br/>• stopFifo = (cnt=k+3)<br/>• cntEnd = (cnt=k+7)<br/><br/>Actions:<br/>• cnt ← cnt + 1<br/>• Read from buffers A & B<br/>• Staggered rdEnA/rdEnB

    sCalculate --> sWrite: cnt = k+7<br/>(cntEnd asserted)<br/><br/>Actions:<br/>• Prepare to write results

    sWrite --> sWrite: writeCnt < N-1<br/><br/>Actions:<br/>• Write matOut row to buffer C<br/>• Pack 4×16-bit → 64-bit word<br/>• writeCnt ← writeCnt + 1<br/>• addrC ← addrC + 1

    sWrite --> sFinish: writeCnt = N-1<br/><br/>Actions:<br/>• writeCnt ← 0<br/>• sysReset ← 1<br/>(clear accumulators)

    sFinish --> sIdle: Unconditional<br/><br/>Actions:<br/>• Assert done signal

    note right of sCalculate
        Timing details (for k×k multiply):
        • stopRead prevents buffer overread
        • startFifo begins FIFO reads at cnt=2
        • stopFifo ends FIFO reads at cnt=k+3
        • Total cycles = k+7 in CALCULATE state
    end note

    note right of sWrite
        Writes N rows to buffer C:
        • Each row = 4 elements
        • Each element truncated to 16-bit
        • Packed as: Cat(elem[3], elem[2], elem[1], elem[0])
        • Total = N × 64-bit words
    end note
```

## TPU Interface

### Top-Level Interface (TPUTop)

```mermaid
graph LR
    subgraph External["External Signals"]
        direction TB
        start["start<br/>Input<br/>1-bit<br/><br/>Begin computation"]
        m["m<br/>Input<br/>4-bit<br/><br/>Matrix A rows"]
        k["k<br/>Input<br/>4-bit<br/><br/>Common dimension"]
        n["n<br/>Input<br/>4-bit<br/><br/>Matrix B columns"]
        done["done<br/>Output<br/>1-bit<br/><br/>Computation complete"]
    end

    subgraph TPU["TPUTop Module"]
        direction TB
        control["TPU Control<br/>(FSM)"]
        buffers["Global Buffers<br/>A, B, C"]
        systolic["Systolic Array<br/>(4×4 MAC grid)"]
    end

    start --> control
    m --> control
    k --> control
    n --> control
    control --> done

    control <--> buffers
    control <--> systolic
    buffers <--> systolic

    style External fill:#fff4e1
    style TPU fill:#e1f5ff
```

### Internal Interfaces

#### Global Buffer Interface (GlobalBufferIO)
```scala
class GlobalBufferIO(config: TPUConfig, wordWidth: Int) {
  wrEn:   Input(Bool())                        // Write enable
  addr:   Input(UInt(bufferAddrWidth.W))       // Address (8-bit for depth=256)
  wrData: Input(UInt(wordWidth.W))             // Write data (32-bit for A/B, 64-bit for C)
  rdData: Output(UInt(wordWidth.W))            // Read data (synchronous)
}
```

#### MAC Interconnect Interface
```scala
class MACInterconnect(dataWidth: Int) {
  upIn:    Input(SInt(dataWidth.W))            // Vertical input (8-bit signed)
  leftIn:  Input(SInt(dataWidth.W))            // Horizontal input (8-bit signed)
  upOut:   Output(SInt(dataWidth.W))           // Vertical output (forwarded)
  leftOut: Output(SInt(dataWidth.W))           // Horizontal output (forwarded)
}
```

#### Systolic Array Interface
```scala
class SystolicArrayIO {
  matrixAData: Input(UInt(32.W))               // Packed 4×8-bit values for matrix A
  matrixBData: Input(UInt(32.W))               // Packed 4×8-bit values for matrix B
  stopRead:    Input(Bool())                   // Stop reading from buffers
  rdEnA:       Input(Vec(4, Bool()))           // Read enable for each FIFO A (staggered)
  rdEnB:       Input(Vec(4, Bool()))           // Read enable for each FIFO B (staggered)
  sysReset:    Input(Bool())                   // Reset accumulators
  matOut:      Output(Vec(4, Vec(4, SInt(21.W)))) // 4×4 matrix of 21-bit accumulators
}
```

#### FIFO Interface (SyncFIFOIO)
```scala
class SyncFIFOIO(dataWidth: Int) {
  wrEn:    Input(Bool())                       // Write enable
  rdEn:    Input(Bool())                       // Read enable
  dataIn:  Input(SInt(dataWidth.W))            // Input data (8-bit signed)
  dataOut: Output(SInt(dataWidth.W))           // Output data (synchronous)
  empty:   Output(Bool())                      // FIFO empty flag
  full:    Output(Bool())                      // FIFO full flag
}
```

## Key Parameters (Default Configuration)

| Parameter | Value | Description |
|-----------|-------|-------------|
| N (array size) | 4 | Systolic array dimension (4×4 grid) |
| dataWidth | 8 bits | Input element width (signed) |
| accWidth | 21 bits | Accumulator width (signed) |
| wordWidth | 32 bits | Buffer A/B word width (4×8-bit) |
| extendedWordWidth | 64 bits | Buffer C word width (4×16-bit) |
| bufferDepth | 256 words | Global buffer capacity |
| bufferAddrWidth | 8 bits | Address bus width |
| fifoDepth | 4 entries | FIFO capacity per channel |

## Data Flow

1. **Load Phase**: Matrices A and B are pre-loaded into global buffers (external process)
2. **Start**: Assert `start` signal with dimensions m, k, n
3. **Calculate**:
   - Control FSM reads from buffers A and B (32-bit words)
   - Data unpacked into 4×8-bit elements
   - FIFOs buffer data for systolic array
   - Staggered read enables create wave-front data flow
   - MAC units perform multiply-accumulate operations
   - Computation takes k+7 cycles
4. **Write**:
   - Results from 16 MAC accumulators (21-bit each)
   - Truncated to 16-bit per element
   - Packed as 64-bit words (4 elements per word)
   - Written to buffer C (4 words for 4×4 result)
5. **Done**: `done` signal asserted, FSM returns to idle

## Systolic Data Flow Timing

For a k×k inner dimension multiply:
- **Cycle 0**: Start signal, enter IDLE2
- **Cycle 1**: Enter CALCULATE, cnt=1
- **Cycle 2**: Start FIFO reads (startFifo)
- **Cycle k+3**: Stop FIFO reads (stopFifo)
- **Cycle k+7**: Enter WRITE state (cntEnd)
- **Cycle k+8 to k+11**: Write 4 rows to buffer C
- **Cycle k+12**: Enter FINISH, assert done

## Building and Testing

See [CLAUDE.md](CLAUDE.md) for build commands and project structure.
