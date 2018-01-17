package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeat {
  private IpConstFeat() {}

  public final static int ALERTNESS = 0;
  public final static int AMBIDEXTROUS = 1;
  public final static int ARMOR_PROF_HEAVY = 24;
  public final static int ARMOR_PROF_LIGHT = 25;
  public final static int ARMOR_PROF_MEDIUM = 26;
  public final static int CLEAVE = 2;
  public final static int COMBAT_CASTING = 3;
  public final static int DISARM = 28;
  public final static int DISARM_WHIP = 37;
  public final static int DODGE = 4;
  public final static int EXTRA_TURNING = 5;
  public final static int HIDE_IN_PLAIN_SIGHT = 31;
  public final static int IMPCRITUNARM = 20;
  public final static int KNOCKDOWN = 6;
  public final static int MOBILITY = 27;
  public final static int PLAYER_TOOL_01 = 53;
  public final static int PLAYER_TOOL_02 = 54;
  public final static int PLAYER_TOOL_03 = 55;
  public final static int PLAYER_TOOL_04 = 56;
  public final static int PLAYER_TOOL_05 = 57;
  public final static int PLAYER_TOOL_06 = 58;
  public final static int PLAYER_TOOL_07 = 59;
  public final static int PLAYER_TOOL_08 = 60;
  public final static int PLAYER_TOOL_09 = 61;
  public final static int PLAYER_TOOL_10 = 62;
  public final static int POINTBLANK = 7;
  public final static int POWERATTACK = 16;
  public final static int RAPID_SHOT = 30;
  public final static int SHIELD_PROFICIENCY = 35;
  public final static int SNEAK_ATTACK_1D6 = 32;
  public final static int SNEAK_ATTACK_2D6 = 33;
  public final static int SNEAK_ATTACK_3D6 = 34;
  public final static int SNEAK_ATTACK_5D6 = 39;
  public final static int SPELLFOCUSABJ = 8;
  public final static int SPELLFOCUSCON = 9;
  public final static int SPELLFOCUSDIV = 10;
  public final static int SPELLFOCUSENC = 11;
  public final static int SPELLFOCUSEVO = 12;
  public final static int SPELLFOCUSILL = 13;
  public final static int SPELLFOCUSNEC = 14;
  public final static int SPELLPENETRATION = 15;
  public final static int TWO_WEAPON_FIGHTING = 17;
  public final static int USE_POISON = 36;
  public final static int WEAPFINESSE = 19;
  public final static int WEAPON_PROF_CREATURE = 38;
  public final static int WEAPON_PROF_EXOTIC = 21;
  public final static int WEAPON_PROF_MARTIAL = 22;
  public final static int WEAPON_PROF_SIMPLE = 23;
  public final static int WEAPSPEUNARM = 18;
  public final static int WHIRLWIND = 29;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstFeat.ALERTNESS";
    if (value == 1) return "IpConstFeat.AMBIDEXTROUS";
    if (value == 24) return "IpConstFeat.ARMOR_PROF_HEAVY";
    if (value == 25) return "IpConstFeat.ARMOR_PROF_LIGHT";
    if (value == 26) return "IpConstFeat.ARMOR_PROF_MEDIUM";
    if (value == 2) return "IpConstFeat.CLEAVE";
    if (value == 3) return "IpConstFeat.COMBAT_CASTING";
    if (value == 28) return "IpConstFeat.DISARM";
    if (value == 37) return "IpConstFeat.DISARM_WHIP";
    if (value == 4) return "IpConstFeat.DODGE";
    if (value == 5) return "IpConstFeat.EXTRA_TURNING";
    if (value == 31) return "IpConstFeat.HIDE_IN_PLAIN_SIGHT";
    if (value == 20) return "IpConstFeat.IMPCRITUNARM";
    if (value == 6) return "IpConstFeat.KNOCKDOWN";
    if (value == 27) return "IpConstFeat.MOBILITY";
    if (value == 53) return "IpConstFeat.PLAYER_TOOL_01";
    if (value == 54) return "IpConstFeat.PLAYER_TOOL_02";
    if (value == 55) return "IpConstFeat.PLAYER_TOOL_03";
    if (value == 56) return "IpConstFeat.PLAYER_TOOL_04";
    if (value == 57) return "IpConstFeat.PLAYER_TOOL_05";
    if (value == 58) return "IpConstFeat.PLAYER_TOOL_06";
    if (value == 59) return "IpConstFeat.PLAYER_TOOL_07";
    if (value == 60) return "IpConstFeat.PLAYER_TOOL_08";
    if (value == 61) return "IpConstFeat.PLAYER_TOOL_09";
    if (value == 62) return "IpConstFeat.PLAYER_TOOL_10";
    if (value == 7) return "IpConstFeat.POINTBLANK";
    if (value == 16) return "IpConstFeat.POWERATTACK";
    if (value == 30) return "IpConstFeat.RAPID_SHOT";
    if (value == 35) return "IpConstFeat.SHIELD_PROFICIENCY";
    if (value == 32) return "IpConstFeat.SNEAK_ATTACK_1D6";
    if (value == 33) return "IpConstFeat.SNEAK_ATTACK_2D6";
    if (value == 34) return "IpConstFeat.SNEAK_ATTACK_3D6";
    if (value == 39) return "IpConstFeat.SNEAK_ATTACK_5D6";
    if (value == 8) return "IpConstFeat.SPELLFOCUSABJ";
    if (value == 9) return "IpConstFeat.SPELLFOCUSCON";
    if (value == 10) return "IpConstFeat.SPELLFOCUSDIV";
    if (value == 11) return "IpConstFeat.SPELLFOCUSENC";
    if (value == 12) return "IpConstFeat.SPELLFOCUSEVO";
    if (value == 13) return "IpConstFeat.SPELLFOCUSILL";
    if (value == 14) return "IpConstFeat.SPELLFOCUSNEC";
    if (value == 15) return "IpConstFeat.SPELLPENETRATION";
    if (value == 17) return "IpConstFeat.TWO_WEAPON_FIGHTING";
    if (value == 36) return "IpConstFeat.USE_POISON";
    if (value == 19) return "IpConstFeat.WEAPFINESSE";
    if (value == 38) return "IpConstFeat.WEAPON_PROF_CREATURE";
    if (value == 21) return "IpConstFeat.WEAPON_PROF_EXOTIC";
    if (value == 22) return "IpConstFeat.WEAPON_PROF_MARTIAL";
    if (value == 23) return "IpConstFeat.WEAPON_PROF_SIMPLE";
    if (value == 18) return "IpConstFeat.WEAPSPEUNARM";
    if (value == 29) return "IpConstFeat.WHIRLWIND";
    return "IpConstFeat.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeat.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeat.(not found: " + value + ")";
  }
}
