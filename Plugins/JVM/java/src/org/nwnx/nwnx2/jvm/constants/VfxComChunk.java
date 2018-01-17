package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_CHUNK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComChunk {
  private VfxComChunk() {}

  public final static int BONE_MEDIUM = 236;
  public final static int GREEN_MEDIUM = 124 ;
  public final static int GREEN_SMALL = 123 ;
  public final static int RED_BALLISTA = 504;
  public final static int RED_LARGE = 235;
  public final static int RED_MEDIUM = 122 ;
  public final static int RED_SMALL = 121 ;
  public final static int STONE_MEDIUM = 354;
  public final static int STONE_SMALL = 353;
  public final static int YELLOW_MEDIUM = 126 ;
  public final static int YELLOW_SMALL = 125 ;

  public static String nameOf(int value) {
    if (value == 236) return "VfxComChunk.BONE_MEDIUM";
    if (value == 124 ) return "VfxComChunk.GREEN_MEDIUM";
    if (value == 123 ) return "VfxComChunk.GREEN_SMALL";
    if (value == 504) return "VfxComChunk.RED_BALLISTA";
    if (value == 235) return "VfxComChunk.RED_LARGE";
    if (value == 122 ) return "VfxComChunk.RED_MEDIUM";
    if (value == 121 ) return "VfxComChunk.RED_SMALL";
    if (value == 354) return "VfxComChunk.STONE_MEDIUM";
    if (value == 353) return "VfxComChunk.STONE_SMALL";
    if (value == 126 ) return "VfxComChunk.YELLOW_MEDIUM";
    if (value == 125 ) return "VfxComChunk.YELLOW_SMALL";
    return "VfxComChunk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComChunk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComChunk.(not found: " + value + ")";
  }
}
