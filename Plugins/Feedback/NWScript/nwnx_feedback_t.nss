#include "nwnx_feedback"
#include "nwnx_tests"

const int NWNX_FEEDBACK_REST_BEGINNING_REST             = 18;
const int NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE        = 3;

void main()
{
    WriteTimestampedLogEntry("NWNX_Feedback unit test begin..");

    NWNX_Feedback_SetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, TRUE);
    NWNX_Tests_Report("NWNX_Feedback", "{Set/Get}FeedbackMessageHidden (Global)", NWNX_Feedback_GetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST));

    NWNX_Feedback_SetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, TRUE);
    NWNX_Tests_Report("NWNX_Feedback", "{Set/Get}CombatMessageHidden (Global)", NWNX_Feedback_GetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE));

    object oPC = GetFirstPC();

    if( GetIsObjectValid(oPC) )
    {
        NWNX_Feedback_SetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, TRUE, oPC);
        NWNX_Tests_Report("NWNX_Feedback", "{Set/Get}FeedbackMessageHidden (Personal)", NWNX_Feedback_GetFeedbackMessageHidden(NWNX_FEEDBACK_REST_BEGINNING_REST, oPC));

        NWNX_Feedback_SetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, TRUE, oPC);
        NWNX_Tests_Report("NWNX_Feedback", "{Set/Get}CombatMessageHidden (Personal)", NWNX_Feedback_GetCombatLogMessageHidden(NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE, oPC));
    }
    else
    {
        WriteTimestampedLogEntry("No valid PC found, skipping personal feedback state tests");
    }


    WriteTimestampedLogEntry("NWNX_Feedback unit test end.");
}
