package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_EVIL_DUNGEON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundEvilDungeon {
  private AmbientSoundEvilDungeon() {}

  public final static int LARGE = 59;
  public final static int MEDIUM = 58;
  public final static int SMALL = 57;

  public static String nameOf(int value) {
    if (value == 59) return "AmbientSoundEvilDungeon.LARGE";
    if (value == 58) return "AmbientSoundEvilDungeon.MEDIUM";
    if (value == 57) return "AmbientSoundEvilDungeon.SMALL";
    return "AmbientSoundEvilDungeon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundEvilDungeon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundEvilDungeon.(not found: " + value + ")";
  }
}
