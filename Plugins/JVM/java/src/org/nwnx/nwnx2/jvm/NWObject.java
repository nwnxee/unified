package org.nwnx.nwnx2.jvm;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class NWObject {
	private static List<ObjectHandler> classHandlers =
		Collections.synchronizedList(new LinkedList<ObjectHandler>());

	private static List<ApplyListener> applyListeners =
		Collections.synchronizedList(new LinkedList<ApplyListener>());

	private static List<ExceptionHandler> exceptionHandlers =
		Collections.synchronizedList(new LinkedList<ExceptionHandler>());

	private static boolean objectInvalidIsNull = false;

	/**
	 * A ClassHandler is used to implement custom object classes.
	 * You can create a object hierarchy this way.
	 */
	public interface ObjectHandler {
		/**
		 * Return an instance of NWObject to have this class handler
		 * handle the given object, or return null.
		 */
		public abstract NWObject handleObjectClass(NWObject obj, boolean valid,
				int objectType, String resRef, String tag);
	}

	public interface ApplyListener {
		public NWObject preApply(int oid, boolean valid,
				int objectType, String resRef, String tag, NWObject o);
		public void newObject(boolean valid,
				int objectType, String resRef, String tag, NWObject o);
		public void postApply(int oid, boolean valid,
				int objectType, String resRef, String tag, NWObject o);
	}

	public static void registerObjectHandler(ObjectHandler e) {
		classHandlers.add(0, e);
	}

	public static void unregisterObjectHandler(ObjectHandler h) {
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

	public static List<ObjectHandler> getObjectHandlers() {
		return classHandlers;
	}

	/**
	 * Creates a new NWObject by walking the registered class handlers
	 * and returning the first one that matches.
	 * Throws an exception if no object matches, or returns null when
	 * no handlers have been registered.
	 * @param oid
	 * @return a NWObject
	 */
	public static NWObject apply(int oid) {
		if (objectInvalidIsNull && oid == 0x7f000000)
			return null;

		NWObject o = new NWObject(oid);
		boolean valid = NWScript.getIsObjectValid(o);
		int objType = NWScript.getObjectType(o);
		String resref = NWScript.getResRef(o);
		String tag = NWScript.getTag(o);
		NWObject ret = null;

		try {

			for (ApplyListener a : applyListeners)
				if ((ret = a.preApply(oid, valid, objType, resref, tag, o)) != null)
					break;


			if (ret == null)
				if (classHandlers.size() > 0) {
					for (ObjectHandler e : classHandlers) {
						ret = e.handleObjectClass(o, valid, objType, resref, tag);
						if (ret != null) {
							for (ApplyListener a : applyListeners)
								a.newObject(valid, objType, resref, tag, ret);
							break;
						}
					}
					if (ret == null)
						throw new RuntimeException("No class handler that matches " + oid + " registered.");
				} else
					return null;

			for (ApplyListener a : applyListeners)
				a.postApply(oid, valid, objType, resref, tag, ret);

		} catch (RuntimeException e) {
			for (ExceptionHandler h : exceptionHandlers)
				if (h.handleException(e))
					return null;
			throw e;
		}

		return ret;
	}

	/**
	 * This is the OBJECT_INVALID constant
	 */
	public final static NWObject INVALID = new NWObject(0x7f000000);

	/**
	 * This is the same constant that GetModule() returns.
	 */
	public final static NWObject MODULE = new NWObject(0x00000000);

	final private int oid;

	public NWObject(int oid) {
		if (oid < 0 || oid > 0x7fffffff)
			throw new IllegalArgumentException("invalid oid: " + oid + ", needs to be 0 <= oid <= 0x7fffffff");
		this.oid = oid;
	}

	@Deprecated
	public int oid() {
		return oid;
	}

	/**
	 * Returns the NWN object ID of this NWObject.
	 * @return the oid
	 */
	public int getObjectId() {
		return oid;
	}

	/**
	 * Checks for NWN validity of this NWObject.
	 * @return true if this object is valid in-game.
	 */
	public boolean valid() {
		return NWScript.getIsObjectValid(this);
	}


	private int objectType = -1;
	/**
	 * Gets the OBJECT_TYPE_ of this NWObject, and caches it for future invocations.
	 * @return
	 */
	public int objectType() {
		if (objectType == -1)
			objectType = NWScript.getObjectType(this);
		return objectType;

	}

	/**
	 * Assign a code block to be executed on this NWObject.
	 * @param anon the code to execute
	 */
	public void assign(Runnable anon) {
		Scheduler.assign(this, anon);
	}

	/**
	 * Assign a code block to be executed on this NWOBject
	 * after the given delay (in milliseconds).
	 *
	 * See Scheduler.delay() for a more detailed description.
	 *
	 * @param delay the delay in milliseconds
	 * @param anon the code to execute.
	 */
	public void delay(long delay, Runnable anon) {
		Scheduler.delay(this, delay, anon);
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof NWObject) {
			return ((NWObject)obj).oid() == oid();
		} else
			return false;
	}

	@Override
	public int hashCode() {
		return 42 * oid;
	}

	@Override
	public String toString() {
		return String.format("%s(0x%x)", getClass().getName(), oid());
	}

	public static void setObjectInvalidIsNull(boolean objectInvalidIsNull) {
		NWObject.objectInvalidIsNull = objectInvalidIsNull;
	}

	public static boolean getObjectInvalidIsNull() {
		return objectInvalidIsNull;
	}
}
