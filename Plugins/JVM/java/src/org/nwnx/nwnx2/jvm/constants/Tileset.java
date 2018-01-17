package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILESET".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Tileset {
  private Tileset() {}

  public final static String RESREF_BEHOLDER_CAVES = "tib01";
  public final static String RESREF_CASTLE_INTERIOR = "tic01";
  public final static String RESREF_CITY_EXTERIOR = "tcn01";
  public final static String RESREF_CITY_INTERIOR = "tin01";
  public final static String RESREF_CRYPT = "tdc01";
  public final static String RESREF_DESERT = "ttd01";
  public final static String RESREF_DROW_INTERIOR = "tid01";
  public final static String RESREF_DUNGEON = "tde01";
  public final static String RESREF_FOREST = "ttf01";
  public final static String RESREF_FROZEN_WASTES = "tti01";
  public final static String RESREF_ILLITHID_INTERIOR = "tii01";
  public final static String RESREF_MICROSET = "tms01";
  public final static String RESREF_MINES_AND_CAVERNS = "tdm01";
  public final static String RESREF_RUINS = "tdr01";
  public final static String RESREF_RURAL = "ttr01";
  public final static String RESREF_RURAL_WINTER = "tts01";
  public final static String RESREF_SEWERS = "tds01";
  public final static String RESREF_UNDERDARK = "ttu01";

  public static String nameOf(int value) {
    return "Tileset.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Tileset.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Tileset.(not found: " + value + ")";
  }
}
