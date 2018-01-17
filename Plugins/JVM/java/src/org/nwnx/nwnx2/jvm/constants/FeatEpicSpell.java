package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSpell {
  private FeatEpicSpell() {}

  public final static int DRAGON_KNIGHT = 875;
  public final static int EPIC_WARDING = 990;
  public final static int FOCUS_ABJURATION = 610;
  public final static int FOCUS_CONJURATION = 611;
  public final static int FOCUS_DIVINATION = 612;
  public final static int FOCUS_ENCHANTMENT = 613;
  public final static int FOCUS_EVOCATION = 614;
  public final static int FOCUS_ILLUSION = 615;
  public final static int FOCUS_NECROMANCY = 616;
  public final static int FOCUS_TRANSMUTATION = 617;
  public final static int HELLBALL = 876;
  public final static int MAGE_ARMOUR = 877;
  public final static int MUMMY_DUST = 874;
  public final static int PENETRATION = 618;
  public final static int RUIN = 878;

  public static String nameOf(int value) {
    if (value == 875) return "FeatEpicSpell.DRAGON_KNIGHT";
    if (value == 990) return "FeatEpicSpell.EPIC_WARDING";
    if (value == 610) return "FeatEpicSpell.FOCUS_ABJURATION";
    if (value == 611) return "FeatEpicSpell.FOCUS_CONJURATION";
    if (value == 612) return "FeatEpicSpell.FOCUS_DIVINATION";
    if (value == 613) return "FeatEpicSpell.FOCUS_ENCHANTMENT";
    if (value == 614) return "FeatEpicSpell.FOCUS_EVOCATION";
    if (value == 615) return "FeatEpicSpell.FOCUS_ILLUSION";
    if (value == 616) return "FeatEpicSpell.FOCUS_NECROMANCY";
    if (value == 617) return "FeatEpicSpell.FOCUS_TRANSMUTATION";
    if (value == 876) return "FeatEpicSpell.HELLBALL";
    if (value == 877) return "FeatEpicSpell.MAGE_ARMOUR";
    if (value == 874) return "FeatEpicSpell.MUMMY_DUST";
    if (value == 618) return "FeatEpicSpell.PENETRATION";
    if (value == 878) return "FeatEpicSpell.RUIN";
    return "FeatEpicSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSpell.(not found: " + value + ")";
  }
}
