package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMAL_COMPANION_CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimalCompanionCreature {
  private AnimalCompanionCreature() {}

  public final static int TYPE_BADGER = 0;
  public final static int TYPE_BEAR = 2;
  public final static int TYPE_BOAR = 3;
  public final static int TYPE_DIRERAT = 8;
  public final static int TYPE_DIREWOLF = 7;
  public final static int TYPE_HAWK = 4;
  public final static int TYPE_NONE = 255;
  public final static int TYPE_PANTHER = 5;
  public final static int TYPE_SPIDER = 6;
  public final static int TYPE_WOLF = 1;

  public static String nameOf(int value) {
    if (value == 0) return "AnimalCompanionCreature.TYPE_BADGER";
    if (value == 2) return "AnimalCompanionCreature.TYPE_BEAR";
    if (value == 3) return "AnimalCompanionCreature.TYPE_BOAR";
    if (value == 8) return "AnimalCompanionCreature.TYPE_DIRERAT";
    if (value == 7) return "AnimalCompanionCreature.TYPE_DIREWOLF";
    if (value == 4) return "AnimalCompanionCreature.TYPE_HAWK";
    if (value == 255) return "AnimalCompanionCreature.TYPE_NONE";
    if (value == 5) return "AnimalCompanionCreature.TYPE_PANTHER";
    if (value == 6) return "AnimalCompanionCreature.TYPE_SPIDER";
    if (value == 1) return "AnimalCompanionCreature.TYPE_WOLF";
    return "AnimalCompanionCreature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimalCompanionCreature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimalCompanionCreature.(not found: " + value + ")";
  }
}
