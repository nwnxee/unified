package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_OBJECT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeObject {
  private AppearanceTypeObject() {}

  public final static int BLUE = 436;
  public final static int BOAT = 473;
  public final static int CANDLE = 433;
  public final static int CHAIR = 431;
  public final static int CHEST = 434;
  public final static int CYAN = 437;
  public final static int FLAME_LARGE = 445;
  public final static int FLAME_MEDIUM = 444;
  public final static int FLAME_SMALL = 443;
  public final static int GREEN = 438;
  public final static int ORANGE = 440;
  public final static int PURPLE = 442;
  public final static int RED = 441;
  public final static int TABLE = 432;
  public final static int WHITE = 435;
  public final static int YELLOW = 439;

  public static String nameOf(int value) {
    if (value == 436) return "AppearanceTypeObject.BLUE";
    if (value == 473) return "AppearanceTypeObject.BOAT";
    if (value == 433) return "AppearanceTypeObject.CANDLE";
    if (value == 431) return "AppearanceTypeObject.CHAIR";
    if (value == 434) return "AppearanceTypeObject.CHEST";
    if (value == 437) return "AppearanceTypeObject.CYAN";
    if (value == 445) return "AppearanceTypeObject.FLAME_LARGE";
    if (value == 444) return "AppearanceTypeObject.FLAME_MEDIUM";
    if (value == 443) return "AppearanceTypeObject.FLAME_SMALL";
    if (value == 438) return "AppearanceTypeObject.GREEN";
    if (value == 440) return "AppearanceTypeObject.ORANGE";
    if (value == 442) return "AppearanceTypeObject.PURPLE";
    if (value == 441) return "AppearanceTypeObject.RED";
    if (value == 432) return "AppearanceTypeObject.TABLE";
    if (value == 435) return "AppearanceTypeObject.WHITE";
    if (value == 439) return "AppearanceTypeObject.YELLOW";
    return "AppearanceTypeObject.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeObject.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeObject.(not found: " + value + ")";
  }
}
