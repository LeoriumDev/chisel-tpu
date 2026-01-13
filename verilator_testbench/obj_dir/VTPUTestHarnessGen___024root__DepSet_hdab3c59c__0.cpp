// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTPUTestHarnessGen.h for the primary calling header

#include "VTPUTestHarnessGen__pch.h"
#include "VTPUTestHarnessGen___024root.h"

VL_INLINE_OPT void VTPUTestHarnessGen___024root___ico_sequent__TOP__0(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0;
    TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0 = 0;
    // Body
    if (vlSelf->io_testMode) {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en 
            = vlSelf->io_bufA_wrEn;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en 
            = vlSelf->io_bufB_wrEn;
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufA_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufB_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = vlSelf->io_bufC_wrEn;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufC_addr;
    } else {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en = 0U;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en = 0U;
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = (3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state));
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC;
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
           == (0x3ffU & ((IData)(7U) + (IData)(vlSelf->io_k))));
    TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
            < (0x3ffU & (IData)(vlSelf->io_k))) & (0U 
                                                   < (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
           == (0x3ffU & ((IData)(3U) + (IData)(vlSelf->io_k))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
            > (0x3ffU & (IData)(vlSelf->io_k))) | (0U 
                                                   == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    if (vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd) {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11 = 3U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2 = 0U;
    } else {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__state;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2 
            = (0xfffU & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_9 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA) 
                    + (IData)(TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0)));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_10 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB) 
                    + (IData)(TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0)));
    if ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21 
            = ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)) 
               | ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo)) 
                  & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)));
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22 
            = ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)) 
               | ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo)) 
                  & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)));
    } else {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
}

void VTPUTestHarnessGen___024root___eval_ico(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTPUTestHarnessGen___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VTPUTestHarnessGen___024root___eval_triggers__ico(VTPUTestHarnessGen___024root* vlSelf);

bool VTPUTestHarnessGen___024root___eval_phase__ico(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTPUTestHarnessGen___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VTPUTestHarnessGen___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VTPUTestHarnessGen___024root___eval_act(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTPUTestHarnessGen___024root___nba_sequent__TOP__0(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0;
    TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0 = 0;
    CData/*7:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 = 0;
    IData/*31:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 = 0;
    IData/*31:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 = 0;
    QData/*63:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr = 0;
    CData/*1:0*/ __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr = 0;
    CData/*1:0*/ __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0;
    __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0;
    __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 = 0;
    CData/*2:0*/ __Vdly__TPUTestHarnessGen__DOT__control__DOT__state;
    __Vdly__TPUTestHarnessGen__DOT__control__DOT__state = 0;
    // Body
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 = 0U;
    __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 = 0U;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr;
    __Vdly__TPUTestHarnessGen__DOT__control__DOT__state 
        = vlSelf->TPUTestHarnessGen__DOT__control__DOT__state;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr;
    __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr 
        = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr;
    __Vdlyvset__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 = 0U;
    if (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 
            = ((IData)(vlSelf->io_testMode) ? vlSelf->io_bufB_wrData
                : 0U);
        __Vdlyvset__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 
            = ((IData)(vlSelf->io_testMode) ? vlSelf->io_bufA_wrData
                : 0U);
        __Vdlyvset__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 
            = (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
               >> 0x18U);
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 
            = (0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                        >> 0x10U));
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 
            = (0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                        >> 8U));
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 
            = (0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg);
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 
            = (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
               >> 0x18U);
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 
            = (0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                        >> 0x10U));
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 
            = (0xffU & (vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                        >> 8U));
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 
            = (0xffU & vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg);
        __Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr;
    }
    if (vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en) {
        __Vdlyvval__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 
            = ((IData)(vlSelf->io_testMode) ? vlSelf->io_bufC_wrData
                : (((QData)((IData)(((((3U == (3U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                        ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg
                                        : ((2U == (3U 
                                                   & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)))
                                            ? vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg
                                            : ((1U 
                                                == 
                                                (3U 
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
                                                         : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg))))))) 
                    << 0x20U) | (QData)((IData)((((
                                                   (3U 
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
                                                          : vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg)))))))));
        __Vdlyvset__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0 
            = vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr;
    }
    if (vlSelf->reset) {
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr = 0U;
        __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr = 0U;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg = 0ULL;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg = 0U;
        __Vdly__TPUTestHarnessGen__DOT__control__DOT__state = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3 = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg = 0U;
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg = 0U;
    } else {
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___wrPtr_T_2));
        }
        if ((1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead)) 
                   & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full))))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___wrPtr_T_2));
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr];
        }
        if (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0) 
             & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty)))) {
            __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr 
                = ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr))
                    ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___rdPtr_T_2));
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr];
        }
        if ((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en)))) {
            vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg 
                = vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr];
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_3;
        }
        if ((((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty)) 
              & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)) 
             & (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_1;
        } else if (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en) 
                    & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)))) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_3;
        }
        if (vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg) {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg = 0U;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg = 0U;
        } else {
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT___accReg_T_2;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn;
            vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg 
                = vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn;
        }
        if ((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en)))) {
            vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg 
                = vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr];
        }
        if ((1U & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en)))) {
            vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg 
                = vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer
                [vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr];
        }
        if ((0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
            if (vlSelf->io_start) {
                __Vdly__TPUTestHarnessGen__DOT__control__DOT__state = 1U;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt = 0U;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA = 0U;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB = 0U;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC = 0U;
            }
        } else {
            if ((1U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                __Vdly__TPUTestHarnessGen__DOT__control__DOT__state = 2U;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt = 1U;
            } else if ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                __Vdly__TPUTestHarnessGen__DOT__control__DOT__state 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2;
            } else {
                __Vdly__TPUTestHarnessGen__DOT__control__DOT__state 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_18;
            }
            if ((1U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                if ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA 
                        = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_9;
                    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB 
                        = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_10;
                }
                if ((2U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC 
                        = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_17;
                }
            }
        }
        if ((0U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
            if ((1U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                if ((2U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                    vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt 
                        = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_16;
                }
            }
        }
        if ((2U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2 = 0U;
            vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3 = 0U;
        } else if ((0U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
            if ((1U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_23;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_25;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_27;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_24;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_26;
                vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3 
                    = vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_28;
            }
        }
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__bufferC__DOT__buffer__v0;
    }
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr;
    if (__Vdlyvset__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr 
        = __Vdly__TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)));
    vlSelf->io_bufC_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg;
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count)));
    if (__Vdlyvset__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__bufferB__DOT__buffer__v0;
    }
    if (__Vdlyvset__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer[__Vdlyvdim0__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0] 
            = __Vdlyvval__TPUTestHarnessGen__DOT__bufferA__DOT__buffer__v0;
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__state 
        = __Vdly__TPUTestHarnessGen__DOT__control__DOT__state;
    vlSelf->io_bufB_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg;
    vlSelf->io_bufA_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg;
    if (vlSelf->io_testMode) {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufA_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufB_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufC_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = vlSelf->io_bufC_wrEn;
    } else {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = (3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state));
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_17 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC) 
                    + (3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))));
    vlSelf->io_done = (4U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state));
    if ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
        if ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt))) {
            vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_16 
                = (7U & 0U);
            vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_18 = 4U;
        } else {
            vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_16 
                = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)));
            vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_18 
                = vlSelf->TPUTestHarnessGen__DOT__control__DOT__state;
        }
    } else {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_16 
            = (7U & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt));
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_18 
            = ((IData)(vlSelf->io_done) ? 0U : (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state));
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
           == (0x3ffU & ((IData)(7U) + (IData)(vlSelf->io_k))));
    TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
            < (0x3ffU & (IData)(vlSelf->io_k))) & (0U 
                                                   < (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
           == (0x3ffU & ((IData)(3U) + (IData)(vlSelf->io_k))));
    if ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))) {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_23 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_25 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_27 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_24 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_26 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_28 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21 
            = ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)) 
               | ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo)) 
                  & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)));
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22 
            = ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)) 
               | ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo)) 
                  & (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)));
    } else {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_23 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_25 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_27 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_24 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_26 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_28 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt) 
            > (0x3ffU & (IData)(vlSelf->io_k))) | (0U 
                                                   == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg)))));
    if (vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd) {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11 = 3U;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2 = 0U;
    } else {
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__state;
        vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2 
            = (0xfffU & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt)));
    }
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_9 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA) 
                    + (IData)(TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0)));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_10 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB) 
                    + (IData)(TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full)) 
                 & (~ (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg 
        = ((IData)(vlSelf->reset) | (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_55));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_55 
        = ((0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg)
            : ((1U != (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state)) 
               & ((2U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))
                   ? (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg)
                   : ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))
                       ? ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt)) 
                          | (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg))
                       : (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg)))));
}

