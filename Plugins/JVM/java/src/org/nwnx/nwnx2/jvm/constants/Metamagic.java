package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "METAMAGIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Metamagic {
  private Metamagic() {}

  public final static int ANY = 255;
  public final static int EMPOWER = 1;
  public final static int EXTEND = 2;
  public final static int MAXIMIZE = 4;
  public final static int NONE = 0;
  public final static int QUICKEN = 8;
  public final static int SILENT = 16;
  public final static int STILL = 32;

  public static String nameOf(int value) {
    if (value == 255) return "Metamagic.ANY";
    if (value == 1) return "Metamagic.EMPOWER";
    if (value == 2) return "Metamagic.EXTEND";
    if (value == 4) return "Metamagic.MAXIMIZE";
    if (value == 0) return "Metamagic.NONE";
    if (value == 8) return "Metamagic.QUICKEN";
    if (value == 16) return "Metamagic.SILENT";
    if (value == 32) return "Metamagic.STILL";
    return "Metamagic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Metamagic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Metamagic.(not found: " + value + ")";
  }
}
