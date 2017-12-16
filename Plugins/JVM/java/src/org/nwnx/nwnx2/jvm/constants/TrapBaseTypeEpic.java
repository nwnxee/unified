package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE_EPIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseTypeEpic {
  private TrapBaseTypeEpic() {}

  public final static int ELECTRICAL = 44;
  public final static int FIRE = 45;
  public final static int FROST = 46;
  public final static int SONIC = 47;

  public static String nameOf(int value) {
    if (value == 44) return "TrapBaseTypeEpic.ELECTRICAL";
    if (value == 45) return "TrapBaseTypeEpic.FIRE";
    if (value == 46) return "TrapBaseTypeEpic.FROST";
    if (value == 47) return "TrapBaseTypeEpic.SONIC";
    return "TrapBaseTypeEpic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseTypeEpic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseTypeEpic.(not found: " + value + ")";
  }
}
