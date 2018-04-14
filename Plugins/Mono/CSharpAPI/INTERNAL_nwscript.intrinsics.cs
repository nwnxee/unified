namespace NWN
{
    partial class NWScript
    {
        public static void AssignCommand(NWN.Object oActionSubject, ActionDelegate aActionToAssign)
        {
            Internal.ClosureAssignCommand(oActionSubject, aActionToAssign);
        }

        public static void DelayCommand(float fSeconds, ActionDelegate aActionToDelay)
        {
            Internal.ClosureDelayCommand(Object.OBJECT_SELF, fSeconds, aActionToDelay);
        }

        public static void ActionDoCommand(ActionDelegate aActionToDelay)
        {
            Internal.ClosureActionDoCommand(Object.OBJECT_SELF, aActionToDelay);
        }
    }
}
