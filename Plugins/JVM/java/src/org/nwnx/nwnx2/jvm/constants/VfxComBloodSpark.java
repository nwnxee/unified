package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_BLOOD_SPARK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComBloodSpark {
  private VfxComBloodSpark() {}

  public final static int LARGE = 239;
  public final static int MEDIUM = 238;
  public final static int SMALL = 237;

  public static String nameOf(int value) {
    if (value == 239) return "VfxComBloodSpark.LARGE";
    if (value == 238) return "VfxComBloodSpark.MEDIUM";
    if (value == 237) return "VfxComBloodSpark.SMALL";
    return "VfxComBloodSpark.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComBloodSpark.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComBloodSpark.(not found: " + value + ")";
  }
}
