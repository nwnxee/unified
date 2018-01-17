package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ABILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Ability {
  private Ability() {}

  public final static int CHARISMA = 5;
  public final static int CONSTITUTION = 2;
  public final static int DEXTERITY = 1;
  public final static int INTELLIGENCE = 3;
  public final static int STRENGTH = 0;
  public final static int WISDOM = 4;

  public static String nameOf(int value) {
    if (value == 5) return "Ability.CHARISMA";
    if (value == 2) return "Ability.CONSTITUTION";
    if (value == 1) return "Ability.DEXTERITY";
    if (value == 3) return "Ability.INTELLIGENCE";
    if (value == 0) return "Ability.STRENGTH";
    if (value == 4) return "Ability.WISDOM";
    return "Ability.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Ability.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Ability.(not found: " + value + ")";
  }
}
