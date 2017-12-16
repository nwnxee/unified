package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SUBTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Subtype {
  private Subtype() {}

  public final static int EXTRAORDINARY = 24;
  public final static int MAGICAL = 8;
  public final static int SUPERNATURAL = 16;

  public static String nameOf(int value) {
    if (value == 24) return "Subtype.EXTRAORDINARY";
    if (value == 8) return "Subtype.MAGICAL";
    if (value == 16) return "Subtype.SUPERNATURAL";
    return "Subtype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Subtype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Subtype.(not found: " + value + ")";
  }
}
