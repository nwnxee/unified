package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ASSOCIATE_COMMAND".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AssociateCommand {
  private AssociateCommand() {}

  public final static int ATTACKNEAREST = -3;
  public final static int DISARMTRAP = -20;
  public final static int FOLLOWMASTER = -5;
  public final static int GUARDMASTER = -7;
  public final static int HEALMASTER = -4;
  public final static int INVENTORY = -19;
  public final static int LEAVEPARTY = -17;
  public final static int MASTERATTACKEDOTHER = -15;
  public final static int MASTERFAILEDLOCKPICK = -6;
  public final static int MASTERGOINGTOBEATTACKED = -16;
  public final static int MASTERSAWTRAP = -14;
  public final static int MASTERUNDERATTACK = -11;
  public final static int PICKLOCK = -18;
  public final static int RELEASEDOMINATION = -12;
  public final static int STANDGROUND = -2;
  public final static int TOGGLECASTING = -21;
  public final static int TOGGLESEARCH = -23;
  public final static int TOGGLESTEALTH = -22;
  public final static int UNPOSSESSFAMILIAR = -13;
  public final static int UNSUMMONANIMALCOMPANION = -9;
  public final static int UNSUMMONFAMILIAR = -8;
  public final static int UNSUMMONSUMMONED = -10;

  public static String nameOf(int value) {
    if (value == -3) return "AssociateCommand.ATTACKNEAREST";
    if (value == -20) return "AssociateCommand.DISARMTRAP";
    if (value == -5) return "AssociateCommand.FOLLOWMASTER";
    if (value == -7) return "AssociateCommand.GUARDMASTER";
    if (value == -4) return "AssociateCommand.HEALMASTER";
    if (value == -19) return "AssociateCommand.INVENTORY";
    if (value == -17) return "AssociateCommand.LEAVEPARTY";
    if (value == -15) return "AssociateCommand.MASTERATTACKEDOTHER";
    if (value == -6) return "AssociateCommand.MASTERFAILEDLOCKPICK";
    if (value == -16) return "AssociateCommand.MASTERGOINGTOBEATTACKED";
    if (value == -14) return "AssociateCommand.MASTERSAWTRAP";
    if (value == -11) return "AssociateCommand.MASTERUNDERATTACK";
    if (value == -18) return "AssociateCommand.PICKLOCK";
    if (value == -12) return "AssociateCommand.RELEASEDOMINATION";
    if (value == -2) return "AssociateCommand.STANDGROUND";
    if (value == -21) return "AssociateCommand.TOGGLECASTING";
    if (value == -23) return "AssociateCommand.TOGGLESEARCH";
    if (value == -22) return "AssociateCommand.TOGGLESTEALTH";
    if (value == -13) return "AssociateCommand.UNPOSSESSFAMILIAR";
    if (value == -9) return "AssociateCommand.UNSUMMONANIMALCOMPANION";
    if (value == -8) return "AssociateCommand.UNSUMMONFAMILIAR";
    if (value == -10) return "AssociateCommand.UNSUMMONSUMMONED";
    return "AssociateCommand.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AssociateCommand.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AssociateCommand.(not found: " + value + ")";
  }
}
