package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Talent {
  private Talent() {}

  public final static int CATEGORY_BENEFICIAL_CONDITIONAL_AREAEFFECT = 6;
  public final static int CATEGORY_BENEFICIAL_CONDITIONAL_POTION = 18;
  public final static int CATEGORY_BENEFICIAL_CONDITIONAL_SINGLE = 7;
  public final static int CATEGORY_BENEFICIAL_ENHANCEMENT_AREAEFFECT = 8;
  public final static int CATEGORY_BENEFICIAL_ENHANCEMENT_POTION = 21;
  public final static int CATEGORY_BENEFICIAL_ENHANCEMENT_SELF = 10;
  public final static int CATEGORY_BENEFICIAL_ENHANCEMENT_SINGLE = 9;
  public final static int CATEGORY_BENEFICIAL_HEALING_AREAEFFECT = 4;
  public final static int CATEGORY_BENEFICIAL_HEALING_POTION = 17;
  public final static int CATEGORY_BENEFICIAL_HEALING_TOUCH = 5;
  public final static int CATEGORY_BENEFICIAL_OBTAIN_ALLIES = 15;
  public final static int CATEGORY_BENEFICIAL_PROTECTION_AREAEFFECT = 14;
  public final static int CATEGORY_BENEFICIAL_PROTECTION_POTION = 20;
  public final static int CATEGORY_BENEFICIAL_PROTECTION_SELF = 12;
  public final static int CATEGORY_BENEFICIAL_PROTECTION_SINGLE = 13;
  public final static int CATEGORY_DRAGONS_BREATH = 19;
  public final static int CATEGORY_HARMFUL_AREAEFFECT_DISCRIMINANT = 1;
  public final static int CATEGORY_HARMFUL_AREAEFFECT_INDISCRIMINANT = 11;
  public final static int CATEGORY_HARMFUL_MELEE = 22;
  public final static int CATEGORY_HARMFUL_RANGED = 2;
  public final static int CATEGORY_HARMFUL_TOUCH = 3;
  public final static int CATEGORY_PERSISTENT_AREA_OF_EFFECT = 16;
  public final static int TYPE_FEAT = 1;
  public final static int TYPE_SKILL = 2;
  public final static int TYPE_SPELL = 0;

  public static String nameOf(int value) {
    if (value == 6) return "Talent.CATEGORY_BENEFICIAL_CONDITIONAL_AREAEFFECT";
    if (value == 18) return "Talent.CATEGORY_BENEFICIAL_CONDITIONAL_POTION";
    if (value == 7) return "Talent.CATEGORY_BENEFICIAL_CONDITIONAL_SINGLE";
    if (value == 8) return "Talent.CATEGORY_BENEFICIAL_ENHANCEMENT_AREAEFFECT";
    if (value == 21) return "Talent.CATEGORY_BENEFICIAL_ENHANCEMENT_POTION";
    if (value == 10) return "Talent.CATEGORY_BENEFICIAL_ENHANCEMENT_SELF";
    if (value == 9) return "Talent.CATEGORY_BENEFICIAL_ENHANCEMENT_SINGLE";
    if (value == 4) return "Talent.CATEGORY_BENEFICIAL_HEALING_AREAEFFECT";
    if (value == 17) return "Talent.CATEGORY_BENEFICIAL_HEALING_POTION";
    if (value == 5) return "Talent.CATEGORY_BENEFICIAL_HEALING_TOUCH";
    if (value == 15) return "Talent.CATEGORY_BENEFICIAL_OBTAIN_ALLIES";
    if (value == 14) return "Talent.CATEGORY_BENEFICIAL_PROTECTION_AREAEFFECT";
    if (value == 20) return "Talent.CATEGORY_BENEFICIAL_PROTECTION_POTION";
    if (value == 12) return "Talent.CATEGORY_BENEFICIAL_PROTECTION_SELF";
    if (value == 13) return "Talent.CATEGORY_BENEFICIAL_PROTECTION_SINGLE";
    if (value == 19) return "Talent.CATEGORY_DRAGONS_BREATH";
    if (value == 1) return "Talent.CATEGORY_HARMFUL_AREAEFFECT_DISCRIMINANT";
    if (value == 11) return "Talent.CATEGORY_HARMFUL_AREAEFFECT_INDISCRIMINANT";
    if (value == 22) return "Talent.CATEGORY_HARMFUL_MELEE";
    if (value == 2) return "Talent.CATEGORY_HARMFUL_RANGED";
    if (value == 3) return "Talent.CATEGORY_HARMFUL_TOUCH";
    if (value == 16) return "Talent.CATEGORY_PERSISTENT_AREA_OF_EFFECT";
    if (value == 1) return "Talent.TYPE_FEAT";
    if (value == 2) return "Talent.TYPE_SKILL";
    if (value == 0) return "Talent.TYPE_SPELL";
    return "Talent.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Talent.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Talent.(not found: " + value + ")";
  }
}
