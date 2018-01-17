package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_KI".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatKi {
  private FeatKi() {}

  public final static int CRITICAL = 885;
  public final static int DAMAGE = 882;
  public final static int STRIKE = 213;

  public static String nameOf(int value) {
    if (value == 885) return "FeatKi.CRITICAL";
    if (value == 882) return "FeatKi.DAMAGE";
    if (value == 213) return "FeatKi.STRIKE";
    return "FeatKi.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatKi.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatKi.(not found: " + value + ")";
  }
}
