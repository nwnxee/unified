#pragma once

//
// Tracy support
// =============
// We wrap all API calls to tracy in custom macros, here.
// The purpose is twofold:
//  - Make it a generic interface so it's not strictly tied to Tracy
//    (even though the API is likely already very tailored).
//  - Allow guarding each invocation with a global toggle; which is needed
//    to turn profiling on/off.
//    NB: Tracy will not take many cpu cycles at all even when turned on.
//        Only connecting with the Tracy client will incur a perf cost, and
//        only while connected.
//
// Note that the terms "zone" and "scope" are used interchangeably in documentation.
//

#define TracyFunction __PRETTY_FUNCTION__
#define __RELATIVE_FILE__ ((const char*)(__FILE__) + CMAKE_SOURCE_DIR_LENGTH)
#define TracyFile __RELATIVE_FILE__

#include "External/tracy/tracy-0.10/public/tracy/Tracy.hpp"

//
// You must never send instrumentation to tracy unless this is true and once
// it turns true, it must not be turned off; otherwise the game is very likely
// to crash in the middle of a zone/scope profile. Restart the game to toggle.
//
extern bool g_bTracyEnabled;

// True if a profiler is connected
extern bool g_bTracyProfilerConnected;

// Used internally to track nested scope disablement.
extern uint32_t g_bTracyScopeDisableCounter;

//
// True if INSTR support is currently enabled.
//
#define INSTR_IS_ENABLED() \
    (g_bTracyEnabled)

//
// True if a Profiler is currently connected.
//
#define INSTR_IS_CONNECTED() \
    (g_bTracyProfilerConnected)

//
// True if INSTR support is enabled and a profiler is connected.
//
#define INSTR_IS_ACTIVE() \
    INSTR_IS_ENABLED() && INSTR_IS_CONNECTED()

//
// True if INSTR is active and the current scope conditional permits evaluation.
//
#define INSTR_SCOPE_IS_ACTIVE() \
    (INSTR_IS_ACTIVE() && g_bTracyScopeDisableCounter == 0)

//
// We set a very low max string length, to avoid attaching
// too much data to busy zones; which can really blow up profile exports.
// Note: Tracy has a baked-in limit of 0xFFFF, never exceed even if you
// increase this value here.
//
#define INSTR_MAX_STRING_SIZE 512

//
// To selectively turn a scope on/off, call this BEFORE setting the scope.
// Note that this will disable this zone _and all subzones_ until the scope it was
// set up in exits.
// Boolish will be evaluated exactly once.
//
#define INSTR_SCOPE_COND(boolish) \
    const bool ___instr_this_zone_enabled = (boolish); \
    SCOPE_GUARD(if (!___instr_this_zone_enabled) g_bTracyScopeDisableCounter--; \
                assert(g_bTracyScopeDisableCounter >= 0)); \
    if (!___instr_this_zone_enabled) { g_bTracyScopeDisableCounter++; }

//
// Instrument a unnamed scope.
// You can only have one INSTR_SCOPE per code scope/block, to keep it simple.
// NB: Scopes/zones will always have the function name displayed.
// Usage advisory: For top level scopes where the purpose is clear from
//                 the function name.
//
#define INSTR_SCOPE() \
    ZoneNamed(___tracy_scoped_zone, INSTR_SCOPE_IS_ACTIVE())

//
// Instrument a named scope. Same meaning as PERF_SCOPE, except this one
// takes a name/label you explicitly give.
//  Note that the function name is always included regardless of custom name.
// Usage advisory: For functions/locations where the divined name makes
//                 no sense. For nested scopes within a function; e.g.:
//   ResMan::Demand() {  INTR_SCOPE ... { INTR_SCOPE_NAMED ... } }
// Scope needs to be a string literal, not a variable, and must be available
// and unchanged across application lifetime.
//
#define INSTR_SCOPE_NAMEDL(scope) \
    Instrumentation::assert_string_literal(scope); \
    ZoneNamedN(___tracy_scoped_zone, scope, INSTR_SCOPE_IS_ACTIVE())

//
// Attaches a char* pointer to the previously-defined zone, which will be rendered
// in the Tracy profiler UI as additional text info.
// Same as the Tracy API, the *L functions take a literal and require availability
// across the whole application lifetime. The macros with a size arg always and
// immediately copy the string data, so you can feed dynamid strings into them.
//
#define INSTR_SCOPE_TEXT(text, size) \
    if (INSTR_SCOPE_IS_ACTIVE()) { ZoneText(text, std::min<uint16_t>(size, INSTR_MAX_STRING_SIZE)); }
#define INSTR_SCOPE_TEXTL(lit) \
    Instrumentation::assert_string_literal(scope); \
    if (INSTR_SCOPE_IS_ACTIVE()) { ZoneTextL(lit); }

//
// Shorthand for attaching a string value directly.
//
#define INSTR_SCOPE_STR(valuestr) \
    INSTR_SCOPE_TEXT(valuestr, strlen(valuestr))

//
// Add a string labelled property to the current scope.
//
#define INSTR_SCOPE_PROP_STR(namestr,valuestr) \
    INSTR_SCOPE_STR((CExoString(namestr) + ": " + CExoString(valuestr)).CStr())

