using System;

namespace NWNX
{
  [AttributeUsage(AttributeTargets.Class)]
  public class NWNXPluginAttribute : Attribute
  {
    public readonly string PluginName;

    public NWNXPluginAttribute(string pluginName)
    {
      PluginName = pluginName;
    }
  }
}
