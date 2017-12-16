package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_RACIALTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstRacialtype {
  private IpConstRacialtype() {}

  public final static int ABERRATION = 7;
  public final static int ANIMAL = 8;
  public final static int BEAST = 9;
  public final static int CONSTRUCT = 10;
  public final static int DRAGON = 11;
  public final static int DWARF = 0;
  public final static int ELEMENTAL = 16;
  public final static int ELF = 1;
  public final static int FEY = 17;
  public final static int GIANT = 18;
  public final static int GNOME = 2;
  public final static int HALFELF = 4;
  public final static int HALFLING = 3;
  public final static int HALFORC = 5;
  public final static int HUMAN = 6;
  public final static int HUMANOID_GOBLINOID = 12;
  public final static int HUMANOID_MONSTROUS = 13;
  public final static int HUMANOID_ORC = 14;
  public final static int HUMANOID_REPTILIAN = 15;
  public final static int MAGICAL_BEAST = 19;
  public final static int OUTSIDER = 20;
  public final static int SHAPECHANGER = 23;
  public final static int UNDEAD = 24;
  public final static int VERMIN = 25;

  public static String nameOf(int value) {
    if (value == 7) return "IpConstRacialtype.ABERRATION";
    if (value == 8) return "IpConstRacialtype.ANIMAL";
    if (value == 9) return "IpConstRacialtype.BEAST";
    if (value == 10) return "IpConstRacialtype.CONSTRUCT";
    if (value == 11) return "IpConstRacialtype.DRAGON";
    if (value == 0) return "IpConstRacialtype.DWARF";
    if (value == 16) return "IpConstRacialtype.ELEMENTAL";
    if (value == 1) return "IpConstRacialtype.ELF";
    if (value == 17) return "IpConstRacialtype.FEY";
    if (value == 18) return "IpConstRacialtype.GIANT";
    if (value == 2) return "IpConstRacialtype.GNOME";
    if (value == 4) return "IpConstRacialtype.HALFELF";
    if (value == 3) return "IpConstRacialtype.HALFLING";
    if (value == 5) return "IpConstRacialtype.HALFORC";
    if (value == 6) return "IpConstRacialtype.HUMAN";
    if (value == 12) return "IpConstRacialtype.HUMANOID_GOBLINOID";
    if (value == 13) return "IpConstRacialtype.HUMANOID_MONSTROUS";
    if (value == 14) return "IpConstRacialtype.HUMANOID_ORC";
    if (value == 15) return "IpConstRacialtype.HUMANOID_REPTILIAN";
    if (value == 19) return "IpConstRacialtype.MAGICAL_BEAST";
    if (value == 20) return "IpConstRacialtype.OUTSIDER";
    if (value == 23) return "IpConstRacialtype.SHAPECHANGER";
    if (value == 24) return "IpConstRacialtype.UNDEAD";
    if (value == 25) return "IpConstRacialtype.VERMIN";
    return "IpConstRacialtype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstRacialtype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstRacialtype.(not found: " + value + ")";
  }
}
