package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_SKELETON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeSkeleton {
  private AppearanceTypeSkeleton() {}

  public final static int CHIEFTAIN = 182;
  public final static int COMMON = 63;
  public final static int MAGE = 148;
  public final static int PRIEST = 62;
  public final static int WARRIOR = 150;
  public final static int WARRIOR_1 = 70;
  public final static int WARRIOR_2 = 71;

  public static String nameOf(int value) {
    if (value == 182) return "AppearanceTypeSkeleton.CHIEFTAIN";
    if (value == 63) return "AppearanceTypeSkeleton.COMMON";
    if (value == 148) return "AppearanceTypeSkeleton.MAGE";
    if (value == 62) return "AppearanceTypeSkeleton.PRIEST";
    if (value == 150) return "AppearanceTypeSkeleton.WARRIOR";
    if (value == 70) return "AppearanceTypeSkeleton.WARRIOR_1";
    if (value == 71) return "AppearanceTypeSkeleton.WARRIOR_2";
    return "AppearanceTypeSkeleton.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeSkeleton.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeSkeleton.(not found: " + value + ")";
  }
}
