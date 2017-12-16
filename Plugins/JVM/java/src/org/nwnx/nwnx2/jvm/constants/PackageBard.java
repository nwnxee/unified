package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_BARD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageBard {
  private PackageBard() {}

  public final static int BLADE = 43;
  public final static int GALLANT = 44;
  public final static int HARPER = 91;
  public final static int HARPER_2NDCLASS = 119;
  public final static int JESTER = 45;
  public final static int LOREMASTER = 46;
  public final static int PACKAGE_BARD = 1;

  public static String nameOf(int value) {
    if (value == 43) return "PackageBard.BLADE";
    if (value == 44) return "PackageBard.GALLANT";
    if (value == 91) return "PackageBard.HARPER";
    if (value == 119) return "PackageBard.HARPER_2NDCLASS";
    if (value == 45) return "PackageBard.JESTER";
    if (value == 46) return "PackageBard.LOREMASTER";
    if (value == 1) return "PackageBard.PACKAGE_BARD";
    return "PackageBard.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageBard.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageBard.(not found: " + value + ")";
  }
}
