package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_MIND_AFFECTING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurMindAffecting {
  private VfxDurMindAffecting() {}

  public final static int DISABLED = 208;
  public final static int DOMINATED = 209;
  public final static int FEAR = 218;
  public final static int NEGATIVE = 7;
  public final static int POSITIVE = 8;

  public static String nameOf(int value) {
    if (value == 208) return "VfxDurMindAffecting.DISABLED";
    if (value == 209) return "VfxDurMindAffecting.DOMINATED";
    if (value == 218) return "VfxDurMindAffecting.FEAR";
    if (value == 7) return "VfxDurMindAffecting.NEGATIVE";
    if (value == 8) return "VfxDurMindAffecting.POSITIVE";
    return "VfxDurMindAffecting.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurMindAffecting.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurMindAffecting.(not found: " + value + ")";
  }
}
