package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SAVING_THROW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SavingThrow {
  private SavingThrow() {}

  public final static int ALL = 0;
  public final static int FORT = 1;
  public final static int REFLEX = 2;
  public final static int TYPE_ACID = 6;
  public final static int TYPE_ALL = 0;
  public final static int TYPE_CHAOS = 19;
  public final static int TYPE_COLD = 12;
  public final static int TYPE_DEATH = 11;
  public final static int TYPE_DISEASE = 3;
  public final static int TYPE_DIVINE = 13;
  public final static int TYPE_ELECTRICITY = 8;
  public final static int TYPE_EVIL = 17;
  public final static int TYPE_FEAR = 4;
  public final static int TYPE_FIRE = 7;
  public final static int TYPE_GOOD = 16;
  public final static int TYPE_LAW = 18;
  public final static int TYPE_MIND_SPELLS = 1;
  public final static int TYPE_NEGATIVE = 10;
  public final static int TYPE_NONE = 0;
  public final static int TYPE_POISON = 2;
  public final static int TYPE_POSITIVE = 9;
  public final static int TYPE_SONIC = 5;
  public final static int TYPE_SPELL = 15;
  public final static int TYPE_TRAP = 14;
  public final static int WILL = 3;

  public static String nameOf(int value) {
    if (value == 0) return "SavingThrow.ALL";
    if (value == 1) return "SavingThrow.FORT";
    if (value == 2) return "SavingThrow.REFLEX";
    if (value == 6) return "SavingThrow.TYPE_ACID";
    if (value == 0) return "SavingThrow.TYPE_ALL";
    if (value == 19) return "SavingThrow.TYPE_CHAOS";
    if (value == 12) return "SavingThrow.TYPE_COLD";
    if (value == 11) return "SavingThrow.TYPE_DEATH";
    if (value == 3) return "SavingThrow.TYPE_DISEASE";
    if (value == 13) return "SavingThrow.TYPE_DIVINE";
    if (value == 8) return "SavingThrow.TYPE_ELECTRICITY";
    if (value == 17) return "SavingThrow.TYPE_EVIL";
    if (value == 4) return "SavingThrow.TYPE_FEAR";
    if (value == 7) return "SavingThrow.TYPE_FIRE";
    if (value == 16) return "SavingThrow.TYPE_GOOD";
    if (value == 18) return "SavingThrow.TYPE_LAW";
    if (value == 1) return "SavingThrow.TYPE_MIND_SPELLS";
    if (value == 10) return "SavingThrow.TYPE_NEGATIVE";
    if (value == 0) return "SavingThrow.TYPE_NONE";
    if (value == 2) return "SavingThrow.TYPE_POISON";
    if (value == 9) return "SavingThrow.TYPE_POSITIVE";
    if (value == 5) return "SavingThrow.TYPE_SONIC";
    if (value == 15) return "SavingThrow.TYPE_SPELL";
    if (value == 14) return "SavingThrow.TYPE_TRAP";
    if (value == 3) return "SavingThrow.WILL";
    return "SavingThrow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SavingThrow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SavingThrow.(not found: " + value + ")";
  }
}
