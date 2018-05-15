-- Iterators Functions

local function first_next_iterator(FirstFunction, NextFunction, CheckFunc, ...)
  local obj, prevobj = FirstFunction(...)
  local arguments = {...}
  return function()
    while CheckFunc(obj) do
      prevobj, obj = obj, NextFunction(unpack(arguments))
      return prevobj
    end
  end
end

function GetNearestObjects(nObjectType, oTarget)
  local nNth = 1
  nObjectType = nObjectType or 32767 --OBJECT_TYPE_ALL
  oTarget = oTarget or OBJECT_SELF
  local obj, prevobj = GetNearestObject(nObjectType, oTarget, nNth)
  return function()
    while obj ~= OBJECT_INVALID do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestObject(nObjectType, oTarget, nNth)
      return prevobj
    end
  end
end

--GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue);
function GetNearestCreatures(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
  nNth = nNth or 1
  nSecondCriteriaType = nSecondCriteriaType or -1
  nSecondCriteriaValue = nSecondCriteriaValue or -1
  nThirdCriteriaType = nThirdCriteriaType or -1
  nThirdCriteriaValue = nThirdCriteriaValue or -1
  local obj, prevobj = GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
  return function()
    while obj ~= OBJECT_INVALID do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
      return prevobj
    end
  end
end

function GetObjectsByTag(sTag)
  local nNth = 0
  local obj, prevobj = GetObjectByTag(sTag, nNth)
  return function()
    while obj ~= OBJECT_INVALID do
      nNth = nNth + 1
      prevobj, obj = obj, GetObjectByTag(sTag, nNth)
      return prevobj
    end
  end
end

--for creatures use 0 or lose one
function GetNearestObjectsByTag(sTag, oObject, nNth)
  nNth = nNth or 1 --!!docs say 1
  local obj, prevobj = GetNearestObjectByTag(sTag, oObject, nNth)
  return function()
    while obj ~= OBJECT_INVALID do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestObjectByTag(sTag, oObject, nNth)
      return prevobj
    end
  end
end

function ItemsInSlot(oPC)
  local nslot = -1
  return function()
    --while (nslot < (nwC.NUM_INVENTORY_SLOTS -2)) do 
    while (nslot < 16) do --(18 - 2)
     nslot = nslot + 1
     local item = GetItemInSlot(nslot, oPC)
     if item ~= OBJECT_INVALID then return nslot, item end
    end
  end
end

function Effects(oPC) 
  return first_next_iterator(GetFirstEffect, GetNextEffect, GetIsEffectValid, oPC) 
end

function ObjectsInArea(oArea) 
  return first_next_iterator(GetFirstObjectInArea, GetNextObjectInArea, GetIsObjectValid, oArea) 
end

function AllInPersistentObject(oObject, ObjectType)
  return first_next_iterator(GetFirstInPersistentObject, GetNextInPersistentObject, GetIsObjectValid, oObject, ObjectType) 
end

function ItemsInInventory(oTarget)
  return first_next_iterator(GetFirstItemInInventory, GetNextItemInInventory, GetIsObjectValid, oTarget) 
end

function FactionMembers(oMember, bPCOnly)
  return first_next_iterator(GetFirstFactionMember, GetNextFactionMember, GetIsObjectValid, oMember, bPCOnly) 
end

function AllPCs()
  return first_next_iterator(GetFirstPC, GetNextPC, GetIsObjectValid) 
end

function ItemProperties(oItem)
  return first_next_iterator(GetFirstItemProperty, GetNextItemProperty, GetIsItemPropertyValid, oItem)
end

function AllAreas()
  return first_next_iterator(GetFirstArea, GetNextArea, GetIsObjectValid)
end

