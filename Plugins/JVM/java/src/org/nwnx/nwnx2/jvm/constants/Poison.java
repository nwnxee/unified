package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POISON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Poison {
  private Poison() {}

  public final static int ARANEA_VENOM = 33;
  public final static int ARSENIC = 23;
  public final static int BEBILITH_VENOM = 29;
  public final static int BLACK_ADDER_VENOM = 11;
  public final static int BLACK_LOTUS_EXTRACT = 19;
  public final static int BLADE_BANE = 2;
  public final static int BLOODROOT = 4;
  public final static int BLUE_WHINNIS = 8;
  public final static int BURNT_OTHUR_FUMES = 27;
  public final static int CARRION_CRAWLER_BRAIN_JUICE = 18;
  public final static int CHAOS_MIST = 28;
  public final static int COLOSSAL_SPIDER_VENOM = 40;
  public final static int DARK_REAVER_POWDER = 25;
  public final static int DEATHBLADE = 12;
  public final static int DRAGON_BILE = 15;
  public final static int ETTERCAP_VENOM = 32;
  public final static int GARGANTUAN_SPIDER_VENOM = 39;
  public final static int GIANT_WASP_POISON = 9;
  public final static int GREENBLOOD_OIL = 3;
  public final static int HUGE_SPIDER_VENOM = 38;
  public final static int ID_MOSS = 21;
  public final static int IRON_GOLEM = 43;
  public final static int LARGE_SCORPION_VENOM = 6;
  public final static int LARGE_SPIDER_VENOM = 37;
  public final static int LICH_DUST = 24;
  public final static int MALYSS_ROOT_PASTE = 13;
  public final static int MEDIUM_SPIDER_VENOM = 36;
  public final static int NIGHTSHADE = 0;
  public final static int NITHARIT = 14;
  public final static int OIL_OF_TAGGIT = 20;
  public final static int PHASE_SPIDER_VENOM = 41;
  public final static int PIT_FIEND_ICHOR = 31;
  public final static int PURPLE_WORM_POISON = 5;
  public final static int QUASIT_VENOM = 30;
  public final static int SASSONE_LEAF_RESIDUE = 16;
  public final static int SHADOW_ESSENCE = 10;
  public final static int SMALL_CENTIPEDE_POISON = 1;
  public final static int SMALL_SPIDER_VENOM = 35;
  public final static int STRIPED_TOADSTOOL = 22;
  public final static int TERINAV_ROOT = 17;
  public final static int TINY_SPIDER_VENOM = 34;
  public final static int UNGOL_DUST = 26;
  public final static int WRAITH_SPIDER_VENOM = 42;
  public final static int WYVERN_POISON = 7;

  public static String nameOf(int value) {
    if (value == 33) return "Poison.ARANEA_VENOM";
    if (value == 23) return "Poison.ARSENIC";
    if (value == 29) return "Poison.BEBILITH_VENOM";
    if (value == 11) return "Poison.BLACK_ADDER_VENOM";
    if (value == 19) return "Poison.BLACK_LOTUS_EXTRACT";
    if (value == 2) return "Poison.BLADE_BANE";
    if (value == 4) return "Poison.BLOODROOT";
    if (value == 8) return "Poison.BLUE_WHINNIS";
    if (value == 27) return "Poison.BURNT_OTHUR_FUMES";
    if (value == 18) return "Poison.CARRION_CRAWLER_BRAIN_JUICE";
    if (value == 28) return "Poison.CHAOS_MIST";
    if (value == 40) return "Poison.COLOSSAL_SPIDER_VENOM";
    if (value == 25) return "Poison.DARK_REAVER_POWDER";
    if (value == 12) return "Poison.DEATHBLADE";
    if (value == 15) return "Poison.DRAGON_BILE";
    if (value == 32) return "Poison.ETTERCAP_VENOM";
    if (value == 39) return "Poison.GARGANTUAN_SPIDER_VENOM";
    if (value == 9) return "Poison.GIANT_WASP_POISON";
    if (value == 3) return "Poison.GREENBLOOD_OIL";
    if (value == 38) return "Poison.HUGE_SPIDER_VENOM";
    if (value == 21) return "Poison.ID_MOSS";
    if (value == 43) return "Poison.IRON_GOLEM";
    if (value == 6) return "Poison.LARGE_SCORPION_VENOM";
    if (value == 37) return "Poison.LARGE_SPIDER_VENOM";
    if (value == 24) return "Poison.LICH_DUST";
    if (value == 13) return "Poison.MALYSS_ROOT_PASTE";
    if (value == 36) return "Poison.MEDIUM_SPIDER_VENOM";
    if (value == 0) return "Poison.NIGHTSHADE";
    if (value == 14) return "Poison.NITHARIT";
    if (value == 20) return "Poison.OIL_OF_TAGGIT";
    if (value == 41) return "Poison.PHASE_SPIDER_VENOM";
    if (value == 31) return "Poison.PIT_FIEND_ICHOR";
    if (value == 5) return "Poison.PURPLE_WORM_POISON";
    if (value == 30) return "Poison.QUASIT_VENOM";
    if (value == 16) return "Poison.SASSONE_LEAF_RESIDUE";
    if (value == 10) return "Poison.SHADOW_ESSENCE";
    if (value == 1) return "Poison.SMALL_CENTIPEDE_POISON";
    if (value == 35) return "Poison.SMALL_SPIDER_VENOM";
    if (value == 22) return "Poison.STRIPED_TOADSTOOL";
    if (value == 17) return "Poison.TERINAV_ROOT";
    if (value == 34) return "Poison.TINY_SPIDER_VENOM";
    if (value == 26) return "Poison.UNGOL_DUST";
    if (value == 42) return "Poison.WRAITH_SPIDER_VENOM";
    if (value == 7) return "Poison.WYVERN_POISON";
    return "Poison.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Poison.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Poison.(not found: " + value + ")";
  }
}
