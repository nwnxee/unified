package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_VISUAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemVisual {
  private ItemVisual() {}

  public final static int ACID = 0;
  public final static int COLD = 1;
  public final static int ELECTRICAL = 2;
  public final static int EVIL = 6;
  public final static int FIRE = 3;
  public final static int HOLY = 5;
  public final static int SONIC = 4;

  public static String nameOf(int value) {
    if (value == 0) return "ItemVisual.ACID";
    if (value == 1) return "ItemVisual.COLD";
    if (value == 2) return "ItemVisual.ELECTRICAL";
    if (value == 6) return "ItemVisual.EVIL";
    if (value == 3) return "ItemVisual.FIRE";
    if (value == 5) return "ItemVisual.HOLY";
    if (value == 4) return "ItemVisual.SONIC";
    return "ItemVisual.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemVisual.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemVisual.(not found: " + value + ")";
  }
}
