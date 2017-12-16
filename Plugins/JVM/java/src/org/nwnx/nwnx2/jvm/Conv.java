package org.nwnx.nwnx2.jvm;

import java.io.UnsupportedEncodingException;

final public class Conv {
	private static String nativeCharset = "ISO-8859-1";

	final public static void setNativeCharset(String charset) {
		nativeCharset = charset;
	}

	final public static String getNativeCharset() {
		return nativeCharset;
	}

	final public static byte[] toNative(String s) throws UnsupportedEncodingException {
		return s.getBytes(nativeCharset);
	}

	final public static String fromNative(byte[] v) throws UnsupportedEncodingException {
		return new String(v, nativeCharset);
	}
}
