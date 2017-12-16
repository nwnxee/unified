package org.nwnx.nwnx2.jvm;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.Map.Entry;
import java.util.concurrent.Callable;
import java.util.concurrent.ConcurrentLinkedQueue;

import org.nwnx.nwnx2.jvm.ScheduledEvery.Timing;

public class Scheduler {
	private Scheduler() { }

	private static Map<Long, List<Runnable>> tokenSets =
		Collections.synchronizedMap(new HashMap<Long,List<Runnable>>());

	private static Map<NWObject, List<Runnable>> tokenMap =
		Collections.synchronizedMap(new HashMap<NWObject, List<Runnable>>());

	private static Queue<Runnable> scheduled =
		new ConcurrentLinkedQueue<Runnable>();

	private static List<ScheduledEvery> scheduledEvery =
		Collections.synchronizedList(new LinkedList<ScheduledEvery>());

	private static Set<SchedulerListener> scheduleListeners =
		Collections.synchronizedSet(new HashSet<SchedulerListener>());

	private static List<ExceptionHandler> exceptionHandlers =
		Collections.synchronizedList(new LinkedList<ExceptionHandler>());

	private static long lastToken = 0;

	volatile private static Thread contextThread = null;

	/**
	 * Checks if the calling thread is the NWN context thread. This
	 * is used by the Scheduler itself to skip some schedule/scheduleWait
	 * round trips, and exported here for convenience.
	 *
	 * @return true if the calling Thread is the one having NWN Context
	 */
	public static synchronized boolean isInContextThread() {
		return Thread.currentThread().equals(contextThread);
	}

	@SuppressWarnings("unused")
	private static void token(NWObject objSelf, String token) {
		boolean unsetContext = false;
		if (null != contextThread) {
			contextThread = Thread.currentThread();
			unsetContext = true;
		}

		try {
			handleEvery(Timing.BEFORE);

			for (SchedulerListener listener : scheduleListeners)
				listener.context(objSelf);

			Long tok = Long.parseLong(token);
			if (tokenSets.containsKey(tok))
				for (Runnable e : tokenSets.remove(tok))
					e.run();
			else
				for (SchedulerListener listener : scheduleListeners)
					listener.missedToken(objSelf, token);

			handleEvery(Timing.AFTER);
		} catch (RuntimeException ex) {
			for (ExceptionHandler h : exceptionHandlers)
				if (h.handleException(ex))
					return;
			throw ex;
		}

		if (unsetContext)
			contextThread = null;
	}

	@SuppressWarnings("unused")
	private static void event(NWObject objSelf, String event) {
		contextThread = Thread.currentThread();

		try {
			handleEvery(Timing.BEFORE);

			for (SchedulerListener listener : scheduleListeners)
				listener.context(objSelf);

			for (SchedulerListener sl : scheduleListeners)
				sl.event(objSelf, event);

			handleEvery(Timing.AFTER);
		} catch (RuntimeException ex) {
			for (ExceptionHandler h : exceptionHandlers)
				if (h.handleException(ex))
					return;
			throw ex;
		}

		contextThread = null;
	}

	public static void addSchedulerListener(SchedulerListener listener) {
		scheduleListeners.add(listener);
	}

	public static void removeSchedulerListener(SchedulerListener listener) {
		scheduleListeners.remove(listener);
	}

	/**
	 * Registers an ExceptionHandler, which will be called for RuntimeExcepions
	 * happening in event() and token().
	 */
	public static void registerExceptionHandler(ExceptionHandler h) {
		exceptionHandlers.add(h);
	}

	public static void unregisterExceptionHandler(ExceptionHandler h) {
		exceptionHandlers.remove(h);
	}

	/**
	 * Schedules the given code block for execution the next
	 * time we have NWN context (through flushQueues()).
	 */
	public static void schedule(Runnable anon) {
		if (isInContextThread())
			anon.run();
		else
			scheduled.add(anon);
	}

	/**
	 * Schedules the given code block and then blocks the calling
	 * thread until the block has been executed.
	 * Will wait() on the Anon object passed in.
	 * @param anon
	 * @throws InterruptedException
	 */
	public static <T> T scheduleWait(final Callable<T> anon) throws Exception {
		if (isInContextThread())
			return anon.call();

		final List<T> outer_ret = Collections.synchronizedList(new LinkedList<T>());
		final List<Exception> outer_ex = Collections.synchronizedList(new LinkedList<Exception>());
		scheduled.add(new Runnable() {
			@Override
			public void run()  {
				T ret;
				try {
					ret = anon.call();
					outer_ret.add(ret);
				} catch (Exception e) {
					outer_ex.add(e);
				}

				synchronized(anon) { anon.notify(); }
			}
		});
		synchronized(anon) { anon.wait(); }

		if (outer_ex.size() > 0)
			throw outer_ex.get(0);
		else
			return outer_ret.get(0);
	}

