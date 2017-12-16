package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_OF_CHOICE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponOfChoice {
  private FeatWeaponOfChoice() {}

  public final static int BASTARDSWORD = 940;
  public final static int BATTLEAXE = 931;
  public final static int CLUB = 919;
  public final static int DAGGER = 920;
  public final static int DIREMACE = 941;
  public final static int DOUBLEAXE = 942;
  public final static int DWAXE = 959;
  public final static int GREATAXE = 932;
  public final static int GREATSWORD = 929;
  public final static int HALBERD = 933;
  public final static int HANDAXE = 930;
  public final static int HEAVYFLAIL = 937;
  public final static int KAMA = 880;
  public final static int KATANA = 939;
  public final static int KUKRI = 881;
  public final static int LIGHTFLAIL = 935;
  public final static int LIGHTHAMMER = 934;
  public final static int LIGHTMACE = 921;
  public final static int LONGSWORD = 928;
  public final static int MORNINGSTAR = 922;
  public final static int QUARTERSTAFF = 923;
  public final static int RAPIER = 926;
  public final static int SCIMITAR = 927;
  public final static int SCYTHE = 938;
  public final static int SHORTSPEAR = 924;
  public final static int SHORTSWORD = 925;
  public final static int SICKLE = 879;
  public final static int TRIDENT = 1079;
  public final static int TWOBLADEDSWORD = 943;
  public final static int WARHAMMER = 936;
  public final static int WHIP = 1000;

  public static String nameOf(int value) {
    if (value == 940) return "FeatWeaponOfChoice.BASTARDSWORD";
    if (value == 931) return "FeatWeaponOfChoice.BATTLEAXE";
    if (value == 919) return "FeatWeaponOfChoice.CLUB";
    if (value == 920) return "FeatWeaponOfChoice.DAGGER";
    if (value == 941) return "FeatWeaponOfChoice.DIREMACE";
    if (value == 942) return "FeatWeaponOfChoice.DOUBLEAXE";
    if (value == 959) return "FeatWeaponOfChoice.DWAXE";
    if (value == 932) return "FeatWeaponOfChoice.GREATAXE";
    if (value == 929) return "FeatWeaponOfChoice.GREATSWORD";
    if (value == 933) return "FeatWeaponOfChoice.HALBERD";
    if (value == 930) return "FeatWeaponOfChoice.HANDAXE";
    if (value == 937) return "FeatWeaponOfChoice.HEAVYFLAIL";
    if (value == 880) return "FeatWeaponOfChoice.KAMA";
    if (value == 939) return "FeatWeaponOfChoice.KATANA";
    if (value == 881) return "FeatWeaponOfChoice.KUKRI";
    if (value == 935) return "FeatWeaponOfChoice.LIGHTFLAIL";
    if (value == 934) return "FeatWeaponOfChoice.LIGHTHAMMER";
    if (value == 921) return "FeatWeaponOfChoice.LIGHTMACE";
    if (value == 928) return "FeatWeaponOfChoice.LONGSWORD";
    if (value == 922) return "FeatWeaponOfChoice.MORNINGSTAR";
    if (value == 923) return "FeatWeaponOfChoice.QUARTERSTAFF";
    if (value == 926) return "FeatWeaponOfChoice.RAPIER";
    if (value == 927) return "FeatWeaponOfChoice.SCIMITAR";
    if (value == 938) return "FeatWeaponOfChoice.SCYTHE";
    if (value == 924) return "FeatWeaponOfChoice.SHORTSPEAR";
    if (value == 925) return "FeatWeaponOfChoice.SHORTSWORD";
    if (value == 879) return "FeatWeaponOfChoice.SICKLE";
    if (value == 1079) return "FeatWeaponOfChoice.TRIDENT";
    if (value == 943) return "FeatWeaponOfChoice.TWOBLADEDSWORD";
    if (value == 936) return "FeatWeaponOfChoice.WARHAMMER";
    if (value == 1000) return "FeatWeaponOfChoice.WHIP";
    return "FeatWeaponOfChoice.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponOfChoice.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponOfChoice.(not found: " + value + ")";
  }
}
