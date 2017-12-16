package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "STANDARD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Standard {
  private Standard() {}

  public final static int FACTION_COMMONER = 1;
  public final static int FACTION_DEFENDER = 3;
  public final static int FACTION_HOSTILE = 0;
  public final static int FACTION_MERCHANT = 2;

  public static String nameOf(int value) {
    if (value == 1) return "Standard.FACTION_COMMONER";
    if (value == 3) return "Standard.FACTION_DEFENDER";
    if (value == 0) return "Standard.FACTION_HOSTILE";
    if (value == 2) return "Standard.FACTION_MERCHANT";
    return "Standard.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Standard.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Standard.(not found: " + value + ")";
  }
}
