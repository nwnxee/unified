package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_MIND".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurMind {
  private VfxDurMind() {}

  public final static int AFFECTING_DISABLED = 208;
  public final static int AFFECTING_DOMINATED = 209;
  public final static int AFFECTING_FEAR = 218;
  public final static int AFFECTING_NEGATIVE = 7;
  public final static int AFFECTING_POSITIVE = 8;

  public static String nameOf(int value) {
    if (value == 208) return "VfxDurMind.AFFECTING_DISABLED";
    if (value == 209) return "VfxDurMind.AFFECTING_DOMINATED";
    if (value == 218) return "VfxDurMind.AFFECTING_FEAR";
    if (value == 7) return "VfxDurMind.AFFECTING_NEGATIVE";
    if (value == 8) return "VfxDurMind.AFFECTING_POSITIVE";
    return "VfxDurMind.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurMind.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurMind.(not found: " + value + ")";
  }
}
