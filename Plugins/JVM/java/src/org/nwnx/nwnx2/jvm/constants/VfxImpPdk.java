package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_PDK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpPdk {
  private VfxImpPdk() {}

  public final static int FINAL_STAND = 631;
  public final static int GENERIC_HEAD_HIT = 624;
  public final static int GENERIC_PULSE = 623;
  public final static int HEROIC_SHIELD = 626;
  public final static int INSPIRE_COURAGE = 627;
  public final static int OATH = 630;
  public final static int RALLYING_CRY = 625;
  public final static int WRATH = 629;

  public static String nameOf(int value) {
    if (value == 631) return "VfxImpPdk.FINAL_STAND";
    if (value == 624) return "VfxImpPdk.GENERIC_HEAD_HIT";
    if (value == 623) return "VfxImpPdk.GENERIC_PULSE";
    if (value == 626) return "VfxImpPdk.HEROIC_SHIELD";
    if (value == 627) return "VfxImpPdk.INSPIRE_COURAGE";
    if (value == 630) return "VfxImpPdk.OATH";
    if (value == 625) return "VfxImpPdk.RALLYING_CRY";
    if (value == 629) return "VfxImpPdk.WRATH";
    return "VfxImpPdk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpPdk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpPdk.(not found: " + value + ")";
  }
}
