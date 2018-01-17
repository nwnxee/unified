package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_DEATHLESS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatDeathless {
  private FeatDeathless() {}

  public final static int MASTERY = 896;
  public final static int MASTER_TOUCH = 897;
  public final static int VIGOR = 891;

  public static String nameOf(int value) {
    if (value == 896) return "FeatDeathless.MASTERY";
    if (value == 897) return "FeatDeathless.MASTER_TOUCH";
    if (value == 891) return "FeatDeathless.VIGOR";
    return "FeatDeathless.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatDeathless.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatDeathless.(not found: " + value + ")";
  }
}
