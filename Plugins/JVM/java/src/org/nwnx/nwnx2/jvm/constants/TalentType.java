package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentType {
  private TalentType() {}

  public final static int FEAT = 1;
  public final static int SKILL = 2;
  public final static int SPELL = 0;

  public static String nameOf(int value) {
    if (value == 1) return "TalentType.FEAT";
    if (value == 2) return "TalentType.SKILL";
    if (value == 0) return "TalentType.SPELL";
    return "TalentType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentType.(not found: " + value + ")";
  }
}
