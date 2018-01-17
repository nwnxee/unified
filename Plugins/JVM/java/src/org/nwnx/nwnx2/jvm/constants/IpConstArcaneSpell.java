package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ARCANE_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstArcaneSpell {
  private IpConstArcaneSpell() {}

  public final static int FAILURE_MINUS_10_PERCENT = 8;
  public final static int FAILURE_MINUS_15_PERCENT = 7;
  public final static int FAILURE_MINUS_20_PERCENT = 6;
  public final static int FAILURE_MINUS_25_PERCENT = 5;
  public final static int FAILURE_MINUS_30_PERCENT = 4;
  public final static int FAILURE_MINUS_35_PERCENT = 3;
  public final static int FAILURE_MINUS_40_PERCENT = 2;
  public final static int FAILURE_MINUS_45_PERCENT = 1;
  public final static int FAILURE_MINUS_50_PERCENT = 0;
  public final static int FAILURE_MINUS_5_PERCENT = 9;
  public final static int FAILURE_PLUS_10_PERCENT = 11;
  public final static int FAILURE_PLUS_15_PERCENT = 12;
  public final static int FAILURE_PLUS_20_PERCENT = 13;
  public final static int FAILURE_PLUS_25_PERCENT = 14;
  public final static int FAILURE_PLUS_30_PERCENT = 15;
  public final static int FAILURE_PLUS_35_PERCENT = 16;
  public final static int FAILURE_PLUS_40_PERCENT = 17;
  public final static int FAILURE_PLUS_45_PERCENT = 18;
  public final static int FAILURE_PLUS_50_PERCENT = 19;
  public final static int FAILURE_PLUS_5_PERCENT = 10;

  public static String nameOf(int value) {
    if (value == 8) return "IpConstArcaneSpell.FAILURE_MINUS_10_PERCENT";
    if (value == 7) return "IpConstArcaneSpell.FAILURE_MINUS_15_PERCENT";
    if (value == 6) return "IpConstArcaneSpell.FAILURE_MINUS_20_PERCENT";
    if (value == 5) return "IpConstArcaneSpell.FAILURE_MINUS_25_PERCENT";
    if (value == 4) return "IpConstArcaneSpell.FAILURE_MINUS_30_PERCENT";
    if (value == 3) return "IpConstArcaneSpell.FAILURE_MINUS_35_PERCENT";
    if (value == 2) return "IpConstArcaneSpell.FAILURE_MINUS_40_PERCENT";
    if (value == 1) return "IpConstArcaneSpell.FAILURE_MINUS_45_PERCENT";
    if (value == 0) return "IpConstArcaneSpell.FAILURE_MINUS_50_PERCENT";
    if (value == 9) return "IpConstArcaneSpell.FAILURE_MINUS_5_PERCENT";
    if (value == 11) return "IpConstArcaneSpell.FAILURE_PLUS_10_PERCENT";
    if (value == 12) return "IpConstArcaneSpell.FAILURE_PLUS_15_PERCENT";
    if (value == 13) return "IpConstArcaneSpell.FAILURE_PLUS_20_PERCENT";
    if (value == 14) return "IpConstArcaneSpell.FAILURE_PLUS_25_PERCENT";
    if (value == 15) return "IpConstArcaneSpell.FAILURE_PLUS_30_PERCENT";
    if (value == 16) return "IpConstArcaneSpell.FAILURE_PLUS_35_PERCENT";
    if (value == 17) return "IpConstArcaneSpell.FAILURE_PLUS_40_PERCENT";
    if (value == 18) return "IpConstArcaneSpell.FAILURE_PLUS_45_PERCENT";
    if (value == 19) return "IpConstArcaneSpell.FAILURE_PLUS_50_PERCENT";
    if (value == 10) return "IpConstArcaneSpell.FAILURE_PLUS_5_PERCENT";
    return "IpConstArcaneSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstArcaneSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstArcaneSpell.(not found: " + value + ")";
  }
}
