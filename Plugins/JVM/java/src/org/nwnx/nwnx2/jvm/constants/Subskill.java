package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SUBSKILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Subskill {
  private Subskill() {}

  public final static int EXAMINETRAP = 102;
  public final static int FLAGTRAP = 100;
  public final static int RECOVERTRAP = 101;

  public static String nameOf(int value) {
    if (value == 102) return "Subskill.EXAMINETRAP";
    if (value == 100) return "Subskill.FLAGTRAP";
    if (value == 101) return "Subskill.RECOVERTRAP";
    return "Subskill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Subskill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Subskill.(not found: " + value + ")";
  }
}
