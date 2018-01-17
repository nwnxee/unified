package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AOE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Aoe {
  private Aoe() {}

  public final static int MOB_BLINDING = 17;
  public final static int MOB_CIRCCHAOS = 15;
  public final static int MOB_CIRCEVIL = 12;
  public final static int MOB_CIRCGOOD = 13;
  public final static int MOB_CIRCLAW = 14;
  public final static int MOB_DRAGON_FEAR = 36;
  public final static int MOB_ELECTRICAL = 25;
  public final static int MOB_FEAR = 16;
  public final static int MOB_FIRE = 23;
  public final static int MOB_FROST = 24;
  public final static int MOB_HORRIFICAPPEARANCE = 44;
  public final static int MOB_INVISIBILITY_PURGE = 35;
  public final static int MOB_MENACE = 19;
  public final static int MOB_PROTECTION = 22;
  public final static int MOB_SILENCE = 30;
  public final static int MOB_STUN = 21;
  public final static int MOB_TIDE_OF_BATTLE = 41;
  public final static int MOB_TROGLODYTE_STENCH = 45;
  public final static int MOB_TYRANT_FOG = 27;
  public final static int MOB_UNEARTHLY = 18;
  public final static int MOB_UNNATURAL = 20;
  public final static int PER_CREEPING_DOOM = 33;
  public final static int PER_CUSTOM_AOE = 37;
  public final static int PER_DARKNESS = 11;
  public final static int PER_DELAY_BLAST_FIREBALL = 31;
  public final static int PER_ENTANGLE = 9;
  public final static int PER_EVARDS_BLACK_TENTACLES = 34;
  public final static int PER_FOGACID = 0;
  public final static int PER_FOGFIRE = 1;
  public final static int PER_FOGGHOUL = 26;
  public final static int PER_FOGKILL = 3;
  public final static int PER_FOGMIND = 4;
  public final static int PER_FOGSTINK = 2;
  public final static int PER_FOG_OF_BEWILDERMENT = 39;
  public final static int PER_GLYPH_OF_WARDING = 38;
  public final static int PER_GREASE = 32;
  public final static int PER_INVIS_SPHERE = 29;
  public final static int PER_OVERMIND = 43;
  public final static int PER_STONEHOLD = 42;
  public final static int PER_STORM = 28;
  public final static int PER_VINE_MINE_CAMOUFLAGE = 40;
  public final static int PER_WALLBLADE = 7;
  public final static int PER_WALLFIRE = 5;
  public final static int PER_WALLWIND = 6;
  public final static int PER_WEB = 8;

  public static String nameOf(int value) {
    if (value == 17) return "Aoe.MOB_BLINDING";
    if (value == 15) return "Aoe.MOB_CIRCCHAOS";
    if (value == 12) return "Aoe.MOB_CIRCEVIL";
    if (value == 13) return "Aoe.MOB_CIRCGOOD";
    if (value == 14) return "Aoe.MOB_CIRCLAW";
    if (value == 36) return "Aoe.MOB_DRAGON_FEAR";
    if (value == 25) return "Aoe.MOB_ELECTRICAL";
    if (value == 16) return "Aoe.MOB_FEAR";
    if (value == 23) return "Aoe.MOB_FIRE";
    if (value == 24) return "Aoe.MOB_FROST";
    if (value == 44) return "Aoe.MOB_HORRIFICAPPEARANCE";
    if (value == 35) return "Aoe.MOB_INVISIBILITY_PURGE";
    if (value == 19) return "Aoe.MOB_MENACE";
    if (value == 22) return "Aoe.MOB_PROTECTION";
    if (value == 30) return "Aoe.MOB_SILENCE";
    if (value == 21) return "Aoe.MOB_STUN";
    if (value == 41) return "Aoe.MOB_TIDE_OF_BATTLE";
    if (value == 45) return "Aoe.MOB_TROGLODYTE_STENCH";
    if (value == 27) return "Aoe.MOB_TYRANT_FOG";
    if (value == 18) return "Aoe.MOB_UNEARTHLY";
    if (value == 20) return "Aoe.MOB_UNNATURAL";
    if (value == 33) return "Aoe.PER_CREEPING_DOOM";
    if (value == 37) return "Aoe.PER_CUSTOM_AOE";
    if (value == 11) return "Aoe.PER_DARKNESS";
    if (value == 31) return "Aoe.PER_DELAY_BLAST_FIREBALL";
    if (value == 9) return "Aoe.PER_ENTANGLE";
    if (value == 34) return "Aoe.PER_EVARDS_BLACK_TENTACLES";
    if (value == 0) return "Aoe.PER_FOGACID";
    if (value == 1) return "Aoe.PER_FOGFIRE";
    if (value == 26) return "Aoe.PER_FOGGHOUL";
    if (value == 3) return "Aoe.PER_FOGKILL";
    if (value == 4) return "Aoe.PER_FOGMIND";
    if (value == 2) return "Aoe.PER_FOGSTINK";
    if (value == 39) return "Aoe.PER_FOG_OF_BEWILDERMENT";
    if (value == 38) return "Aoe.PER_GLYPH_OF_WARDING";
    if (value == 32) return "Aoe.PER_GREASE";
    if (value == 29) return "Aoe.PER_INVIS_SPHERE";
    if (value == 43) return "Aoe.PER_OVERMIND";
    if (value == 42) return "Aoe.PER_STONEHOLD";
    if (value == 28) return "Aoe.PER_STORM";
    if (value == 40) return "Aoe.PER_VINE_MINE_CAMOUFLAGE";
    if (value == 7) return "Aoe.PER_WALLBLADE";
    if (value == 5) return "Aoe.PER_WALLFIRE";
    if (value == 6) return "Aoe.PER_WALLWIND";
    if (value == 8) return "Aoe.PER_WEB";
    return "Aoe.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Aoe.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Aoe.(not found: " + value + ")";
  }
}
