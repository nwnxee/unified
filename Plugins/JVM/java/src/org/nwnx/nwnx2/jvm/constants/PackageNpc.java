package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_NPC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageNpc {
  private PackageNpc() {}

  public final static int ARIBETH_BLACKGUARD = 130;
  public final static int ARIBETH_PALADIN = 129;
  public final static int BARBARIAN_DAELAN = 105;
  public final static int BARD = 72;
  public final static int BARD_DEEKIN_2 = 117;
  public final static int BARD_FIGHTER = 106;
  public final static int BARD_FIGHTER_SHARWYN2 = 114;
  public final static int CLERIC_LINU = 104;
  public final static int FT_WEAPONMASTER = 102;
  public final static int FT_WEAPONMASTER_VALEN_2 = 113;
  public final static int PALADIN_FALLING = 107;
  public final static int RG_SHADOWDANCER = 103;
  public final static int RG_TOMI_2 = 116;
  public final static int ROGUE = 71;
  public final static int SORCERER = 70;
  public final static int WIZASSASSIN = 101;
  public final static int WIZASSASSIN_NATHYRRA = 115;

  public static String nameOf(int value) {
    if (value == 130) return "PackageNpc.ARIBETH_BLACKGUARD";
    if (value == 129) return "PackageNpc.ARIBETH_PALADIN";
    if (value == 105) return "PackageNpc.BARBARIAN_DAELAN";
    if (value == 72) return "PackageNpc.BARD";
    if (value == 117) return "PackageNpc.BARD_DEEKIN_2";
    if (value == 106) return "PackageNpc.BARD_FIGHTER";
    if (value == 114) return "PackageNpc.BARD_FIGHTER_SHARWYN2";
    if (value == 104) return "PackageNpc.CLERIC_LINU";
    if (value == 102) return "PackageNpc.FT_WEAPONMASTER";
    if (value == 113) return "PackageNpc.FT_WEAPONMASTER_VALEN_2";
    if (value == 107) return "PackageNpc.PALADIN_FALLING";
    if (value == 103) return "PackageNpc.RG_SHADOWDANCER";
    if (value == 116) return "PackageNpc.RG_TOMI_2";
    if (value == 71) return "PackageNpc.ROGUE";
    if (value == 70) return "PackageNpc.SORCERER";
    if (value == 101) return "PackageNpc.WIZASSASSIN";
    if (value == 115) return "PackageNpc.WIZASSASSIN_NATHYRRA";
    return "PackageNpc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageNpc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageNpc.(not found: " + value + ")";
  }
}
