package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "GENDER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Gender {
  private Gender() {}

  public final static int BOTH = 2;
  public final static int FEMALE = 1;
  public final static int MALE = 0;
  public final static int NONE = 4;
  public final static int OTHER = 3;

  public static String nameOf(int value) {
    if (value == 2) return "Gender.BOTH";
    if (value == 1) return "Gender.FEMALE";
    if (value == 0) return "Gender.MALE";
    if (value == 4) return "Gender.NONE";
    if (value == 3) return "Gender.OTHER";
    return "Gender.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Gender.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Gender.(not found: " + value + ")";
  }
}
