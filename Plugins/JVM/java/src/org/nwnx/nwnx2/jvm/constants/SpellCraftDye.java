package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_CRAFT_DYE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellCraftDye {
  private SpellCraftDye() {}

  public final static int CLOTHCOLOR_1 = 648;
  public final static int CLOTHCOLOR_2 = 649;
  public final static int LEATHERCOLOR_1 = 650;
  public final static int LEATHERCOLOR_2 = 651;
  public final static int METALCOLOR_1 = 652;
  public final static int METALCOLOR_2 = 653;

  public static String nameOf(int value) {
    if (value == 648) return "SpellCraftDye.CLOTHCOLOR_1";
    if (value == 649) return "SpellCraftDye.CLOTHCOLOR_2";
    if (value == 650) return "SpellCraftDye.LEATHERCOLOR_1";
    if (value == 651) return "SpellCraftDye.LEATHERCOLOR_2";
    if (value == 652) return "SpellCraftDye.METALCOLOR_1";
    if (value == 653) return "SpellCraftDye.METALCOLOR_2";
    return "SpellCraftDye.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellCraftDye.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellCraftDye.(not found: " + value + ")";
  }
}
