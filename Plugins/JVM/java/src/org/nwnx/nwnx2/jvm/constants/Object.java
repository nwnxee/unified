package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "OBJECT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Object {
  private Object() {}

  public final static int TYPE_ALL = 32767;
  public final static int TYPE_AREA_OF_EFFECT = 16;
  public final static int TYPE_CREATURE = 1;
  public final static int TYPE_DOOR = 8;
  public final static int TYPE_ENCOUNTER = 256;
  public final static int TYPE_INVALID = 32767;
  public final static int TYPE_ITEM = 2;
  public final static int TYPE_PLACEABLE = 64;
  public final static int TYPE_STORE = 128;
  public final static int TYPE_TRIGGER = 4;
  public final static int TYPE_WAYPOINT = 32;

  public static String nameOf(int value) {
    if (value == 32767) return "Object.TYPE_ALL";
    if (value == 16) return "Object.TYPE_AREA_OF_EFFECT";
    if (value == 1) return "Object.TYPE_CREATURE";
    if (value == 8) return "Object.TYPE_DOOR";
    if (value == 256) return "Object.TYPE_ENCOUNTER";
    if (value == 32767) return "Object.TYPE_INVALID";
    if (value == 2) return "Object.TYPE_ITEM";
    if (value == 64) return "Object.TYPE_PLACEABLE";
    if (value == 128) return "Object.TYPE_STORE";
    if (value == 4) return "Object.TYPE_TRIGGER";
    if (value == 32) return "Object.TYPE_WAYPOINT";
    return "Object.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Object.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Object.(not found: " + value + ")";
  }
}
