package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_DRAGON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatDragon {
  private FeatDragon() {}

  public final static int ABILITIES = 962;
  public final static int ARMOR = 961;
  public final static int DIS_BREATH = 965;
  public final static int HDINCREASE_D10 = 1044;
  public final static int HDINCREASE_D6 = 1042;
  public final static int HDINCREASE_D8 = 1043;
  public final static int IMMUNE_FIRE = 964;
  public final static int IMMUNE_PARALYSIS = 963;

  public static String nameOf(int value) {
    if (value == 962) return "FeatDragon.ABILITIES";
    if (value == 961) return "FeatDragon.ARMOR";
    if (value == 965) return "FeatDragon.DIS_BREATH";
    if (value == 1044) return "FeatDragon.HDINCREASE_D10";
    if (value == 1042) return "FeatDragon.HDINCREASE_D6";
    if (value == 1043) return "FeatDragon.HDINCREASE_D8";
    if (value == 964) return "FeatDragon.IMMUNE_FIRE";
    if (value == 963) return "FeatDragon.IMMUNE_PARALYSIS";
    return "FeatDragon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatDragon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatDragon.(not found: " + value + ")";
  }
}
