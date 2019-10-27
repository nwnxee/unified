/// @ingroup nwnx
/// @addtogroup tests NWNX Tests
/// @brief Helper functions when running the test scripts
/// @{
/// @file nwnx_tests.nss

void NWNX_Tests_Report(string sPlugin, string sTestName, int bSuccess);

void NWNX_Tests_Report(string sPlugin, string sTestName, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry(sPlugin + ": " + sTestName + "() success");
    else
        WriteTimestampedLogEntry(sPlugin + ": " + sTestName + "() failed");
}

/// @} // End of tests