	public static void every(ScheduledEvery sched) {
		scheduledEvery.add(sched);
	}

	/**
	 * Assigns a Anon block to obj and queues it for execution.
	 * This is the equivalent to AssignCommand() you know.
	 */
	public static void assign(NWObject obj, Runnable anon) {
		if (!tokenMap.containsKey(obj))
			tokenMap.put(obj, new LinkedList<Runnable>());
		tokenMap.get(obj).add(anon);
	}

	/**
	 * Assigns a Anon block to obj and schedules it for later execution
	 * by the nwserver scheduler.
	 *
	 * This uses the NWN-native scheduler. Actual execution
	 * delay depends on server scheduler busyness and should
	 * NOT be adjusted for unless you know what you are doing.
	 *
	 * All scheduled delays drift forwards by the time it takes
	 * to execute the JVM roundtrip.
	 *
	 * Granularity is limited and environment-dependant.
	 */
	public static void delay(NWObject obj, long delay, Runnable anon) {
		LinkedList<Runnable> e = new LinkedList<Runnable>();
		e.add(anon);
		delaySet(obj, delay, e);
	}

	/**
	 * Assign a Anon block to obj and immediately execute it, instead
	 * of queueing it and waiting for flushQueues() to be called.
	 */
	public static void assignNow(NWObject obj, Runnable anon) {
		LinkedList<Runnable> e = new LinkedList<Runnable>();
		e.add(anon);
		assignSet(obj, e);
	}

	/**
	 * Flushes the assign() and delay() queues. You need to call
	 * this periodically, ideally after finishing a event call from nwserver.
	 * @return the number of queued blocks remaining.
	 */
	public static long flushQueues() {
		return flushQueues(0);
	}

	/**
	 * Flushes the assign() and delay() queues. You need to call
	 * this periodically, ideally after finishing a event call from nwserver.
	 * Spends a maximum of maxMilliSecondsSpent milliseconds doing scheduled
	 * code blocks; the rest will be kept until the next call.
	 * @return the number of queued blocks remaining.
	 */
	public static long flushQueues(long maxMilliSecondsSpent) {
		synchronized(tokenMap) {
			for (Entry<NWObject, List<Runnable>> obj : tokenMap.entrySet())
				assignSet(obj.getKey(), obj.getValue());
			tokenMap.clear();
		}
		synchronized (scheduled) {
			long start = System.currentTimeMillis();
			while (scheduled.size() > 0  && ( maxMilliSecondsSpent == 0 ||
					System.currentTimeMillis() - start < maxMilliSecondsSpent))
				try {
					scheduled.remove().run();
				} catch (RuntimeException ex) {
					boolean handled = false;
					for (ExceptionHandler h : exceptionHandlers)
						if (h.handleException(ex)) {
							handled = true;
							break;
						}
					if (!handled)
						throw ex;
				}
		}

		int remaining = scheduled.size() + tokenMap.size();

		for (SchedulerListener listener : scheduleListeners)
			listener.postFlushQueues(remaining);

		return remaining;
	}

	private static void assignSet(NWObject obj, List<Runnable> anon) {
		Long token = lastToken++;
		tokenSets.put(token, anon);
		NWScript.setLocalString(NWObject.MODULE, "jvm_token", token.toString());
		NWScript.setLocalString(NWObject.MODULE, "jvm_token_type", "execute");
		NWScript.executeScript("jvm_token", obj);
	}

	private static void delaySet(NWObject obj, long delay, List<Runnable> anon) {
		Long token = lastToken++;
		tokenSets.put(token, anon);
		float f_delay = (float) (((double) delay) / 1000);
		NWScript.setLocalString(NWObject.MODULE, "jvm_token", token.toString());
		NWScript.setLocalString(NWObject.MODULE, "jvm_token_type", "delay");
		NWScript.setLocalFloat(NWObject.MODULE, "jvm_token_delay", f_delay);
		NWScript.executeScript("jvm_token", obj);
	}

	private synchronized static void handleEvery(Timing timing) {
		final long n = System.currentTimeMillis();
		List<ScheduledEvery> toRemove = new LinkedList<ScheduledEvery>();
		for (ScheduledEvery e : scheduledEvery) {
			if (e.isStopped()) {
				toRemove.add(e);
				continue;
			}

			if (!timing.equals(e.getTiming()))
				continue;

			if (n >= (e.getLastRun() + e.getInterval())) {
				try {
					e.run();
				} catch (Exception ex) {
					ex.printStackTrace();
					toRemove.add(e);
				}
			}
		}
		scheduledEvery.removeAll(toRemove);
	}

}