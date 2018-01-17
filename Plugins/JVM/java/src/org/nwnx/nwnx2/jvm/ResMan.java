package org.nwnx.nwnx2.jvm;

import java.util.LinkedList;
import java.util.List;

public class ResMan {
	private static List<ResManListener> handlers =
		new LinkedList<ResManListener>();

	public static void addResManListener(ResManListener h) {
		handlers.add(h);
	}

	private ResMan() {
	}

	@SuppressWarnings("unused")
	private static int exists(String resRef) {
		int ret = -1;

		for (ResManListener h : handlers) {
			int current = h.exists(resRef);
			if (current > ret)
				ret = current;
		}

		return ret;
	}

	@SuppressWarnings("unused")
	private static byte[] demand(String resRef) {
		byte[] ret = null;
		for (ResManListener h : handlers)
			if (null != (ret = h.demand(resRef)))
				return ret;

		return null;
	}
}