void VTPUTestHarnessGen___024root___eval_nba(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTPUTestHarnessGen___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void VTPUTestHarnessGen___024root___eval_triggers__act(VTPUTestHarnessGen___024root* vlSelf);

bool VTPUTestHarnessGen___024root___eval_phase__act(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTPUTestHarnessGen___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VTPUTestHarnessGen___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTPUTestHarnessGen___024root___eval_phase__nba(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTPUTestHarnessGen___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__ico(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__nba(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__act(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG

void VTPUTestHarnessGen___024root___eval(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VTPUTestHarnessGen___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../generated_testharness/TPUTestHarnessGen.v", 1388, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTPUTestHarnessGen___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VTPUTestHarnessGen___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../generated_testharness/TPUTestHarnessGen.v", 1388, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VTPUTestHarnessGen___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../generated_testharness/TPUTestHarnessGen.v", 1388, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VTPUTestHarnessGen___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VTPUTestHarnessGen___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTPUTestHarnessGen___024root___eval_debug_assertions(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_start & 0xfeU))) {
        Verilated::overWidthError("io_start");}
    if (VL_UNLIKELY((vlSelf->io_testMode & 0xfeU))) {
        Verilated::overWidthError("io_testMode");}
    if (VL_UNLIKELY((vlSelf->io_bufA_wrEn & 0xfeU))) {
        Verilated::overWidthError("io_bufA_wrEn");}
    if (VL_UNLIKELY((vlSelf->io_bufB_wrEn & 0xfeU))) {
        Verilated::overWidthError("io_bufB_wrEn");}
    if (VL_UNLIKELY((vlSelf->io_bufC_wrEn & 0xfeU))) {
        Verilated::overWidthError("io_bufC_wrEn");}
}
#endif  // VL_DEBUG
