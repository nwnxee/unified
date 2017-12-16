package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_STINGER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeStinger {
  private AppearanceTypeStinger() {}

  public final static int APPEARANCE_TYPE_STINGER = 356;
  public final static int CHIEFTAIN = 358;
  public final static int MAGE = 359;
  public final static int WARRIOR = 357;

  public static String nameOf(int value) {
    if (value == 356) return "AppearanceTypeStinger.APPEARANCE_TYPE_STINGER";
    if (value == 358) return "AppearanceTypeStinger.CHIEFTAIN";
    if (value == 359) return "AppearanceTypeStinger.MAGE";
    if (value == 357) return "AppearanceTypeStinger.WARRIOR";
    return "AppearanceTypeStinger.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeStinger.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeStinger.(not found: " + value + ")";
  }
}
