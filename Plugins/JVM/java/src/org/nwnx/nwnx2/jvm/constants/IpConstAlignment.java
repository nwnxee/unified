package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ALIGNMENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstAlignment {
  private IpConstAlignment() {}

  public final static int CE = 8;
  public final static int CG = 6;
  public final static int CN = 7;
  public final static int LE = 2;
  public final static int LG = 0;
  public final static int LN = 1;
  public final static int NE = 5;
  public final static int NG = 3;
  public final static int TN = 4;

  public static String nameOf(int value) {
    if (value == 8) return "IpConstAlignment.CE";
    if (value == 6) return "IpConstAlignment.CG";
    if (value == 7) return "IpConstAlignment.CN";
    if (value == 2) return "IpConstAlignment.LE";
    if (value == 0) return "IpConstAlignment.LG";
    if (value == 1) return "IpConstAlignment.LN";
    if (value == 5) return "IpConstAlignment.NE";
    if (value == 3) return "IpConstAlignment.NG";
    if (value == 4) return "IpConstAlignment.TN";
    return "IpConstAlignment.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstAlignment.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstAlignment.(not found: " + value + ")";
  }
}
