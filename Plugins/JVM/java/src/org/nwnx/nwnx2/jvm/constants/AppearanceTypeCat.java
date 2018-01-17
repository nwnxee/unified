package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_CAT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeCat {
  private AppearanceTypeCat() {}

  public final static int CAT_DIRE = 95;
  public final static int COUGAR = 203;
  public final static int CRAG_CAT = 94;
  public final static int JAGUAR = 98;
  public final static int KRENSHAR = 96;
  public final static int LEOPARD = 93;
  public final static int LION = 97;
  public final static int MPANTHER = 306;
  public final static int PANTHER = 202;

  public static String nameOf(int value) {
    if (value == 95) return "AppearanceTypeCat.CAT_DIRE";
    if (value == 203) return "AppearanceTypeCat.COUGAR";
    if (value == 94) return "AppearanceTypeCat.CRAG_CAT";
    if (value == 98) return "AppearanceTypeCat.JAGUAR";
    if (value == 96) return "AppearanceTypeCat.KRENSHAR";
    if (value == 93) return "AppearanceTypeCat.LEOPARD";
    if (value == 97) return "AppearanceTypeCat.LION";
    if (value == 306) return "AppearanceTypeCat.MPANTHER";
    if (value == 202) return "AppearanceTypeCat.PANTHER";
    return "AppearanceTypeCat.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeCat.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeCat.(not found: " + value + ")";
  }
}
