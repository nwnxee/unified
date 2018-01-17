package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_CHUNK_RED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComChunkRed {
  private VfxComChunkRed() {}

  public final static int BALLISTA = 504;
  public final static int LARGE = 235;
  public final static int MEDIUM = 122 ;
  public final static int SMALL = 121 ;

  public static String nameOf(int value) {
    if (value == 504) return "VfxComChunkRed.BALLISTA";
    if (value == 235) return "VfxComChunkRed.LARGE";
    if (value == 122 ) return "VfxComChunkRed.MEDIUM";
    if (value == 121 ) return "VfxComChunkRed.SMALL";
    return "VfxComChunkRed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComChunkRed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComChunkRed.(not found: " + value + ")";
  }
}
