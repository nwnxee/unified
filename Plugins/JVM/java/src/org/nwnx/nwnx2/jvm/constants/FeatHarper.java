package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_HARPER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatHarper {
  private FeatHarper() {}

  public final static int CATS_GRACE = 442;
  public final static int EAGLES_SPLENDOR = 443;
  public final static int INVISIBILITY = 444;
  public final static int SLEEP = 441;

  public static String nameOf(int value) {
    if (value == 442) return "FeatHarper.CATS_GRACE";
    if (value == 443) return "FeatHarper.EAGLES_SPLENDOR";
    if (value == 444) return "FeatHarper.INVISIBILITY";
    if (value == 441) return "FeatHarper.SLEEP";
    return "FeatHarper.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatHarper.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatHarper.(not found: " + value + ")";
  }
}
