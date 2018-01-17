package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMAL_COMPANION_CREATURE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimalCompanionCreatureType {
  private AnimalCompanionCreatureType() {}

  public final static int BADGER = 0;
  public final static int BEAR = 2;
  public final static int BOAR = 3;
  public final static int DIRERAT = 8;
  public final static int DIREWOLF = 7;
  public final static int HAWK = 4;
  public final static int NONE = 255;
  public final static int PANTHER = 5;
  public final static int SPIDER = 6;
  public final static int WOLF = 1;

  public static String nameOf(int value) {
    if (value == 0) return "AnimalCompanionCreatureType.BADGER";
    if (value == 2) return "AnimalCompanionCreatureType.BEAR";
    if (value == 3) return "AnimalCompanionCreatureType.BOAR";
    if (value == 8) return "AnimalCompanionCreatureType.DIRERAT";
    if (value == 7) return "AnimalCompanionCreatureType.DIREWOLF";
    if (value == 4) return "AnimalCompanionCreatureType.HAWK";
    if (value == 255) return "AnimalCompanionCreatureType.NONE";
    if (value == 5) return "AnimalCompanionCreatureType.PANTHER";
    if (value == 6) return "AnimalCompanionCreatureType.SPIDER";
    if (value == 1) return "AnimalCompanionCreatureType.WOLF";
    return "AnimalCompanionCreatureType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimalCompanionCreatureType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimalCompanionCreatureType.(not found: " + value + ")";
  }
}
