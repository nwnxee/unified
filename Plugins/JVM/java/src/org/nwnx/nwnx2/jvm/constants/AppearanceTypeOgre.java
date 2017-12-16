package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_OGRE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeOgre {
  private AppearanceTypeOgre() {}

  public final static int APPEARANCE_TYPE_OGRE = 127;
  public final static int CHIEFTAIN = 128;
  public final static int CHIEFTAINB = 208;
  public final static int MAGE = 129;
  public final static int MAGEB = 209;

  public static String nameOf(int value) {
    if (value == 127) return "AppearanceTypeOgre.APPEARANCE_TYPE_OGRE";
    if (value == 128) return "AppearanceTypeOgre.CHIEFTAIN";
    if (value == 208) return "AppearanceTypeOgre.CHIEFTAINB";
    if (value == 129) return "AppearanceTypeOgre.MAGE";
    if (value == 209) return "AppearanceTypeOgre.MAGEB";
    return "AppearanceTypeOgre.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeOgre.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeOgre.(not found: " + value + ")";
  }
}
