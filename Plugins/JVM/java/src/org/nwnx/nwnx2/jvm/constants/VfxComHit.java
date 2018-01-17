package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_HIT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComHit {
  private VfxComHit() {}

  public final static int ACID = 283;
  public final static int DIVINE = 289;
  public final static int ELECTRICAL = 282;
  public final static int FIRE = 280;
  public final static int FROST = 281;
  public final static int NEGATIVE = 288;
  public final static int SONIC = 284;

  public static String nameOf(int value) {
    if (value == 283) return "VfxComHit.ACID";
    if (value == 289) return "VfxComHit.DIVINE";
    if (value == 282) return "VfxComHit.ELECTRICAL";
    if (value == 280) return "VfxComHit.FIRE";
    if (value == 281) return "VfxComHit.FROST";
    if (value == 288) return "VfxComHit.NEGATIVE";
    if (value == 284) return "VfxComHit.SONIC";
    return "VfxComHit.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComHit.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComHit.(not found: " + value + ")";
  }
}
