#include "nwnx"

// Returns the last reply type as a int:
// 1: array
// 2: bulk_string
// 3: error
// 4: integer
// 5: simple_string
// 6: null
// 0: unknown/none
int NWNX_Redis_GetLastReplyType();

// Returns the length of the last LIST result. Note that this will
// be overwritten by any command that returns a list, so nested iteration
// is not currently supported.
// Returns 0 if the last command wasn't a list type.
int NWNX_Redis_GetLastReplyArrayLength();

// Returns a list entry as a string.
// Will return "" if the last command did not result in a list, or if
// the requested index is out of bounds.
string NWNX_Redis_GetLastReplyArrayElement(int idx);

int NWNX_Redis_GetLastReplyType()
{
    NWNX_CallFunction("NWNX_Redis", "GetLastReplyType");
    return NWNX_GetReturnValueInt("NWNX_Redis", "GetLastReplyType");
}

int NWNX_Redis_GetLastReplyArrayLength()
{
    NWNX_CallFunction("NWNX_Redis", "GetLastReplyArrayLength");
    return NWNX_GetReturnValueInt("NWNX_Redis", "GetLastReplyArrayLength");
}

// Returns the last
string NWNX_Redis_GetLastReplyArrayElement(int idx)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetLastReplyArrayElement", idx);
    NWNX_CallFunction("NWNX_Redis", "GetLastReplyArrayElement");
    return NWNX_GetReturnValueString("NWNX_Redis", "GetLastReplyArrayElement");
}
