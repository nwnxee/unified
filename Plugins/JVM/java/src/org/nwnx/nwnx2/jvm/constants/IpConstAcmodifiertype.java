package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ACMODIFIERTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstAcmodifiertype {
  private IpConstAcmodifiertype() {}

  public final static int ARMOR = 2;
  public final static int DEFLECTION = 4;
  public final static int DODGE = 0;
  public final static int NATURAL = 1;
  public final static int SHIELD = 3;

  public static String nameOf(int value) {
    if (value == 2) return "IpConstAcmodifiertype.ARMOR";
    if (value == 4) return "IpConstAcmodifiertype.DEFLECTION";
    if (value == 0) return "IpConstAcmodifiertype.DODGE";
    if (value == 1) return "IpConstAcmodifiertype.NATURAL";
    if (value == 3) return "IpConstAcmodifiertype.SHIELD";
    return "IpConstAcmodifiertype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstAcmodifiertype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstAcmodifiertype.(not found: " + value + ")";
  }
}
