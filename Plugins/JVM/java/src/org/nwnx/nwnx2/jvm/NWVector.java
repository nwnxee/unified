package org.nwnx.nwnx2.jvm;

import java.io.Serializable;

public class NWVector implements Serializable {
	private static final long serialVersionUID = 543062733475144178L;

	public static final NWVector ORIGIN = new NWVector(0, 0, 0);

	final private float x, y, z;

	public float getX() {
		return x;
	}

	public float getY() {
		return y;
	}

	public float getZ() {
		return z;
	}

	public NWVector(float x, float y, float z) {
		this.x = x; this.y = y; this.z = z;
	}

	public NWVector(String fromNWNXString) {
		String[] partials = fromNWNXString.split("¬", 3);
		if (partials.length != 3)
			throw new IllegalArgumentException("Not a valid stringified NWNX vector.");
		this.x = Float.parseFloat(partials[0]);
		this.y = Float.parseFloat(partials[1]);
		this.z = Float.parseFloat(partials[2]);
	}

	@Deprecated
	public float x() {
		return x;
	}
	@Deprecated
	public float y() {
		return y;
	}
	@Deprecated
	public float z() {
		return z;
	}

	public String asNWNXString() {
		return x + "¬" + y + "¬" + z;
	}

	public static NWVector apply(float x, float y, float z) {
		return new NWVector(x, y, z);
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof NWVector) {
			NWVector v = (NWVector) obj;
			return v.x == x && v.y == y && v.z == z;
		} else
			return false;
	}

	@Override
	public int hashCode() {
		return 1 + (int) (x * 37 + y * 37 + z * 37);
	}

	/**
	 * Creates a new Vector at the position distance units away at the given angle.
	 */
	public NWVector positionFrom(float distance, float angle) {
		return new NWVector(
			(float) Math.abs(x + distance * Math.cos(angle)),
			(float) Math.abs(y + distance * Math.sin(angle)),
			z
		);
	}

	/**
	 * Calculates the distance from this Vector to to another Vector.
	 */
	public float distanceTo(NWVector to) {
		if (to.equals(ORIGIN))
			return 0;
		else
			return (float) Math.sqrt(Math.pow(to.x - x, 2) + Math.pow(to.y - y, 2) + Math.pow(to.z - z, 2));
	}

	/**
	 * Calculates the angle to another Vector.
	 */
	public float angleTo(NWVector to) {
		if (to.equals(ORIGIN))
			return 0;
		else
			return (float) Math.acos(Math.abs((x - to.x)) / distanceTo(to));
	}

	/**
	 * Add another Vector to this one, returning a new Vector.
	 */
	public NWVector add(NWVector o) {
		return new NWVector(x + o.x, y + o.y, z + o.z);
	}

	/**
	 * Add another Vector with a fixed value, returning a new Vector.
	 */
	public NWVector add(float o) {
		return new NWVector(x + o, y + o, z + o);
	}


	/**
	 * Substract another Vector from this one, returning a new Vector.
	 */
	public NWVector substract(NWVector o) {
		return new NWVector(x - o.x, y - o.y, z - o.z);
	}

	/**
	 * Substract this Vector with a fixed value, returning a new Vector.
	 */
	public NWVector substract(float o) {
		return new NWVector(x - o, y - o, z - o);
	}


	/**
	 * Multiply another vector with this one, returning a new Vector.
	 */
	public NWVector multiply(NWVector o) {
		return new NWVector(x * o.x, y * o.y, z * o.z);
	}

	/**
	 * Multiply another vector with a fixed value, returning a new Vector.
	 */
	public NWVector multiply(float o) {
		return new NWVector(x * o, y * o, z * o);
	}

	/**
	 *  Divide this Vector with another one, returning a new Vector.
	 */
	public NWVector divide(NWVector o) {
		return new NWVector(x / o.x, y / o.y, z / o.z);
	}

	/**
	 *  Divide this Vector with a fixed value, returning a new Vector.
	 */
	public NWVector divide(float o) {
		return new NWVector(x / o, y / o, z / o);
	}

	/**
	 * Create the dot product between this Vector and the given one.
	 */
	public float dot(NWVector o) {
		return x * o.x + y * o.y + z * o.z;
	}

	/**
	 * The magnitude of this Vector.
	 */
	public float magnitude() {
		return distanceTo(ORIGIN);
	}

	/**
	 *  Returns the normalised unit-Vector.
	 */
	public NWVector normalized() {
		return this.divide(magnitude());
	}

	/**
	 *  Returns the angle of this Vector.
	 */
	public float angle() {
		return angleTo(ORIGIN);
	}

	@Override
	public String toString() {
		return String.format("%s(%f : %f : %f)", getClass().getName(), x, y, z);
	}
}
