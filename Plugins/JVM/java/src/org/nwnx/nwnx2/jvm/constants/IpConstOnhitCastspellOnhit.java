package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ONHIT_CASTSPELL_ONHIT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstOnhitCastspellOnhit {
  private IpConstOnhitCastspellOnhit() {}

  public final static int CHAOSSHIELD = 130;
  public final static int CONSTRICTWEAPON = 131;
  public final static int DARKFIRE = 127;
  public final static int EXTRACTBRAIN = 128;
  public final static int FIREDAMAGE = 124;
  public final static int PLANARRIFT = 126;
  public final static int SLAYRAKSHASA = 123;
  public final static int TELEPORT = 122;
  public final static int UNIQUEPOWER = 125;

  public static String nameOf(int value) {
    if (value == 130) return "IpConstOnhitCastspellOnhit.CHAOSSHIELD";
    if (value == 131) return "IpConstOnhitCastspellOnhit.CONSTRICTWEAPON";
    if (value == 127) return "IpConstOnhitCastspellOnhit.DARKFIRE";
    if (value == 128) return "IpConstOnhitCastspellOnhit.EXTRACTBRAIN";
    if (value == 124) return "IpConstOnhitCastspellOnhit.FIREDAMAGE";
    if (value == 126) return "IpConstOnhitCastspellOnhit.PLANARRIFT";
    if (value == 123) return "IpConstOnhitCastspellOnhit.SLAYRAKSHASA";
    if (value == 122) return "IpConstOnhitCastspellOnhit.TELEPORT";
    if (value == 125) return "IpConstOnhitCastspellOnhit.UNIQUEPOWER";
    return "IpConstOnhitCastspellOnhit.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstOnhitCastspellOnhit.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstOnhitCastspellOnhit.(not found: " + value + ")";
  }
}