//
// Add a numeric labelled property to the current scope.
// The value passed in can be any format-compatible expression and will be evaluated
// exactly once only if the profiler is enabled and attached.
//
#define INSTR_SCOPE_PROP_NUM(namestr, valuenum) \
    INSTR_SCOPE_STR((CExoString(namestr) + ": " + CExoString::ToString(valuenum)).CStr())

//
// Add a numeric labelled property to the current scope, formatted in 32bit hex.
// The value passed in can be any format-compatible expression and will be evaluated
// exactly once only if the profiler is enabled and attached.
//
#define INSTR_SCOPE_PROP_HEX8(namestr, value) \
    INSTR_SCOPE_STR(CExoString::F("%s: 0x%.2x", namestr, value).CStr())
#define INSTR_SCOPE_PROP_HEX16(namestr, value) \
    INSTR_SCOPE_STR(CExoString::F("%s: 0x%.4x", namestr, value).CStr())
#define INSTR_SCOPE_PROP_HEX32(namestr, value) \
    INSTR_SCOPE_STR(CExoString::F("%s: 0x%.8x", namestr, value).CStr())
#define INSTR_SCOPE_PROP_HEX64(namestr, value) \
    INSTR_SCOPE_STR(CExoString::F("%s: 0x%.16x", namestr, value).CStr())

//
// Call this after a logical frame ends on the root of the application.
// Should only happen once in main.cpp.
// NB: This tracks the time between invocations. This is NOT a scope marker.
//
#define INSTR_FRAME_MARK_ROOT() \
    if (INSTR_IS_ENABLED()) { FrameMark; }

//
// A helper to set a scope and a frame mark at the same time - the scope
// at the beginning of the scope; the frame mark at the end.
// This differs from INSTR_FRAME_MARK_* in that it can mark discontinous
// frame times (e.g. a partial slice of an overall frame used for processing).
// You want to use this to discern client/server. Any sub-processing within
// a "app category" should be regular INSTR_SCOPEs.
//
#define INSTR_SCOPE_FRAME_MARK_NAMEDL(name) \
    Instrumentation::StartScope(name); \
    if (INSTR_IS_ENABLED()) { FrameMarkStart(name); }; \
    SCOPE_GUARD(Instrumentation::EndScope(name); \
        if (INSTR_IS_ENABLED()) { FrameMarkEnd(name); })

//
// Emit a human-readable, textual message to the profiler timegraph. Max 64K.
//
#define INSTR_MESSAGE(text, size) \
    if (INSTR_IS_ACTIVE()) { TracyMessage(text, std::min<uint16_t>(size, INSTR_MAX_STRING_SIZE)); }
#define INSTR_MESSAGEC(text, size, col) \
    if (INSTR_IS_ACTIVE()) { TracyMessageC(text, std::min<uint16_t>(size, INSTR_MAX_STRING_SIZE), col); }
#define INSTR_MESSAGEL(text) \
    if (INSTR_IS_ACTIVE()) { TracyMessageL(text); }

//
// Name the currently-calling thread something else than a random thread id.
//
#define INSTR_SET_THREAD_NAMEL(text) \
    Instrumentation::SetThreadName(text)

// Takes the mean value of all pushed plot points over the given plot timespan.
#define INSTR_PLOT_AGGREGATE_MEAN    0
// Sums all pushed data points and plots the final value every plot timespan.
#define INSTR_PLOT_AGGREGATE_SUM     1
// Only consider the last-pushed value. All previously pushed values for the
// current timespan are discarded.
#define INSTR_PLOT_AGGREGATE_LAST    2

#define INSTR_PLOT_TYPE_NUMBER       0 // tracy::PlotFormatType::Number
#define INSTR_PLOT_TYPE_BYTES        1 // tracy::PlotFormatType::Memory
#define INSTR_PLOT_TYPE_PERCENTAGE   2 // tracy::PlotFormatType::Percentage (value: 0-100 incl)

//
// Plot the value numish once per msec.
// Configuration:
// - msec: recalculate and plot every N msec. Calculation and plot intervals are currently linked;
//   so if you want to plot a "things per second", this value needs to be 1000.
// - agg_type: one of INSTR_PLOT_AGGREGATE_, which will be used to calculate
//   an aggregate value over the given timespan.
// - plot_type: one of INSTR_PLOT_TYPE_, which is profiler-side presentation only
// NB: These config values are only stored on the very first invocation; they cannot
//   be changed in later calls to this macro.
//
#define INSTR_PLOT_AGGREGATE_TIMED(msec, name, agg_type, numish, plot_type) \
    Instrumentation::assert_string_literal(name); \
    if (INSTR_IS_ACTIVE()) { Instrumentation::PushPlotAggregate(msec, name, agg_type, numish, plot_type); } \

//
// Add a counting plot to the timegraph.
// This value is plotted immediately and not aggregated.
//
#define INSTR_PLOT_COUNT(name,value) \
    Instrumentation::assert_string_literal(name); \
    if (INSTR_IS_ACTIVE()) { TracyPlot(name, (int64_t)value); }

namespace Instrumentation
{
    template <unsigned N>
    constexpr void assert_string_literal(const char (&s)[N]) { }
    int32_t StartScope(const char *scope, bool final = false);
    void EndScope(const char *scope, int32_t token = 0);
    void SetThreadName(const char* lit);
    void PushPlotAggregate(uint32_t nMsec, const char* sNameLit, uint8_t nAggrType, int64_t nValue, uint8_t nPlotType);
}
