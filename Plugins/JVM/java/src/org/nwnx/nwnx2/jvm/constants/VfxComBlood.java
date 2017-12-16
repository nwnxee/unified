package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_BLOOD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComBlood {
  private VfxComBlood() {}

  public final static int CRT_GREEN = 116 ;
  public final static int CRT_RED = 115 ;
  public final static int CRT_WIMP = 108 ;
  public final static int CRT_YELLOW = 117 ;
  public final static int LRG_GREEN = 113 ;
  public final static int LRG_RED = 112 ;
  public final static int LRG_WIMP = 107 ;
  public final static int LRG_YELLOW = 114 ;
  public final static int REG_GREEN = 110 ;
  public final static int REG_RED = 109 ;
  public final static int REG_WIMP = 106 ;
  public final static int REG_YELLOW = 111 ;
  public final static int SPARK_LARGE = 239;
  public final static int SPARK_MEDIUM = 238;
  public final static int SPARK_SMALL = 237;

  public static String nameOf(int value) {
    if (value == 116 ) return "VfxComBlood.CRT_GREEN";
    if (value == 115 ) return "VfxComBlood.CRT_RED";
    if (value == 108 ) return "VfxComBlood.CRT_WIMP";
    if (value == 117 ) return "VfxComBlood.CRT_YELLOW";
    if (value == 113 ) return "VfxComBlood.LRG_GREEN";
    if (value == 112 ) return "VfxComBlood.LRG_RED";
    if (value == 107 ) return "VfxComBlood.LRG_WIMP";
    if (value == 114 ) return "VfxComBlood.LRG_YELLOW";
    if (value == 110 ) return "VfxComBlood.REG_GREEN";
    if (value == 109 ) return "VfxComBlood.REG_RED";
    if (value == 106 ) return "VfxComBlood.REG_WIMP";
    if (value == 111 ) return "VfxComBlood.REG_YELLOW";
    if (value == 239) return "VfxComBlood.SPARK_LARGE";
    if (value == 238) return "VfxComBlood.SPARK_MEDIUM";
    if (value == 237) return "VfxComBlood.SPARK_SMALL";
    return "VfxComBlood.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComBlood.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComBlood.(not found: " + value + ")";
  }
}
