package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_HEAD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpHead {
  private VfxImpHead() {}

  public final static int ACID = 194;
  public final static int COLD = 198;
  public final static int ELECTRICITY = 197;
  public final static int EVIL = 203;
  public final static int FIRE = 195;
  public final static int HEAL = 201;
  public final static int HOLY = 199;
  public final static int MIND = 202;
  public final static int NATURE = 200;
  public final static int ODD = 204;
  public final static int SONIC = 196;

  public static String nameOf(int value) {
    if (value == 194) return "VfxImpHead.ACID";
    if (value == 198) return "VfxImpHead.COLD";
    if (value == 197) return "VfxImpHead.ELECTRICITY";
    if (value == 203) return "VfxImpHead.EVIL";
    if (value == 195) return "VfxImpHead.FIRE";
    if (value == 201) return "VfxImpHead.HEAL";
    if (value == 199) return "VfxImpHead.HOLY";
    if (value == 202) return "VfxImpHead.MIND";
    if (value == 200) return "VfxImpHead.NATURE";
    if (value == 204) return "VfxImpHead.ODD";
    if (value == 196) return "VfxImpHead.SONIC";
    return "VfxImpHead.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpHead.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpHead.(not found: " + value + ")";
  }
}
