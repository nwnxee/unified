package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_SAVEVS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstSavevs {
  private IpConstSavevs() {}

  public final static int ACID = 1;
  public final static int COLD = 3;
  public final static int DEATH = 4;
  public final static int DISEASE = 5;
  public final static int DIVINE = 6;
  public final static int ELECTRICAL = 7;
  public final static int FEAR = 8;
  public final static int FIRE = 9;
  public final static int MINDAFFECTING = 11;
  public final static int NEGATIVE = 12;
  public final static int POISON = 13;
  public final static int POSITIVE = 14;
  public final static int SONIC = 15;
  public final static int UNIVERSAL = 0;

  public static String nameOf(int value) {
    if (value == 1) return "IpConstSavevs.ACID";
    if (value == 3) return "IpConstSavevs.COLD";
    if (value == 4) return "IpConstSavevs.DEATH";
    if (value == 5) return "IpConstSavevs.DISEASE";
    if (value == 6) return "IpConstSavevs.DIVINE";
    if (value == 7) return "IpConstSavevs.ELECTRICAL";
    if (value == 8) return "IpConstSavevs.FEAR";
    if (value == 9) return "IpConstSavevs.FIRE";
    if (value == 11) return "IpConstSavevs.MINDAFFECTING";
    if (value == 12) return "IpConstSavevs.NEGATIVE";
    if (value == 13) return "IpConstSavevs.POISON";
    if (value == 14) return "IpConstSavevs.POSITIVE";
    if (value == 15) return "IpConstSavevs.SONIC";
    if (value == 0) return "IpConstSavevs.UNIVERSAL";
    return "IpConstSavevs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstSavevs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstSavevs.(not found: " + value + ")";
  }
}
