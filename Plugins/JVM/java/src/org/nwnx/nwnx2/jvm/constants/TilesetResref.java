package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILESET_RESREF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TilesetResref {
  private TilesetResref() {}

  public final static String BEHOLDER_CAVES = "tib01";
  public final static String CASTLE_INTERIOR = "tic01";
  public final static String CITY_EXTERIOR = "tcn01";
  public final static String CITY_INTERIOR = "tin01";
  public final static String CRYPT = "tdc01";
  public final static String DESERT = "ttd01";
  public final static String DROW_INTERIOR = "tid01";
  public final static String DUNGEON = "tde01";
  public final static String FOREST = "ttf01";
  public final static String FROZEN_WASTES = "tti01";
  public final static String ILLITHID_INTERIOR = "tii01";
  public final static String MICROSET = "tms01";
  public final static String MINES_AND_CAVERNS = "tdm01";
  public final static String RUINS = "tdr01";
  public final static String RURAL = "ttr01";
  public final static String RURAL_WINTER = "tts01";
  public final static String SEWERS = "tds01";
  public final static String UNDERDARK = "ttu01";

  public static String nameOf(int value) {
    return "TilesetResref.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TilesetResref.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TilesetResref.(not found: " + value + ")";
  }
}
