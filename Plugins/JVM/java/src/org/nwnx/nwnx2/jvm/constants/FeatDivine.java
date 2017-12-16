package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_DIVINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatDivine {
  private FeatDivine() {}

  public final static int GRACE = 217;
  public final static int HEALTH = 219;
  public final static int MIGHT = 413;
  public final static int SHIELD = 414;
  public final static int WRATH = 909;

  public static String nameOf(int value) {
    if (value == 217) return "FeatDivine.GRACE";
    if (value == 219) return "FeatDivine.HEALTH";
    if (value == 413) return "FeatDivine.MIGHT";
    if (value == 414) return "FeatDivine.SHIELD";
    if (value == 909) return "FeatDivine.WRATH";
    return "FeatDivine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatDivine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatDivine.(not found: " + value + ")";
  }
}
