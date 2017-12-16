package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_EPIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellEpic {
  private SpellEpic() {}

  public final static int DRAGON_KNIGHT = 638;
  public final static int HELLBALL = 636;
  public final static int MAGE_ARMOR = 639;
  public final static int MUMMY_DUST = 637;
  public final static int RUIN = 640;

  public static String nameOf(int value) {
    if (value == 638) return "SpellEpic.DRAGON_KNIGHT";
    if (value == 636) return "SpellEpic.HELLBALL";
    if (value == 639) return "SpellEpic.MAGE_ARMOR";
    if (value == 637) return "SpellEpic.MUMMY_DUST";
    if (value == 640) return "SpellEpic.RUIN";
    return "SpellEpic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellEpic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellEpic.(not found: " + value + ")";
  }
}
