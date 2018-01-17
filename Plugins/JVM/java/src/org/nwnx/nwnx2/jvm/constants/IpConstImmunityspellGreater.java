package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_GREATER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellGreater {
  private IpConstImmunityspellGreater() {}

  public final static int BULLS_STRENGTH = 179;
  public final static int CATS_GRACE = 180;
  public final static int DISPELLING = 60;
  public final static int EAGLES_SPLENDOR = 176;
  public final static int ENDURANCE = 181;
  public final static int FOXS_CUNNING = 178;
  public final static int OWLS_WISDOM = 177;
  public final static int PLANAR_BINDING = 62;
  public final static int SHADOW_CONJURATION = 64;
  public final static int SPELL_BREACH = 65;

  public static String nameOf(int value) {
    if (value == 179) return "IpConstImmunityspellGreater.BULLS_STRENGTH";
    if (value == 180) return "IpConstImmunityspellGreater.CATS_GRACE";
    if (value == 60) return "IpConstImmunityspellGreater.DISPELLING";
    if (value == 176) return "IpConstImmunityspellGreater.EAGLES_SPLENDOR";
    if (value == 181) return "IpConstImmunityspellGreater.ENDURANCE";
    if (value == 178) return "IpConstImmunityspellGreater.FOXS_CUNNING";
    if (value == 177) return "IpConstImmunityspellGreater.OWLS_WISDOM";
    if (value == 62) return "IpConstImmunityspellGreater.PLANAR_BINDING";
    if (value == 64) return "IpConstImmunityspellGreater.SHADOW_CONJURATION";
    if (value == 65) return "IpConstImmunityspellGreater.SPELL_BREACH";
    return "IpConstImmunityspellGreater.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellGreater.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellGreater.(not found: " + value + ")";
  }
}
