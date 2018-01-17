package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "RACIAL_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class RacialType {
  private RacialType() {}

  public final static int ABERRATION = 7;
  public final static int ALL = 28;
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
  public final static int INVALID = 28;
  public final static int MAGICAL_BEAST = 19;
  public final static int OOZE = 29;
  public final static int OUTSIDER = 20;
  public final static int SHAPECHANGER = 23;
  public final static int UNDEAD = 24;
  public final static int VERMIN = 25;

  public static String nameOf(int value) {
    if (value == 7) return "RacialType.ABERRATION";
    if (value == 28) return "RacialType.ALL";
    if (value == 8) return "RacialType.ANIMAL";
    if (value == 9) return "RacialType.BEAST";
    if (value == 10) return "RacialType.CONSTRUCT";
    if (value == 11) return "RacialType.DRAGON";
    if (value == 0) return "RacialType.DWARF";
    if (value == 16) return "RacialType.ELEMENTAL";
    if (value == 1) return "RacialType.ELF";
    if (value == 17) return "RacialType.FEY";
    if (value == 18) return "RacialType.GIANT";
    if (value == 2) return "RacialType.GNOME";
    if (value == 4) return "RacialType.HALFELF";
    if (value == 3) return "RacialType.HALFLING";
    if (value == 5) return "RacialType.HALFORC";
    if (value == 6) return "RacialType.HUMAN";
    if (value == 12) return "RacialType.HUMANOID_GOBLINOID";
    if (value == 13) return "RacialType.HUMANOID_MONSTROUS";
    if (value == 14) return "RacialType.HUMANOID_ORC";
    if (value == 15) return "RacialType.HUMANOID_REPTILIAN";
    if (value == 28) return "RacialType.INVALID";
    if (value == 19) return "RacialType.MAGICAL_BEAST";
    if (value == 29) return "RacialType.OOZE";
    if (value == 20) return "RacialType.OUTSIDER";
    if (value == 23) return "RacialType.SHAPECHANGER";
    if (value == 24) return "RacialType.UNDEAD";
    if (value == 25) return "RacialType.VERMIN";
    return "RacialType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "RacialType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "RacialType.(not found: " + value + ")";
  }
}
