package org.nwnx.nwnx2.jvm;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;


public class NWItemProperty {
	private static List<ItemPropertyHandler> classHandlers =
		Collections.synchronizedList(new LinkedList<ItemPropertyHandler>());

	private static List<ApplyListener> applyListeners =
		Collections.synchronizedList(new LinkedList<ApplyListener>());

	private static List<ExceptionHandler> exceptionHandlers =
		Collections.synchronizedList(new LinkedList<ExceptionHandler>());

	/**
	 * A ClassHandler is used to implement custom object classes.
	 * You can create a object hierarchy this way.
	 */
	public interface ItemPropertyHandler {
		/**
		 * Return an instance of NWObject to have this class handler
		 * handle the given object, or return null.
		 */
		public abstract NWItemProperty handleItemPropertyClass(NWItemProperty eff);
	}

	public interface ApplyListener {
		public NWItemProperty preApply(NWItemProperty prp);
		public void newItemProperty(NWItemProperty prp);
		public void postApply(NWItemProperty prp);
	}

	public static void registerItemPropertyHandler(ItemPropertyHandler e) {
		classHandlers.add(0, e);
	}

	public static void unregisterItemPropertyHandler(ItemPropertyHandler h) {
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

	public static List<ItemPropertyHandler> getItemPropertyHandlers() {
		return classHandlers;
	}

	/**
	 * Creates a new NWItemProperty by walking the registered class handlers
	 * and returning the first one that matches.
	 * Throws an exception if no object matches, or no handlers have been
	 * registered.
	 * @param oid
	 * @return a NWItemProperty
	 */
	public static NWItemProperty apply(int oid) {
		NWItemProperty o = new NWItemProperty(oid);
		NWItemProperty ret = null;

		try {

			for (ApplyListener a : applyListeners)
				if ((ret = a.preApply(o)) != null)
					break;

			if (ret == null)
				if (classHandlers.size() > 0) {
					for (ItemPropertyHandler e : classHandlers) {
						ret = e.handleItemPropertyClass(o);
						if (ret != null) {
							for (ApplyListener a : applyListeners)
								a.newItemProperty(ret);
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

	public NWItemProperty(int oid) {
		this.oid = oid;
	}

	@Deprecated
	public int oid() {
		return oid;
	}

	public int getItemPropertyId() {
		return oid;
	}

}
