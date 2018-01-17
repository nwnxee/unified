package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "STANDARD_FACTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class StandardFaction {
  private StandardFaction() {}

  public final static int COMMONER = 1;
  public final static int DEFENDER = 3;
  public final static int HOSTILE = 0;
  public final static int MERCHANT = 2;

  public static String nameOf(int value) {
    if (value == 1) return "StandardFaction.COMMONER";
    if (value == 3) return "StandardFaction.DEFENDER";
    if (value == 0) return "StandardFaction.HOSTILE";
    if (value == 2) return "StandardFaction.MERCHANT";
    return "StandardFaction.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "StandardFaction.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "StandardFaction.(not found: " + value + ")";
  }
}
