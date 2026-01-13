// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTPUTestHarnessGen.h for the primary calling header

#include "VTPUTestHarnessGen__pch.h"
#include "VTPUTestHarnessGen___024root.h"

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_static(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_initial(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_final(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__stl(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTPUTestHarnessGen___024root___eval_phase__stl(VTPUTestHarnessGen___024root* vlSelf);

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_settle(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VTPUTestHarnessGen___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../generated_testharness/TPUTestHarnessGen.v", 1388, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTPUTestHarnessGen___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__stl(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTPUTestHarnessGen___024root___stl_sequent__TOP__0(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0;
    TPUTestHarnessGen__DOT__control__DOT____VdfgTmp_h3d7a59c6__0 = 0;
    // Body
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___wrPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___rdPtr_T_2 
        = (3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_1 
        = (7U & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count) 
                 - (IData)(1U)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_3 
        = (7U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count)));
    vlSelf->io_bufA_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg;
    vlSelf->io_bufB_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg;
    vlSelf->io_bufC_rdData = vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg;
    vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en 
        = ((IData)(vlSelf->io_bufA_wrEn) & (IData)(vlSelf->io_testMode));
    vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en 
        = ((IData)(vlSelf->io_bufB_wrEn) & (IData)(vlSelf->io_testMode));
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_17 
        = (0xffU & ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC) 
                    + (3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state))));
    if (vlSelf->io_testMode) {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufA_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufB_addr;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = vlSelf->io_bufC_wrEn;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->io_bufC_addr;
    } else {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA;
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB;
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en 
            = (3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__state));
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr 
            = vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC;
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count)));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty 
        = (((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)) 
           & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count)));
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
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full 
        = (((3U & ((IData)(1U) + (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr))) 
            == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr)) 
           | ((3U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr)) 
              & (0U == (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg)
            : 0U);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn 
        = ((IData)(vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3)
            ? (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg)
            : 0U);
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
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg)))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg)))));
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
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product))));
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
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product))));
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT___accReg_T_2 
        = (0x1fffffU & (vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg 
                        + ((0x1f0000U & ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product) 
                                                        >> 0xfU)))) 
                                         << 0x10U)) 
                           | (IData)(vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product))));
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_stl(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTPUTestHarnessGen___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root___eval_triggers__stl(VTPUTestHarnessGen___024root* vlSelf);

VL_ATTR_COLD bool VTPUTestHarnessGen___024root___eval_phase__stl(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTPUTestHarnessGen___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VTPUTestHarnessGen___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__ico(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__act(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__nba(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTPUTestHarnessGen___024root___ctor_var_reset(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_start = VL_RAND_RESET_I(1);
    vlSelf->io_m = VL_RAND_RESET_I(16);
    vlSelf->io_k = VL_RAND_RESET_I(16);
    vlSelf->io_n = VL_RAND_RESET_I(16);
    vlSelf->io_done = VL_RAND_RESET_I(1);
    vlSelf->io_testMode = VL_RAND_RESET_I(1);
    vlSelf->io_bufA_wrEn = VL_RAND_RESET_I(1);
    vlSelf->io_bufA_addr = VL_RAND_RESET_I(8);
    vlSelf->io_bufA_wrData = VL_RAND_RESET_I(32);
    vlSelf->io_bufA_rdData = VL_RAND_RESET_I(32);
    vlSelf->io_bufB_wrEn = VL_RAND_RESET_I(1);
    vlSelf->io_bufB_addr = VL_RAND_RESET_I(8);
    vlSelf->io_bufB_wrData = VL_RAND_RESET_I(32);
    vlSelf->io_bufB_rdData = VL_RAND_RESET_I(32);
    vlSelf->io_bufC_wrEn = VL_RAND_RESET_I(1);
    vlSelf->io_bufC_addr = VL_RAND_RESET_I(8);
    vlSelf->io_bufC_wrData = VL_RAND_RESET_Q(64);
    vlSelf->io_bufC_rdData = VL_RAND_RESET_Q(64);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray_io_stopRead = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_rdDataReg_MPORT_addr = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__bufferA__DOT__rdDataReg = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_rdDataReg_MPORT_addr = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__bufferB__DOT__rdDataReg = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_rdDataReg_MPORT_addr = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__bufferC__DOT__rdDataReg = VL_RAND_RESET_Q(64);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_empty = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7_io_full = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_upIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0_io_interconnect_leftIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1_io_interconnect_upIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2_io_interconnect_upIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3_io_interconnect_upIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0_io_interconnect_leftIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0_io_interconnect_leftIn = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0_io_interconnect_leftIn = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_1__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_2__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_3__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_4__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_5__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_6__DOT___count_T_3 = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__buffer_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__wrPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__rdPtr = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT__dataOutReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___wrPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___rdPtr_T_2 = VL_RAND_RESET_I(2);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_1 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__SyncFIFO_7__DOT___count_T_3 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_0__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_1__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_2__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_0_3__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_0__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_1__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_2__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_1_3__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_0__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_1__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_2__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_2_3__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_0__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_1__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_2__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__upReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__leftReg = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__accReg = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT__product = VL_RAND_RESET_I(16);
    vlSelf->TPUTestHarnessGen__DOT__systolicArray__DOT__macGrid_3_3__DOT___accReg_T_2 = VL_RAND_RESET_I(21);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__cnt = VL_RAND_RESET_I(12);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrA = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrB = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__addrC = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__writeCnt = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__stopFifo = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__cntEnd = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_0 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_1 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_2 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnAReg_3 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_0 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_1 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_2 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__rdEnBReg_3 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT__sysResetReg = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___cnt_T_2 = VL_RAND_RESET_I(12);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_9 = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_10 = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_11 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_16 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_17 = VL_RAND_RESET_I(8);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_18 = VL_RAND_RESET_I(3);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_21 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_22 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_23 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_24 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_25 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_26 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_27 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_28 = VL_RAND_RESET_I(1);
    vlSelf->TPUTestHarnessGen__DOT__control__DOT___GEN_55 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
