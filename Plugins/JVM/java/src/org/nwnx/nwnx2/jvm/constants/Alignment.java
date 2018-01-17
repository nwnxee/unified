package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ALIGNMENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Alignment {
  private Alignment() {}

  public final static int ALL = 0;
  public final static int CHAOTIC = 3;
  public final static int EVIL = 5;
  public final static int GOOD = 4;
  public final static int LAWFUL = 2;
  public final static int NEUTRAL = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Alignment.ALL";
    if (value == 3) return "Alignment.CHAOTIC";
    if (value == 5) return "Alignment.EVIL";
    if (value == 4) return "Alignment.GOOD";
    if (value == 2) return "Alignment.LAWFUL";
    if (value == 1) return "Alignment.NEUTRAL";
    return "Alignment.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Alignment.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Alignment.(not found: " + value + ")";
  }
}
