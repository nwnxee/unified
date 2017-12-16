package org.nwnx.nwnx2.jvm;

public interface ExceptionHandler {

	/**
	 * Called when an exception occurs. Return true to not
	 * pass it on, false to pass it on to the caller.
	 */
	public boolean handleException(Exception ex);
}
