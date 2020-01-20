/// @addtogroup ruby Ruby
/// @brief Allows users to execute arbitrary Ruby from the game.
/// @{
/// @file nwnx_ruby.nss
#include "nwnx"

const string NWNX_Ruby = "NWNX_Ruby"; ///< @private

string NWNX_Ruby_Evaluate (string sCode);

/// @brief Evaluates some ruby code.
/// @param sCode The code to evaluate.
/// @return The output of the call.
string NWNX_Ruby_Evaluate(string sCode)
{
    string sFunc = "Evaluate";

    NWNX_PushArgumentString (NWNX_Ruby, sFunc, sCode);
    NWNX_CallFunction (NWNX_Ruby, sFunc);
    return NWNX_GetReturnValueString (NWNX_Ruby, sFunc);
}

/// @}
