package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_EPIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityEpic {
  private SpellabilityEpic() {}

  public final static int CURSE_SONG = 644;
  public final static int IMPROVED_WHIRLWIND = 645;
  public final static int MIGHTY_RAGE = 642;
  public final static int SHAPE_DRAGON = 647;
  public final static int SHAPE_DRAGONKIN = 646;

  public static String nameOf(int value) {
    if (value == 644) return "SpellabilityEpic.CURSE_SONG";
    if (value == 645) return "SpellabilityEpic.IMPROVED_WHIRLWIND";
    if (value == 642) return "SpellabilityEpic.MIGHTY_RAGE";
    if (value == 647) return "SpellabilityEpic.SHAPE_DRAGON";
    if (value == 646) return "SpellabilityEpic.SHAPE_DRAGONKIN";
    return "SpellabilityEpic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityEpic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityEpic.(not found: " + value + ")";
  }
}
