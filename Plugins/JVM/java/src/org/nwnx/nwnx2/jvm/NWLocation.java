package org.nwnx.nwnx2.jvm;

import java.io.Serializable;

public class NWLocation implements Serializable {
	private static final long serialVersionUID = 570647458062879344L;

	private final float x, y, z;
	private final float facing;
	private final NWObject area;

	public NWLocation(NWObject area, float x, float y, float z, float facing) {
		this.area = area; this.x = x; this.y = y; this.z = z; this.facing = facing;
	}

	public float getX() {
		return x;
	}

	public float getY() {
		return y;
	}

	public float getZ() {
		return z;
	}

	public float getFacing() {
		return facing;
	}

	public NWObject getArea() {
		return area;
	}

	@Deprecated
	public NWObject area() {
		return area;
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
	@Deprecated
	public float facing() {
		return facing;
	}

	public static NWLocation apply(NWObject area, float x, float y, float z, float facing) {
		return new NWLocation(area, x, y, z, facing);
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof NWLocation) {
			NWLocation v = (NWLocation) obj;
			return v.area == area && v.x == x && v.y == y && v.z == z && v.facing == facing;
		} else
			return false;
	}

	@Override
	public int hashCode() {
		return 1 + (int) (
				(area == null ? 12 : area.hashCode()) * 37 +
				x * 37 +
				y * 37 +
				z * 37 +
				facing * 37
		);
	}

	/**
	 * Calculates the distance to the given position in the same area.
	 */
	public float distanceTo(NWVector to) {
		return (new NWVector(x(), y(), z())).distanceTo(to);
	}

	@Override
	public String toString() {
		return String.format("%s(%s, %f : %f : %f, %f",
			getClass().getName(), area, x, y, z, facing);
	}
}
