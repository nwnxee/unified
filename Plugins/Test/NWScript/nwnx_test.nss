/// @addtogroup test Test
/// @brief Adds testing infrastructure for NWScript
/// @{
/// @file nwnx_test.nss
#include "nwnx"

const string NWNX_Test = "NWNX_Test"; ///< @private

/// @brief Adds a NWScript to the test runner.
/// @param sScript Test script to be executed.
/// @param sPluginDepend Optional, if specified the test script will only execute if plugin is loaded.
void NWNX_Test_AddTestScript(string sScript);

/// @brief Adds some context to the test runner output
/// @param message Message to print.
/// @param depth Optional. Adds indentation.  Default: 2
/// @param bOverride Optional. If `FALSE` depth is additive to the current test scope, if `TRUE` overrides the current scope. Default:`FALSE`
void NWNX_Test_Context(string message, int depth = 2, int bOverride = FALSE);

/// @brief Determines if the given plugin exists and is enabled.
/// @param sPlugin The name of the plugin to check. This is the case sensitive plugin name as used by NWNX_CallFunction, NWNX_PushArgumentX
/// @note `NWNX_Util` must be loaded for this to work.
/// @return TRUE if the plugin exists and is enabled, otherwise FALSE.
int NWNX_Test_PluginExists(string sPlugin);

/// @anchor nwnx_test_script_functions
/// @name NWNX Test Script Functions
/// @{

/// @brief Starts a new sub-test if called with a new name.
/// @param testname The name of the test,
/// @note Example usage: while (TEST("xxx")).  This will only one iteration.
/// @return `TRUE` if called with different name, `FALSE` if the same.
int TEST(string testname);

/// @brief Asserts that a particular test is true.
/// @param failure Failure is determined by whether this parameters is equal to "".
/// @param messsage Message to add contect or aid in debugging.
/// @note If the assertion fails all following tests and sub-tests in the current scope will be skipped.
/// @return `failure` == ""
int ASSERT(string failure, string message="");

/// @brief Asserts that a particular test is true.
/// @param failure Failure is determined by whether this parameters is equal to "".
/// @param messsage Message to add contect or aid in debugging.
/// @note Unlike `ASSERT` all tests and sub-tests in the current scope will still run.
/// @return `failure` == ""
int EXPECT(string failure, string message="");

/// @brief Test Object Validity
/// @param obj Object to be tested
/// @return "" on success, error message on failure
string IS_VALID(object obj) { return !GetIsObjectValid(obj) ? "Valid Object, got Invalid Object" : ""; }
/// @copydoc IS_VALID()
string IS_INVALID(object obj)  { return GetIsObjectValid(obj) ? "Invalid Object, got Valid Object" : ""; }

/// @brief Test Equality
/// @param a First value
/// @param b Second value
/// @return "" on success, error message on failure
string IS_EQUAL_INT(int a, int b) { return a != b ? IntToString(a) + " == " + IntToString(b) : ""; }
/// @copydoc IS_EQUAL_INT()
string IS_EQUAL_FLOAT(float a, float b) { return a != b ? FloatToString(a) + " == " + FloatToString(b) : ""; }
/// @copydoc IS_EQUAL_INT()
string IS_EQUAL_OBJECT(object a, object b) { return a != b ? ObjectToString(a) + " == " + ObjectToString(b) : ""; }
/// @copydoc IS_EQUAL_INT()
string IS_EQUAL_STRING(string a, string b) { return a != b ? "'" + a + "'" + " == " + "'" + b + "'" : ""; }

/// @copydoc IS_EQUAL_INT()
string NOT_EQUAL_INT(int a, int b) { return a == b ? IntToString(a) + " != " + IntToString(b) : ""; }
/// @copydoc IS_EQUAL_INT()
string NOT_EQUAL_FLOAT(float a, float b) { return a == b ? FloatToString(a) + " != " + FloatToString(b) : ""; }
/// @copydoc IS_EQUAL_INT()
string NOT_EQUAL_STRING(string a, string b) { return a == b ? "'" + a + "'" + " != " + "'" + b + "'" : ""; }

