package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_ARMOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprArmor {
  private ItemApprArmor() {}

  public final static int COLOR_CLOTH1 = 2;
  public final static int COLOR_CLOTH2 = 3;
  public final static int COLOR_LEATHER1 = 0;
  public final static int COLOR_LEATHER2 = 1;
  public final static int COLOR_METAL1 = 4;
  public final static int COLOR_METAL2 = 5;
  public final static int MODEL_BELT = 8;
  public final static int MODEL_LBICEP = 13;
  public final static int MODEL_LFOOT = 1;
  public final static int MODEL_LFOREARM = 11;
  public final static int MODEL_LHAND = 17;
  public final static int MODEL_LSHIN = 3;
  public final static int MODEL_LSHOULDER = 15;
  public final static int MODEL_LTHIGH = 4;
  public final static int MODEL_NECK = 9;
  public final static int MODEL_PELVIS = 6;
  public final static int MODEL_RBICEP = 12;
  public final static int MODEL_RFOOT = 0;
  public final static int MODEL_RFOREARM = 10;
  public final static int MODEL_RHAND = 16;
  public final static int MODEL_ROBE = 18;
  public final static int MODEL_RSHIN = 2;
  public final static int MODEL_RSHOULDER = 14;
  public final static int MODEL_RTHIGH = 5;
  public final static int MODEL_TORSO = 7;
  public final static int NUM_COLORS = 6;
  public final static int NUM_MODELS = 19;

  public static String nameOf(int value) {
    if (value == 2) return "ItemApprArmor.COLOR_CLOTH1";
    if (value == 3) return "ItemApprArmor.COLOR_CLOTH2";
    if (value == 0) return "ItemApprArmor.COLOR_LEATHER1";
    if (value == 1) return "ItemApprArmor.COLOR_LEATHER2";
    if (value == 4) return "ItemApprArmor.COLOR_METAL1";
    if (value == 5) return "ItemApprArmor.COLOR_METAL2";
    if (value == 8) return "ItemApprArmor.MODEL_BELT";
    if (value == 13) return "ItemApprArmor.MODEL_LBICEP";
    if (value == 1) return "ItemApprArmor.MODEL_LFOOT";
    if (value == 11) return "ItemApprArmor.MODEL_LFOREARM";
    if (value == 17) return "ItemApprArmor.MODEL_LHAND";
    if (value == 3) return "ItemApprArmor.MODEL_LSHIN";
    if (value == 15) return "ItemApprArmor.MODEL_LSHOULDER";
    if (value == 4) return "ItemApprArmor.MODEL_LTHIGH";
    if (value == 9) return "ItemApprArmor.MODEL_NECK";
    if (value == 6) return "ItemApprArmor.MODEL_PELVIS";
    if (value == 12) return "ItemApprArmor.MODEL_RBICEP";
    if (value == 0) return "ItemApprArmor.MODEL_RFOOT";
    if (value == 10) return "ItemApprArmor.MODEL_RFOREARM";
    if (value == 16) return "ItemApprArmor.MODEL_RHAND";
    if (value == 18) return "ItemApprArmor.MODEL_ROBE";
    if (value == 2) return "ItemApprArmor.MODEL_RSHIN";
    if (value == 14) return "ItemApprArmor.MODEL_RSHOULDER";
    if (value == 5) return "ItemApprArmor.MODEL_RTHIGH";
    if (value == 7) return "ItemApprArmor.MODEL_TORSO";
    if (value == 6) return "ItemApprArmor.NUM_COLORS";
    if (value == 19) return "ItemApprArmor.NUM_MODELS";
    return "ItemApprArmor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprArmor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprArmor.(not found: " + value + ")";
  }
}
