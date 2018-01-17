package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_LOS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfLos {
  private VfxFnfLos() {}

  public final static int EVIL_10 = 185;
  public final static int EVIL_20 = 186;
  public final static int EVIL_30 = 187;
  public final static int HOLY_10 = 188;
  public final static int HOLY_20 = 189;
  public final static int HOLY_30 = 190;
  public final static int NORMAL_10 = 191;
  public final static int NORMAL_20 = 192;
  public final static int NORMAL_30 = 193;

  public static String nameOf(int value) {
    if (value == 185) return "VfxFnfLos.EVIL_10";
    if (value == 186) return "VfxFnfLos.EVIL_20";
    if (value == 187) return "VfxFnfLos.EVIL_30";
    if (value == 188) return "VfxFnfLos.HOLY_10";
    if (value == 189) return "VfxFnfLos.HOLY_20";
    if (value == 190) return "VfxFnfLos.HOLY_30";
    if (value == 191) return "VfxFnfLos.NORMAL_10";
    if (value == 192) return "VfxFnfLos.NORMAL_20";
    if (value == 193) return "VfxFnfLos.NORMAL_30";
    return "VfxFnfLos.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfLos.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfLos.(not found: " + value + ")";
  }
}
