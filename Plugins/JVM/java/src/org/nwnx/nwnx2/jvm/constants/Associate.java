package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ASSOCIATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Associate {
  private Associate() {}

  public final static int COMMAND_ATTACKNEAREST = -3;
  public final static int COMMAND_DISARMTRAP = -20;
  public final static int COMMAND_FOLLOWMASTER = -5;
  public final static int COMMAND_GUARDMASTER = -7;
  public final static int COMMAND_HEALMASTER = -4;
  public final static int COMMAND_INVENTORY = -19;
  public final static int COMMAND_LEAVEPARTY = -17;
  public final static int COMMAND_MASTERATTACKEDOTHER = -15;
  public final static int COMMAND_MASTERFAILEDLOCKPICK = -6;
  public final static int COMMAND_MASTERGOINGTOBEATTACKED = -16;
  public final static int COMMAND_MASTERSAWTRAP = -14;
  public final static int COMMAND_MASTERUNDERATTACK = -11;
  public final static int COMMAND_PICKLOCK = -18;
  public final static int COMMAND_RELEASEDOMINATION = -12;
  public final static int COMMAND_STANDGROUND = -2;
  public final static int COMMAND_TOGGLECASTING = -21;
  public final static int COMMAND_TOGGLESEARCH = -23;
  public final static int COMMAND_TOGGLESTEALTH = -22;
  public final static int COMMAND_UNPOSSESSFAMILIAR = -13;
  public final static int COMMAND_UNSUMMONANIMALCOMPANION = -9;
  public final static int COMMAND_UNSUMMONFAMILIAR = -8;
  public final static int COMMAND_UNSUMMONSUMMONED = -10;
  public final static int TYPE_ANIMALCOMPANION = 2;
  public final static int TYPE_DOMINATED = 5;
  public final static int TYPE_FAMILIAR = 3;
  public final static int TYPE_HENCHMAN = 1;
  public final static int TYPE_NONE = 0;
  public final static int TYPE_SUMMONED = 4;

  public static String nameOf(int value) {
    if (value == -3) return "Associate.COMMAND_ATTACKNEAREST";
    if (value == -20) return "Associate.COMMAND_DISARMTRAP";
    if (value == -5) return "Associate.COMMAND_FOLLOWMASTER";
    if (value == -7) return "Associate.COMMAND_GUARDMASTER";
    if (value == -4) return "Associate.COMMAND_HEALMASTER";
    if (value == -19) return "Associate.COMMAND_INVENTORY";
    if (value == -17) return "Associate.COMMAND_LEAVEPARTY";
    if (value == -15) return "Associate.COMMAND_MASTERATTACKEDOTHER";
    if (value == -6) return "Associate.COMMAND_MASTERFAILEDLOCKPICK";
    if (value == -16) return "Associate.COMMAND_MASTERGOINGTOBEATTACKED";
    if (value == -14) return "Associate.COMMAND_MASTERSAWTRAP";
    if (value == -11) return "Associate.COMMAND_MASTERUNDERATTACK";
    if (value == -18) return "Associate.COMMAND_PICKLOCK";
    if (value == -12) return "Associate.COMMAND_RELEASEDOMINATION";
    if (value == -2) return "Associate.COMMAND_STANDGROUND";
    if (value == -21) return "Associate.COMMAND_TOGGLECASTING";
    if (value == -23) return "Associate.COMMAND_TOGGLESEARCH";
    if (value == -22) return "Associate.COMMAND_TOGGLESTEALTH";
    if (value == -13) return "Associate.COMMAND_UNPOSSESSFAMILIAR";
    if (value == -9) return "Associate.COMMAND_UNSUMMONANIMALCOMPANION";
    if (value == -8) return "Associate.COMMAND_UNSUMMONFAMILIAR";
    if (value == -10) return "Associate.COMMAND_UNSUMMONSUMMONED";
    if (value == 2) return "Associate.TYPE_ANIMALCOMPANION";
    if (value == 5) return "Associate.TYPE_DOMINATED";
    if (value == 3) return "Associate.TYPE_FAMILIAR";
    if (value == 1) return "Associate.TYPE_HENCHMAN";
    if (value == 0) return "Associate.TYPE_NONE";
    if (value == 4) return "Associate.TYPE_SUMMONED";
    return "Associate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Associate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Associate.(not found: " + value + ")";
  }
}
