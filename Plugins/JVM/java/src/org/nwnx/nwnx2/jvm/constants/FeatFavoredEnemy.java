package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_FAVORED_ENEMY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatFavoredEnemy {
  private FeatFavoredEnemy() {}

  public final static int ABERRATION = 268;
  public final static int ANIMAL = 269;
  public final static int BEAST = 270;
  public final static int CONSTRUCT = 271;
  public final static int DRAGON = 272;
  public final static int DWARF = 261;
  public final static int ELEMENTAL = 277;
  public final static int ELF = 262;
  public final static int FEY = 278;
  public final static int GIANT = 279;
  public final static int GNOME = 263;
  public final static int GOBLINOID = 273;
  public final static int HALFELF = 265;
  public final static int HALFLING = 264;
  public final static int HALFORC = 266;
  public final static int HUMAN = 267;
  public final static int MAGICAL_BEAST = 280;
  public final static int MONSTROUS = 274;
  public final static int ORC = 275;
  public final static int OUTSIDER = 281;
  public final static int REPTILIAN = 276;
  public final static int SHAPECHANGER = 284;
  public final static int UNDEAD = 285;
  public final static int VERMIN = 286;

  public static String nameOf(int value) {
    if (value == 268) return "FeatFavoredEnemy.ABERRATION";
    if (value == 269) return "FeatFavoredEnemy.ANIMAL";
    if (value == 270) return "FeatFavoredEnemy.BEAST";
    if (value == 271) return "FeatFavoredEnemy.CONSTRUCT";
    if (value == 272) return "FeatFavoredEnemy.DRAGON";
    if (value == 261) return "FeatFavoredEnemy.DWARF";
    if (value == 277) return "FeatFavoredEnemy.ELEMENTAL";
    if (value == 262) return "FeatFavoredEnemy.ELF";
    if (value == 278) return "FeatFavoredEnemy.FEY";
    if (value == 279) return "FeatFavoredEnemy.GIANT";
    if (value == 263) return "FeatFavoredEnemy.GNOME";
    if (value == 273) return "FeatFavoredEnemy.GOBLINOID";
    if (value == 265) return "FeatFavoredEnemy.HALFELF";
    if (value == 264) return "FeatFavoredEnemy.HALFLING";
    if (value == 266) return "FeatFavoredEnemy.HALFORC";
    if (value == 267) return "FeatFavoredEnemy.HUMAN";
    if (value == 280) return "FeatFavoredEnemy.MAGICAL_BEAST";
    if (value == 274) return "FeatFavoredEnemy.MONSTROUS";
    if (value == 275) return "FeatFavoredEnemy.ORC";
    if (value == 281) return "FeatFavoredEnemy.OUTSIDER";
    if (value == 276) return "FeatFavoredEnemy.REPTILIAN";
    if (value == 284) return "FeatFavoredEnemy.SHAPECHANGER";
    if (value == 285) return "FeatFavoredEnemy.UNDEAD";
    if (value == 286) return "FeatFavoredEnemy.VERMIN";
    return "FeatFavoredEnemy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatFavoredEnemy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatFavoredEnemy.(not found: " + value + ")";
  }
}
