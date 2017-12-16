package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "BODY_NODE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class BodyNode {
  private BodyNode() {}

  public final static int CHEST = 1;
  public final static int HAND = 0;
  public final static int MONSTER_0 = 2;
  public final static int MONSTER_1 = 3;
  public final static int MONSTER_2 = 4;
  public final static int MONSTER_3 = 5;
  public final static int MONSTER_4 = 6;
  public final static int MONSTER_5 = 7;
  public final static int MONSTER_6 = 8;
  public final static int MONSTER_7 = 9;
  public final static int MONSTER_8 = 10;
  public final static int MONSTER_9 = 11;

  public static String nameOf(int value) {
    if (value == 1) return "BodyNode.CHEST";
    if (value == 0) return "BodyNode.HAND";
    if (value == 2) return "BodyNode.MONSTER_0";
    if (value == 3) return "BodyNode.MONSTER_1";
    if (value == 4) return "BodyNode.MONSTER_2";
    if (value == 5) return "BodyNode.MONSTER_3";
    if (value == 6) return "BodyNode.MONSTER_4";
    if (value == 7) return "BodyNode.MONSTER_5";
    if (value == 8) return "BodyNode.MONSTER_6";
    if (value == 9) return "BodyNode.MONSTER_7";
    if (value == 10) return "BodyNode.MONSTER_8";
    if (value == 11) return "BodyNode.MONSTER_9";
    return "BodyNode.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "BodyNode.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "BodyNode.(not found: " + value + ")";
  }
}
