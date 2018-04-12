namespace NWN
{
    partial class NWScript
    {
        public static void AssignCommand(NWN.Object oActionSubject, ActionDelegate aActionToAssign)
        {
            Internal.Closure closure = new Internal.Closure
            {
                m_Object = oActionSubject,
                m_Func = aActionToAssign
            };

            Internal.EnqueueClosure(closure);
        }

        public static void DelayCommand(float fSeconds, ActionDelegate aActionToDelay)
        {
            Internal.Closure closure = new Internal.Closure
            {
                m_Delay = fSeconds,
                m_Func = aActionToDelay,
                m_Object = Object.OBJECT_SELF
            };

            Internal.EnqueueClosure(closure);
        }
    }
}
