package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_ARMOR_MODEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprArmorModel {
  private ItemApprArmorModel() {}

  public final static int BELT = 8;
  public final static int LBICEP = 13;
  public final static int LFOOT = 1;
  public final static int LFOREARM = 11;
  public final static int LHAND = 17;
  public final static int LSHIN = 3;
  public final static int LSHOULDER = 15;
  public final static int LTHIGH = 4;
  public final static int NECK = 9;
  public final static int PELVIS = 6;
  public final static int RBICEP = 12;
  public final static int RFOOT = 0;
  public final static int RFOREARM = 10;
  public final static int RHAND = 16;
  public final static int ROBE = 18;
  public final static int RSHIN = 2;
  public final static int RSHOULDER = 14;
  public final static int RTHIGH = 5;
  public final static int TORSO = 7;

  public static String nameOf(int value) {
    if (value == 8) return "ItemApprArmorModel.BELT";
    if (value == 13) return "ItemApprArmorModel.LBICEP";
    if (value == 1) return "ItemApprArmorModel.LFOOT";
    if (value == 11) return "ItemApprArmorModel.LFOREARM";
    if (value == 17) return "ItemApprArmorModel.LHAND";
    if (value == 3) return "ItemApprArmorModel.LSHIN";
    if (value == 15) return "ItemApprArmorModel.LSHOULDER";
    if (value == 4) return "ItemApprArmorModel.LTHIGH";
    if (value == 9) return "ItemApprArmorModel.NECK";
    if (value == 6) return "ItemApprArmorModel.PELVIS";
    if (value == 12) return "ItemApprArmorModel.RBICEP";
    if (value == 0) return "ItemApprArmorModel.RFOOT";
    if (value == 10) return "ItemApprArmorModel.RFOREARM";
    if (value == 16) return "ItemApprArmorModel.RHAND";
    if (value == 18) return "ItemApprArmorModel.ROBE";
    if (value == 2) return "ItemApprArmorModel.RSHIN";
    if (value == 14) return "ItemApprArmorModel.RSHOULDER";
    if (value == 5) return "ItemApprArmorModel.RTHIGH";
    if (value == 7) return "ItemApprArmorModel.TORSO";
    return "ItemApprArmorModel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprArmorModel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprArmorModel.(not found: " + value + ")";
  }
}
