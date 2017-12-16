package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Creature {
  private Creature() {}

  public final static int MODEL_TYPE_NONE = 0;
  public final static int MODEL_TYPE_SKIN = 1;
  public final static int MODEL_TYPE_TATTOO = 2;
  public final static int MODEL_TYPE_UNDEAD = 255;
  public final static int PART_BELT = 8;
  public final static int PART_HEAD = 20;
  public final static int PART_LEFT_BICEP = 13;
  public final static int PART_LEFT_FOOT = 1;
  public final static int PART_LEFT_FOREARM = 11;
  public final static int PART_LEFT_HAND = 17;
  public final static int PART_LEFT_SHIN = 3;
  public final static int PART_LEFT_SHOULDER = 15;
  public final static int PART_LEFT_THIGH = 4;
  public final static int PART_NECK = 9;
  public final static int PART_PELVIS = 6;
  public final static int PART_RIGHT_BICEP = 12;
  public final static int PART_RIGHT_FOOT = 0;
  public final static int PART_RIGHT_FOREARM = 10;
  public final static int PART_RIGHT_HAND = 16;
  public final static int PART_RIGHT_SHIN = 2;
  public final static int PART_RIGHT_SHOULDER = 14;
  public final static int PART_RIGHT_THIGH = 5;
  public final static int PART_TORSO = 7;
  public final static int SIZE_HUGE = 5;
  public final static int SIZE_INVALID = 0;
  public final static int SIZE_LARGE = 4;
  public final static int SIZE_MEDIUM = 3;
  public final static int SIZE_SMALL = 2;
  public final static int SIZE_TINY = 1;
  public final static int TAIL_TYPE_BONE = 2;
  public final static int TAIL_TYPE_DEVIL = 3;
  public final static int TAIL_TYPE_LIZARD = 1;
  public final static int TAIL_TYPE_NONE = 0;
  public final static int TYPE_CLASS = 2;
  public final static int TYPE_DOES_NOT_HAVE_SPELL_EFFECT = 6;
  public final static int TYPE_HAS_SPELL_EFFECT = 5;
  public final static int TYPE_IS_ALIVE = 4;
  public final static int TYPE_PERCEPTION = 7;
  public final static int TYPE_PLAYER_CHAR = 1;
  public final static int TYPE_RACIAL_TYPE = 0;
  public final static int TYPE_REPUTATION = 3;
  public final static int WING_TYPE_ANGEL = 2;
  public final static int WING_TYPE_BAT = 3;
  public final static int WING_TYPE_BIRD = 6;
  public final static int WING_TYPE_BUTTERFLY = 5;
  public final static int WING_TYPE_DEMON = 1;
  public final static int WING_TYPE_DRAGON = 4;
  public final static int WING_TYPE_NONE = 0;

  public static String nameOf(int value) {
    if (value == 0) return "Creature.MODEL_TYPE_NONE";
    if (value == 1) return "Creature.MODEL_TYPE_SKIN";
    if (value == 2) return "Creature.MODEL_TYPE_TATTOO";
    if (value == 255) return "Creature.MODEL_TYPE_UNDEAD";
    if (value == 8) return "Creature.PART_BELT";
    if (value == 20) return "Creature.PART_HEAD";
    if (value == 13) return "Creature.PART_LEFT_BICEP";
    if (value == 1) return "Creature.PART_LEFT_FOOT";
    if (value == 11) return "Creature.PART_LEFT_FOREARM";
    if (value == 17) return "Creature.PART_LEFT_HAND";
    if (value == 3) return "Creature.PART_LEFT_SHIN";
    if (value == 15) return "Creature.PART_LEFT_SHOULDER";
    if (value == 4) return "Creature.PART_LEFT_THIGH";
    if (value == 9) return "Creature.PART_NECK";
    if (value == 6) return "Creature.PART_PELVIS";
    if (value == 12) return "Creature.PART_RIGHT_BICEP";
    if (value == 0) return "Creature.PART_RIGHT_FOOT";
    if (value == 10) return "Creature.PART_RIGHT_FOREARM";
    if (value == 16) return "Creature.PART_RIGHT_HAND";
    if (value == 2) return "Creature.PART_RIGHT_SHIN";
    if (value == 14) return "Creature.PART_RIGHT_SHOULDER";
    if (value == 5) return "Creature.PART_RIGHT_THIGH";
    if (value == 7) return "Creature.PART_TORSO";
    if (value == 5) return "Creature.SIZE_HUGE";
    if (value == 0) return "Creature.SIZE_INVALID";
    if (value == 4) return "Creature.SIZE_LARGE";
    if (value == 3) return "Creature.SIZE_MEDIUM";
    if (value == 2) return "Creature.SIZE_SMALL";
    if (value == 1) return "Creature.SIZE_TINY";
    if (value == 2) return "Creature.TAIL_TYPE_BONE";
    if (value == 3) return "Creature.TAIL_TYPE_DEVIL";
    if (value == 1) return "Creature.TAIL_TYPE_LIZARD";
    if (value == 0) return "Creature.TAIL_TYPE_NONE";
    if (value == 2) return "Creature.TYPE_CLASS";
    if (value == 6) return "Creature.TYPE_DOES_NOT_HAVE_SPELL_EFFECT";
    if (value == 5) return "Creature.TYPE_HAS_SPELL_EFFECT";
    if (value == 4) return "Creature.TYPE_IS_ALIVE";
    if (value == 7) return "Creature.TYPE_PERCEPTION";
    if (value == 1) return "Creature.TYPE_PLAYER_CHAR";
    if (value == 0) return "Creature.TYPE_RACIAL_TYPE";
    if (value == 3) return "Creature.TYPE_REPUTATION";
    if (value == 2) return "Creature.WING_TYPE_ANGEL";
    if (value == 3) return "Creature.WING_TYPE_BAT";
    if (value == 6) return "Creature.WING_TYPE_BIRD";
    if (value == 5) return "Creature.WING_TYPE_BUTTERFLY";
    if (value == 1) return "Creature.WING_TYPE_DEMON";
    if (value == 4) return "Creature.WING_TYPE_DRAGON";
    if (value == 0) return "Creature.WING_TYPE_NONE";
    return "Creature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Creature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Creature.(not found: " + value + ")";
  }
}
