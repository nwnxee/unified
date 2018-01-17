package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_HOWL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfHowl {
  private VfxFnfHowl() {}

  public final static int MIND = 278;
  public final static int ODD = 279;
  public final static int WAR_CRY = 285;
  public final static int WAR_CRY_FEMALE = 290;

  public static String nameOf(int value) {
    if (value == 278) return "VfxFnfHowl.MIND";
    if (value == 279) return "VfxFnfHowl.ODD";
    if (value == 285) return "VfxFnfHowl.WAR_CRY";
    if (value == 290) return "VfxFnfHowl.WAR_CRY_FEMALE";
    return "VfxFnfHowl.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfHowl.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfHowl.(not found: " + value + ")";
  }
}
