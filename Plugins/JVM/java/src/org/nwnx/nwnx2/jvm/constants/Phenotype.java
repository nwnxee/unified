package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PHENOTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Phenotype {
  private Phenotype() {}

  public final static int BIG = 2;
  public final static int CUSTOM1 = 3;
  public final static int CUSTOM10 = 12;
  public final static int CUSTOM11 = 13;
  public final static int CUSTOM12 = 14;
  public final static int CUSTOM13 = 15;
  public final static int CUSTOM14 = 16;
  public final static int CUSTOM15 = 17;
  public final static int CUSTOM16 = 18;
  public final static int CUSTOM17 = 19;
  public final static int CUSTOM18 = 20;
  public final static int CUSTOM2 = 4;
  public final static int CUSTOM3 = 5;
  public final static int CUSTOM4 = 6;
  public final static int CUSTOM5 = 7;
  public final static int CUSTOM6 = 8;
  public final static int CUSTOM7 = 9;
  public final static int CUSTOM8 = 10;
  public final static int CUSTOM9 = 11;
  public final static int NORMAL = 0;

  public static String nameOf(int value) {
    if (value == 2) return "Phenotype.BIG";
    if (value == 3) return "Phenotype.CUSTOM1";
    if (value == 12) return "Phenotype.CUSTOM10";
    if (value == 13) return "Phenotype.CUSTOM11";
    if (value == 14) return "Phenotype.CUSTOM12";
    if (value == 15) return "Phenotype.CUSTOM13";
    if (value == 16) return "Phenotype.CUSTOM14";
    if (value == 17) return "Phenotype.CUSTOM15";
    if (value == 18) return "Phenotype.CUSTOM16";
    if (value == 19) return "Phenotype.CUSTOM17";
    if (value == 20) return "Phenotype.CUSTOM18";
    if (value == 4) return "Phenotype.CUSTOM2";
    if (value == 5) return "Phenotype.CUSTOM3";
    if (value == 6) return "Phenotype.CUSTOM4";
    if (value == 7) return "Phenotype.CUSTOM5";
    if (value == 8) return "Phenotype.CUSTOM6";
    if (value == 9) return "Phenotype.CUSTOM7";
    if (value == 10) return "Phenotype.CUSTOM8";
    if (value == 11) return "Phenotype.CUSTOM9";
    if (value == 0) return "Phenotype.NORMAL";
    return "Phenotype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Phenotype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Phenotype.(not found: " + value + ")";
  }
}
