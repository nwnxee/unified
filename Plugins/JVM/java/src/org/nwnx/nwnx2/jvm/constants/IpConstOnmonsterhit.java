package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ONMONSTERHIT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstOnmonsterhit {
  private IpConstOnmonsterhit() {}

  public final static int ABILITYDRAIN = 0;
  public final static int CONFUSION = 1;
  public final static int DISEASE = 2;
  public final static int DOOM = 3;
  public final static int FEAR = 4;
  public final static int LEVELDRAIN = 5;
  public final static int POISON = 6;
  public final static int SLOW = 7;
  public final static int STUN = 8;
  public final static int WOUNDING = 9;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstOnmonsterhit.ABILITYDRAIN";
    if (value == 1) return "IpConstOnmonsterhit.CONFUSION";
    if (value == 2) return "IpConstOnmonsterhit.DISEASE";
    if (value == 3) return "IpConstOnmonsterhit.DOOM";
    if (value == 4) return "IpConstOnmonsterhit.FEAR";
    if (value == 5) return "IpConstOnmonsterhit.LEVELDRAIN";
    if (value == 6) return "IpConstOnmonsterhit.POISON";
    if (value == 7) return "IpConstOnmonsterhit.SLOW";
    if (value == 8) return "IpConstOnmonsterhit.STUN";
    if (value == 9) return "IpConstOnmonsterhit.WOUNDING";
    return "IpConstOnmonsterhit.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstOnmonsterhit.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstOnmonsterhit.(not found: " + value + ")";
  }
}
