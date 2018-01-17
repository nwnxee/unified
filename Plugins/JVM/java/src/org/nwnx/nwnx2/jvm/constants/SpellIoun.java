package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_IOUN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellIoun {
  private SpellIoun() {}

  public final static int STONE_BLUE = 557;
  public final static int STONE_DEEP_RED = 558;
  public final static int STONE_DUSTY_ROSE = 554;
  public final static int STONE_PALE_BLUE = 555;
  public final static int STONE_PINK = 559;
  public final static int STONE_PINK_GREEN = 560;
  public final static int STONE_SCARLET_BLUE = 556;

  public static String nameOf(int value) {
    if (value == 557) return "SpellIoun.STONE_BLUE";
    if (value == 558) return "SpellIoun.STONE_DEEP_RED";
    if (value == 554) return "SpellIoun.STONE_DUSTY_ROSE";
    if (value == 555) return "SpellIoun.STONE_PALE_BLUE";
    if (value == 559) return "SpellIoun.STONE_PINK";
    if (value == 560) return "SpellIoun.STONE_PINK_GREEN";
    if (value == 556) return "SpellIoun.STONE_SCARLET_BLUE";
    return "SpellIoun.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellIoun.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellIoun.(not found: " + value + ")";
  }
}
