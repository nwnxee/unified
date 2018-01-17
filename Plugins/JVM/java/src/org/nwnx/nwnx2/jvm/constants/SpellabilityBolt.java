package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_BOLT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityBolt {
  private SpellabilityBolt() {}

  public final static int ABILITY_DRAIN_CHARISMA = 205;
  public final static int ABILITY_DRAIN_CONSTITUTION = 206;
  public final static int ABILITY_DRAIN_DEXTERITY = 207;
  public final static int ABILITY_DRAIN_INTELLIGENCE = 208;
  public final static int ABILITY_DRAIN_STRENGTH = 209;
  public final static int ABILITY_DRAIN_WISDOM = 210;
  public final static int ACID = 211;
  public final static int CHARM = 212;
  public final static int COLD = 213;
  public final static int CONFUSE = 214;
  public final static int DAZE = 215;
  public final static int DEATH = 216;
  public final static int DISEASE = 217;
  public final static int DOMINATE = 218;
  public final static int FIRE = 219;
  public final static int KNOCKDOWN = 220;
  public final static int LEVEL_DRAIN = 221;
  public final static int LIGHTNING = 222;
  public final static int PARALYZE = 223;
  public final static int POISON = 224;
  public final static int SHARDS = 225;
  public final static int SLOW = 226;
  public final static int STUN = 227;
  public final static int WEB = 228;

  public static String nameOf(int value) {
    if (value == 205) return "SpellabilityBolt.ABILITY_DRAIN_CHARISMA";
    if (value == 206) return "SpellabilityBolt.ABILITY_DRAIN_CONSTITUTION";
    if (value == 207) return "SpellabilityBolt.ABILITY_DRAIN_DEXTERITY";
    if (value == 208) return "SpellabilityBolt.ABILITY_DRAIN_INTELLIGENCE";
    if (value == 209) return "SpellabilityBolt.ABILITY_DRAIN_STRENGTH";
    if (value == 210) return "SpellabilityBolt.ABILITY_DRAIN_WISDOM";
    if (value == 211) return "SpellabilityBolt.ACID";
    if (value == 212) return "SpellabilityBolt.CHARM";
    if (value == 213) return "SpellabilityBolt.COLD";
    if (value == 214) return "SpellabilityBolt.CONFUSE";
    if (value == 215) return "SpellabilityBolt.DAZE";
    if (value == 216) return "SpellabilityBolt.DEATH";
    if (value == 217) return "SpellabilityBolt.DISEASE";
    if (value == 218) return "SpellabilityBolt.DOMINATE";
    if (value == 219) return "SpellabilityBolt.FIRE";
    if (value == 220) return "SpellabilityBolt.KNOCKDOWN";
    if (value == 221) return "SpellabilityBolt.LEVEL_DRAIN";
    if (value == 222) return "SpellabilityBolt.LIGHTNING";
    if (value == 223) return "SpellabilityBolt.PARALYZE";
    if (value == 224) return "SpellabilityBolt.POISON";
    if (value == 225) return "SpellabilityBolt.SHARDS";
    if (value == 226) return "SpellabilityBolt.SLOW";
    if (value == 227) return "SpellabilityBolt.STUN";
    if (value == 228) return "SpellabilityBolt.WEB";
    return "SpellabilityBolt.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityBolt.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityBolt.(not found: " + value + ")";
  }
}
