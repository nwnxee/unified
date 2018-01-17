package org.nwnx.nwnx2.jvm;

public interface ResManListener {
	/**
	 * Gets called when NWServer wants to load a resource.
	 *
	 * This method needs to return the latest modification
	 * time of +resRef+ (as a unixtime) IF you intend to serve it.
	 *
	 * Return -1 to not handle the request, and pass it
	 * on to other listeners or NWServer. Unhandled requests
	 * will be handled by nwserver itself by searching haks and base
	 * resources.
	 */
	public int exists(String resRef);

	/**
	 * Gets called when NWServer wants to load a resource.
	 *
	 * This will only be called if you returned a timestamp in
	 * exists() and your timestamp is the newest.
	 *
	 * You must not return NULL here.
	 */
	public byte[] demand(String resRef);
}
