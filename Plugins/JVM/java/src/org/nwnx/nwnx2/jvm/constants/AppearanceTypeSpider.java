package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_SPIDER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeSpider {
  private AppearanceTypeSpider() {}

  public final static int DEMON = 422;
  public final static int DIRE = 158;
  public final static int GIANT = 159;
  public final static int PHASE = 160;
  public final static int SWORD = 161;
  public final static int WRAITH = 162;

  public static String nameOf(int value) {
    if (value == 422) return "AppearanceTypeSpider.DEMON";
    if (value == 158) return "AppearanceTypeSpider.DIRE";
    if (value == 159) return "AppearanceTypeSpider.GIANT";
    if (value == 160) return "AppearanceTypeSpider.PHASE";
    if (value == 161) return "AppearanceTypeSpider.SWORD";
    if (value == 162) return "AppearanceTypeSpider.WRAITH";
    return "AppearanceTypeSpider.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeSpider.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeSpider.(not found: " + value + ")";
  }
}
