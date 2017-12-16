package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_OF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponOf {
  private FeatWeaponOf() {}

  public final static int CHOICE_BASTARDSWORD = 940;
  public final static int CHOICE_BATTLEAXE = 931;
  public final static int CHOICE_CLUB = 919;
  public final static int CHOICE_DAGGER = 920;
  public final static int CHOICE_DIREMACE = 941;
  public final static int CHOICE_DOUBLEAXE = 942;
  public final static int CHOICE_DWAXE = 959;
  public final static int CHOICE_GREATAXE = 932;
  public final static int CHOICE_GREATSWORD = 929;
  public final static int CHOICE_HALBERD = 933;
  public final static int CHOICE_HANDAXE = 930;
  public final static int CHOICE_HEAVYFLAIL = 937;
  public final static int CHOICE_KAMA = 880;
  public final static int CHOICE_KATANA = 939;
  public final static int CHOICE_KUKRI = 881;
  public final static int CHOICE_LIGHTFLAIL = 935;
  public final static int CHOICE_LIGHTHAMMER = 934;
  public final static int CHOICE_LIGHTMACE = 921;
  public final static int CHOICE_LONGSWORD = 928;
  public final static int CHOICE_MORNINGSTAR = 922;
  public final static int CHOICE_QUARTERSTAFF = 923;
  public final static int CHOICE_RAPIER = 926;
  public final static int CHOICE_SCIMITAR = 927;
  public final static int CHOICE_SCYTHE = 938;
  public final static int CHOICE_SHORTSPEAR = 924;
  public final static int CHOICE_SHORTSWORD = 925;
  public final static int CHOICE_SICKLE = 879;
  public final static int CHOICE_TRIDENT = 1079;
  public final static int CHOICE_TWOBLADEDSWORD = 943;
  public final static int CHOICE_WARHAMMER = 936;
  public final static int CHOICE_WHIP = 1000;

  public static String nameOf(int value) {
    if (value == 940) return "FeatWeaponOf.CHOICE_BASTARDSWORD";
    if (value == 931) return "FeatWeaponOf.CHOICE_BATTLEAXE";
    if (value == 919) return "FeatWeaponOf.CHOICE_CLUB";
    if (value == 920) return "FeatWeaponOf.CHOICE_DAGGER";
    if (value == 941) return "FeatWeaponOf.CHOICE_DIREMACE";
    if (value == 942) return "FeatWeaponOf.CHOICE_DOUBLEAXE";
    if (value == 959) return "FeatWeaponOf.CHOICE_DWAXE";
    if (value == 932) return "FeatWeaponOf.CHOICE_GREATAXE";
    if (value == 929) return "FeatWeaponOf.CHOICE_GREATSWORD";
    if (value == 933) return "FeatWeaponOf.CHOICE_HALBERD";
    if (value == 930) return "FeatWeaponOf.CHOICE_HANDAXE";
    if (value == 937) return "FeatWeaponOf.CHOICE_HEAVYFLAIL";
    if (value == 880) return "FeatWeaponOf.CHOICE_KAMA";
    if (value == 939) return "FeatWeaponOf.CHOICE_KATANA";
    if (value == 881) return "FeatWeaponOf.CHOICE_KUKRI";
    if (value == 935) return "FeatWeaponOf.CHOICE_LIGHTFLAIL";
    if (value == 934) return "FeatWeaponOf.CHOICE_LIGHTHAMMER";
    if (value == 921) return "FeatWeaponOf.CHOICE_LIGHTMACE";
    if (value == 928) return "FeatWeaponOf.CHOICE_LONGSWORD";
    if (value == 922) return "FeatWeaponOf.CHOICE_MORNINGSTAR";
    if (value == 923) return "FeatWeaponOf.CHOICE_QUARTERSTAFF";
    if (value == 926) return "FeatWeaponOf.CHOICE_RAPIER";
    if (value == 927) return "FeatWeaponOf.CHOICE_SCIMITAR";
    if (value == 938) return "FeatWeaponOf.CHOICE_SCYTHE";
    if (value == 924) return "FeatWeaponOf.CHOICE_SHORTSPEAR";
    if (value == 925) return "FeatWeaponOf.CHOICE_SHORTSWORD";
    if (value == 879) return "FeatWeaponOf.CHOICE_SICKLE";
    if (value == 1079) return "FeatWeaponOf.CHOICE_TRIDENT";
    if (value == 943) return "FeatWeaponOf.CHOICE_TWOBLADEDSWORD";
    if (value == 936) return "FeatWeaponOf.CHOICE_WARHAMMER";
    if (value == 1000) return "FeatWeaponOf.CHOICE_WHIP";
    return "FeatWeaponOf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponOf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponOf.(not found: " + value + ")";
  }
}
