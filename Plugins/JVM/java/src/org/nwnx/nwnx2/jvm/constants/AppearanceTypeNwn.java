package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_NWN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeNwn {
  private AppearanceTypeNwn() {}

  public final static int AARIN = 188;
  public final static int ARIBETH_EVIL = 189;
  public final static int HAEDRALINE = 191;
  public final static int MAUGRIM = 193;
  public final static int MORAG = 192;
  public final static int NASHER = 296;
  public final static int SEDOS = 297;

  public static String nameOf(int value) {
    if (value == 188) return "AppearanceTypeNwn.AARIN";
    if (value == 189) return "AppearanceTypeNwn.ARIBETH_EVIL";
    if (value == 191) return "AppearanceTypeNwn.HAEDRALINE";
    if (value == 193) return "AppearanceTypeNwn.MAUGRIM";
    if (value == 192) return "AppearanceTypeNwn.MORAG";
    if (value == 296) return "AppearanceTypeNwn.NASHER";
    if (value == 297) return "AppearanceTypeNwn.SEDOS";
    return "AppearanceTypeNwn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeNwn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeNwn.(not found: " + value + ")";
  }
}
