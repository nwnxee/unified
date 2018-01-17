package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureType {
  private CreatureType() {}

  public final static int CLASS = 2;
  public final static int DOES_NOT_HAVE_SPELL_EFFECT = 6;
  public final static int HAS_SPELL_EFFECT = 5;
  public final static int IS_ALIVE = 4;
  public final static int PERCEPTION = 7;
  public final static int PLAYER_CHAR = 1;
  public final static int RACIAL_TYPE = 0;
  public final static int REPUTATION = 3;

  public static String nameOf(int value) {
    if (value == 2) return "CreatureType.CLASS";
    if (value == 6) return "CreatureType.DOES_NOT_HAVE_SPELL_EFFECT";
    if (value == 5) return "CreatureType.HAS_SPELL_EFFECT";
    if (value == 4) return "CreatureType.IS_ALIVE";
    if (value == 7) return "CreatureType.PERCEPTION";
    if (value == 1) return "CreatureType.PLAYER_CHAR";
    if (value == 0) return "CreatureType.RACIAL_TYPE";
    if (value == 3) return "CreatureType.REPUTATION";
    return "CreatureType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureType.(not found: " + value + ")";
  }
}
