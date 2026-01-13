// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTPUTestHarnessGen__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VTPUTestHarnessGen::VTPUTestHarnessGen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTPUTestHarnessGen__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_start{vlSymsp->TOP.io_start}
    , io_done{vlSymsp->TOP.io_done}
    , io_testMode{vlSymsp->TOP.io_testMode}
    , io_bufA_wrEn{vlSymsp->TOP.io_bufA_wrEn}
    , io_bufA_addr{vlSymsp->TOP.io_bufA_addr}
    , io_bufB_wrEn{vlSymsp->TOP.io_bufB_wrEn}
    , io_bufB_addr{vlSymsp->TOP.io_bufB_addr}
    , io_bufC_wrEn{vlSymsp->TOP.io_bufC_wrEn}
    , io_bufC_addr{vlSymsp->TOP.io_bufC_addr}
    , io_m{vlSymsp->TOP.io_m}
    , io_k{vlSymsp->TOP.io_k}
    , io_n{vlSymsp->TOP.io_n}
    , io_bufA_wrData{vlSymsp->TOP.io_bufA_wrData}
    , io_bufA_rdData{vlSymsp->TOP.io_bufA_rdData}
    , io_bufB_wrData{vlSymsp->TOP.io_bufB_wrData}
    , io_bufB_rdData{vlSymsp->TOP.io_bufB_rdData}
    , io_bufC_wrData{vlSymsp->TOP.io_bufC_wrData}
    , io_bufC_rdData{vlSymsp->TOP.io_bufC_rdData}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTPUTestHarnessGen::VTPUTestHarnessGen(const char* _vcname__)
    : VTPUTestHarnessGen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTPUTestHarnessGen::~VTPUTestHarnessGen() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTPUTestHarnessGen___024root___eval_debug_assertions(VTPUTestHarnessGen___024root* vlSelf);
#endif  // VL_DEBUG
void VTPUTestHarnessGen___024root___eval_static(VTPUTestHarnessGen___024root* vlSelf);
void VTPUTestHarnessGen___024root___eval_initial(VTPUTestHarnessGen___024root* vlSelf);
void VTPUTestHarnessGen___024root___eval_settle(VTPUTestHarnessGen___024root* vlSelf);
void VTPUTestHarnessGen___024root___eval(VTPUTestHarnessGen___024root* vlSelf);

void VTPUTestHarnessGen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTPUTestHarnessGen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTPUTestHarnessGen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTPUTestHarnessGen___024root___eval_static(&(vlSymsp->TOP));
        VTPUTestHarnessGen___024root___eval_initial(&(vlSymsp->TOP));
        VTPUTestHarnessGen___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTPUTestHarnessGen___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTPUTestHarnessGen::eventsPending() { return false; }

uint64_t VTPUTestHarnessGen::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTPUTestHarnessGen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTPUTestHarnessGen___024root___eval_final(VTPUTestHarnessGen___024root* vlSelf);

VL_ATTR_COLD void VTPUTestHarnessGen::final() {
    VTPUTestHarnessGen___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTPUTestHarnessGen::hierName() const { return vlSymsp->name(); }
const char* VTPUTestHarnessGen::modelName() const { return "VTPUTestHarnessGen"; }
unsigned VTPUTestHarnessGen::threads() const { return 1; }
void VTPUTestHarnessGen::prepareClone() const { contextp()->prepareClone(); }
void VTPUTestHarnessGen::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VTPUTestHarnessGen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VTPUTestHarnessGen___024root__trace_decl_types(VerilatedVcd* tracep);

void VTPUTestHarnessGen___024root__trace_init_top(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTPUTestHarnessGen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTPUTestHarnessGen___024root*>(voidSelf);
    VTPUTestHarnessGen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VTPUTestHarnessGen___024root__trace_decl_types(tracep);
    VTPUTestHarnessGen___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VTPUTestHarnessGen___024root__trace_register(VTPUTestHarnessGen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTPUTestHarnessGen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VTPUTestHarnessGen::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VTPUTestHarnessGen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
