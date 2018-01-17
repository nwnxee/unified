package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AOE_PER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AoePer {
  private AoePer() {}

  public final static int CREEPING_DOOM = 33;
  public final static int CUSTOM_AOE = 37;
  public final static int DARKNESS = 11;
  public final static int DELAY_BLAST_FIREBALL = 31;
  public final static int ENTANGLE = 9;
  public final static int EVARDS_BLACK_TENTACLES = 34;
  public final static int FOGACID = 0;
  public final static int FOGFIRE = 1;
  public final static int FOGGHOUL = 26;
  public final static int FOGKILL = 3;
  public final static int FOGMIND = 4;
  public final static int FOGSTINK = 2;
  public final static int FOG_OF_BEWILDERMENT = 39;
  public final static int GLYPH_OF_WARDING = 38;
  public final static int GREASE = 32;
  public final static int INVIS_SPHERE = 29;
  public final static int OVERMIND = 43;
  public final static int STONEHOLD = 42;
  public final static int STORM = 28;
  public final static int VINE_MINE_CAMOUFLAGE = 40;
  public final static int WALLBLADE = 7;
  public final static int WALLFIRE = 5;
  public final static int WALLWIND = 6;
  public final static int WEB = 8;

  public static String nameOf(int value) {
    if (value == 33) return "AoePer.CREEPING_DOOM";
    if (value == 37) return "AoePer.CUSTOM_AOE";
    if (value == 11) return "AoePer.DARKNESS";
    if (value == 31) return "AoePer.DELAY_BLAST_FIREBALL";
    if (value == 9) return "AoePer.ENTANGLE";
    if (value == 34) return "AoePer.EVARDS_BLACK_TENTACLES";
    if (value == 0) return "AoePer.FOGACID";
    if (value == 1) return "AoePer.FOGFIRE";
    if (value == 26) return "AoePer.FOGGHOUL";
    if (value == 3) return "AoePer.FOGKILL";
    if (value == 4) return "AoePer.FOGMIND";
    if (value == 2) return "AoePer.FOGSTINK";
    if (value == 39) return "AoePer.FOG_OF_BEWILDERMENT";
    if (value == 38) return "AoePer.GLYPH_OF_WARDING";
    if (value == 32) return "AoePer.GREASE";
    if (value == 29) return "AoePer.INVIS_SPHERE";
    if (value == 43) return "AoePer.OVERMIND";
    if (value == 42) return "AoePer.STONEHOLD";
    if (value == 28) return "AoePer.STORM";
    if (value == 40) return "AoePer.VINE_MINE_CAMOUFLAGE";
    if (value == 7) return "AoePer.WALLBLADE";
    if (value == 5) return "AoePer.WALLFIRE";
    if (value == 6) return "AoePer.WALLWIND";
    if (value == 8) return "AoePer.WEB";
    return "AoePer.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AoePer.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AoePer.(not found: " + value + ")";
  }
}
