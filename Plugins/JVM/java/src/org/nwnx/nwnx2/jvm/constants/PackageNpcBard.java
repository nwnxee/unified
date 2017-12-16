package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_NPC_BARD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageNpcBard {
  private PackageNpcBard() {}

  public final static int DEEKIN_2 = 117;
  public final static int FIGHTER = 106;
  public final static int FIGHTER_SHARWYN2 = 114;
  public final static int PACKAGE_NPC_BARD = 72;

  public static String nameOf(int value) {
    if (value == 117) return "PackageNpcBard.DEEKIN_2";
    if (value == 106) return "PackageNpcBard.FIGHTER";
    if (value == 114) return "PackageNpcBard.FIGHTER_SHARWYN2";
    if (value == 72) return "PackageNpcBard.PACKAGE_NPC_BARD";
    return "PackageNpcBard.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageNpcBard.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageNpcBard.(not found: " + value + ")";
  }
}
