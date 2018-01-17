package org.nwnx.nwnx2.jvm;

import org.nwnx.nwnx2.jvm.constants.*;

public class TestRunner {

	public static void init() {
		System.out.println("Initializing TestRunner. This class runs various sanity tests and benchmarks.");
		System.out.println("If anything in this class makes your server crash, something is wrong and NEEDs to be fixed!");
		System.out.println("You need to load a module that has at least one event firing on a creature sometime.");

		NWObject.setObjectInvalidIsNull(true);

		NWObject.registerObjectHandler(new NWObject.ObjectHandler() {
		    public NWObject handleObjectClass(NWObject obj, boolean valid,
		            int objectType, String resRef, String tag) {
		        return obj;
		    }
		});
		NWEffect.registerEffectHandler(new NWEffect.EffectHandler() {
		    public NWEffect handleEffectClass(NWEffect eff) {
		        return eff;
		    }
		});
		NWItemProperty.registerItemPropertyHandler(new NWItemProperty.ItemPropertyHandler() {
		    public NWItemProperty handleItemPropertyClass(NWItemProperty prp) {
		        return prp;
		    }
		});

		ResMan.addResManListener(new ResManListener() {
			@Override
			public byte[] demand(String resRef) {
				System.out.println("Demand ResRef: " + resRef);
				if (resRef.equals("resmantest.2da")) {
					System.out.println("Returning our own 2da table!");
					return "2DA V2.0\r\n\r\n     A B\r\n0 a1 b1\r\n1 a2 b2\r\n".getBytes();
				}
				return null;
			}

			@Override
			public int exists(String resRef) {
				return resRef.equals("resmantest.2da") ? 1 : -1;
			}
		});


		Scheduler.addSchedulerListener(new SchedulerListener() {

			@Override
			public void postFlushQueues(int remainingTokens) {
			}

			@Override
			public void missedToken(NWObject objSelf, String token) {
			}

			@Override
			public void event(NWObject objSelf, String event) {
				System.out.println("getObjectType");
				int objType = NWScript.getObjectType(objSelf);
				System.out.println("getName");
				String name = NWScript.getName(objSelf, false);
				System.out.println("event on " + objSelf.getObjectId() + ": " + event + ", name = " + name + ", type = " + objType);

				// String testResman = NWScript.get2DAString("resmantest", "A", 1);
				// if (!testResman.equals("a2"))
				// 	throw new RuntimeException("ResMan not working; expected 'a2', got '" + testResman + "'");
				// System.out.println("Tested Resman hook: " + testResman);

				if (objType == ObjectType.CREATURE) {
					System.out.println("Testing placing a temporary effect and retrieving it.");
					System.out.println("Creating a effect.");
					NWEffect e = NWScript.effectDeaf();
					System.out.println("Applying effect: " + e.getEffectId());
					NWScript.applyEffectToObject(1, e, objSelf, 7f);
					// System.out.println("Retrieving effects.");
					// NWEffect[] e2 = NWScript.getEffects(objSelf);
					// String ret = ""; for (NWEffect ee : e2) ret += ee.getEffectId() + " ";
					// System.out.println("The creature has " + e2.length + " effects on himself: " + ret);

					// System.out.println("Testing retrieving all objects in that area.");
					// NWObject area = NWScript.getArea(objSelf);
					// NWObject[] objInArea = NWScript.getObjectsInArea(area);
					// System.out.println("There are " + objInArea.length + " objects in that area.");

					// System.out.println("Testing retrieving all faction members.");
					// NWObject[] members = NWScript.getFactionMembers(objSelf,false);
					// System.out.println("There are " + members.length + " members.");

					System.out.println("Running a generic useless benchmark (Should be around 150ms, give or take)");
					long start = System.currentTimeMillis();
					for (int i = 0; i < 100000; i++)
						NWScript.getPosition(objSelf);
					long time = System.currentTimeMillis() - start;
					System.out.println("100000 times getPosition() took " + time + " ms");

					if (event.equals("creature_hb")) {
						System.out.println("Testing SCO/RCO on oid " + objSelf.getObjectId());
						byte[] data = SCORCO.saveObject(objSelf);
						System.out.println("got " + data.length + " bytes.");
						NWObject rco = SCORCO.loadObject(data, NWScript.getLocation(objSelf), null);

						if (rco != null)  {
							System.out.println("RCO worked, name of duplicated object is: " + NWScript.getName(rco, true));
							System.out.println("RCO worked, oid of duplicated object is: " + rco.getObjectId());
							NWScript.destroyObject(rco, 0f);
						} else {
							throw new RuntimeException("RCO failed.");
						}
					}

					System.out.println("Press Ctrl+C when you're bored. You should see the shutdown handler print a farewell message.");
				}
			}

			@Override
			public void context(NWObject objSelf) {
			}
		});
	}

	@SuppressWarnings("unused")
	private static void setup() {
	}

	@SuppressWarnings("unused")
	private static void shutdown() {
		System.out.println("Shutdown! Byebye, thanks for all the fish!");
	}
}
