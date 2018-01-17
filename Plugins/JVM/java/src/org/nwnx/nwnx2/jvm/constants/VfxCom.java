package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxCom {
  private VfxCom() {}

  public final static int BLOOD_CRT_GREEN = 116 ;
  public final static int BLOOD_CRT_RED = 115 ;
  public final static int BLOOD_CRT_WIMP = 108 ;
  public final static int BLOOD_CRT_YELLOW = 117 ;
  public final static int BLOOD_LRG_GREEN = 113 ;
  public final static int BLOOD_LRG_RED = 112 ;
  public final static int BLOOD_LRG_WIMP = 107 ;
  public final static int BLOOD_LRG_YELLOW = 114 ;
  public final static int BLOOD_REG_GREEN = 110 ;
  public final static int BLOOD_REG_RED = 109 ;
  public final static int BLOOD_REG_WIMP = 106 ;
  public final static int BLOOD_REG_YELLOW = 111 ;
  public final static int BLOOD_SPARK_LARGE = 239;
  public final static int BLOOD_SPARK_MEDIUM = 238;
  public final static int BLOOD_SPARK_SMALL = 237;
  public final static int CHUNK_BONE_MEDIUM = 236;
  public final static int CHUNK_GREEN_MEDIUM = 124 ;
  public final static int CHUNK_GREEN_SMALL = 123 ;
  public final static int CHUNK_RED_BALLISTA = 504;
  public final static int CHUNK_RED_LARGE = 235;
  public final static int CHUNK_RED_MEDIUM = 122 ;
  public final static int CHUNK_RED_SMALL = 121 ;
  public final static int CHUNK_STONE_MEDIUM = 354;
  public final static int CHUNK_STONE_SMALL = 353;
  public final static int CHUNK_YELLOW_MEDIUM = 126 ;
  public final static int CHUNK_YELLOW_SMALL = 125 ;
  public final static int HIT_ACID = 283;
  public final static int HIT_DIVINE = 289;
  public final static int HIT_ELECTRICAL = 282;
  public final static int HIT_FIRE = 280;
  public final static int HIT_FROST = 281;
  public final static int HIT_NEGATIVE = 288;
  public final static int HIT_SONIC = 284;
  public final static int SPARKS_PARRY = 118 ;
  public final static int SPECIAL_BLUE_RED = 100 ;
  public final static int SPECIAL_PINK_ORANGE = 101 ;
  public final static int SPECIAL_RED_ORANGE = 103 ;
  public final static int SPECIAL_RED_WHITE = 102 ;
  public final static int SPECIAL_WHITE_BLUE = 104 ;
  public final static int SPECIAL_WHITE_ORANGE = 105 ;
  public final static int UNLOAD_MODEL = 120 ;

  public static String nameOf(int value) {
    if (value == 116 ) return "VfxCom.BLOOD_CRT_GREEN";
    if (value == 115 ) return "VfxCom.BLOOD_CRT_RED";
    if (value == 108 ) return "VfxCom.BLOOD_CRT_WIMP";
    if (value == 117 ) return "VfxCom.BLOOD_CRT_YELLOW";
    if (value == 113 ) return "VfxCom.BLOOD_LRG_GREEN";
    if (value == 112 ) return "VfxCom.BLOOD_LRG_RED";
    if (value == 107 ) return "VfxCom.BLOOD_LRG_WIMP";
    if (value == 114 ) return "VfxCom.BLOOD_LRG_YELLOW";
    if (value == 110 ) return "VfxCom.BLOOD_REG_GREEN";
    if (value == 109 ) return "VfxCom.BLOOD_REG_RED";
    if (value == 106 ) return "VfxCom.BLOOD_REG_WIMP";
    if (value == 111 ) return "VfxCom.BLOOD_REG_YELLOW";
    if (value == 239) return "VfxCom.BLOOD_SPARK_LARGE";
    if (value == 238) return "VfxCom.BLOOD_SPARK_MEDIUM";
    if (value == 237) return "VfxCom.BLOOD_SPARK_SMALL";
    if (value == 236) return "VfxCom.CHUNK_BONE_MEDIUM";
    if (value == 124 ) return "VfxCom.CHUNK_GREEN_MEDIUM";
    if (value == 123 ) return "VfxCom.CHUNK_GREEN_SMALL";
    if (value == 504) return "VfxCom.CHUNK_RED_BALLISTA";
    if (value == 235) return "VfxCom.CHUNK_RED_LARGE";
    if (value == 122 ) return "VfxCom.CHUNK_RED_MEDIUM";
    if (value == 121 ) return "VfxCom.CHUNK_RED_SMALL";
    if (value == 354) return "VfxCom.CHUNK_STONE_MEDIUM";
    if (value == 353) return "VfxCom.CHUNK_STONE_SMALL";
    if (value == 126 ) return "VfxCom.CHUNK_YELLOW_MEDIUM";
    if (value == 125 ) return "VfxCom.CHUNK_YELLOW_SMALL";
    if (value == 283) return "VfxCom.HIT_ACID";
    if (value == 289) return "VfxCom.HIT_DIVINE";
    if (value == 282) return "VfxCom.HIT_ELECTRICAL";
    if (value == 280) return "VfxCom.HIT_FIRE";
    if (value == 281) return "VfxCom.HIT_FROST";
    if (value == 288) return "VfxCom.HIT_NEGATIVE";
    if (value == 284) return "VfxCom.HIT_SONIC";
    if (value == 118 ) return "VfxCom.SPARKS_PARRY";
    if (value == 100 ) return "VfxCom.SPECIAL_BLUE_RED";
    if (value == 101 ) return "VfxCom.SPECIAL_PINK_ORANGE";
    if (value == 103 ) return "VfxCom.SPECIAL_RED_ORANGE";
    if (value == 102 ) return "VfxCom.SPECIAL_RED_WHITE";
    if (value == 104 ) return "VfxCom.SPECIAL_WHITE_BLUE";
    if (value == 105 ) return "VfxCom.SPECIAL_WHITE_ORANGE";
    if (value == 120 ) return "VfxCom.UNLOAD_MODEL";
    return "VfxCom.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxCom.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxCom.(not found: " + value + ")";
  }
}
