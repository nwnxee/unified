package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE_WYRMLING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphTypeWyrmling {
  private PolymorphTypeWyrmling() {}

  public final static int BLACK = 56;
  public final static int BLUE = 53;
  public final static int GREEN = 55;
  public final static int RED = 54;
  public final static int WHITE = 52;

  public static String nameOf(int value) {
    if (value == 56) return "PolymorphTypeWyrmling.BLACK";
    if (value == 53) return "PolymorphTypeWyrmling.BLUE";
    if (value == 55) return "PolymorphTypeWyrmling.GREEN";
    if (value == 54) return "PolymorphTypeWyrmling.RED";
    if (value == 52) return "PolymorphTypeWyrmling.WHITE";
    return "PolymorphTypeWyrmling.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphTypeWyrmling.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphTypeWyrmling.(not found: " + value + ")";
  }
}
