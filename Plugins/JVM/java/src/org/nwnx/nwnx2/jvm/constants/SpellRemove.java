package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_REMOVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellRemove {
  private SpellRemove() {}

  public final static int BLINDNESS_AND_DEAFNESS = 145;
  public final static int CURSE = 146;
  public final static int DISEASE = 147;
  public final static int FEAR = 148;
  public final static int PARALYSIS = 149;

  public static String nameOf(int value) {
    if (value == 145) return "SpellRemove.BLINDNESS_AND_DEAFNESS";
    if (value == 146) return "SpellRemove.CURSE";
    if (value == 147) return "SpellRemove.DISEASE";
    if (value == 148) return "SpellRemove.FEAR";
    if (value == 149) return "SpellRemove.PARALYSIS";
    return "SpellRemove.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellRemove.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellRemove.(not found: " + value + ")";
  }
}
