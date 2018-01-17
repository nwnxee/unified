package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "BODY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Body {
  private Body() {}

  public final static int NODE_CHEST = 1;
  public final static int NODE_HAND = 0;
  public final static int NODE_MONSTER_0 = 2;
  public final static int NODE_MONSTER_1 = 3;
  public final static int NODE_MONSTER_2 = 4;
  public final static int NODE_MONSTER_3 = 5;
  public final static int NODE_MONSTER_4 = 6;
  public final static int NODE_MONSTER_5 = 7;
  public final static int NODE_MONSTER_6 = 8;
  public final static int NODE_MONSTER_7 = 9;
  public final static int NODE_MONSTER_8 = 10;
  public final static int NODE_MONSTER_9 = 11;

  public static String nameOf(int value) {
    if (value == 1) return "Body.NODE_CHEST";
    if (value == 0) return "Body.NODE_HAND";
    if (value == 2) return "Body.NODE_MONSTER_0";
    if (value == 3) return "Body.NODE_MONSTER_1";
    if (value == 4) return "Body.NODE_MONSTER_2";
    if (value == 5) return "Body.NODE_MONSTER_3";
    if (value == 6) return "Body.NODE_MONSTER_4";
    if (value == 7) return "Body.NODE_MONSTER_5";
    if (value == 8) return "Body.NODE_MONSTER_6";
    if (value == 9) return "Body.NODE_MONSTER_7";
    if (value == 10) return "Body.NODE_MONSTER_8";
    if (value == 11) return "Body.NODE_MONSTER_9";
    return "Body.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Body.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Body.(not found: " + value + ")";
  }
}
