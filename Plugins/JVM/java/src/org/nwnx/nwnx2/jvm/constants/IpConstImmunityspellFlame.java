package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_FLAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellFlame {
  private IpConstImmunityspellFlame() {}

  public final static int ARROW = 54;
  public final static int LASH = 55;
  public final static int STRIKE = 56;

  public static String nameOf(int value) {
    if (value == 54) return "IpConstImmunityspellFlame.ARROW";
    if (value == 55) return "IpConstImmunityspellFlame.LASH";
    if (value == 56) return "IpConstImmunityspellFlame.STRIKE";
    return "IpConstImmunityspellFlame.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellFlame.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellFlame.(not found: " + value + ")";
  }
}
