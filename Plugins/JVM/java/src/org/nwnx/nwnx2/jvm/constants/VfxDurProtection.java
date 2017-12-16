package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_PROTECTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurProtection {
  private VfxDurProtection() {}

  public final static int ELEMENTS = 224;
  public final static int EVIL_MAJOR = 228;
  public final static int EVIL_MINOR = 227;
  public final static int GOOD_MAJOR = 226;
  public final static int GOOD_MINOR = 225;

  public static String nameOf(int value) {
    if (value == 224) return "VfxDurProtection.ELEMENTS";
    if (value == 228) return "VfxDurProtection.EVIL_MAJOR";
    if (value == 227) return "VfxDurProtection.EVIL_MINOR";
    if (value == 226) return "VfxDurProtection.GOOD_MAJOR";
    if (value == 225) return "VfxDurProtection.GOOD_MINOR";
    return "VfxDurProtection.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurProtection.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurProtection.(not found: " + value + ")";
  }
}
