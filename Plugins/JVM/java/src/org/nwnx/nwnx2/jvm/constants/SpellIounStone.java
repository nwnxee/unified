package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_IOUN_STONE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellIounStone {
  private SpellIounStone() {}

  public final static int BLUE = 557;
  public final static int DEEP_RED = 558;
  public final static int DUSTY_ROSE = 554;
  public final static int PALE_BLUE = 555;
  public final static int PINK = 559;
  public final static int PINK_GREEN = 560;
  public final static int SCARLET_BLUE = 556;

  public static String nameOf(int value) {
    if (value == 557) return "SpellIounStone.BLUE";
    if (value == 558) return "SpellIounStone.DEEP_RED";
    if (value == 554) return "SpellIounStone.DUSTY_ROSE";
    if (value == 555) return "SpellIounStone.PALE_BLUE";
    if (value == 559) return "SpellIounStone.PINK";
    if (value == 560) return "SpellIounStone.PINK_GREEN";
    if (value == 556) return "SpellIounStone.SCARLET_BLUE";
    return "SpellIounStone.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellIounStone.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellIounStone.(not found: " + value + ")";
  }
}
