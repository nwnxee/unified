package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SHAPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Shape {
  private Shape() {}

  public final static int CONE = 1;
  public final static int CUBE = 2;
  public final static int SPELLCONE = 3;
  public final static int SPELLCYLINDER = 0;
  public final static int SPHERE = 4;

  public static String nameOf(int value) {
    if (value == 1) return "Shape.CONE";
    if (value == 2) return "Shape.CUBE";
    if (value == 3) return "Shape.SPELLCONE";
    if (value == 0) return "Shape.SPELLCYLINDER";
    if (value == 4) return "Shape.SPHERE";
    return "Shape.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Shape.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Shape.(not found: " + value + ")";
  }
}
