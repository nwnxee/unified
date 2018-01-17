package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE_DIRE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphTypeDire {
  private PolymorphTypeDire() {}

  public final static int BADGER = 37;
  public final static int BOAR = 36;
  public final static int BROWN_BEAR = 33;
  public final static int PANTHER = 34;
  public final static int WOLF = 35;

  public static String nameOf(int value) {
    if (value == 37) return "PolymorphTypeDire.BADGER";
    if (value == 36) return "PolymorphTypeDire.BOAR";
    if (value == 33) return "PolymorphTypeDire.BROWN_BEAR";
    if (value == 34) return "PolymorphTypeDire.PANTHER";
    if (value == 35) return "PolymorphTypeDire.WOLF";
    return "PolymorphTypeDire.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphTypeDire.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphTypeDire.(not found: " + value + ")";
  }
}
