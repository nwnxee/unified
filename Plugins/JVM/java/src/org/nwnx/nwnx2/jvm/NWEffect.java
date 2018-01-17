package org.nwnx.nwnx2.jvm;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class NWEffect {
	private static List<EffectHandler> classHandlers =
		Collections.synchronizedList(new LinkedList<EffectHandler>());

	private static List<ApplyListener> applyListeners =
		Collections.synchronizedList(new LinkedList<ApplyListener>());

	private static List<ExceptionHandler> exceptionHandlers =
		Collections.synchronizedList(new LinkedList<ExceptionHandler>());

	/**
	 * A ClassHandler is used to implement custom object classes.
	 * You can create a object hierarchy this way.
	 */
	public interface EffectHandler {
		/**
		 * Return an instance of NWObject to have this class handler
		 * handle the given object, or return null.
		 */
		public abstract NWEffect handleEffectClass(NWEffect eff);
	}

	public interface ApplyListener {
		public NWEffect preApply(NWEffect eff);
		public void newEffect(NWEffect eff);
		public void postApply(NWEffect eff);
	}

	public static void registerEffectHandler(EffectHandler e) {
		classHandlers.add(0, e);
	}

	public static void unregisterEffectHandler(EffectHandler h) {
		classHandlers.remove(h);
	}

	/**
	 * Registers an ExceptionHandler, which will be called for RuntimeExcepions
	 * happening in apply().
	 */
	public static void registerExceptionHandler(ExceptionHandler h) {
		exceptionHandlers.add(h);
	}

	public static void unregisterExceptionHandler(ExceptionHandler h) {
		exceptionHandlers.remove(h);
	}

	public static void addApplyListener(ApplyListener applyListener) {
		applyListeners.add(applyListener);
	}

	public static void removeApplyListener(ApplyListener applyListener) {
		applyListeners.remove(applyListener);
	}

	public static List<EffectHandler> getEffectHandlers() {
		return classHandlers;
	}

	/**
	 * Creates a new NWEffect by walking the registered class handlers
	 * and returning the first one that matches.
	 * Throws an exception if no object matches, or no handlers have been
	 * registered.
	 * @param oid
	 * @return a NWEffect
	 */
	public static NWEffect apply(int oid) {
		NWEffect o = new NWEffect(oid);
		NWEffect ret = null;

		try {

			for (ApplyListener a : applyListeners)
				if ((ret = a.preApply(o)) != null)
					break;

			if (ret == null)
				if (classHandlers.size() > 0) {
					for (EffectHandler e : classHandlers) {
						ret = e.handleEffectClass(o);
						if (ret != null) {
							for (ApplyListener a : applyListeners)
								a.newEffect(ret);
							break;
						}
					}
					if (ret == null)
						throw new RuntimeException("No class handler that matches " + oid + " registered.");
				} else
					throw new RuntimeException("No class handlers registered.");

			for (ApplyListener a : applyListeners)
				a.postApply(ret);

		} catch (RuntimeException e) {
			for (ExceptionHandler h : exceptionHandlers)
				if (h.handleException(e))
					return null;
			throw e;
		}

		return ret;
	}

	final private int oid;

	public NWEffect(int oid) {
		this.oid = oid;
	}

	@Deprecated
	public int oid() {
		return oid;
	}

	public int getEffectId() {
		return oid;
	}

	private int
		type = -2,
		subType = -2,
		durationType = -2,
		spellId = -2;
	private NWObject creator = null;

	/**
	 * Returns this NWEffects EffectType, and caches it for future invocations.
	 */
	public int type() {
		if (type == -2)
			type = NWScript.getEffectType(this);
		return type;
	}

	/**
	 * Returns this NWEffects SubType, and caches it for future invocations.
	 */
	public int subType() {
		if (subType == -2)
			subType = NWScript.getEffectSubType(this);
		return subType;
	}

	/**
	 * Returns this NWEffects DurationType, and caches it for future invocations.
	 */
	public int durationType() {
		if (durationType == -2)
			durationType = NWScript.getEffectDurationType(this);
		return durationType;
	}

	/**
	 * Returns this NWEffects spell ID, and caches it for future invocations.
	 */
	public int spellId() {
		if (spellId == -2)
			spellId = NWScript.getEffectSpellId(this);
		return spellId;
	}

	/**
	 * Returns this NWEffects creator, and caches it for future invocations.
	 */
	public NWObject creator() {
		if (creator == null)
			creator = NWScript.getEffectCreator(this);
		return creator;
	}

	@Override
	public String toString() {
		return String.format("%s(type=%d,subType=%d,durationType=%d,spellId=%d)",
				getClass().getName(), type, subType, durationType, spellId);
	}
}
