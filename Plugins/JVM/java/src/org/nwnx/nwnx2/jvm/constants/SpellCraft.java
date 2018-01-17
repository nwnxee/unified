package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_CRAFT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellCraft {
  private SpellCraft() {}

  public final static int ADD_ITEM_PROPERTY = 654;
  public final static int CRAFT_ARMOR_SKILL = 657;
  public final static int CRAFT_WEAPON_SKILL = 656;
  public final static int DYE_CLOTHCOLOR_1 = 648;
  public final static int DYE_CLOTHCOLOR_2 = 649;
  public final static int DYE_LEATHERCOLOR_1 = 650;
  public final static int DYE_LEATHERCOLOR_2 = 651;
  public final static int DYE_METALCOLOR_1 = 652;
  public final static int DYE_METALCOLOR_2 = 653;
  public final static int HARPER_ITEM = 479;
  public final static int POISON_WEAPON_OR_AMMO = 655;

  public static String nameOf(int value) {
    if (value == 654) return "SpellCraft.ADD_ITEM_PROPERTY";
    if (value == 657) return "SpellCraft.CRAFT_ARMOR_SKILL";
    if (value == 656) return "SpellCraft.CRAFT_WEAPON_SKILL";
    if (value == 648) return "SpellCraft.DYE_CLOTHCOLOR_1";
    if (value == 649) return "SpellCraft.DYE_CLOTHCOLOR_2";
    if (value == 650) return "SpellCraft.DYE_LEATHERCOLOR_1";
    if (value == 651) return "SpellCraft.DYE_LEATHERCOLOR_2";
    if (value == 652) return "SpellCraft.DYE_METALCOLOR_1";
    if (value == 653) return "SpellCraft.DYE_METALCOLOR_2";
    if (value == 479) return "SpellCraft.HARPER_ITEM";
    if (value == 655) return "SpellCraft.POISON_WEAPON_OR_AMMO";
    return "SpellCraft.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellCraft.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellCraft.(not found: " + value + ")";
  }
}
