// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTPUTestHarnessGen.h for the primary calling header

#include "VTPUTestHarnessGen__pch.h"
#include "VTPUTestHarnessGen__Syms.h"
#include "VTPUTestHarnessGen___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__ico(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG

void VTPUTestHarnessGen___024root___eval_triggers__ico(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTPUTestHarnessGen___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTPUTestHarnessGen___024root___dump_triggers__act(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG

void VTPUTestHarnessGen___024root___eval_triggers__act(VTPUTestHarnessGen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTPUTestHarnessGen___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTPUTestHarnessGen___024root___dump_triggers__act(vlSelf);
    }
#endif
}
