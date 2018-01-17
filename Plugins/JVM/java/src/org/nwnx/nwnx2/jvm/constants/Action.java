package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ACTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Action {
  private Action() {}

  public final static int ANIMALEMPATHY = 16;
  public final static int ATTACKOBJECT = 3;
  public final static int CASTSPELL = 4;
  public final static int CLOSEDOOR = 6;
  public final static int COUNTERSPELL = 31;
  public final static int DIALOGOBJECT = 7;
  public final static int DISABLETRAP = 8;
  public final static int DROPITEM = 2;
  public final static int EXAMINETRAP = 11;
  public final static int FLAGTRAP = 10;
  public final static int FOLLOW = 35;
  public final static int HEAL = 33;
  public final static int INVALID = 65535;
  public final static int ITEMCASTSPELL = 19;
  public final static int KIDAMAGE = 41;
  public final static int LOCK = 14;
  public final static int MODE_COUNTERSPELL = 5;
  public final static int MODE_DEFENSIVE_CAST = 10;
  public final static int MODE_DETECT = 0;
  public final static int MODE_DIRTY_FIGHTING = 11;
  public final static int MODE_EXPERTISE = 8;
  public final static int MODE_FLURRY_OF_BLOWS = 6;
  public final static int MODE_IMPROVED_EXPERTISE = 9;
  public final static int MODE_IMPROVED_POWER_ATTACK = 4;
  public final static int MODE_PARRY = 2;
  public final static int MODE_POWER_ATTACK = 3;
  public final static int MODE_RAPID_SHOT = 7;
  public final static int MODE_STEALTH = 1;
  public final static int MOVETOPOINT = 0;
  public final static int OPENDOOR = 5;
  public final static int OPENLOCK = 13;
  public final static int PICKPOCKET = 34;
  public final static int PICKUPITEM = 1;
  public final static int RANDOMWALK = 43;
  public final static int RECOVERTRAP = 9;
  public final static int REST = 17;
  public final static int SETTRAP = 12;
  public final static int SIT = 37;
  public final static int SMITEGOOD = 40;
  public final static int TAUNT = 18;
  public final static int USEOBJECT = 15;
  public final static int WAIT = 36;

  public static String nameOf(int value) {
    if (value == 16) return "Action.ANIMALEMPATHY";
    if (value == 3) return "Action.ATTACKOBJECT";
    if (value == 4) return "Action.CASTSPELL";
    if (value == 6) return "Action.CLOSEDOOR";
    if (value == 31) return "Action.COUNTERSPELL";
    if (value == 7) return "Action.DIALOGOBJECT";
    if (value == 8) return "Action.DISABLETRAP";
    if (value == 2) return "Action.DROPITEM";
    if (value == 11) return "Action.EXAMINETRAP";
    if (value == 10) return "Action.FLAGTRAP";
    if (value == 35) return "Action.FOLLOW";
    if (value == 33) return "Action.HEAL";
    if (value == 65535) return "Action.INVALID";
    if (value == 19) return "Action.ITEMCASTSPELL";
    if (value == 41) return "Action.KIDAMAGE";
    if (value == 14) return "Action.LOCK";
    if (value == 5) return "Action.MODE_COUNTERSPELL";
    if (value == 10) return "Action.MODE_DEFENSIVE_CAST";
    if (value == 0) return "Action.MODE_DETECT";
    if (value == 11) return "Action.MODE_DIRTY_FIGHTING";
    if (value == 8) return "Action.MODE_EXPERTISE";
    if (value == 6) return "Action.MODE_FLURRY_OF_BLOWS";
    if (value == 9) return "Action.MODE_IMPROVED_EXPERTISE";
    if (value == 4) return "Action.MODE_IMPROVED_POWER_ATTACK";
    if (value == 2) return "Action.MODE_PARRY";
    if (value == 3) return "Action.MODE_POWER_ATTACK";
    if (value == 7) return "Action.MODE_RAPID_SHOT";
    if (value == 1) return "Action.MODE_STEALTH";
    if (value == 0) return "Action.MOVETOPOINT";
    if (value == 5) return "Action.OPENDOOR";
    if (value == 13) return "Action.OPENLOCK";
    if (value == 34) return "Action.PICKPOCKET";
    if (value == 1) return "Action.PICKUPITEM";
    if (value == 43) return "Action.RANDOMWALK";
    if (value == 9) return "Action.RECOVERTRAP";
    if (value == 17) return "Action.REST";
    if (value == 12) return "Action.SETTRAP";
    if (value == 37) return "Action.SIT";
    if (value == 40) return "Action.SMITEGOOD";
    if (value == 18) return "Action.TAUNT";
    if (value == 15) return "Action.USEOBJECT";
    if (value == 36) return "Action.WAIT";
    return "Action.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Action.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Action.(not found: " + value + ")";
  }
}
