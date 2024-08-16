using System;

namespace NWN
{
  public partial class Effect
  {
    public IntPtr Handle;
    public Effect(IntPtr handle) => Handle = handle;
    ~Effect() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_EFFECT, Handle); }

    public static implicit operator IntPtr(Effect effect) => effect.Handle;
    public static implicit operator Effect(IntPtr intPtr) => new Effect(intPtr);
  }

  public partial class Event
  {
    public IntPtr Handle;
    public Event(IntPtr handle) => Handle = handle;
    ~Event() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_EVENT, Handle); }

    public static implicit operator IntPtr(Event effect) => effect.Handle;
    public static implicit operator Event(IntPtr intPtr) => new Event(intPtr);
  }

  public partial class Location
  {
    public IntPtr Handle;
    public Location(IntPtr handle) => Handle = handle;
    ~Location() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_LOCATION, Handle); }

    public static implicit operator IntPtr(Location effect) => effect.Handle;
    public static implicit operator Location(IntPtr intPtr) => new Location(intPtr);
  }

  public partial class Talent
  {
    public IntPtr Handle;
    public Talent(IntPtr handle) => Handle = handle;
    ~Talent() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_TALENT, Handle); }

    public static implicit operator IntPtr(Talent effect) => effect.Handle;
    public static implicit operator Talent(IntPtr intPtr) => new Talent(intPtr);
  }

  public partial class ItemProperty
  {
    public IntPtr Handle;
    public ItemProperty(IntPtr handle) => Handle = handle;
    ~ItemProperty() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_ITEM_PROPERTY, Handle); }

    public static implicit operator IntPtr(ItemProperty effect) => effect.Handle;
    public static implicit operator ItemProperty(IntPtr intPtr) => new ItemProperty(intPtr);
  }

  public partial class SQLQuery
  {
    public IntPtr Handle;
    public SQLQuery(IntPtr handle) => Handle = handle;
    ~SQLQuery() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_SQL_QUERY, Handle); }

    public static implicit operator IntPtr(SQLQuery effect) => effect.Handle;
    public static implicit operator SQLQuery(IntPtr intPtr) => new SQLQuery(intPtr);
  }

  public delegate void ActionDelegate();
}
