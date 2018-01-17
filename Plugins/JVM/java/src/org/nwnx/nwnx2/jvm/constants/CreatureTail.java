package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_TAIL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureTail {
  private CreatureTail() {}

  public final static int TYPE_BONE = 2;
  public final static int TYPE_DEVIL = 3;
  public final static int TYPE_LIZARD = 1;
  public final static int TYPE_NONE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "CreatureTail.TYPE_BONE";
    if (value == 3) return "CreatureTail.TYPE_DEVIL";
    if (value == 1) return "CreatureTail.TYPE_LIZARD";
    if (value == 0) return "CreatureTail.TYPE_NONE";
    return "CreatureTail.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureTail.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureTail.(not found: " + value + ")";
  }
}
