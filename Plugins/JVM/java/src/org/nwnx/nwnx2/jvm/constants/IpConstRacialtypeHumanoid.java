package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_RACIALTYPE_HUMANOID".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstRacialtypeHumanoid {
  private IpConstRacialtypeHumanoid() {}

  public final static int GOBLINOID = 12;
  public final static int MONSTROUS = 13;
  public final static int ORC = 14;
  public final static int REPTILIAN = 15;

  public static String nameOf(int value) {
    if (value == 12) return "IpConstRacialtypeHumanoid.GOBLINOID";
    if (value == 13) return "IpConstRacialtypeHumanoid.MONSTROUS";
    if (value == 14) return "IpConstRacialtypeHumanoid.ORC";
    if (value == 15) return "IpConstRacialtypeHumanoid.REPTILIAN";
    return "IpConstRacialtypeHumanoid.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstRacialtypeHumanoid.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstRacialtypeHumanoid.(not found: " + value + ")";
  }
}
