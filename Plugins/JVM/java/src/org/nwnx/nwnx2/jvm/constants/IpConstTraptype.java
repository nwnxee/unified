package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_TRAPTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstTraptype {
  private IpConstTraptype() {}

  public final static int ACID_SPLASH = 9;
  public final static int BLOBOFACID = 4;
  public final static int ELECTRICAL = 6;
  public final static int FIRE = 5;
  public final static int FROST = 8;
  public final static int GAS = 7;
  public final static int HOLY = 2;
  public final static int NEGATIVE = 11;
  public final static int SONIC = 10;
  public final static int SPIKE = 1;
  public final static int TANGLE = 3;

  public static String nameOf(int value) {
    if (value == 9) return "IpConstTraptype.ACID_SPLASH";
    if (value == 4) return "IpConstTraptype.BLOBOFACID";
    if (value == 6) return "IpConstTraptype.ELECTRICAL";
    if (value == 5) return "IpConstTraptype.FIRE";
    if (value == 8) return "IpConstTraptype.FROST";
    if (value == 7) return "IpConstTraptype.GAS";
    if (value == 2) return "IpConstTraptype.HOLY";
    if (value == 11) return "IpConstTraptype.NEGATIVE";
    if (value == 10) return "IpConstTraptype.SONIC";
    if (value == 1) return "IpConstTraptype.SPIKE";
    if (value == 3) return "IpConstTraptype.TANGLE";
    return "IpConstTraptype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstTraptype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstTraptype.(not found: " + value + ")";
  }
}
