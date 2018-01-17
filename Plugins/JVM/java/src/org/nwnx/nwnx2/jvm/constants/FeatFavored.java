package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_FAVORED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatFavored {
  private FeatFavored() {}

  public final static int ENEMY_ABERRATION = 268;
  public final static int ENEMY_ANIMAL = 269;
  public final static int ENEMY_BEAST = 270;
  public final static int ENEMY_CONSTRUCT = 271;
  public final static int ENEMY_DRAGON = 272;
  public final static int ENEMY_DWARF = 261;
  public final static int ENEMY_ELEMENTAL = 277;
  public final static int ENEMY_ELF = 262;
  public final static int ENEMY_FEY = 278;
  public final static int ENEMY_GIANT = 279;
  public final static int ENEMY_GNOME = 263;
  public final static int ENEMY_GOBLINOID = 273;
  public final static int ENEMY_HALFELF = 265;
  public final static int ENEMY_HALFLING = 264;
  public final static int ENEMY_HALFORC = 266;
  public final static int ENEMY_HUMAN = 267;
  public final static int ENEMY_MAGICAL_BEAST = 280;
  public final static int ENEMY_MONSTROUS = 274;
  public final static int ENEMY_ORC = 275;
  public final static int ENEMY_OUTSIDER = 281;
  public final static int ENEMY_REPTILIAN = 276;
  public final static int ENEMY_SHAPECHANGER = 284;
  public final static int ENEMY_UNDEAD = 285;
  public final static int ENEMY_VERMIN = 286;

  public static String nameOf(int value) {
    if (value == 268) return "FeatFavored.ENEMY_ABERRATION";
    if (value == 269) return "FeatFavored.ENEMY_ANIMAL";
    if (value == 270) return "FeatFavored.ENEMY_BEAST";
    if (value == 271) return "FeatFavored.ENEMY_CONSTRUCT";
    if (value == 272) return "FeatFavored.ENEMY_DRAGON";
    if (value == 261) return "FeatFavored.ENEMY_DWARF";
    if (value == 277) return "FeatFavored.ENEMY_ELEMENTAL";
    if (value == 262) return "FeatFavored.ENEMY_ELF";
    if (value == 278) return "FeatFavored.ENEMY_FEY";
    if (value == 279) return "FeatFavored.ENEMY_GIANT";
    if (value == 263) return "FeatFavored.ENEMY_GNOME";
    if (value == 273) return "FeatFavored.ENEMY_GOBLINOID";
    if (value == 265) return "FeatFavored.ENEMY_HALFELF";
    if (value == 264) return "FeatFavored.ENEMY_HALFLING";
    if (value == 266) return "FeatFavored.ENEMY_HALFORC";
    if (value == 267) return "FeatFavored.ENEMY_HUMAN";
    if (value == 280) return "FeatFavored.ENEMY_MAGICAL_BEAST";
    if (value == 274) return "FeatFavored.ENEMY_MONSTROUS";
    if (value == 275) return "FeatFavored.ENEMY_ORC";
    if (value == 281) return "FeatFavored.ENEMY_OUTSIDER";
    if (value == 276) return "FeatFavored.ENEMY_REPTILIAN";
    if (value == 284) return "FeatFavored.ENEMY_SHAPECHANGER";
    if (value == 285) return "FeatFavored.ENEMY_UNDEAD";
    if (value == 286) return "FeatFavored.ENEMY_VERMIN";
    return "FeatFavored.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatFavored.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatFavored.(not found: " + value + ")";
  }
}
