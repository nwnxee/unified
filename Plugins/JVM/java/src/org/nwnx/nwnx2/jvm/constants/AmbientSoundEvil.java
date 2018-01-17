package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_EVIL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundEvil {
  private AmbientSoundEvil() {}

  public final static int DRONE_XP2 = 101;
  public final static int DUNGEON_LARGE = 59;
  public final static int DUNGEON_MEDIUM = 58;
  public final static int DUNGEON_SMALL = 57;

  public static String nameOf(int value) {
    if (value == 101) return "AmbientSoundEvil.DRONE_XP2";
    if (value == 59) return "AmbientSoundEvil.DUNGEON_LARGE";
    if (value == 58) return "AmbientSoundEvil.DUNGEON_MEDIUM";
    if (value == 57) return "AmbientSoundEvil.DUNGEON_SMALL";
    return "AmbientSoundEvil.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundEvil.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundEvil.(not found: " + value + ")";
  }
}
