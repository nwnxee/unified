package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DISEASE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Disease {
  private Disease() {}

  public final static int BLINDING_SICKNESS = 0;
  public final static int BURROW_MAGGOTS = 14;
  public final static int CACKLE_FEVER = 1;
  public final static int DEMON_FEVER = 3;
  public final static int DEVIL_CHILLS = 2;
  public final static int DREAD_BLISTERS = 13;
  public final static int FILTH_FEVER = 4;
  public final static int GHOUL_ROT = 11;
  public final static int MINDFIRE = 5;
  public final static int MUMMY_ROT = 6;
  public final static int RED_ACHE = 7;
  public final static int RED_SLAAD_EGGS = 10;
  public final static int SHAKES = 8;
  public final static int SLIMY_DOOM = 9;
  public final static int SOLDIER_SHAKES = 15;
  public final static int VERMIN_MADNESS = 16;
  public final static int ZOMBIE_CREEP = 12;

  public static String nameOf(int value) {
    if (value == 0) return "Disease.BLINDING_SICKNESS";
    if (value == 14) return "Disease.BURROW_MAGGOTS";
    if (value == 1) return "Disease.CACKLE_FEVER";
    if (value == 3) return "Disease.DEMON_FEVER";
    if (value == 2) return "Disease.DEVIL_CHILLS";
    if (value == 13) return "Disease.DREAD_BLISTERS";
    if (value == 4) return "Disease.FILTH_FEVER";
    if (value == 11) return "Disease.GHOUL_ROT";
    if (value == 5) return "Disease.MINDFIRE";
    if (value == 6) return "Disease.MUMMY_ROT";
    if (value == 7) return "Disease.RED_ACHE";
    if (value == 10) return "Disease.RED_SLAAD_EGGS";
    if (value == 8) return "Disease.SHAKES";
    if (value == 9) return "Disease.SLIMY_DOOM";
    if (value == 15) return "Disease.SOLDIER_SHAKES";
    if (value == 16) return "Disease.VERMIN_MADNESS";
    if (value == 12) return "Disease.ZOMBIE_CREEP";
    return "Disease.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Disease.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Disease.(not found: " + value + ")";
  }
}
