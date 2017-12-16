package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Animal {
  private Animal() {}

  public final static int COMPANION_CREATURE_TYPE_BADGER = 0;
  public final static int COMPANION_CREATURE_TYPE_BEAR = 2;
  public final static int COMPANION_CREATURE_TYPE_BOAR = 3;
  public final static int COMPANION_CREATURE_TYPE_DIRERAT = 8;
  public final static int COMPANION_CREATURE_TYPE_DIREWOLF = 7;
  public final static int COMPANION_CREATURE_TYPE_HAWK = 4;
  public final static int COMPANION_CREATURE_TYPE_NONE = 255;
  public final static int COMPANION_CREATURE_TYPE_PANTHER = 5;
  public final static int COMPANION_CREATURE_TYPE_SPIDER = 6;
  public final static int COMPANION_CREATURE_TYPE_WOLF = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Animal.COMPANION_CREATURE_TYPE_BADGER";
    if (value == 2) return "Animal.COMPANION_CREATURE_TYPE_BEAR";
    if (value == 3) return "Animal.COMPANION_CREATURE_TYPE_BOAR";
    if (value == 8) return "Animal.COMPANION_CREATURE_TYPE_DIRERAT";
    if (value == 7) return "Animal.COMPANION_CREATURE_TYPE_DIREWOLF";
    if (value == 4) return "Animal.COMPANION_CREATURE_TYPE_HAWK";
    if (value == 255) return "Animal.COMPANION_CREATURE_TYPE_NONE";
    if (value == 5) return "Animal.COMPANION_CREATURE_TYPE_PANTHER";
    if (value == 6) return "Animal.COMPANION_CREATURE_TYPE_SPIDER";
    if (value == 1) return "Animal.COMPANION_CREATURE_TYPE_WOLF";
    return "Animal.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Animal.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Animal.(not found: " + value + ")";
  }
}
