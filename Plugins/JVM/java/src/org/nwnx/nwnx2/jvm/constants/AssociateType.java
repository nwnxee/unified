package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ASSOCIATE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AssociateType {
  private AssociateType() {}

  public final static int ANIMALCOMPANION = 2;
  public final static int DOMINATED = 5;
  public final static int FAMILIAR = 3;
  public final static int HENCHMAN = 1;
  public final static int NONE = 0;
  public final static int SUMMONED = 4;

  public static String nameOf(int value) {
    if (value == 2) return "AssociateType.ANIMALCOMPANION";
    if (value == 5) return "AssociateType.DOMINATED";
    if (value == 3) return "AssociateType.FAMILIAR";
    if (value == 1) return "AssociateType.HENCHMAN";
    if (value == 0) return "AssociateType.NONE";
    if (value == 4) return "AssociateType.SUMMONED";
    return "AssociateType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AssociateType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AssociateType.(not found: " + value + ")";
  }
}
