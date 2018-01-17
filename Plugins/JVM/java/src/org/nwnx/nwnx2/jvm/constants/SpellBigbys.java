package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_BIGBYS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellBigbys {
  private SpellBigbys() {}

  public final static int CLENCHED_FIST = 462;
  public final static int CRUSHING_HAND = 463;
  public final static int FORCEFUL_HAND = 460;
  public final static int GRASPING_HAND = 461;
  public final static int INTERPOSING_HAND = 459;

  public static String nameOf(int value) {
    if (value == 462) return "SpellBigbys.CLENCHED_FIST";
    if (value == 463) return "SpellBigbys.CRUSHING_HAND";
    if (value == 460) return "SpellBigbys.FORCEFUL_HAND";
    if (value == 461) return "SpellBigbys.GRASPING_HAND";
    if (value == 459) return "SpellBigbys.INTERPOSING_HAND";
    return "SpellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellBigbys.(not found: " + value + ")";
  }
}
