namespace NWN
{
    public static partial class Internal
    {
        public delegate void ManagedAssignCommandDelegate(uint obj, ActionDelegate func);

        public delegate void ManagedDelayCommandDelegate(uint obj, float duration, ActionDelegate func);

        public delegate void ManagedActionCommandDelegate(uint obj, ActionDelegate func);

        public struct ManagedHandles
        {
            public ManagedAssignCommandDelegate ClosureAssignCommand;
            public ManagedDelayCommandDelegate ClosureDelayCommand;
            public ManagedActionCommandDelegate ClosureActionDoCommand;
        }
    }
}
