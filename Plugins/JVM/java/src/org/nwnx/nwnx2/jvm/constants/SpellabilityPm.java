package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_PM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityPm {
  private SpellabilityPm() {}

  public final static int ANIMATE_DEAD = 623;
  public final static int DEATHLESS_MASTER_TOUCH = 628;
  public final static int SUMMON_GREATER_UNDEAD = 627;
  public final static int SUMMON_UNDEAD = 624;
  public final static int UNDEAD_GRAFT_1 = 625;
  public final static int UNDEAD_GRAFT_2 = 626;

  public static String nameOf(int value) {
    if (value == 623) return "SpellabilityPm.ANIMATE_DEAD";
    if (value == 628) return "SpellabilityPm.DEATHLESS_MASTER_TOUCH";
    if (value == 627) return "SpellabilityPm.SUMMON_GREATER_UNDEAD";
    if (value == 624) return "SpellabilityPm.SUMMON_UNDEAD";
    if (value == 625) return "SpellabilityPm.UNDEAD_GRAFT_1";
    if (value == 626) return "SpellabilityPm.UNDEAD_GRAFT_2";
    return "SpellabilityPm.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityPm.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityPm.(not found: " + value + ")";
  }
}
