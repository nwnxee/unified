package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_HORSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatHorse {
  private FeatHorse() {}

  public final static int ASSIGN_MOUNT = 1094;
  public final static int DISMOUNT = 1091;
  public final static int MENU = 1089;
  public final static int MOUNT = 1090;
  public final static int PARTY_DISMOUNT = 1093;
  public final static int PARTY_MOUNT = 1092;

  public static String nameOf(int value) {
    if (value == 1094) return "FeatHorse.ASSIGN_MOUNT";
    if (value == 1091) return "FeatHorse.DISMOUNT";
    if (value == 1089) return "FeatHorse.MENU";
    if (value == 1090) return "FeatHorse.MOUNT";
    if (value == 1093) return "FeatHorse.PARTY_DISMOUNT";
    if (value == 1092) return "FeatHorse.PARTY_MOUNT";
    return "FeatHorse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatHorse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatHorse.(not found: " + value + ")";
  }
}
