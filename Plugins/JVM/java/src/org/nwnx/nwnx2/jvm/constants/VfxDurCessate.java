package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_CESSATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurCessate {
  private VfxDurCessate() {}

  public final static int NEGATIVE = 207;
  public final static int NEUTRAL = 205;
  public final static int POSITIVE = 206;

  public static String nameOf(int value) {
    if (value == 207) return "VfxDurCessate.NEGATIVE";
    if (value == 205) return "VfxDurCessate.NEUTRAL";
    if (value == 206) return "VfxDurCessate.POSITIVE";
    return "VfxDurCessate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurCessate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurCessate.(not found: " + value + ")";
  }
}
