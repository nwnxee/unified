package org.nwnx.nwnx2.jvm;

public class NWNotInContextException extends RuntimeException {
	private static final long serialVersionUID = 4035358890793811865L;

	public NWNotInContextException(String msg) {
		super(msg);
	}
}
