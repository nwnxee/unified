package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SAVING_THROW_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SavingThrowType {
  private SavingThrowType() {}

  public final static int ACID = 6;
  public final static int ALL = 0;
  public final static int CHAOS = 19;
  public final static int COLD = 12;
  public final static int DEATH = 11;
  public final static int DISEASE = 3;
  public final static int DIVINE = 13;
  public final static int ELECTRICITY = 8;
  public final static int EVIL = 17;
  public final static int FEAR = 4;
  public final static int FIRE = 7;
  public final static int GOOD = 16;
  public final static int LAW = 18;
  public final static int MIND_SPELLS = 1;
  public final static int NEGATIVE = 10;
  public final static int NONE = 0;
  public final static int POISON = 2;
  public final static int POSITIVE = 9;
  public final static int SONIC = 5;
  public final static int SPELL = 15;
  public final static int TRAP = 14;

  public static String nameOf(int value) {
    if (value == 6) return "SavingThrowType.ACID";
    if (value == 0) return "SavingThrowType.ALL";
    if (value == 19) return "SavingThrowType.CHAOS";
    if (value == 12) return "SavingThrowType.COLD";
    if (value == 11) return "SavingThrowType.DEATH";
    if (value == 3) return "SavingThrowType.DISEASE";
    if (value == 13) return "SavingThrowType.DIVINE";
    if (value == 8) return "SavingThrowType.ELECTRICITY";
    if (value == 17) return "SavingThrowType.EVIL";
    if (value == 4) return "SavingThrowType.FEAR";
    if (value == 7) return "SavingThrowType.FIRE";
    if (value == 16) return "SavingThrowType.GOOD";
    if (value == 18) return "SavingThrowType.LAW";
    if (value == 1) return "SavingThrowType.MIND_SPELLS";
    if (value == 10) return "SavingThrowType.NEGATIVE";
    if (value == 0) return "SavingThrowType.NONE";
    if (value == 2) return "SavingThrowType.POISON";
    if (value == 9) return "SavingThrowType.POSITIVE";
    if (value == 5) return "SavingThrowType.SONIC";
    if (value == 15) return "SavingThrowType.SPELL";
    if (value == 14) return "SavingThrowType.TRAP";
    return "SavingThrowType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SavingThrowType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SavingThrowType.(not found: " + value + ")";
  }
}
