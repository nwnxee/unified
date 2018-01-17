package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYMISC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunitymisc {
  private IpConstImmunitymisc() {}

  public final static int BACKSTAB = 0;
  public final static int CRITICAL_HITS = 8;
  public final static int DEATH_MAGIC = 9;
  public final static int DISEASE = 4;
  public final static int FEAR = 5;
  public final static int KNOCKDOWN = 6;
  public final static int LEVEL_ABIL_DRAIN = 1;
  public final static int MINDSPELLS = 2;
  public final static int PARALYSIS = 7;
  public final static int POISON = 3;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstImmunitymisc.BACKSTAB";
    if (value == 8) return "IpConstImmunitymisc.CRITICAL_HITS";
    if (value == 9) return "IpConstImmunitymisc.DEATH_MAGIC";
    if (value == 4) return "IpConstImmunitymisc.DISEASE";
    if (value == 5) return "IpConstImmunitymisc.FEAR";
    if (value == 6) return "IpConstImmunitymisc.KNOCKDOWN";
    if (value == 1) return "IpConstImmunitymisc.LEVEL_ABIL_DRAIN";
    if (value == 2) return "IpConstImmunitymisc.MINDSPELLS";
    if (value == 7) return "IpConstImmunitymisc.PARALYSIS";
    if (value == 3) return "IpConstImmunitymisc.POISON";
    return "IpConstImmunitymisc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunitymisc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunitymisc.(not found: " + value + ")";
  }
}
