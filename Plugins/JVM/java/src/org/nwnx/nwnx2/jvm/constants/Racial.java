package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "RACIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Racial {
  private Racial() {}

  public final static int TYPE_ABERRATION = 7;
  public final static int TYPE_ALL = 28;
  public final static int TYPE_ANIMAL = 8;
  public final static int TYPE_BEAST = 9;
  public final static int TYPE_CONSTRUCT = 10;
  public final static int TYPE_DRAGON = 11;
  public final static int TYPE_DWARF = 0;
  public final static int TYPE_ELEMENTAL = 16;
  public final static int TYPE_ELF = 1;
  public final static int TYPE_FEY = 17;
  public final static int TYPE_GIANT = 18;
  public final static int TYPE_GNOME = 2;
  public final static int TYPE_HALFELF = 4;
  public final static int TYPE_HALFLING = 3;
  public final static int TYPE_HALFORC = 5;
  public final static int TYPE_HUMAN = 6;
  public final static int TYPE_HUMANOID_GOBLINOID = 12;
  public final static int TYPE_HUMANOID_MONSTROUS = 13;
  public final static int TYPE_HUMANOID_ORC = 14;
  public final static int TYPE_HUMANOID_REPTILIAN = 15;
  public final static int TYPE_INVALID = 28;
  public final static int TYPE_MAGICAL_BEAST = 19;
  public final static int TYPE_OOZE = 29;
  public final static int TYPE_OUTSIDER = 20;
  public final static int TYPE_SHAPECHANGER = 23;
  public final static int TYPE_UNDEAD = 24;
  public final static int TYPE_VERMIN = 25;

  public static String nameOf(int value) {
    if (value == 7) return "Racial.TYPE_ABERRATION";
    if (value == 28) return "Racial.TYPE_ALL";
    if (value == 8) return "Racial.TYPE_ANIMAL";
    if (value == 9) return "Racial.TYPE_BEAST";
    if (value == 10) return "Racial.TYPE_CONSTRUCT";
    if (value == 11) return "Racial.TYPE_DRAGON";
    if (value == 0) return "Racial.TYPE_DWARF";
    if (value == 16) return "Racial.TYPE_ELEMENTAL";
    if (value == 1) return "Racial.TYPE_ELF";
    if (value == 17) return "Racial.TYPE_FEY";
    if (value == 18) return "Racial.TYPE_GIANT";
    if (value == 2) return "Racial.TYPE_GNOME";
    if (value == 4) return "Racial.TYPE_HALFELF";
    if (value == 3) return "Racial.TYPE_HALFLING";
    if (value == 5) return "Racial.TYPE_HALFORC";
    if (value == 6) return "Racial.TYPE_HUMAN";
    if (value == 12) return "Racial.TYPE_HUMANOID_GOBLINOID";
    if (value == 13) return "Racial.TYPE_HUMANOID_MONSTROUS";
    if (value == 14) return "Racial.TYPE_HUMANOID_ORC";
    if (value == 15) return "Racial.TYPE_HUMANOID_REPTILIAN";
    if (value == 28) return "Racial.TYPE_INVALID";
    if (value == 19) return "Racial.TYPE_MAGICAL_BEAST";
    if (value == 29) return "Racial.TYPE_OOZE";
    if (value == 20) return "Racial.TYPE_OUTSIDER";
    if (value == 23) return "Racial.TYPE_SHAPECHANGER";
    if (value == 24) return "Racial.TYPE_UNDEAD";
    if (value == 25) return "Racial.TYPE_VERMIN";
    return "Racial.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Racial.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Racial.(not found: " + value + ")";
  }
}
