package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_SHARK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeShark {
  private AppearanceTypeShark() {}

  public final static int GOBLIN = 449;
  public final static int HAMMERHEAD = 448;
  public final static int MAKO = 447;

  public static String nameOf(int value) {
    if (value == 449) return "AppearanceTypeShark.GOBLIN";
    if (value == 448) return "AppearanceTypeShark.HAMMERHEAD";
    if (value == 447) return "AppearanceTypeShark.MAKO";
    return "AppearanceTypeShark.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeShark.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeShark.(not found: " + value + ")";
  }
}
