#include "nwnx_feedback"

const int NWNX_FEEDBACK_REST_BEGINNING_REST             = 18;
const int NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE        = 3;

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Feedback: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Feedback: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Feedback unit test begin..");

    NWNX_Feedback_SetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, TRUE);
    report("{Set/Get}FeedbackMessageHidden (Global)", NWNX_Feedback_GetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST));

    NWNX_Feedback_SetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, TRUE);
    report("{Set/Get}CombatMessageHidden (Global)", NWNX_Feedback_GetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE));

    object oPC = GetFirstPC();

    if( GetIsObjectValid(oPC) )
    {
        NWNX_Feedback_SetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, TRUE, oPC);
        report("{Set/Get}FeedbackMessageHidden (Personal)", NWNX_Feedback_GetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, oPC));

        NWNX_Feedback_SetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, TRUE, oPC);
        report("{Set/Get}CombatMessageHidden (Personal)", NWNX_Feedback_GetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, oPC));
    }
    else
    {
        WriteTimestampedLogEntry("No valid PC found, skipping personal feedback state tests");
    }


    WriteTimestampedLogEntry("NWNX_Feedback unit test end.");
}
