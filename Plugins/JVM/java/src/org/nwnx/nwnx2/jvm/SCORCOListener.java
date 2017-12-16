package org.nwnx.nwnx2.jvm;

public interface SCORCOListener {
	/**
	 * Return a valid byte array to handle this request,
	 * return null to not handle it.
	 * @param key
	 * @return
	 */
	public byte[] onRCO(String key);

	/**
	 * Return true to handle this request, return false
	 * to not handle it.
	 * @param key
	 * @param gffData
	 */
	public boolean onSCO(String key, byte[] gffData);
}