/// @brief Test Comparison
/// @param a First value
/// @param b Second value
/// @return "" on success, error message on failure
string IS_GT_INT(int a, int b) { return a <= b ? IntToString(a) + " > " + IntToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_GTE_INT(int a, int b) { return a < b ? IntToString(a) + " >= " + IntToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_LT_INT(int a, int b) { return a >= b ? IntToString(a) + " < " + IntToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_LTE_INT(int a, int b) { return a > b ? IntToString(a) + " <= " + IntToString(b) : ""; }

/// @copydoc IS_EQUAL_GT()
string IS_GT_FLOAT(float a, float b) { return a <= b ? FloatToString(a) + " > " + FloatToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_GTE_FLOAT(float a, float b) { return a < b ? FloatToString(a) + " >= " + FloatToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_LT_FLOAT(float a, float b) { return a >= b ? FloatToString(a) + " < " + FloatToString(b) : ""; }
/// @copydoc IS_EQUAL_GT()
string IS_LTE_FLOAT(float a, float b) { return a > b ? FloatToString(a) + " <= " + FloatToString(b) : ""; }

/// @brief Test Truthiness
/// @param a First value
/// @param b Second value
/// @return "" on success, error message on failure
string IS_FALSE(int a) { return a ? "FALSE, got TRUE" : ""; }
/// @copydoc IS_FALSE()
string IS_TRUE(int a) { return !a ? "TRUE, got FALSE" : ""; }
/// @}

/// @}

// Private Function Declarations
int NWNX_Test_IncLocal(object obj, string key, int by = 1);
int NWNX_Test_DecLocal(object obj, string key, int by = 1);
int NWNX_Test_GetStackDepth();
string NWNX_Test_GetTestName();
int NWNX_Test_Skip(int nStackDepth);
void NWNX_Test_Flush(int passed, int failed, int skipped, int depth, int finished = 0);
void NWNX_Test_ReportFailure(string failure, string message, int depth);
// End Private Function Declarations

void NWNX_Test_AddTestScript(string sScript)
{
    string sFunc = "AddTestScript";
    NWNX_PushArgumentString(NWNX_Test, sFunc, sScript);
    NWNX_CallFunction(NWNX_Test, sFunc);
}

void NWNX_Test_ReportFailure(string failure, string message, int depth)
{
    string sFunc = "ReportFailure";
    NWNX_PushArgumentInt(NWNX_Test, sFunc, depth);
    NWNX_PushArgumentString(NWNX_Test, sFunc, message);
    NWNX_PushArgumentString(NWNX_Test, sFunc, failure);
    NWNX_CallFunction(NWNX_Test, sFunc);
}

void NWNX_Test_Context(string message, int depth = 2, int bOverride = FALSE)
{
    if(!bOverride)
        depth += NWNX_Test_GetStackDepth();

    string sFunc = "Context";
    NWNX_PushArgumentInt(NWNX_Test, sFunc, depth);
    NWNX_PushArgumentString(NWNX_Test, sFunc, message);
    NWNX_CallFunction(NWNX_Test, sFunc);
}

void NWNX_Test_Flush(int passed, int failed, int skipped, int depth, int finished = 0)
{
    string sFunc = "Flush";
    NWNX_PushArgumentInt(NWNX_Test, sFunc, finished);
    NWNX_PushArgumentInt(NWNX_Test, sFunc, depth);
    NWNX_PushArgumentInt(NWNX_Test, sFunc, skipped);
    NWNX_PushArgumentInt(NWNX_Test, sFunc, failed);
    NWNX_PushArgumentInt(NWNX_Test, sFunc, passed);
    NWNX_CallFunction(NWNX_Test, sFunc);
}

/// @brief Determines if the given plugin exists and is enabled.
/// @param sPlugin The name of the plugin to check. This is the case sensitive plugin name as used by NWNX_CallFunction, NWNX_PushArgumentX
/// @note `NWNX_Util` must be loaded for this to work.
/// @return TRUE if the plugin exists and is enabled, otherwise FALSE.
int NWNX_Test_PluginExists(string sPlugin)
{
    string sFunc = "PluginExists";
    NWNX_PushArgumentString("NWNX_Util", sFunc, sPlugin);
    NWNX_CallFunction("NWNX_Util", sFunc);
    return NWNX_GetReturnValueInt("NWNX_Util", sFunc); // Doing a bit of cheating here, but we can't have circular depenencies
}

const string gTestCaseKey = "NWNX_TEST_CASE_";
const string gTestAssertKey = "NWNX_TEST_CASE_ASSERT_";
const string gTestSkipKey = "NWNX_TEST_CASE_SKIP_";
const string gTestPassKey = "NWNX_TEST_CASE_PASS_";
const string gTestFailKey = "NWNX_TEST_CASE_FAIL_";
const string gTestStackDepthKey = "NWNX_TEST_STACK_DEPTH";

// Starts a new sub-test if called with a new name, and returns TRUE
// If called with the same name as currently active test, ends the test and returns FALSE.
// Example usage: while(TEST("xxx")) // will only run one iteration
int TEST(string testname)
{
    int sd = NWNX_Test_GetStackDepth();
    WriteTimestampedLogEntry(IntToString(sd));

    string key = gTestCaseKey+IntToString(sd);
    if(GetLocalString(GetModule(), key) == testname)
    {
        NWNX_Test_Context(NWNX_Test_GetTestName()+" finished.", sd, TRUE);
        NWNX_Test_Flush(
            GetLocalInt(GetModule(), gTestPassKey + IntToString(sd)),
            GetLocalInt(GetModule(), gTestFailKey + IntToString(sd)),
            GetLocalInt(GetModule(), gTestSkipKey + IntToString(sd)),
            sd,
            sd == 1
        );
        SetLocalInt(GetModule(), gTestStackDepthKey, --sd);
        return FALSE;
    }
    else
    {
        SetLocalInt(GetModule(), gTestStackDepthKey, ++sd);

        key = gTestCaseKey + IntToString(sd);
        SetLocalString(GetModule(), key, testname);
        key = gTestAssertKey + IntToString(sd);
        SetLocalInt(GetModule(), key, 0);
        key = gTestSkipKey + IntToString(sd);
        SetLocalInt(GetModule(), key, 0);
        key = gTestPassKey + IntToString(sd);
        SetLocalInt(GetModule(), key, 0);
        key = gTestFailKey + IntToString(sd);
        SetLocalInt(GetModule(), key, 0);

        if (sd > 1)
        {
            NWNX_Test_Context("Running sub-test case " + NWNX_Test_GetTestName(), sd, TRUE);
        }
        else
        {
            NWNX_Test_Context("Running test case " + NWNX_Test_GetTestName(), sd, TRUE);
        }

        return TRUE;
    }
}

int ASSERT(string failure, string message="")
{
    int sd = NWNX_Test_GetStackDepth();

    if(failure == "")
    {
        NWNX_Test_IncLocal(GetModule(), gTestPassKey+IntToString(sd));
        return TRUE;
    }

    int asserts = NWNX_Test_IncLocal(GetModule(), gTestAssertKey+IntToString(sd));

    if (asserts > 1)
    {
        NWNX_Test_IncLocal(GetModule(), gTestSkipKey+IntToString(sd));
    }
    else
    {
        NWNX_Test_IncLocal(GetModule(), gTestFailKey+IntToString(sd));
        NWNX_Test_ReportFailure("Asserted " + failure, message, sd);
    }
    return FALSE;
}

int EXPECT(string failure, string message="")
{
    int sd = NWNX_Test_GetStackDepth();

    if (NWNX_Test_Skip(sd))
    {
        NWNX_Test_IncLocal(GetModule(), gTestSkipKey+IntToString(sd));
        return FALSE;
    }
    else if (failure == "")
    {
        NWNX_Test_IncLocal(GetModule(), gTestPassKey+IntToString(sd));
        return TRUE;
    }
    else
    {
        NWNX_Test_IncLocal(GetModule(), gTestFailKey+IntToString(sd));
        NWNX_Test_ReportFailure("Expected " + failure, message, sd);
        return FALSE;
    }
}

// Private function definitions
int NWNX_Test_IncLocal(object obj, string key, int by = 1)
{
    int i = GetLocalInt(obj, key) + by;
    SetLocalInt(obj, key, i);
    return i;
}

int NWNX_Test_DecLocal(object obj, string key, int by = 1)
{
    int i = GetLocalInt(obj, key) - by;
    SetLocalInt(obj, key, i);
    return i;
}

int NWNX_Test_GetStackDepth()
{
    return GetLocalInt(GetModule(), gTestStackDepthKey);
}

string NWNX_Test_GetTestName()
{
    int sd = GetLocalInt(GetModule(), gTestStackDepthKey);
    int i;
    string res = GetLocalString(GetModule(), gTestCaseKey+"1");

    for (i = 2; i <= sd; ++i)
    {
        res += "::" + GetLocalString(GetModule(), gTestCaseKey+IntToString(i));
    }
    return res;
}

int NWNX_Test_Skip(int nStackDepth)
{
    int i;
    int result = FALSE;

    for (i = nStackDepth; i > 0; --i)
    {
        result |= GetLocalInt(GetModule(), gTestAssertKey+IntToString(i));
    }

    return result;
}

