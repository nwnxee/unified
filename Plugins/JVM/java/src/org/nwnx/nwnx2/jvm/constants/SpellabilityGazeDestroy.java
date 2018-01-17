package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_GAZE_DESTROY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityGazeDestroy {
  private SpellabilityGazeDestroy() {}

  public final static int CHAOS = 254;
  public final static int EVIL = 255;
  public final static int GOOD = 256;
  public final static int LAW = 257;

  public static String nameOf(int value) {
    if (value == 254) return "SpellabilityGazeDestroy.CHAOS";
    if (value == 255) return "SpellabilityGazeDestroy.EVIL";
    if (value == 256) return "SpellabilityGazeDestroy.GOOD";
    if (value == 257) return "SpellabilityGazeDestroy.LAW";
    return "SpellabilityGazeDestroy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityGazeDestroy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityGazeDestroy.(not found: " + value + ")";
  }
}
