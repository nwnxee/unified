package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "OBJECT_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ObjectType {
  private ObjectType() {}

  public final static int ALL = 32767;
  public final static int AREA_OF_EFFECT = 16;
  public final static int CREATURE = 1;
  public final static int DOOR = 8;
  public final static int ENCOUNTER = 256;
  public final static int INVALID = 32767;
  public final static int ITEM = 2;
  public final static int PLACEABLE = 64;
  public final static int STORE = 128;
  public final static int TRIGGER = 4;
  public final static int WAYPOINT = 32;

  public static String nameOf(int value) {
    if (value == 32767) return "ObjectType.ALL";
    if (value == 16) return "ObjectType.AREA_OF_EFFECT";
    if (value == 1) return "ObjectType.CREATURE";
    if (value == 8) return "ObjectType.DOOR";
    if (value == 256) return "ObjectType.ENCOUNTER";
    if (value == 32767) return "ObjectType.INVALID";
    if (value == 2) return "ObjectType.ITEM";
    if (value == 64) return "ObjectType.PLACEABLE";
    if (value == 128) return "ObjectType.STORE";
    if (value == 4) return "ObjectType.TRIGGER";
    if (value == 32) return "ObjectType.WAYPOINT";
    return "ObjectType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ObjectType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ObjectType.(not found: " + value + ")";
  }
}
