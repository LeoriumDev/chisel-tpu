// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTPUTestHarnessGen__Syms.h"


void VTPUTestHarnessGen___024root__trace_chg_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTPUTestHarnessGen___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_chg_0\n"); );
    // Init
    VTPUTestHarnessGen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTPUTestHarnessGen___024root*>(voidSelf);
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTPUTestHarnessGen___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTPUTestHarnessGen___024root__trace_chg_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+1,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+2,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en)))));
        bufp->chgBit(oldp+3,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en)))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+4,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr),8);
        bufp->chgCData(oldp+5,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr),8);
        bufp->chgBit(oldp+6,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en));
        bufp->chgCData(oldp+7,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr),8);
        bufp->chgBit(oldp+8,(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead));
        bufp->chgIData(oldp+9,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer
                               [vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr]),32);
        bufp->chgIData(oldp+10,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer
                                [vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr]),32);
        bufp->chgBit(oldp+11,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en)))));
        bufp->chgQData(oldp+12,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer
                                [vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr]),64);
        bufp->chgBit(oldp+14,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo));
        bufp->chgBit(oldp+15,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd));
        bufp->chgBit(oldp+16,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)))));
        bufp->chgBit(oldp+17,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+18,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+19,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+20,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+21,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+22,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+23,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en));
        bufp->chgBit(oldp+24,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+25,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0));
        bufp->chgBit(oldp+26,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1));
        bufp->chgBit(oldp+27,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2));
        bufp->chgBit(oldp+28,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3));
        bufp->chgBit(oldp+29,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0));
        bufp->chgBit(oldp+30,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1));
        bufp->chgBit(oldp+31,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2));
        bufp->chgBit(oldp+32,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3));
        bufp->chgBit(oldp+33,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg));
        bufp->chgIData(oldp+34,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg),21);
        bufp->chgIData(oldp+35,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg),21);
        bufp->chgIData(oldp+36,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg),21);
        bufp->chgIData(oldp+37,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg),21);
        bufp->chgIData(oldp+38,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg),21);
        bufp->chgIData(oldp+39,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg),21);
        bufp->chgIData(oldp+40,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg),21);
        bufp->chgIData(oldp+41,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg),21);
        bufp->chgIData(oldp+42,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg),21);
        bufp->chgIData(oldp+43,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg),21);
        bufp->chgIData(oldp+44,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg),21);
        bufp->chgIData(oldp+45,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg),21);
        bufp->chgIData(oldp+46,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg),21);
        bufp->chgIData(oldp+47,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg),21);
        bufp->chgIData(oldp+48,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg),21);
        bufp->chgIData(oldp+49,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg),21);
        bufp->chgCData(oldp+50,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA),8);
        bufp->chgCData(oldp+51,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB),8);
        bufp->chgBit(oldp+52,((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))));
        bufp->chgCData(oldp+53,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC),8);
        bufp->chgQData(oldp+54,((((QData)((IData)((
                                                   (((3U 
                                                      == 
                                                      (3U 
                                                       & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                      ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (3U 
                                                        & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                       ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (3U 
                                                         & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg
                                                        : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & ((3U 
                                                          == 
                                                          (3U 
                                                           & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                          ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg
                                                          : 
                                                         ((2U 
                                                           == 
                                                           (3U 
                                                            & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                           ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg
                                                           : 
                                                          ((1U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                            ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg
                                                            : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg))))))) 
                                  << 0x20U) | (QData)((IData)(
                                                              ((((3U 
                                                                  == 
                                                                  (3U 
                                                                   & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                  ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg
                                                                  : 
                                                                 ((2U 
                                                                   == 
                                                                   (3U 
                                                                    & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                   ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (3U 
                                                                     & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg
                                                                    : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg))) 
                                                                << 0x10U) 
                                                               | (0xffffU 
                                                                  & ((3U 
                                                                      == 
                                                                      (3U 
                                                                       & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                      ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg
                                                                      : 
                                                                     ((2U 
                                                                       == 
                                                                       (3U 
                                                                        & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                       ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg
                                                                       : 
                                                                      ((1U 
                                                                        == 
                                                                        (3U 
                                                                         & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg
                                                                        : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg))))))))),64);
        bufp->chgIData(oldp+56,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg),32);
        bufp->chgIData(oldp+57,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg),32);
        bufp->chgQData(oldp+58,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg),64);
        bufp->chgCData(oldp+60,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state),3);
        bufp->chgSData(oldp+61,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt),12);
        bufp->chgCData(oldp+62,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt),3);
        bufp->chgBit(oldp+63,((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt))));
        bufp->chgIData(oldp+64,(((((3U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg
                                    : ((2U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg
                                        : ((1U == (3U 
                                                   & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                            ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg
                                            : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg))) 
                                  << 0x10U) | (0xffffU 
                                               & ((3U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                   ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                     ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg
                                                     : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg)))))),32);
        bufp->chgIData(oldp+65,(((((3U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg
                                    : ((2U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg
                                        : ((1U == (3U 
                                                   & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                            ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg
                                            : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg))) 
                                  << 0x10U) | (0xffffU 
                                               & ((3U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                   ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                     ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg
                                                     : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg)))))),32);
        bufp->chgCData(oldp+66,((0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg)),8);
        bufp->chgCData(oldp+67,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg),8);
        bufp->chgBit(oldp+68,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty));
        bufp->chgBit(oldp+69,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full));
        bufp->chgCData(oldp+70,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                                          >> 8U))),8);
        bufp->chgCData(oldp+71,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg),8);
        bufp->chgBit(oldp+72,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty));
        bufp->chgBit(oldp+73,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full));
        bufp->chgCData(oldp+74,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                                          >> 0x10U))),8);
        bufp->chgCData(oldp+75,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg),8);
        bufp->chgBit(oldp+76,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty));
        bufp->chgBit(oldp+77,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full));
        bufp->chgCData(oldp+78,((vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                                 >> 0x18U)),8);
        bufp->chgCData(oldp+79,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg),8);
        bufp->chgBit(oldp+80,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty));
        bufp->chgBit(oldp+81,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full));
        bufp->chgCData(oldp+82,((0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg)),8);
        bufp->chgCData(oldp+83,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg),8);
        bufp->chgBit(oldp+84,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty));
        bufp->chgBit(oldp+85,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full));
        bufp->chgCData(oldp+86,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                                          >> 8U))),8);
        bufp->chgCData(oldp+87,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg),8);
        bufp->chgBit(oldp+88,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty));
        bufp->chgBit(oldp+89,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full));
        bufp->chgCData(oldp+90,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                                          >> 0x10U))),8);
        bufp->chgCData(oldp+91,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg),8);
        bufp->chgBit(oldp+92,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty));
        bufp->chgBit(oldp+93,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full));
        bufp->chgCData(oldp+94,((vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                                 >> 0x18U)),8);
        bufp->chgCData(oldp+95,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg),8);
        bufp->chgBit(oldp+96,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty));
        bufp->chgBit(oldp+97,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full));
        bufp->chgCData(oldp+98,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn),8);
        bufp->chgCData(oldp+99,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn),8);
        bufp->chgCData(oldp+100,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg),8);
        bufp->chgCData(oldp+101,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg),8);
        bufp->chgCData(oldp+102,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn),8);
        bufp->chgCData(oldp+103,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg),8);
        bufp->chgCData(oldp+104,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg),8);
        bufp->chgCData(oldp+105,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn),8);
        bufp->chgCData(oldp+106,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg),8);
        bufp->chgCData(oldp+107,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg),8);
        bufp->chgCData(oldp+108,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn),8);
        bufp->chgCData(oldp+109,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg),8);
        bufp->chgCData(oldp+110,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg),8);
        bufp->chgCData(oldp+111,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn),8);
        bufp->chgCData(oldp+112,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg),8);
        bufp->chgCData(oldp+113,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg),8);
        bufp->chgCData(oldp+114,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg),8);
        bufp->chgCData(oldp+115,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg),8);
        bufp->chgCData(oldp+116,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg),8);
        bufp->chgCData(oldp+117,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg),8);
        bufp->chgCData(oldp+118,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg),8);
        bufp->chgCData(oldp+119,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg),8);
        bufp->chgCData(oldp+120,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn),8);
        bufp->chgCData(oldp+121,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg),8);
        bufp->chgCData(oldp+122,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg),8);
        bufp->chgCData(oldp+123,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg),8);
        bufp->chgCData(oldp+124,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg),8);
        bufp->chgCData(oldp+125,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg),8);
        bufp->chgCData(oldp+126,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg),8);
        bufp->chgCData(oldp+127,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg),8);
        bufp->chgCData(oldp+128,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg),8);
        bufp->chgCData(oldp+129,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn),8);
        bufp->chgCData(oldp+130,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg),8);
        bufp->chgCData(oldp+131,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg),8);
        bufp->chgCData(oldp+132,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg),8);
        bufp->chgCData(oldp+133,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg),8);
        bufp->chgCData(oldp+134,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg),8);
        bufp->chgCData(oldp+135,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg),8);
        bufp->chgCData(oldp+136,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg),8);
        bufp->chgCData(oldp+137,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg),8);
        bufp->chgCData(oldp+138,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[0]),8);
        bufp->chgCData(oldp+139,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[1]),8);
        bufp->chgCData(oldp+140,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[2]),8);
        bufp->chgCData(oldp+141,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[3]),8);
        bufp->chgBit(oldp+142,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0))));
        bufp->chgCData(oldp+143,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr),2);
        bufp->chgCData(oldp+144,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr]),8);
        bufp->chgCData(oldp+145,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr),2);
        bufp->chgCData(oldp+146,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count),3);
        bufp->chgCData(oldp+147,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[0]),8);
        bufp->chgCData(oldp+148,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[1]),8);
        bufp->chgCData(oldp+149,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[2]),8);
        bufp->chgCData(oldp+150,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[3]),8);
        bufp->chgBit(oldp+151,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1))));
        bufp->chgCData(oldp+152,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr),2);
        bufp->chgCData(oldp+153,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr]),8);
        bufp->chgCData(oldp+154,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr),2);
        bufp->chgCData(oldp+155,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count),3);
        bufp->chgCData(oldp+156,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[0]),8);
        bufp->chgCData(oldp+157,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[1]),8);
        bufp->chgCData(oldp+158,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[2]),8);
        bufp->chgCData(oldp+159,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[3]),8);
        bufp->chgBit(oldp+160,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2))));
        bufp->chgCData(oldp+161,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr),2);
        bufp->chgCData(oldp+162,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr]),8);
        bufp->chgCData(oldp+163,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr),2);
        bufp->chgCData(oldp+164,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count),3);
        bufp->chgCData(oldp+165,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[0]),8);
        bufp->chgCData(oldp+166,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[1]),8);
        bufp->chgCData(oldp+167,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[2]),8);
        bufp->chgCData(oldp+168,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[3]),8);
        bufp->chgBit(oldp+169,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3))));
        bufp->chgCData(oldp+170,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr),2);
        bufp->chgCData(oldp+171,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr]),8);
        bufp->chgCData(oldp+172,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr),2);
        bufp->chgCData(oldp+173,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count),3);
        bufp->chgCData(oldp+174,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[0]),8);
        bufp->chgCData(oldp+175,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[1]),8);
        bufp->chgCData(oldp+176,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[2]),8);
        bufp->chgCData(oldp+177,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[3]),8);
        bufp->chgBit(oldp+178,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0))));
        bufp->chgCData(oldp+179,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr),2);
        bufp->chgCData(oldp+180,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr]),8);
        bufp->chgCData(oldp+181,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr),2);
        bufp->chgCData(oldp+182,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count),3);
        bufp->chgCData(oldp+183,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[0]),8);
        bufp->chgCData(oldp+184,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[1]),8);
        bufp->chgCData(oldp+185,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[2]),8);
        bufp->chgCData(oldp+186,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[3]),8);
        bufp->chgBit(oldp+187,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1))));
        bufp->chgCData(oldp+188,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr),2);
        bufp->chgCData(oldp+189,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr]),8);
        bufp->chgCData(oldp+190,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr),2);
        bufp->chgCData(oldp+191,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count),3);
        bufp->chgCData(oldp+192,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[0]),8);
        bufp->chgCData(oldp+193,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[1]),8);
        bufp->chgCData(oldp+194,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[2]),8);
        bufp->chgCData(oldp+195,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[3]),8);
        bufp->chgBit(oldp+196,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2))));
        bufp->chgCData(oldp+197,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr),2);
        bufp->chgCData(oldp+198,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr]),8);
        bufp->chgCData(oldp+199,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr),2);
        bufp->chgCData(oldp+200,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count),3);
        bufp->chgCData(oldp+201,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[0]),8);
        bufp->chgCData(oldp+202,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[1]),8);
        bufp->chgCData(oldp+203,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[2]),8);
        bufp->chgCData(oldp+204,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[3]),8);
        bufp->chgBit(oldp+205,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty)) 
                                & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3))));
        bufp->chgCData(oldp+206,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr),2);
        bufp->chgCData(oldp+207,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer
                                 [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr]),8);
        bufp->chgCData(oldp+208,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr),2);
        bufp->chgCData(oldp+209,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count),3);
        bufp->chgSData(oldp+210,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product),16);
        bufp->chgSData(oldp+211,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product),16);
        bufp->chgSData(oldp+212,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product),16);
        bufp->chgSData(oldp+213,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product),16);
        bufp->chgSData(oldp+214,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product),16);
        bufp->chgSData(oldp+215,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product),16);
        bufp->chgSData(oldp+216,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product),16);
        bufp->chgSData(oldp+217,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product),16);
        bufp->chgSData(oldp+218,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product),16);
        bufp->chgSData(oldp+219,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product),16);
        bufp->chgSData(oldp+220,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product),16);
        bufp->chgSData(oldp+221,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product),16);
        bufp->chgSData(oldp+222,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product),16);
        bufp->chgSData(oldp+223,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product),16);
        bufp->chgSData(oldp+224,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product),16);
        bufp->chgSData(oldp+225,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product),16);
    }
    bufp->chgBit(oldp+226,(vlSelf->clock));
    bufp->chgBit(oldp+227,(vlSelf->reset));
    bufp->chgBit(oldp+228,(vlSelf->io_start));
    bufp->chgSData(oldp+229,(vlSelf->io_m),16);
    bufp->chgSData(oldp+230,(vlSelf->io_k),16);
    bufp->chgSData(oldp+231,(vlSelf->io_n),16);
    bufp->chgBit(oldp+232,(vlSelf->io_done));
    bufp->chgBit(oldp+233,(vlSelf->io_testMode));
    bufp->chgBit(oldp+234,(vlSelf->io_bufA_wrEn));
    bufp->chgCData(oldp+235,(vlSelf->io_bufA_addr),8);
    bufp->chgIData(oldp+236,(vlSelf->io_bufA_wrData),32);
    bufp->chgIData(oldp+237,(vlSelf->io_bufA_rdData),32);
    bufp->chgBit(oldp+238,(vlSelf->io_bufB_wrEn));
    bufp->chgCData(oldp+239,(vlSelf->io_bufB_addr),8);
    bufp->chgIData(oldp+240,(vlSelf->io_bufB_wrData),32);
    bufp->chgIData(oldp+241,(vlSelf->io_bufB_rdData),32);
    bufp->chgBit(oldp+242,(vlSelf->io_bufC_wrEn));
    bufp->chgCData(oldp+243,(vlSelf->io_bufC_addr),8);
    bufp->chgQData(oldp+244,(vlSelf->io_bufC_wrData),64);
    bufp->chgQData(oldp+246,(vlSelf->io_bufC_rdData),64);
    bufp->chgIData(oldp+248,(((IData)(vlSelf->io_testMode)
                               ? vlSelf->io_bufA_wrData
                               : 0U)),32);
    bufp->chgIData(oldp+249,(((IData)(vlSelf->io_testMode)
                               ? vlSelf->io_bufB_wrData
                               : 0U)),32);
    bufp->chgQData(oldp+250,(((IData)(vlSelf->io_testMode)
                               ? vlSelf->io_bufC_wrData
                               : (((QData)((IData)(
                                                   ((((3U 
                                                       == 
                                                       (3U 
                                                        & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                       ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (3U 
                                                         & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                         ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg
                                                         : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & ((3U 
                                                           == 
                                                           (3U 
                                                            & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                           ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg
                                                           : 
                                                          ((2U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                            ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg
                                                            : 
                                                           ((1U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                             ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg
                                                             : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               ((((3U 
                                                                   == 
                                                                   (3U 
                                                                    & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                   ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg
                                                                   : 
                                                                  ((2U 
                                                                    == 
                                                                    (3U 
                                                                     & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                    ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg
                                                                    : 
                                                                   ((1U 
                                                                     == 
                                                                     (3U 
                                                                      & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                     ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg
                                                                     : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg))) 
                                                                 << 0x10U) 
                                                                | (0xffffU 
                                                                   & ((3U 
                                                                       == 
                                                                       (3U 
                                                                        & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                       ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg
                                                                       : 
                                                                      ((2U 
                                                                        == 
                                                                        (3U 
                                                                         & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg
                                                                        : 
                                                                       ((1U 
                                                                         == 
                                                                         (3U 
                                                                          & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                                                         ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg
                                                                         : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg)))))))))),64);
    bufp->chgSData(oldp+252,((0x3ffU & (IData)(vlSelf->io_k))),10);
}

void VTPUTestHarnessGen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_cleanup\n"); );
    // Init
    VTPUTestHarnessGen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTPUTestHarnessGen___024root*>(voidSelf);
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
