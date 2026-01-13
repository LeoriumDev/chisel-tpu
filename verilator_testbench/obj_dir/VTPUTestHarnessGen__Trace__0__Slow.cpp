// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTPUTestHarnessGen__Syms.h"


VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_init_sub__TOP__0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"io_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"io_m",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+231,0,"io_k",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+232,0,"io_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+233,0,"io_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"io_testMode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"io_bufA_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+236,0,"io_bufA_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"io_bufA_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"io_bufA_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+239,0,"io_bufB_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+240,0,"io_bufB_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+241,0,"io_bufB_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_bufB_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"io_bufC_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"io_bufC_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+245,0,"io_bufC_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+247,0,"io_bufC_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("TPUTestHarnessGen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"io_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"io_m",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+231,0,"io_k",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+232,0,"io_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+233,0,"io_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"io_testMode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"io_bufA_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+236,0,"io_bufA_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"io_bufA_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"io_bufA_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+239,0,"io_bufB_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+240,0,"io_bufB_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+241,0,"io_bufB_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_bufB_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"io_bufC_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"io_bufC_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+245,0,"io_bufC_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+247,0,"io_bufC_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+227,0,"bufferA_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"bufferA_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"bufferA_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"bufferA_io_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+249,0,"bufferA_io_wrData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"bufferA_io_rdData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+227,0,"bufferB_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"bufferB_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"bufferB_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"bufferB_io_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+250,0,"bufferB_io_wrData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"bufferB_io_rdData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+227,0,"bufferC_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"bufferC_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"bufferC_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"bufferC_io_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+251,0,"bufferC_io_wrData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+247,0,"bufferC_io_rdData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+227,0,"systolicArray_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"systolicArray_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+238,0,"systolicArray_io_matrixAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"systolicArray_io_matrixBData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"systolicArray_io_stopRead",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"systolicArray_io_rdEnA_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"systolicArray_io_rdEnA_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"systolicArray_io_rdEnA_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"systolicArray_io_rdEnA_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"systolicArray_io_rdEnB_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"systolicArray_io_rdEnB_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"systolicArray_io_rdEnB_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"systolicArray_io_rdEnB_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"systolicArray_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"systolicArray_io_matOut_0_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+36,0,"systolicArray_io_matOut_0_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+37,0,"systolicArray_io_matOut_0_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+38,0,"systolicArray_io_matOut_0_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+39,0,"systolicArray_io_matOut_1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+40,0,"systolicArray_io_matOut_1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+41,0,"systolicArray_io_matOut_1_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+42,0,"systolicArray_io_matOut_1_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+43,0,"systolicArray_io_matOut_2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+44,0,"systolicArray_io_matOut_2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+45,0,"systolicArray_io_matOut_2_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+46,0,"systolicArray_io_matOut_2_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+47,0,"systolicArray_io_matOut_3_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+48,0,"systolicArray_io_matOut_3_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+49,0,"systolicArray_io_matOut_3_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+50,0,"systolicArray_io_matOut_3_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+227,0,"control_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"control_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"control_io_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"control_io_k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+233,0,"control_io_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"control_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"control_io_stopRead",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"control_io_rdEnA_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"control_io_rdEnA_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"control_io_rdEnA_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"control_io_rdEnA_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"control_io_rdEnB_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"control_io_rdEnB_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"control_io_rdEnB_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"control_io_rdEnB_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"control_io_bufA_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+52,0,"control_io_bufB_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+53,0,"control_io_bufC_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"control_io_bufC_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+55,0,"control_io_bufC_wrData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+35,0,"control_io_matOut_0_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+36,0,"control_io_matOut_0_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+37,0,"control_io_matOut_0_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+38,0,"control_io_matOut_0_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+39,0,"control_io_matOut_1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+40,0,"control_io_matOut_1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+41,0,"control_io_matOut_1_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+42,0,"control_io_matOut_1_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+43,0,"control_io_matOut_2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+44,0,"control_io_matOut_2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+45,0,"control_io_matOut_2_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+46,0,"control_io_matOut_2_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+47,0,"control_io_matOut_3_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+48,0,"control_io_matOut_3_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+49,0,"control_io_matOut_3_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+50,0,"control_io_matOut_3_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->pushPrefix("bufferA", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"io_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+249,0,"io_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"io_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"buffer_rdDataReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"buffer_rdDataReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+10,0,"buffer_rdDataReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+249,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"rdDataReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("bufferB", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+250,0,"io_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"buffer_rdDataReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"buffer_rdDataReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+11,0,"buffer_rdDataReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"rdDataReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("bufferC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+251,0,"io_wrData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+247,0,"io_rdData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+12,0,"buffer_rdDataReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"buffer_rdDataReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+13,0,"buffer_rdDataReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+251,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+8,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+59,0,"rdDataReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("control", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"io_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"io_k",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+233,0,"io_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"io_stopRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"io_rdEnA_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_rdEnA_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"io_rdEnA_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_rdEnA_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_rdEnB_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"io_rdEnB_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_rdEnB_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_rdEnB_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"io_bufA_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+52,0,"io_bufB_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+53,0,"io_bufC_wrEn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"io_bufC_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+55,0,"io_bufC_wrData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+35,0,"io_matOut_0_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+36,0,"io_matOut_0_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+37,0,"io_matOut_0_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+38,0,"io_matOut_0_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+39,0,"io_matOut_1_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+40,0,"io_matOut_1_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+41,0,"io_matOut_1_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+42,0,"io_matOut_1_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+43,0,"io_matOut_2_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+44,0,"io_matOut_2_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+45,0,"io_matOut_2_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+46,0,"io_matOut_2_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+47,0,"io_matOut_3_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+48,0,"io_matOut_3_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+49,0,"io_matOut_3_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+50,0,"io_matOut_3_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+61,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+62,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+51,0,"addrA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+52,0,"addrB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+54,0,"addrC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+63,0,"writeCnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+64,0,"startFifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"stopFifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"cntEnd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"rdEnAReg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"rdEnAReg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"rdEnAReg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"rdEnAReg_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"rdEnBReg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"rdEnBReg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rdEnBReg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"rdEnBReg_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"sysResetReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"packedRow_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"packedRow_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("systolicArray", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+238,0,"io_matrixAData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_matrixBData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"io_stopRead",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"io_rdEnA_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_rdEnA_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"io_rdEnA_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_rdEnA_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_rdEnB_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"io_rdEnB_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_rdEnB_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_rdEnB_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"io_matOut_0_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+36,0,"io_matOut_0_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+37,0,"io_matOut_0_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+38,0,"io_matOut_0_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+39,0,"io_matOut_1_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+40,0,"io_matOut_1_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+41,0,"io_matOut_1_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+42,0,"io_matOut_1_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+43,0,"io_matOut_2_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+44,0,"io_matOut_2_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+45,0,"io_matOut_2_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+46,0,"io_matOut_2_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+47,0,"io_matOut_3_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+48,0,"io_matOut_3_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+49,0,"io_matOut_3_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+50,0,"io_matOut_3_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+227,0,"SyncFIFO_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"SyncFIFO_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"SyncFIFO_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"SyncFIFO_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+69,0,"SyncFIFO_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"SyncFIFO_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_1_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_1_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_1_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"SyncFIFO_1_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"SyncFIFO_1_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"SyncFIFO_1_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+73,0,"SyncFIFO_1_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"SyncFIFO_1_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_2_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_2_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_2_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"SyncFIFO_2_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"SyncFIFO_2_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"SyncFIFO_2_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+77,0,"SyncFIFO_2_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"SyncFIFO_2_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_3_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_3_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_3_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"SyncFIFO_3_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"SyncFIFO_3_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+80,0,"SyncFIFO_3_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+81,0,"SyncFIFO_3_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"SyncFIFO_3_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_4_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_4_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_4_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"SyncFIFO_4_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"SyncFIFO_4_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+84,0,"SyncFIFO_4_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+85,0,"SyncFIFO_4_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"SyncFIFO_4_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_5_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_5_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_5_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"SyncFIFO_5_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"SyncFIFO_5_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"SyncFIFO_5_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+89,0,"SyncFIFO_5_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"SyncFIFO_5_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_6_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_6_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_6_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"SyncFIFO_6_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"SyncFIFO_6_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+92,0,"SyncFIFO_6_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+93,0,"SyncFIFO_6_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"SyncFIFO_6_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"SyncFIFO_7_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"SyncFIFO_7_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"SyncFIFO_7_io_wrEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"SyncFIFO_7_io_rdEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"SyncFIFO_7_io_dataIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+96,0,"SyncFIFO_7_io_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+97,0,"SyncFIFO_7_io_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"SyncFIFO_7_io_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_0_0_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_0_0_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"macGrid_0_0_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+100,0,"macGrid_0_0_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+101,0,"macGrid_0_0_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"macGrid_0_0_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"macGrid_0_0_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_0_0_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_0_1_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_0_1_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"macGrid_0_1_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"macGrid_0_1_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+104,0,"macGrid_0_1_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"macGrid_0_1_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+36,0,"macGrid_0_1_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_0_1_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_0_2_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_0_2_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"macGrid_0_2_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"macGrid_0_2_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"macGrid_0_2_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"macGrid_0_2_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"macGrid_0_2_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_0_2_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_0_3_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_0_3_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"macGrid_0_3_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"macGrid_0_3_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+110,0,"macGrid_0_3_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"macGrid_0_3_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"macGrid_0_3_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_0_3_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_1_0_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_1_0_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"macGrid_1_0_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+112,0,"macGrid_1_0_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+113,0,"macGrid_1_0_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"macGrid_1_0_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"macGrid_1_0_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_1_0_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_1_1_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_1_1_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"macGrid_1_1_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"macGrid_1_1_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+115,0,"macGrid_1_1_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"macGrid_1_1_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"macGrid_1_1_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_1_1_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_1_2_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_1_2_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"macGrid_1_2_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"macGrid_1_2_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+117,0,"macGrid_1_2_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+118,0,"macGrid_1_2_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"macGrid_1_2_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_1_2_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_1_3_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_1_3_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"macGrid_1_3_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+118,0,"macGrid_1_3_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+119,0,"macGrid_1_3_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+120,0,"macGrid_1_3_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"macGrid_1_3_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_1_3_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_2_0_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_2_0_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"macGrid_2_0_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+121,0,"macGrid_2_0_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+122,0,"macGrid_2_0_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"macGrid_2_0_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"macGrid_2_0_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_2_0_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_2_1_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_2_1_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"macGrid_2_1_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"macGrid_2_1_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+124,0,"macGrid_2_1_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"macGrid_2_1_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"macGrid_2_1_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_2_1_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_2_2_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_2_2_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"macGrid_2_2_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"macGrid_2_2_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+126,0,"macGrid_2_2_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"macGrid_2_2_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"macGrid_2_2_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_2_2_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_2_3_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_2_3_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"macGrid_2_3_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"macGrid_2_3_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+128,0,"macGrid_2_3_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+129,0,"macGrid_2_3_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"macGrid_2_3_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_2_3_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_3_0_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_3_0_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"macGrid_3_0_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+130,0,"macGrid_3_0_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+131,0,"macGrid_3_0_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"macGrid_3_0_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"macGrid_3_0_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_3_0_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_3_1_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_3_1_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"macGrid_3_1_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"macGrid_3_1_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+133,0,"macGrid_3_1_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"macGrid_3_1_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"macGrid_3_1_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_3_1_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_3_2_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_3_2_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"macGrid_3_2_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"macGrid_3_2_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"macGrid_3_2_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"macGrid_3_2_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"macGrid_3_2_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_3_2_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"macGrid_3_3_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"macGrid_3_3_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"macGrid_3_3_io_interconnect_upIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"macGrid_3_3_io_interconnect_leftIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"macGrid_3_3_io_interconnect_upOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"macGrid_3_3_io_interconnect_leftOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"macGrid_3_3_io_matOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"macGrid_3_3_io_sysReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"fifosB_0_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"fifosB_1_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+92,0,"fifosB_2_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+96,0,"fifosB_3_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"fifosA_0_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"fifosA_1_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"fifosA_2_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+80,0,"fifosA_3_dataOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("SyncFIFO", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+69,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+139+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+143,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+145,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+146,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+144,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+147,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+68,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+73,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+148+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+152,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+154,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+71,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+155,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+153,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+156,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+72,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+77,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+157+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+161,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+162,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+163,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+164,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+162,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+165,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+76,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+80,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+81,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+166+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+170,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+171,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+172,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+173,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+171,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+174,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+80,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+84,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+85,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+175+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+179,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+180,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+181,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+83,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+182,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+180,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+183,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+84,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+89,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+184+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+188,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+189,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+190,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+87,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+191,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+189,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+192,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+88,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+92,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+93,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+193+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+197,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+199,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+200,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+200,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+198,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+201,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+92,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SyncFIFO_7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_wrEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_rdEn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"io_dataIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+96,0,"io_dataOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+97,0,"io_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("buffer", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+202+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+206,0,"buffer_dataOutReg_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+207,0,"buffer_dataOutReg_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+208,0,"buffer_dataOutReg_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+95,0,"buffer_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+209,0,"buffer_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+254,0,"buffer_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"buffer_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+209,0,"wrPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+207,0,"rdPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+210,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+96,0,"dataOutReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_0_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+100,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+101,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+211,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_0_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+104,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+36,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+36,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+212,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_0_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+213,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_0_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+110,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+214,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_1_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+112,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+113,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+215,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_1_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+115,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+216,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_1_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+117,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+118,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+118,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+217,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_1_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+118,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+119,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+120,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+120,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+218,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_2_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+121,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+122,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+219,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_2_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+124,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+220,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_2_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+126,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+221,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_2_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+128,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+129,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+129,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+222,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_3_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+130,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+131,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+223,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_3_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+133,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+224,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_3_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+135,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+225,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("macGrid_3_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+227,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"io_interconnect_upIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"io_interconnect_leftIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"io_interconnect_upOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"io_interconnect_leftOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"io_matOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+34,0,"io_sysReset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"upReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"leftReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"accReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+226,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_init_top(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_init_top\n"); );
    // Body
    VTPUTestHarnessGen___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTPUTestHarnessGen___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTPUTestHarnessGen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_register(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VTPUTestHarnessGen___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VTPUTestHarnessGen___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VTPUTestHarnessGen___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VTPUTestHarnessGen___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_const_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_const_0\n"); );
    // Init
    VTPUTestHarnessGen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTPUTestHarnessGen___024root*>(voidSelf);
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTPUTestHarnessGen___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_const_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+254,(1U));
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_full_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_full_0\n"); );
    // Init
    VTPUTestHarnessGen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTPUTestHarnessGen___024root*>(voidSelf);
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTPUTestHarnessGen___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_full_0_sub_0(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+2,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+3,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en)))));
    bufp->fullBit(oldp+4,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en)))));
    bufp->fullCData(oldp+5,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr),8);
    bufp->fullCData(oldp+6,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr),8);
    bufp->fullBit(oldp+7,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en));
    bufp->fullCData(oldp+8,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr),8);
    bufp->fullBit(oldp+9,(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead));
    bufp->fullIData(oldp+10,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer
                             [vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr]),32);
    bufp->fullIData(oldp+11,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer
                             [vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr]),32);
    bufp->fullBit(oldp+12,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en)))));
    bufp->fullQData(oldp+13,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer
                             [vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr]),64);
    bufp->fullBit(oldp+15,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo));
    bufp->fullBit(oldp+16,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd));
    bufp->fullBit(oldp+17,((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)))));
    bufp->fullBit(oldp+18,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+19,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+20,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+21,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+22,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+23,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+24,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+25,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en));
    bufp->fullBit(oldp+26,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0));
    bufp->fullBit(oldp+27,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1));
    bufp->fullBit(oldp+28,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2));
    bufp->fullBit(oldp+29,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3));
    bufp->fullBit(oldp+30,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0));
    bufp->fullBit(oldp+31,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1));
    bufp->fullBit(oldp+32,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2));
    bufp->fullBit(oldp+33,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3));
    bufp->fullBit(oldp+34,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg));
    bufp->fullIData(oldp+35,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg),21);
    bufp->fullIData(oldp+36,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg),21);
    bufp->fullIData(oldp+37,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg),21);
    bufp->fullIData(oldp+38,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg),21);
    bufp->fullIData(oldp+39,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg),21);
    bufp->fullIData(oldp+40,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg),21);
    bufp->fullIData(oldp+41,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg),21);
    bufp->fullIData(oldp+42,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg),21);
    bufp->fullIData(oldp+43,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg),21);
    bufp->fullIData(oldp+44,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg),21);
    bufp->fullIData(oldp+45,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg),21);
    bufp->fullIData(oldp+46,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg),21);
    bufp->fullIData(oldp+47,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg),21);
    bufp->fullIData(oldp+48,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg),21);
    bufp->fullIData(oldp+49,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg),21);
    bufp->fullIData(oldp+50,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg),21);
    bufp->fullCData(oldp+51,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA),8);
    bufp->fullCData(oldp+52,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB),8);
    bufp->fullBit(oldp+53,((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))));
    bufp->fullCData(oldp+54,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC),8);
    bufp->fullQData(oldp+55,((((QData)((IData)(((((3U 
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
    bufp->fullIData(oldp+57,(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg),32);
    bufp->fullIData(oldp+58,(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg),32);
    bufp->fullQData(oldp+59,(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg),64);
    bufp->fullCData(oldp+61,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state),3);
    bufp->fullSData(oldp+62,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt),12);
    bufp->fullCData(oldp+63,(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt),3);
    bufp->fullBit(oldp+64,((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt))));
    bufp->fullIData(oldp+65,(((((3U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
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
                                                : (
                                                   (2U 
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
    bufp->fullIData(oldp+66,(((((3U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
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
                                                : (
                                                   (2U 
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
    bufp->fullCData(oldp+67,((0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg)),8);
    bufp->fullCData(oldp+68,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg),8);
    bufp->fullBit(oldp+69,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty));
    bufp->fullBit(oldp+70,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full));
    bufp->fullCData(oldp+71,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                                       >> 8U))),8);
    bufp->fullCData(oldp+72,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg),8);
    bufp->fullBit(oldp+73,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty));
    bufp->fullBit(oldp+74,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full));
    bufp->fullCData(oldp+75,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                                       >> 0x10U))),8);
    bufp->fullCData(oldp+76,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg),8);
    bufp->fullBit(oldp+77,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty));
    bufp->fullBit(oldp+78,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full));
    bufp->fullCData(oldp+79,((vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                              >> 0x18U)),8);
    bufp->fullCData(oldp+80,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg),8);
    bufp->fullBit(oldp+81,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty));
    bufp->fullBit(oldp+82,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full));
    bufp->fullCData(oldp+83,((0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg)),8);
    bufp->fullCData(oldp+84,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg),8);
    bufp->fullBit(oldp+85,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty));
    bufp->fullBit(oldp+86,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full));
    bufp->fullCData(oldp+87,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                                       >> 8U))),8);
    bufp->fullCData(oldp+88,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg),8);
    bufp->fullBit(oldp+89,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty));
    bufp->fullBit(oldp+90,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full));
    bufp->fullCData(oldp+91,((0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                                       >> 0x10U))),8);
    bufp->fullCData(oldp+92,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg),8);
    bufp->fullBit(oldp+93,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty));
    bufp->fullBit(oldp+94,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full));
    bufp->fullCData(oldp+95,((vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                              >> 0x18U)),8);
    bufp->fullCData(oldp+96,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg),8);
    bufp->fullBit(oldp+97,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty));
    bufp->fullBit(oldp+98,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full));
    bufp->fullCData(oldp+99,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn),8);
    bufp->fullCData(oldp+100,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn),8);
    bufp->fullCData(oldp+101,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg),8);
    bufp->fullCData(oldp+102,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg),8);
    bufp->fullCData(oldp+103,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn),8);
    bufp->fullCData(oldp+104,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg),8);
    bufp->fullCData(oldp+105,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg),8);
    bufp->fullCData(oldp+106,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn),8);
    bufp->fullCData(oldp+107,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg),8);
    bufp->fullCData(oldp+108,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg),8);
    bufp->fullCData(oldp+109,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn),8);
    bufp->fullCData(oldp+110,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg),8);
    bufp->fullCData(oldp+111,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg),8);
    bufp->fullCData(oldp+112,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn),8);
    bufp->fullCData(oldp+113,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg),8);
    bufp->fullCData(oldp+114,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg),8);
    bufp->fullCData(oldp+115,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg),8);
    bufp->fullCData(oldp+116,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg),8);
    bufp->fullCData(oldp+117,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg),8);
    bufp->fullCData(oldp+118,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg),8);
    bufp->fullCData(oldp+119,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg),8);
    bufp->fullCData(oldp+120,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg),8);
    bufp->fullCData(oldp+121,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn),8);
    bufp->fullCData(oldp+122,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg),8);
    bufp->fullCData(oldp+123,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg),8);
    bufp->fullCData(oldp+124,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg),8);
    bufp->fullCData(oldp+125,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg),8);
    bufp->fullCData(oldp+126,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg),8);
    bufp->fullCData(oldp+127,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg),8);
    bufp->fullCData(oldp+128,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg),8);
    bufp->fullCData(oldp+129,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg),8);
    bufp->fullCData(oldp+130,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn),8);
    bufp->fullCData(oldp+131,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg),8);
    bufp->fullCData(oldp+132,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg),8);
    bufp->fullCData(oldp+133,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg),8);
    bufp->fullCData(oldp+134,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg),8);
    bufp->fullCData(oldp+135,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg),8);
    bufp->fullCData(oldp+136,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg),8);
    bufp->fullCData(oldp+137,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg),8);
    bufp->fullCData(oldp+138,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg),8);
    bufp->fullCData(oldp+139,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[0]),8);
    bufp->fullCData(oldp+140,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[1]),8);
    bufp->fullCData(oldp+141,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[2]),8);
    bufp->fullCData(oldp+142,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[3]),8);
    bufp->fullBit(oldp+143,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0))));
    bufp->fullCData(oldp+144,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr),2);
    bufp->fullCData(oldp+145,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr]),8);
    bufp->fullCData(oldp+146,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr),2);
    bufp->fullCData(oldp+147,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count),3);
    bufp->fullCData(oldp+148,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[0]),8);
    bufp->fullCData(oldp+149,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[1]),8);
    bufp->fullCData(oldp+150,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[2]),8);
    bufp->fullCData(oldp+151,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[3]),8);
    bufp->fullBit(oldp+152,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1))));
    bufp->fullCData(oldp+153,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr),2);
    bufp->fullCData(oldp+154,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr]),8);
    bufp->fullCData(oldp+155,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr),2);
    bufp->fullCData(oldp+156,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count),3);
    bufp->fullCData(oldp+157,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[0]),8);
    bufp->fullCData(oldp+158,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[1]),8);
    bufp->fullCData(oldp+159,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[2]),8);
    bufp->fullCData(oldp+160,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[3]),8);
    bufp->fullBit(oldp+161,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2))));
    bufp->fullCData(oldp+162,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr),2);
    bufp->fullCData(oldp+163,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr]),8);
    bufp->fullCData(oldp+164,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr),2);
    bufp->fullCData(oldp+165,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count),3);
    bufp->fullCData(oldp+166,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[0]),8);
    bufp->fullCData(oldp+167,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[1]),8);
    bufp->fullCData(oldp+168,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[2]),8);
    bufp->fullCData(oldp+169,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[3]),8);
    bufp->fullBit(oldp+170,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3))));
    bufp->fullCData(oldp+171,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr),2);
    bufp->fullCData(oldp+172,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr]),8);
    bufp->fullCData(oldp+173,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr),2);
    bufp->fullCData(oldp+174,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count),3);
    bufp->fullCData(oldp+175,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[0]),8);
    bufp->fullCData(oldp+176,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[1]),8);
    bufp->fullCData(oldp+177,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[2]),8);
    bufp->fullCData(oldp+178,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[3]),8);
    bufp->fullBit(oldp+179,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0))));
    bufp->fullCData(oldp+180,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr),2);
    bufp->fullCData(oldp+181,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr]),8);
    bufp->fullCData(oldp+182,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr),2);
    bufp->fullCData(oldp+183,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count),3);
    bufp->fullCData(oldp+184,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[0]),8);
    bufp->fullCData(oldp+185,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[1]),8);
    bufp->fullCData(oldp+186,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[2]),8);
    bufp->fullCData(oldp+187,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[3]),8);
    bufp->fullBit(oldp+188,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1))));
    bufp->fullCData(oldp+189,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr),2);
    bufp->fullCData(oldp+190,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr]),8);
    bufp->fullCData(oldp+191,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr),2);
    bufp->fullCData(oldp+192,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count),3);
    bufp->fullCData(oldp+193,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[0]),8);
    bufp->fullCData(oldp+194,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[1]),8);
    bufp->fullCData(oldp+195,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[2]),8);
    bufp->fullCData(oldp+196,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[3]),8);
    bufp->fullBit(oldp+197,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2))));
    bufp->fullCData(oldp+198,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr),2);
    bufp->fullCData(oldp+199,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr]),8);
    bufp->fullCData(oldp+200,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr),2);
    bufp->fullCData(oldp+201,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count),3);
    bufp->fullCData(oldp+202,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[0]),8);
    bufp->fullCData(oldp+203,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[1]),8);
    bufp->fullCData(oldp+204,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[2]),8);
    bufp->fullCData(oldp+205,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[3]),8);
    bufp->fullBit(oldp+206,(((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty)) 
                             & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3))));
    bufp->fullCData(oldp+207,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr),2);
    bufp->fullCData(oldp+208,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer
                              [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr]),8);
    bufp->fullCData(oldp+209,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr),2);
    bufp->fullCData(oldp+210,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count),3);
    bufp->fullSData(oldp+211,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product),16);
    bufp->fullSData(oldp+212,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product),16);
    bufp->fullSData(oldp+213,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product),16);
    bufp->fullSData(oldp+214,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product),16);
    bufp->fullSData(oldp+215,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product),16);
    bufp->fullSData(oldp+216,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product),16);
    bufp->fullSData(oldp+217,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product),16);
    bufp->fullSData(oldp+218,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product),16);
    bufp->fullSData(oldp+219,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product),16);
    bufp->fullSData(oldp+220,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product),16);
    bufp->fullSData(oldp+221,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product),16);
    bufp->fullSData(oldp+222,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product),16);
    bufp->fullSData(oldp+223,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product),16);
    bufp->fullSData(oldp+224,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product),16);
    bufp->fullSData(oldp+225,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product),16);
    bufp->fullSData(oldp+226,(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product),16);
    bufp->fullBit(oldp+227,(vlSelf->clock));
    bufp->fullBit(oldp+228,(vlSelf->reset));
    bufp->fullBit(oldp+229,(vlSelf->io_start));
    bufp->fullSData(oldp+230,(vlSelf->io_m),16);
    bufp->fullSData(oldp+231,(vlSelf->io_k),16);
    bufp->fullSData(oldp+232,(vlSelf->io_n),16);
    bufp->fullBit(oldp+233,(vlSelf->io_done));
    bufp->fullBit(oldp+234,(vlSelf->io_testMode));
    bufp->fullBit(oldp+235,(vlSelf->io_bufA_wrEn));
    bufp->fullCData(oldp+236,(vlSelf->io_bufA_addr),8);
    bufp->fullIData(oldp+237,(vlSelf->io_bufA_wrData),32);
    bufp->fullIData(oldp+238,(vlSelf->io_bufA_rdData),32);
    bufp->fullBit(oldp+239,(vlSelf->io_bufB_wrEn));
    bufp->fullCData(oldp+240,(vlSelf->io_bufB_addr),8);
    bufp->fullIData(oldp+241,(vlSelf->io_bufB_wrData),32);
    bufp->fullIData(oldp+242,(vlSelf->io_bufB_rdData),32);
    bufp->fullBit(oldp+243,(vlSelf->io_bufC_wrEn));
    bufp->fullCData(oldp+244,(vlSelf->io_bufC_addr),8);
    bufp->fullQData(oldp+245,(vlSelf->io_bufC_wrData),64);
    bufp->fullQData(oldp+247,(vlSelf->io_bufC_rdData),64);
    bufp->fullIData(oldp+249,(((IData)(vlSelf->io_testMode)
                                ? vlSelf->io_bufA_wrData
                                : 0U)),32);
    bufp->fullIData(oldp+250,(((IData)(vlSelf->io_testMode)
                                ? vlSelf->io_bufB_wrData
                                : 0U)),32);
    bufp->fullQData(oldp+251,(((IData)(vlSelf->io_testMode)
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
    bufp->fullSData(oldp+253,((0x3ffU & (IData)(vlSelf->io_k))),10);
}
