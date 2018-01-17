package org.nwnx.nwnx2.jvm;

public class ScheduledEvery {
	public enum Policy {
		/**
		 * Best effort scheduling simply runs scheduled timers
		 * when at least the given interval has passed, with
		 * no guarantees of timely scheduling whatsover. This
		 * is the default.
		 */
		AS_AVAILABLE
	};

	public enum Timing {

		/**
		 * This Scheduled runs before a event or token gets distributed.
		 * (The default, see @Every)
		 */
		BEFORE,

		/**
		 * This Scheduled runs after a event or token gets distributed.
		 */
		AFTER
	};

	private final ScheduledAnon anon;
	private Policy policy;
	private final long every;
	private long lastRun = 0;
	private long runCount = 0;
	private boolean stopped = false;
	private long runsRemaining = -1;
	private Timing timing = Timing.BEFORE;

	public ScheduledEvery(long every, ScheduledAnon anon, Policy policy) {
		this.every = every;
		this.anon = anon;
		this.setPolicy(policy);
	}

	public void stop() {
		stopped = true;
	}
	public boolean isStopped() {
		return stopped;
	}

	public ScheduledAnon getAnon() {
		return anon;
	}

	public long getInterval() {
		return every;
	}

	public long getLastRun() {
		return lastRun;
	}

	public long getDrift() {
		if (lastRun == 0)
			return 0;
		else
			return System.currentTimeMillis() - (lastRun + every);
	}

	/**
	 * Run this scheduled status. Usually not called by you, but
	 * by the Scheduler instead.
	 */
	public void run() throws Exception {
		if (isStopped())
			return;

		if (runsRemaining != -1 && runsRemaining < 1) {
			stop();
			return;
		}

		assert(runsRemaining >= -1);

		anon.e(this);
		lastRun = System.currentTimeMillis();
		runCount += 1;

		if (runsRemaining != -1)
			runsRemaining -= 1;
	}

	/**
	 * Returns how often this ScheduledEvery has been run, excluding
	 * any currently-running.
	 */
	public long getRunCount() {
		return runCount;
	}

	/**
	 * Sets how often this ScheduledEvery should run (after any currently-running).
	 * A value of -1 means to run forever.
	 * @param runsRemaining
	 */
	public void setRunsRemaining(long runsRemaining) {
		assert(runsRemaining >= -1);
		this.runsRemaining = runsRemaining;
	}

	/**
	 * Returns how often this ScheduledEvery should run (after any currently-running).
	 * @return
	 */
	public long getRunsRemaining() {
		return runsRemaining;
	}

	public void setTiming(Timing timing) {
		this.timing = timing;
	}

	public Timing getTiming() {
		return timing;
	}

	public void setPolicy(Policy policy) {
		this.policy = policy;
	}

	public Policy getPolicy() {
		return policy;
	}
}
