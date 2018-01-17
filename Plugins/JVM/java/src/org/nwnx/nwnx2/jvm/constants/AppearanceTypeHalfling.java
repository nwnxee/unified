package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_HALFLING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeHalfling {
  private AppearanceTypeHalfling() {}

  public final static int APPEARANCE_TYPE_HALFLING = 3;
  public final static int NPC_FEMALE = 250;
  public final static int NPC_MALE = 251;

  public static String nameOf(int value) {
    if (value == 3) return "AppearanceTypeHalfling.APPEARANCE_TYPE_HALFLING";
    if (value == 250) return "AppearanceTypeHalfling.NPC_FEMALE";
    if (value == 251) return "AppearanceTypeHalfling.NPC_MALE";
    return "AppearanceTypeHalfling.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeHalfling.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeHalfling.(not found: " + value + ")";
  }
}
