package org.nwnx.nwnx2.jvm;

public interface SchedulerListener {

	/**
	 * Called after flushing all queued up tokens (via assign/delay).
	 * @param remainingTokens
	 */
	void postFlushQueues(int remainingTokens);

	/**
	 * Called when NWServer tried to execute a token that didn't exist.
	 * @param objSelf
	 * @param token
	 */
	void missedToken(NWObject objSelf, String token);

	/**
	 * Called when NWServer sends a event. Use this to handle events.
	 * @param objSelf
	 * @param event
	 */
	void event(NWObject objSelf, String event);

	/**
	 * Called each time the nwserver thread yields to the JVM.
	 * @param objSelf
	 */
	void context(NWObject objSelf);
}