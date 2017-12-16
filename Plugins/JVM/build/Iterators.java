    /**
      * Get all currently online players.
    **/
    public static synchronized NWObject[] getPCs() throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstPC();
      while (i.valid()) {
        ret.add(i);
        i = getNextPC();
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all effects on the given NWObject.
    **/
    public static synchronized NWEffect[] getEffects(NWObject oWithEffects) throws NWNotInContextException
    {
      Vector<NWEffect> ret = new Vector<NWEffect>();
      NWEffect i = getFirstEffect(oWithEffects);
      while (getIsEffectValid(i)) {
        ret.add(i);
        i = getNextEffect(oWithEffects);
      }
      return ret.toArray(new NWEffect[0]);
    }

    /**
      * Get all itemproperties on the given NWObject.
    **/
    public static synchronized NWItemProperty[] getItemProperties(NWObject oItem) throws NWNotInContextException
    {
      Vector<NWItemProperty> ret = new Vector<NWItemProperty>();
      NWItemProperty i = getFirstItemProperty(oItem);
      while (getIsItemPropertyValid(i)) {
        ret.add(i);
        i = getNextItemProperty(oItem);
      }
      return ret.toArray(new NWItemProperty[0]);
    }

    /**
      * Get all items in the given NWObjects inventory.
    **/
    public static synchronized NWObject[] getItemsInInventory(NWObject oWithInventory) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstItemInInventory(oWithInventory);
      while (i.valid()) {
        ret.add(i);
        i = getNextItemInInventory(oWithInventory);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects in the given area.
    **/
    public static synchronized NWObject[] getObjectsInArea(NWObject oArea) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstObjectInArea(oArea);
      while (i.valid()) {
        ret.add(i);
        i = getNextObjectInArea(oArea);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects in the given shape.
      * @param nShape SHAPE_*
      * @param fSize
      * -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
      * -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
      * Spell Cylinder's always have a radius of 1.5m.
      * -> If nShape == SHAPE_CONE, this is the widest radius of the cone
      * -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
      * direction of lTarget. Spell cones are always 60 degrees with the origin
      * at OBJECT_SELF.
      * -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
      * the cube
      * @param lTarget This is the centre of the effect, usually GetSpellTargetLocation(),
      * or the end of a cylinder or cone.
      * @param bLineOfSight This controls whether to do a line-of-sight check on the
      * object returned. Line of sight check is done from origin to target object
      * at a height 1m above the ground
      * (This can be used to ensure that spell effects do not go through walls.)
      * @param nObjectFilter This allows you to filter out undesired object types, using
      * bitwise "or".
      * For example, to return only creatures and doors, the value for this
      * parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
      * @param vOrigin This is only used for cylinders and cones, and specifies the
      * origin of the effect(normally the spell-caster's position).
    **/
    public static synchronized NWObject[] getObjectsInShape(int nShapeType, float fSize, NWLocation lTarget, boolean bLineOfSight, int nObjectFilter, NWVector vOrigin) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstObjectInShape(nShapeType, fSize, lTarget, bLineOfSight, nObjectFilter, vOrigin);
      while (i.valid()) {
        ret.add(i);
        i = getNextObjectInShape(nShapeType, fSize, lTarget, bLineOfSight, nObjectFilter, vOrigin);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Returns all members of the given objects faction.
    */
    public static synchronized NWObject[] getFactionMembers(NWObject oMemberOf, boolean bPCOnly) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstFactionMember(oMemberOf, bPCOnly);
      while (i.valid()) {
        ret.add(i);
        i = getNextFactionMember(oMemberOf, bPCOnly);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects within within oPersistentObject.
      * @param oPersistentObject
      * @param nResidentObjectType OBJECT_TYPE_*
      * @param nPersistentZone PERSISTENT_ZONE_ACTIVE. [This could also take the value
      * PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
    **/
    public static synchronized NWObject[] getObjectsInPersistentObject(NWObject oPersistentObject, int nResidentObjectType, int nPersistentZone) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone);
      while (i.valid()) {
        ret.add(i);
        i = getNextInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone);
      }
      return ret.toArray(new NWObject[0]);
    }
