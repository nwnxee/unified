package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_RESIST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatResist {
  private FeatResist() {}

  public final static int DISEASE = 426;
  public final static int ENERGY_ACID = 428;
  public final static int ENERGY_COLD = 427;
  public final static int ENERGY_ELECTRICAL = 430;
  public final static int ENERGY_FIRE = 429;
  public final static int ENERGY_SONIC = 431;
  public final static int NATURES_LURE = 202;
  public final static int POISON = 383;

  public static String nameOf(int value) {
    if (value == 426) return "FeatResist.DISEASE";
    if (value == 428) return "FeatResist.ENERGY_ACID";
    if (value == 427) return "FeatResist.ENERGY_COLD";
    if (value == 430) return "FeatResist.ENERGY_ELECTRICAL";
    if (value == 429) return "FeatResist.ENERGY_FIRE";
    if (value == 431) return "FeatResist.ENERGY_SONIC";
    if (value == 202) return "FeatResist.NATURES_LURE";
    if (value == 383) return "FeatResist.POISON";
    return "FeatResist.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatResist.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatResist.(not found: " + value + ")";
  }
}
