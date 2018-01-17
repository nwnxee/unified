package org.nwnx.nwnx2.jvm;


public class SCORCO {
	final static public String KEY_RCO = SCORCO.class.getName();
	final static public String KEY_SCO = SCORCO.class.getName();

	private SCORCO() {
	}

	private static volatile byte[] rcoData = null;
	private static volatile byte[] scoData = null;

	/**
	 * Loads a Item or Creature via SCO/RCO into the game. Needs NWN context.
	 *
	 * @param data the raw GFF data.
	 * @param toLocation the location to create the object at
	 * @param toOwner the inventory to create the object in (if item)
	 * @return the object, or null on failure
	 */
	synchronized public static NWObject loadObject(final byte[] gffData, final NWLocation toLocation, final NWObject toOwner) {
		rcoData = gffData;
		return NWScript.retrieveCampaignObject("NWNX", KEY_RCO, toLocation, toOwner, null);
	}

	@SuppressWarnings("unused")
	private static byte[] rco(final String key) {
		byte[] ret = rcoData;
		rcoData = null;
		return ret;
	}

	/**
	 * Retrieves the raw GFF data of a Item or Creature. Needs NWN context.
	 *
	 * @param o the Item or Creature to serialize
	 * @return a byte array containing valid GFF data, or null on failure
	 */
	synchronized public static byte[] saveObject(final NWObject o) {
		NWScript.storeCampaignObject("NWNX", KEY_SCO, o, null);
		byte ret[] = scoData;
		scoData = null;
		return ret;
	}

	@SuppressWarnings("unused")
	private static void sco(final String key, final byte[] gffData) {
		if (key.equals(KEY_SCO))
			scoData = gffData;
	}
}
