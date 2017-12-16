package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_HORSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellHorse {
  private SpellHorse() {}

  public final static int ASSIGN_MOUNT = 817;
  public final static int DISMOUNT = 814;
  public final static int MENU = 812;
  public final static int MOUNT = 813;
  public final static int PARTY_DISMOUNT = 816;
  public final static int PARTY_MOUNT = 815;

  public static String nameOf(int value) {
    if (value == 817) return "SpellHorse.ASSIGN_MOUNT";
    if (value == 814) return "SpellHorse.DISMOUNT";
    if (value == 812) return "SpellHorse.MENU";
    if (value == 813) return "SpellHorse.MOUNT";
    if (value == 816) return "SpellHorse.PARTY_DISMOUNT";
    if (value == 815) return "SpellHorse.PARTY_MOUNT";
    return "SpellHorse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellHorse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellHorse.(not found: " + value + ")";
  }
}
