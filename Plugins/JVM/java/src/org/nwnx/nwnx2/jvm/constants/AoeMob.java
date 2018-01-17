package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AOE_MOB".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AoeMob {
  private AoeMob() {}

  public final static int BLINDING = 17;
  public final static int CIRCCHAOS = 15;
  public final static int CIRCEVIL = 12;
  public final static int CIRCGOOD = 13;
  public final static int CIRCLAW = 14;
  public final static int DRAGON_FEAR = 36;
  public final static int ELECTRICAL = 25;
  public final static int FEAR = 16;
  public final static int FIRE = 23;
  public final static int FROST = 24;
  public final static int HORRIFICAPPEARANCE = 44;
  public final static int INVISIBILITY_PURGE = 35;
  public final static int MENACE = 19;
  public final static int PROTECTION = 22;
  public final static int SILENCE = 30;
  public final static int STUN = 21;
  public final static int TIDE_OF_BATTLE = 41;
  public final static int TROGLODYTE_STENCH = 45;
  public final static int TYRANT_FOG = 27;
  public final static int UNEARTHLY = 18;
  public final static int UNNATURAL = 20;

  public static String nameOf(int value) {
    if (value == 17) return "AoeMob.BLINDING";
    if (value == 15) return "AoeMob.CIRCCHAOS";
    if (value == 12) return "AoeMob.CIRCEVIL";
    if (value == 13) return "AoeMob.CIRCGOOD";
    if (value == 14) return "AoeMob.CIRCLAW";
    if (value == 36) return "AoeMob.DRAGON_FEAR";
    if (value == 25) return "AoeMob.ELECTRICAL";
    if (value == 16) return "AoeMob.FEAR";
    if (value == 23) return "AoeMob.FIRE";
    if (value == 24) return "AoeMob.FROST";
    if (value == 44) return "AoeMob.HORRIFICAPPEARANCE";
    if (value == 35) return "AoeMob.INVISIBILITY_PURGE";
    if (value == 19) return "AoeMob.MENACE";
    if (value == 22) return "AoeMob.PROTECTION";
    if (value == 30) return "AoeMob.SILENCE";
    if (value == 21) return "AoeMob.STUN";
    if (value == 41) return "AoeMob.TIDE_OF_BATTLE";
    if (value == 45) return "AoeMob.TROGLODYTE_STENCH";
    if (value == 27) return "AoeMob.TYRANT_FOG";
    if (value == 18) return "AoeMob.UNEARTHLY";
    if (value == 20) return "AoeMob.UNNATURAL";
    return "AoeMob.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AoeMob.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AoeMob.(not found: " + value + ")";
  }
}
