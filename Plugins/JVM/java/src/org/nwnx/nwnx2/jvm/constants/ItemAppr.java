package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemAppr {
  private ItemAppr() {}

  public final static int ARMOR_COLOR_CLOTH1 = 2;
  public final static int ARMOR_COLOR_CLOTH2 = 3;
  public final static int ARMOR_COLOR_LEATHER1 = 0;
  public final static int ARMOR_COLOR_LEATHER2 = 1;
  public final static int ARMOR_COLOR_METAL1 = 4;
  public final static int ARMOR_COLOR_METAL2 = 5;
  public final static int ARMOR_MODEL_BELT = 8;
  public final static int ARMOR_MODEL_LBICEP = 13;
  public final static int ARMOR_MODEL_LFOOT = 1;
  public final static int ARMOR_MODEL_LFOREARM = 11;
  public final static int ARMOR_MODEL_LHAND = 17;
  public final static int ARMOR_MODEL_LSHIN = 3;
  public final static int ARMOR_MODEL_LSHOULDER = 15;
  public final static int ARMOR_MODEL_LTHIGH = 4;
  public final static int ARMOR_MODEL_NECK = 9;
  public final static int ARMOR_MODEL_PELVIS = 6;
  public final static int ARMOR_MODEL_RBICEP = 12;
  public final static int ARMOR_MODEL_RFOOT = 0;
  public final static int ARMOR_MODEL_RFOREARM = 10;
  public final static int ARMOR_MODEL_RHAND = 16;
  public final static int ARMOR_MODEL_ROBE = 18;
  public final static int ARMOR_MODEL_RSHIN = 2;
  public final static int ARMOR_MODEL_RSHOULDER = 14;
  public final static int ARMOR_MODEL_RTHIGH = 5;
  public final static int ARMOR_MODEL_TORSO = 7;
  public final static int ARMOR_NUM_COLORS = 6;
  public final static int ARMOR_NUM_MODELS = 19;
  public final static int NUM_TYPES = 5;
  public final static int TYPE_ARMOR_COLOR = 4;
  public final static int TYPE_ARMOR_MODEL = 3;
  public final static int TYPE_SIMPLE_MODEL = 0;
  public final static int TYPE_WEAPON_COLOR = 1;
  public final static int TYPE_WEAPON_MODEL = 2;
  public final static int WEAPON_COLOR_BOTTOM = 0;
  public final static int WEAPON_COLOR_MIDDLE = 1;
  public final static int WEAPON_COLOR_TOP = 2;
  public final static int WEAPON_MODEL_BOTTOM = 0;
  public final static int WEAPON_MODEL_MIDDLE = 1;
  public final static int WEAPON_MODEL_TOP = 2;

  public static String nameOf(int value) {
    if (value == 2) return "ItemAppr.ARMOR_COLOR_CLOTH1";
    if (value == 3) return "ItemAppr.ARMOR_COLOR_CLOTH2";
    if (value == 0) return "ItemAppr.ARMOR_COLOR_LEATHER1";
    if (value == 1) return "ItemAppr.ARMOR_COLOR_LEATHER2";
    if (value == 4) return "ItemAppr.ARMOR_COLOR_METAL1";
    if (value == 5) return "ItemAppr.ARMOR_COLOR_METAL2";
    if (value == 8) return "ItemAppr.ARMOR_MODEL_BELT";
    if (value == 13) return "ItemAppr.ARMOR_MODEL_LBICEP";
    if (value == 1) return "ItemAppr.ARMOR_MODEL_LFOOT";
    if (value == 11) return "ItemAppr.ARMOR_MODEL_LFOREARM";
    if (value == 17) return "ItemAppr.ARMOR_MODEL_LHAND";
    if (value == 3) return "ItemAppr.ARMOR_MODEL_LSHIN";
    if (value == 15) return "ItemAppr.ARMOR_MODEL_LSHOULDER";
    if (value == 4) return "ItemAppr.ARMOR_MODEL_LTHIGH";
    if (value == 9) return "ItemAppr.ARMOR_MODEL_NECK";
    if (value == 6) return "ItemAppr.ARMOR_MODEL_PELVIS";
    if (value == 12) return "ItemAppr.ARMOR_MODEL_RBICEP";
    if (value == 0) return "ItemAppr.ARMOR_MODEL_RFOOT";
    if (value == 10) return "ItemAppr.ARMOR_MODEL_RFOREARM";
    if (value == 16) return "ItemAppr.ARMOR_MODEL_RHAND";
    if (value == 18) return "ItemAppr.ARMOR_MODEL_ROBE";
    if (value == 2) return "ItemAppr.ARMOR_MODEL_RSHIN";
    if (value == 14) return "ItemAppr.ARMOR_MODEL_RSHOULDER";
    if (value == 5) return "ItemAppr.ARMOR_MODEL_RTHIGH";
    if (value == 7) return "ItemAppr.ARMOR_MODEL_TORSO";
    if (value == 6) return "ItemAppr.ARMOR_NUM_COLORS";
    if (value == 19) return "ItemAppr.ARMOR_NUM_MODELS";
    if (value == 5) return "ItemAppr.NUM_TYPES";
    if (value == 4) return "ItemAppr.TYPE_ARMOR_COLOR";
    if (value == 3) return "ItemAppr.TYPE_ARMOR_MODEL";
    if (value == 0) return "ItemAppr.TYPE_SIMPLE_MODEL";
    if (value == 1) return "ItemAppr.TYPE_WEAPON_COLOR";
    if (value == 2) return "ItemAppr.TYPE_WEAPON_MODEL";
    if (value == 0) return "ItemAppr.WEAPON_COLOR_BOTTOM";
    if (value == 1) return "ItemAppr.WEAPON_COLOR_MIDDLE";
    if (value == 2) return "ItemAppr.WEAPON_COLOR_TOP";
    if (value == 0) return "ItemAppr.WEAPON_MODEL_BOTTOM";
    if (value == 1) return "ItemAppr.WEAPON_MODEL_MIDDLE";
    if (value == 2) return "ItemAppr.WEAPON_MODEL_TOP";
    return "ItemAppr.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemAppr.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemAppr.(not found: " + value + ")";
  }
}
