package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_GREATER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellGreater {
  private IpConstCastspellGreater() {}

  public final static int BULLS_STRENGTH_11 = 300;
  public final static int CATS_GRACE_11 = 301;
  public final static int DISPELLING_15 = 124;
  public final static int DISPELLING_7 = 123;
  public final static int EAGLES_SPLENDOR_11 = 297;
  public final static int ENDURANCE_11 = 302;
  public final static int FOXS_CUNNING_11 = 299;
  public final static int MAGIC_FANG_9 = 384;
  public final static int OWLS_WISDOM_11 = 298;
  public final static int PLANAR_BINDING_15 = 126;
  public final static int RESTORATION_13 = 127;
  public final static int SHADOW_CONJURATION_9 = 128;
  public final static int SPELL_BREACH_11 = 129;
  public final static int SPELL_MANTLE_17 = 130;
  public final static int STONESKIN_11 = 131;

  public static String nameOf(int value) {
    if (value == 300) return "IpConstCastspellGreater.BULLS_STRENGTH_11";
    if (value == 301) return "IpConstCastspellGreater.CATS_GRACE_11";
    if (value == 124) return "IpConstCastspellGreater.DISPELLING_15";
    if (value == 123) return "IpConstCastspellGreater.DISPELLING_7";
    if (value == 297) return "IpConstCastspellGreater.EAGLES_SPLENDOR_11";
    if (value == 302) return "IpConstCastspellGreater.ENDURANCE_11";
    if (value == 299) return "IpConstCastspellGreater.FOXS_CUNNING_11";
    if (value == 384) return "IpConstCastspellGreater.MAGIC_FANG_9";
    if (value == 298) return "IpConstCastspellGreater.OWLS_WISDOM_11";
    if (value == 126) return "IpConstCastspellGreater.PLANAR_BINDING_15";
    if (value == 127) return "IpConstCastspellGreater.RESTORATION_13";
    if (value == 128) return "IpConstCastspellGreater.SHADOW_CONJURATION_9";
    if (value == 129) return "IpConstCastspellGreater.SPELL_BREACH_11";
    if (value == 130) return "IpConstCastspellGreater.SPELL_MANTLE_17";
    if (value == 131) return "IpConstCastspellGreater.STONESKIN_11";
    return "IpConstCastspellGreater.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellGreater.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellGreater.(not found: " + value + ")";
  }
}
