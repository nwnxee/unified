package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SAVING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Saving {
  private Saving() {}

  public final static int THROW_ALL = 0;
  public final static int THROW_FORT = 1;
  public final static int THROW_REFLEX = 2;
  public final static int THROW_TYPE_ACID = 6;
  public final static int THROW_TYPE_ALL = 0;
  public final static int THROW_TYPE_CHAOS = 19;
  public final static int THROW_TYPE_COLD = 12;
  public final static int THROW_TYPE_DEATH = 11;
  public final static int THROW_TYPE_DISEASE = 3;
  public final static int THROW_TYPE_DIVINE = 13;
  public final static int THROW_TYPE_ELECTRICITY = 8;
  public final static int THROW_TYPE_EVIL = 17;
  public final static int THROW_TYPE_FEAR = 4;
  public final static int THROW_TYPE_FIRE = 7;
  public final static int THROW_TYPE_GOOD = 16;
  public final static int THROW_TYPE_LAW = 18;
  public final static int THROW_TYPE_MIND_SPELLS = 1;
  public final static int THROW_TYPE_NEGATIVE = 10;
  public final static int THROW_TYPE_NONE = 0;
  public final static int THROW_TYPE_POISON = 2;
  public final static int THROW_TYPE_POSITIVE = 9;
  public final static int THROW_TYPE_SONIC = 5;
  public final static int THROW_TYPE_SPELL = 15;
  public final static int THROW_TYPE_TRAP = 14;
  public final static int THROW_WILL = 3;

  public static String nameOf(int value) {
    if (value == 0) return "Saving.THROW_ALL";
    if (value == 1) return "Saving.THROW_FORT";
    if (value == 2) return "Saving.THROW_REFLEX";
    if (value == 6) return "Saving.THROW_TYPE_ACID";
    if (value == 0) return "Saving.THROW_TYPE_ALL";
    if (value == 19) return "Saving.THROW_TYPE_CHAOS";
    if (value == 12) return "Saving.THROW_TYPE_COLD";
    if (value == 11) return "Saving.THROW_TYPE_DEATH";
    if (value == 3) return "Saving.THROW_TYPE_DISEASE";
    if (value == 13) return "Saving.THROW_TYPE_DIVINE";
    if (value == 8) return "Saving.THROW_TYPE_ELECTRICITY";
    if (value == 17) return "Saving.THROW_TYPE_EVIL";
    if (value == 4) return "Saving.THROW_TYPE_FEAR";
    if (value == 7) return "Saving.THROW_TYPE_FIRE";
    if (value == 16) return "Saving.THROW_TYPE_GOOD";
    if (value == 18) return "Saving.THROW_TYPE_LAW";
    if (value == 1) return "Saving.THROW_TYPE_MIND_SPELLS";
    if (value == 10) return "Saving.THROW_TYPE_NEGATIVE";
    if (value == 0) return "Saving.THROW_TYPE_NONE";
    if (value == 2) return "Saving.THROW_TYPE_POISON";
    if (value == 9) return "Saving.THROW_TYPE_POSITIVE";
    if (value == 5) return "Saving.THROW_TYPE_SONIC";
    if (value == 15) return "Saving.THROW_TYPE_SPELL";
    if (value == 14) return "Saving.THROW_TYPE_TRAP";
    if (value == 3) return "Saving.THROW_WILL";
    return "Saving.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Saving.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Saving.(not found: " + value + ")";
  }
}
