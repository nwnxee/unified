#include "nwnx.hpp"

#include "API/CNWSObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreatureAppearanceInfo.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNWVisibilityNode.hpp"

#include <vector>
#include <unordered_map>
#include <regex>
#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::VectorMath;

enum ComparisonType
{
    Equals = 0,
    NotEquals = 1,
    GreaterThan = 2,
    LesserThan = 3,
    GreaterThanOrEquals = 4,
    LesserThanOrEquals = 5,
};

enum FilterType
{
    Tag = 1,
    LocalVariable = 2,
    CreatureStats = 3,
    Location = 4,
    Appearance = 5,
    Effect = 6,
    Custom = 7,
    Reputation = 8,
    MAX,
};

enum FilterSubtype
{
    Default = 0,

    String_Regex = 1,

    LocalVar_Int = 1,
    LocalVar_Float = 2,
    LocalVar_Object = 3,
    LocalVar_String = 4,

    Creature_Ability = 1,
    Creature_AbilityMod = 2,
    Creature_HasClass = 3,
    Creature_HasClassOfLevel = 4,
    Creature_IsPlayerCharacter = 5,
    Creature_RacialType = 6,
    Creature_Level = 7,
    Creature_HasFeat = 8,
    Creature_Experience = 9,
    Creature_Gold = 10,
    Creature_Poisoned = 11,
    Creature_Diseased = 12,
    Creature_SoundSet = 13,
    Creature_Perception = 14,

    Location_Area = 1,
    Location_X = 2,
    Location_Y = 3,
    Location_Z = 4,
    Location_Orientation = 5,

    Appearance_Creature = 1,
    Appearance_Placeable = 2,

    Effect_HasSpellEffect = 1,
    Effect_HasFeatEffect = 2,

    Custom_RunConditionalScript = 1,

    Reputation_GetReputation = 1,
    Reputation_IsFriend = 2,
    Reputation_IsNeutral= 3,
    Reputation_IsEnemy = 4,
};

enum FilterResult
{
    InvalidObjectTypeForFilter = -2,
    InvalidFilter = -1,
    False = 0,
    True = 1,
};

struct SnapshotFilter
{
    FilterType type;
    FilterSubtype subtype;
    ComparisonType comparisonType;
    bool invert;

    int32_t nParam1;
    int32_t nParam2;
    std::string sParam1;
    std::string sParam2;
    float fParam1;
    float fParam2;
    ObjectID oidParam1;
    ObjectID oidParam2;
};

static std::unordered_map<int32_t, std::vector<ObjectID>> s_SnapshotLists;
static std::unordered_map<int32_t, std::vector<SnapshotFilter>> s_FilterLists;

static bool GetObjectIsInFilter(const std::vector<SnapshotFilter> &filters, CNWSObject *pObject)
{
    auto CompareString = [](const std::string& toCheck, const std::string &value, const ComparisonType &comparisonType) -> int32_t
    {
        switch (comparisonType)
        {
            case Equals:    return toCheck == value;
            case NotEquals: return toCheck != value;
            default:        return FilterResult::InvalidFilter;
        }
    };

    auto CompareValue = [](const auto &toCheck, const auto &value, ComparisonType comparisonType) -> int32_t
    {
        switch (comparisonType)
        {
            case Equals:                return toCheck == value;
            case NotEquals:             return toCheck != value;
            case GreaterThan:           return toCheck > value;
            case LesserThan:            return toCheck < value;
            case GreaterThanOrEquals:   return toCheck >= value;
            case LesserThanOrEquals:    return toCheck <= value;
            default:                    return FilterResult::InvalidFilter;
        }
    };

    for (const auto& filter : filters)
    {
        int32_t retVal = FilterResult::InvalidFilter;

        switch (filter.type)
        {
            case FilterType::Tag:
            {
                if (filter.subtype == Default)
                    retVal = CompareString(pObject->m_sTag.CStr(), filter.sParam1, filter.comparisonType);
                else if (filter.subtype == String_Regex)
                    retVal = std::regex_match(pObject->m_sTag.CStr(), std::regex(filter.sParam1));
            }
            break;

            case FilterType::LocalVariable:
            {
                if (auto *pVarTable = Utils::GetScriptVarTable(pObject))
                {
                    CExoString varName = filter.sParam1;

                    switch (filter.subtype)
                    {
                        case FilterSubtype::LocalVar_Int:
                            retVal = CompareValue(pVarTable->GetInt(varName), filter.nParam1, filter.comparisonType);
                        break;
                        case FilterSubtype::LocalVar_Float:
                            retVal = CompareValue(pVarTable->GetFloat(varName), filter.fParam1, filter.comparisonType);
                        break;
                        case FilterSubtype::LocalVar_Object:
                            retVal = CompareValue(pVarTable->GetObject(varName), filter.oidParam1, filter.comparisonType);
                        break;
                        case FilterSubtype::LocalVar_String:
                            retVal = CompareString(pVarTable->GetString(varName).CStr(), filter.sParam2, filter.comparisonType);
                        break;

                        default: break;
                    }
                }
                else
                {
                    retVal = FilterResult::InvalidObjectTypeForFilter;
                }
            }
            break;

            case FilterType::CreatureStats:
            {
                if (auto *pCreature = Utils::AsNWSCreature(pObject))
                {
                    switch (filter.subtype)
                    {
                        case FilterSubtype::Creature_Ability:
                        {
                            switch (filter.nParam1)
                            {
                                case Constants::Ability::Strength:
                                    retVal = CompareValue(pCreature->m_pStats->GetSTRStat(), filter.nParam2, filter.comparisonType);
                                break;
                                case Constants::Ability::Dexterity:
                                    retVal = CompareValue(pCreature->m_pStats->GetDEXStat(), filter.nParam2, filter.comparisonType);
                                break;
                                case Constants::Ability::Constitution:
                                    retVal = CompareValue(pCreature->m_pStats->GetCONStat(), filter.nParam2, filter.comparisonType);
                                break;
                                case Constants::Ability::Intelligence:
                                    retVal = CompareValue(pCreature->m_pStats->GetINTStat(), filter.nParam2, filter.comparisonType);
                                break;
                                case Constants::Ability::Wisdom:
                                    retVal = CompareValue(pCreature->m_pStats->GetWISStat(), filter.nParam2, filter.comparisonType);
                                break;
                                case Constants::Ability::Charisma:
                                    retVal = CompareValue(pCreature->m_pStats->GetCHAStat(), filter.nParam2, filter.comparisonType);
                                break;
                            }
                        }
                        break;

                        case FilterSubtype::Creature_AbilityMod:
                        {
                            if (filter.nParam1 >= Constants::Ability::MIN && filter.nParam1 <= Constants::Ability::MAX)
                                retVal = CompareValue(pCreature->m_pStats->GetAbilityMod(filter.nParam1), filter.nParam2, filter.comparisonType);
                        }
                        break;

                        case FilterSubtype::Creature_HasClass:
                        {
                            retVal = false;
                            for (uint8_t multiClass = 0; multiClass < 3; multiClass++)
                            {
                                if (pCreature->m_pStats->GetClass(multiClass) == filter.nParam1)
                                {
                                    retVal = true;
                                    break;
                                }
                            }
                        }
                        break;

                        case FilterSubtype::Creature_HasClassOfLevel:
                        {
                            retVal = false;
                            for (uint8_t multiClass = 0; multiClass < 3; multiClass++)
                            {
                                if (pCreature->m_pStats->GetClass(multiClass) == filter.nParam1)
                                {
                                    retVal = CompareValue(pCreature->m_pStats->GetClassLevel(multiClass), filter.nParam2, filter.comparisonType);
                                    break;
                                }
                            }
                        }
                        break;

                        case FilterSubtype::Creature_IsPlayerCharacter:
                            retVal = pCreature->m_pStats->m_bIsPC;
                        break;

                        case FilterSubtype::Creature_RacialType:
                            retVal = CompareValue(pCreature->m_pStats->m_nRace, filter.nParam1, filter.comparisonType);
                        break;

                        case FilterSubtype::Creature_Level:
                            retVal = CompareValue(pCreature->m_pStats->GetLevel(), filter.nParam1, filter.comparisonType);
                        break;

                        case FilterSubtype::Creature_HasFeat:
                            retVal = pCreature->m_pStats->HasFeat(filter.nParam1);
                        break;

                        case FilterSubtype::Creature_Experience:
                            retVal = CompareValue((int32_t)pCreature->m_pStats->m_nExperience, filter.nParam1, filter.comparisonType);
                        break;

                        case FilterSubtype::Creature_Gold:
                            retVal = CompareValue((int32_t)pCreature->m_nGold, filter.nParam1, filter.comparisonType);
                        break;

                        case FilterSubtype::Creature_Poisoned:
                            retVal = pCreature->m_bPoisoned;
                        break;

                        case FilterSubtype::Creature_Diseased:
                            retVal = pCreature->m_bDiseased;
                        break;

                        case FilterSubtype::Creature_SoundSet:
                            retVal = CompareValue((int32_t)pCreature->m_nSoundSet, filter.nParam1, filter.comparisonType);
                        break;

                        case FilterSubtype::Creature_Perception:
                        {
                            uint8_t nSeen = 2, nHeard = 2;
                            bool bHeard = false, bSeen = false;

                            switch (filter.nParam1)
                            {
                                case 0: nSeen = nHeard = 1; break;      // PERCEPTION_SEEN_AND_HEARD
                                case 1: nSeen = nHeard = 0; break;      // PERCEPTION_NOT_SEEN_AND_NOT_HEARD
                                case 2: nSeen = 0; nHeard = 1; break;   // PERCEPTION_HEARD_AND_NOT_SEEN
                                case 3: nSeen = 1; nHeard = 0; break;   // PERCEPTION_SEEN_AND_NOT_HEARD
                                case 4: nHeard = 0; break;              // PERCEPTION_NOT_HEARD
                                case 5: nHeard = 1; break;              // PERCEPTION_HEARD
                                case 6: nSeen = 0; break;               // PERCEPTION_NOT_SEEN
                                case 7: nSeen = 1; break;               // PERCEPTION_SEEN
                            }

                            if (auto *pVisibilityNode = pCreature->GetVisibleListElement(filter.oidParam1))
                            {
                                bSeen = pVisibilityNode->m_bSeen;
                                bHeard = pVisibilityNode->m_bHeard;
                            }

                            retVal = ((nSeen == 2 || bSeen == nSeen)) && ((nHeard == 2 || bHeard == nHeard));
                        }
                        break;

                        default: break;
                    }
                }
                else
                {
                    retVal = FilterResult::InvalidObjectTypeForFilter;
                }
            }
            break;

            case FilterType::Location:
            {
                switch (filter.subtype)
                {
                    case FilterSubtype::Location_Area:
                        retVal = pObject->m_oidArea == filter.oidParam1;
                    break;

                    case FilterSubtype::Location_X:
                        retVal = CompareValue(pObject->m_vPosition.x, filter.fParam1, filter.comparisonType);
                    break;

                    case FilterSubtype::Location_Y:
                        retVal = CompareValue(pObject->m_vPosition.y, filter.fParam1, filter.comparisonType);
                    break;

                    case FilterSubtype::Location_Z:
                        retVal = CompareValue(pObject->m_vPosition.z, filter.fParam1, filter.comparisonType);
                    break;

                    case FilterSubtype::Location_Orientation:
                    {
                        Vector vOrientation = pObject->m_vOrientation;
                        vOrientation.z = 0.0f;
                        Vector vNormal = Normalize(vOrientation);
                        float fAngle = std::atan2(vOrientation.y, vOrientation.x) * (180.0f / M_PI);

                        if(vNormal.y < 0.0f)
                            fAngle = 360.0f + fAngle;

                        fAngle = (float)(int32_t)(fAngle + 0.5f);

                        retVal = CompareValue(fAngle, filter.fParam1, filter.comparisonType);
                    }
                    break;

                    default: break;
                }
            }
            break;

            case FilterType::Appearance:
            {
                switch (filter.subtype)
                {
                    case FilterSubtype::Appearance_Creature:
                    {
                        if (auto *pCreature = Utils::AsNWSCreature(pObject))
                            retVal = CompareValue(pCreature->m_cAppearance.m_nAppearanceType, filter.nParam1, filter.comparisonType);
                        else
                            retVal = FilterResult::InvalidObjectTypeForFilter;
                    }
                    break;

                    case FilterSubtype::Appearance_Placeable:
                    {
                        if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
                            retVal = CompareValue(pPlaceable->m_nAppearance, filter.nParam1, filter.comparisonType);
                        else
                            retVal = FilterResult::InvalidObjectTypeForFilter;
                    }
                    break;

                    default: break;
                }
            }
            break;

            case FilterType::Effect:
            {
                switch (filter.subtype)
                {
                    case FilterSubtype::Effect_HasSpellEffect:
                        retVal = pObject->HasSpellEffectApplied(filter.nParam1);
                    break;

                    case FilterSubtype::Effect_HasFeatEffect:
                        retVal = pObject->GetHasFeatEffectApplied(filter.nParam1);
                    break;

                    default: break;
                }
            }
            break;

            case FilterType::Custom:
            {
                switch (filter.subtype)
                {
                    case Custom_RunConditionalScript:
                    {
                        retVal = false;
                        CExoString sConditionalScript = filter.sParam1;

                        if (Globals::VirtualMachine()->RunScript(&sConditionalScript, pObject->m_idSelf, true, 0))
                        {
                            int32_t nParameterType;
                            void* pParameter;

                            if (Globals::VirtualMachine()->GetRunScriptReturnValue(&nParameterType, &pParameter) && nParameterType == 3)
                                retVal = (intptr_t)pParameter != 0 ? true : false;
                        }
                    }
                    break;

                    default: break;
                }
            }
            break;

            case FilterType::Reputation:
            {
                int32_t bIsInParty;
                switch (filter.subtype)
                {
                    case FilterSubtype::Reputation_GetReputation:
                        retVal = CompareValue(pObject->GetReputation(filter.oidParam1, bIsInParty), filter.nParam1, filter.comparisonType);
                    break;

                    case FilterSubtype::Reputation_IsFriend:
                        retVal = pObject->GetReputation(filter.oidParam1, bIsInParty) >= 90;
                    break;

                    case FilterSubtype::Reputation_IsNeutral:
                    {
                        int32_t nReputation = pObject->GetReputation(filter.oidParam1, bIsInParty);
                        retVal = nReputation > 10 && nReputation < 90;
                    }
                    break;

                    case FilterSubtype::Reputation_IsEnemy:
                        retVal = pObject->GetReputation(filter.oidParam1, bIsInParty) <= 10;
                    break;

                    default: break;
                }
            }
            break;

            default: break;
        }

        if (retVal == FilterResult::InvalidObjectTypeForFilter)
            return false;
        else if (retVal != FilterResult::InvalidFilter)
        {
            if (filter.invert)
                retVal = !retVal;

            if (!retVal)
                return false;
        }
    }

    return true;
}

NWNX_EXPORT ArgumentStack CreateAreaShapeSnapshot(ArgumentStack &&args)
{
    const auto shape = args.extract<int32_t>();
    const auto size = args.extract<float>();
    auto *pArea = Utils::PopArea(args);
    const auto x = args.extract<float>();
    const auto y = args.extract<float>();
    const auto z = args.extract<float>();
    const auto lineOfSight = !!args.extract<int32_t>();
    const auto objectFilter = args.extract<int32_t>();
    const auto originX = args.extract<float>();
    const auto originY = args.extract<float>();
    const auto originZ = args.extract<float>();
    const auto snapshotId = args.extract<int32_t>();

    s_SnapshotLists.erase(snapshotId);

    if (!pArea)
        return 0;

    const ObjectID oidObjectRunScript = Globals::VirtualMachine()->m_oidObjectRunScript[Globals::VirtualMachine()->m_nRecursionLevel];
    const float sizeSquared = size * size;
    Vector target = {x, y, z};
    Vector origin = {originX, originY, originZ};
    Vector losOrigin{};
    float minX, maxX;

    switch (shape)
    {
        case 0:// SHAPE_SPELLCYLINDER
        {
            Vector dir = Normalize(Subtract(target, origin));

            if (Dot(dir, dir) <= 0.00000001f)
                dir = Vector(0.0f, 1.0f, 0.0f);

            target = Add(origin, Multiply(dir, size));
            float f = dir.x;
            dir.x = -dir.y;
            dir.y = f;
            dir = Multiply(dir, 1.5f);

            Vector v[4]{};
            v[0] = Add(origin, dir);
            v[1] = Subtract(origin, dir);
            v[2] = Add(target, dir);
            v[3] = Subtract(target, dir);

            minX = v[0].x;
            maxX = v[0].x;

            for (int i = 1; i < 4; i++)
            {
                if (v[i].x < minX)
                    minX = v[i].x;
                if (v[i].x > maxX)
                    maxX = v[i].x;
            }

            losOrigin = origin;
            break;
        }

        case 1:// SHAPE_CONE
        case 3:// SHAPE_SPELLCONE
        {
            if (shape == 3)
            {
                if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectRunScript)))
                    origin = pObject->m_vPosition;
            }

            minX = ((target.x < origin.x) ? target.x : origin.x) - size;
            maxX = ((target.x > origin.x) ? target.x : origin.x) + size;
            losOrigin = origin;
            break;
        }

        case 2://  SHAPE_CUBE
        default:// SHAPE_SPHERE
        {
            minX = target.x - size;
            maxX = target.x + size;
            losOrigin = target;
            break;
        }
    }

    losOrigin.z += 1.0f;

    int32_t index;
    if (!pArea->GetFirstObjectIndiceByX(&index, minX))
        return 0;

    auto filtersList = s_FilterLists.find(snapshotId);
    bool hasFilters = filtersList != s_FilterLists.end() && !filtersList->second.empty();

    s_SnapshotLists[snapshotId].reserve(50);

    while (index < pArea->m_aGameObjects.num)
    {
        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(pArea->m_aGameObjects[index])))
        {
            bool bObjectIsInShape = false;
            Vector objectPosition = pObject->m_vPosition;

            if (objectPosition.x > maxX)
                break;

            auto IsAllowedObject = [&](int32_t nwscriptConstant, Constants::ObjectType::TYPE engineConstant) -> bool
            {
                return (objectFilter & nwscriptConstant) == nwscriptConstant && pObject->m_nObjectType == engineConstant;
            };

            if (((objectFilter & 32767) == 32767) ||
                (IsAllowedObject(1, Constants::ObjectType::Creature) && !Utils::AsNWSCreature(pObject)->m_pStats->GetIsDM()) ||
                 IsAllowedObject(2, Constants::ObjectType::Item) ||
                 IsAllowedObject(4, Constants::ObjectType::Trigger) ||
                 IsAllowedObject(8, Constants::ObjectType::Door) ||
                 IsAllowedObject(16, Constants::ObjectType::AreaOfEffect) ||
                 IsAllowedObject(32, Constants::ObjectType::Waypoint) ||
                 IsAllowedObject(64, Constants::ObjectType::Placeable) ||
                 IsAllowedObject(128, Constants::ObjectType::Store) ||
                 IsAllowedObject(256, Constants::ObjectType::Encounter) )
            {
                switch (shape)
                {
                    case 0:// SHAPE_SPELLCYLINDER
                    {
                        if (MagnitudeSquared(Subtract(objectPosition, origin)) <= sizeSquared &&
                            Dot(Normalize(Subtract(target, origin)), Normalize(Subtract(objectPosition, origin))) >= 0.0f &&
                            MagnitudeSquared(Subtract(objectPosition, Lineproject(origin, target, objectPosition))) <= 2.25f)
                        {
                            bObjectIsInShape = true;
                        }
                        break;
                    }

                    case 1:// SHAPE_CONE
                    {
                        auto sqr = [](float f) -> float { return f * f; };
                        Vector closestPoint = Lineproject(origin, target, objectPosition);
                        if (Dot(Normalize(Subtract(target, origin)), Normalize(Subtract(objectPosition, origin))) > 0.0f &&
                            MagnitudeSquared(Subtract(objectPosition, closestPoint)) <=
                            sqr((size / Magnitude(Subtract(target, origin))) * Magnitude(closestPoint)))
                        {
                            bObjectIsInShape = true;
                        }
                        break;
                    }

                    case 2:// SHAPE_CUBE
                    {
                        if ((objectPosition.x <= target.x + size) && (objectPosition.x >= target.x - size) &&
                            (objectPosition.y <= target.y + size) && (objectPosition.y >= target.y - size) &&
                            (objectPosition.z <= target.z + size) && (objectPosition.z >= target.z - size))
                        {
                            bObjectIsInShape = true;
                        }
                        break;
                    }

                    case 3:// SHAPE_SPELLCONE
                    {
                        const float f = MagnitudeSquared(Subtract(Lineproject(origin, target, objectPosition), origin));
                        if (Dot(Normalize(Subtract(target, origin)), Normalize(Subtract(objectPosition, origin))) >= 0.866f &&
                            f <= sizeSquared && f >= 0.01f)
                        {
                            bObjectIsInShape = true;
                        }
                        break;
                    }

                    default:// SHAPE_SPHERE
                    {
                        Vector distance = Subtract(objectPosition, target);
                        if (Dot(distance, distance) <= sizeSquared)
                        {
                            bObjectIsInShape = true;
                        }
                        break;
                    }
                }

                if (bObjectIsInShape && lineOfSight)
                {
                    Vector impact{};
                    ObjectID oidImpact;
                    objectPosition.z += 1.0f;

                    if (!pArea->ClearLineOfSight(losOrigin, objectPosition, &impact, &oidImpact, oidObjectRunScript, pObject->m_idSelf, true))
                        bObjectIsInShape = false;
                }

                if (bObjectIsInShape && hasFilters)
                    bObjectIsInShape = GetObjectIsInFilter(filtersList->second, pObject);

                if (bObjectIsInShape)
                    s_SnapshotLists[snapshotId].emplace_back(pObject->m_idSelf);
            }
        }

        index++;
    }

    if (snapshotId == 0)
        s_FilterLists.erase(snapshotId);

    return (int32_t)s_SnapshotLists[snapshotId].size();
}

NWNX_EXPORT ArgumentStack CreateAreaSnapshot(ArgumentStack &&args)
{
    auto *pArea = Utils::PopArea(args);
    const auto objectFilter = args.extract<int32_t>();
    const auto snapshotId = args.extract<int32_t>();

    s_SnapshotLists.erase(snapshotId);

    if (!pArea || !pArea->m_aGameObjects.num)
        return 0;

    auto filtersList = s_FilterLists.find(snapshotId);
    bool hasFilters = filtersList != s_FilterLists.end() && !filtersList->second.empty();
    s_SnapshotLists[snapshotId].reserve(100);

    int32_t index = 0;
    while (index < pArea->m_aGameObjects.num)
    {
        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(pArea->m_aGameObjects[index])))
        {
            auto IsAllowedObject = [&](int32_t nwscriptConstant, Constants::ObjectType::TYPE engineConstant) -> bool
            {
                return (objectFilter & nwscriptConstant) == nwscriptConstant && pObject->m_nObjectType == engineConstant;
            };

            if (((objectFilter & 32767) == 32767) ||
                (IsAllowedObject(1, Constants::ObjectType::Creature) && !Utils::AsNWSCreature(pObject)->m_pStats->GetIsDM()) ||
                 IsAllowedObject(2, Constants::ObjectType::Item) ||
                 IsAllowedObject(4, Constants::ObjectType::Trigger) ||
                 IsAllowedObject(8, Constants::ObjectType::Door) ||
                 IsAllowedObject(16, Constants::ObjectType::AreaOfEffect) ||
                 IsAllowedObject(32, Constants::ObjectType::Waypoint) ||
                 IsAllowedObject(64, Constants::ObjectType::Placeable) ||
                 IsAllowedObject(128, Constants::ObjectType::Store) ||
                 IsAllowedObject(256, Constants::ObjectType::Encounter) )
            {
                if (!hasFilters || (hasFilters && GetObjectIsInFilter(filtersList->second, pObject)))
                    s_SnapshotLists[snapshotId].emplace_back(pObject->m_idSelf);
            }
        }

        index++;
    }

    if (snapshotId == 0)
        s_FilterLists.erase(snapshotId);

    return (int32_t)s_SnapshotLists[snapshotId].size();
}

NWNX_EXPORT ArgumentStack CreateModuleSnapshot(ArgumentStack &&args)
{
    const auto objectFilter = args.extract<int32_t>();
    const auto snapshotId = args.extract<int32_t>();

    s_SnapshotLists.erase(snapshotId);

    auto *pGameObjectArray = Globals::AppManager()->m_pServerExoApp->GetObjectArray();

    if (!pGameObjectArray)
        return 0;

    auto filtersList = s_FilterLists.find(snapshotId);
    bool hasFilters = filtersList != s_FilterLists.end() && !filtersList->second.empty();
    s_SnapshotLists[snapshotId].reserve(250);

    ObjectID oidObject = pGameObjectArray->m_nNextObjectArrayID[0] - 1;
    while (oidObject > 0)
    {
        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObject)))
        {
            auto IsAllowedObject = [&](int32_t nwscriptConstant, Constants::ObjectType::TYPE engineConstant) -> bool
            {
                return (objectFilter & nwscriptConstant) == nwscriptConstant && pObject->m_nObjectType == engineConstant;
            };

            if (((objectFilter & 32767) == 32767) ||
                (IsAllowedObject(1, Constants::ObjectType::Creature) && !Utils::AsNWSCreature(pObject)->m_pStats->GetIsDM()) ||
                 IsAllowedObject(2, Constants::ObjectType::Item) ||
                 IsAllowedObject(4, Constants::ObjectType::Trigger) ||
                 IsAllowedObject(8, Constants::ObjectType::Door) ||
                 IsAllowedObject(16, Constants::ObjectType::AreaOfEffect) ||
                 IsAllowedObject(32, Constants::ObjectType::Waypoint) ||
                 IsAllowedObject(64, Constants::ObjectType::Placeable) ||
                 IsAllowedObject(128, Constants::ObjectType::Store) ||
                 IsAllowedObject(256, Constants::ObjectType::Encounter) )
            {
                if (!hasFilters || (hasFilters && GetObjectIsInFilter(filtersList->second, pObject)))
                    s_SnapshotLists[snapshotId].emplace_back(pObject->m_idSelf);
            }
        }

        oidObject--;
    }

    if (snapshotId == 0)
        s_FilterLists.erase(snapshotId);

    return (int32_t)s_SnapshotLists[snapshotId].size();
}

NWNX_EXPORT ArgumentStack CreatePlayerSnapshot(ArgumentStack &&args)
{
    const auto snapshotId = args.extract<int32_t>();

    auto filtersList = s_FilterLists.find(snapshotId);
    bool hasFilters = filtersList != s_FilterLists.end() && !filtersList->second.empty();
    s_SnapshotLists.erase(snapshotId);
    s_SnapshotLists[snapshotId].reserve(25);

    ObjectID oidObject = Globals::AppManager()->m_pServerExoApp->GetFirstPCObject();
    while (oidObject != Constants::OBJECT_INVALID)
    {
        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObject)))
        {
            if (!hasFilters || (hasFilters && GetObjectIsInFilter(filtersList->second, pObject)))
                s_SnapshotLists[snapshotId].emplace_back(pObject->m_idSelf);
        }

        oidObject = Globals::AppManager()->m_pServerExoApp->GetNextPCObject();
    }

    if (snapshotId == 0)
        s_FilterLists.erase(snapshotId);

    return (int32_t)s_SnapshotLists[snapshotId].size();
}

NWNX_EXPORT ArgumentStack GetObjectFromSnapshot(ArgumentStack &&args)
{
    const auto index = args.extract<int32_t>();
      ASSERT_OR_THROW(index >= 0);
    const auto snapshotID = args.extract<int32_t>();

    auto snapshotList = s_SnapshotLists.find(snapshotID);
    if (snapshotList != s_SnapshotLists.end())
    {
        if ((size_t)index < snapshotList->second.size())
            return snapshotList->second[index];
    }

    return Constants::OBJECT_INVALID;
}

NWNX_EXPORT ArgumentStack PruneSnapshot(ArgumentStack &&args)
{
    const auto snapshotID = args.extract<int32_t>();

    auto snapshotList = s_SnapshotLists.find(snapshotID);
    if (snapshotList != s_SnapshotLists.end())
    {
        snapshotList->second.erase(std::remove_if(snapshotList->second.begin(), snapshotList->second.end(),
                                   [](const ObjectID& oid) { return !Utils::GetGameObject(oid); }), snapshotList->second.end());

        if (snapshotList->second.empty())
        {
            s_SnapshotLists.erase(snapshotID);
            return 0;
        }

        return (int32_t)snapshotList->second.size();
    }

    return 0;
}

NWNX_EXPORT ArgumentStack ClearSnapshot(ArgumentStack &&args)
{
    s_SnapshotLists.erase(args.extract<int32_t>());
    return {};
}

NWNX_EXPORT ArgumentStack SortSnapshotByDistance(ArgumentStack &&args)
{
    const auto *pTarget = Utils::PopObject(args);
    const auto snapshotID = args.extract<int32_t>();
    const auto ascending = !!args.extract<int32_t>();

    auto snapshotList = s_SnapshotLists.find(snapshotID);
    if (pTarget && snapshotList != s_SnapshotLists.end() && snapshotList->second.size() > 1)
    {
        Vector vTarget = pTarget->m_vPosition;
        ObjectID oidTargetArea = pTarget->m_oidArea;

        std::sort(snapshotList->second.begin(), snapshotList->second.end(),
            [vTarget, oidTargetArea, ascending](const ObjectID& oidA, const ObjectID& oidB)
            {
                float fDistanceA = 99999.0f;
                float fDistanceB = 99999.0f;

                if (auto *pObjectA = Utils::AsNWSObject(Utils::GetGameObject(oidA)))
                {
                    if (pObjectA->m_oidArea == oidTargetArea)
                        fDistanceA = MagnitudeSquared(Subtract(vTarget, pObjectA->m_vPosition));
                }

                if (auto *pObjectB = Utils::AsNWSObject(Utils::GetGameObject(oidB)))
                {
                    if (pObjectB->m_oidArea == oidTargetArea)
                        fDistanceB = MagnitudeSquared(Subtract(vTarget, pObjectB->m_vPosition));
                }

                return ascending ? fDistanceA < fDistanceB : fDistanceA > fDistanceB;
            });
    }

    return {};
}

NWNX_EXPORT ArgumentStack AddFilter(ArgumentStack &&args)
{
    const auto snapshotID = args.extract<int32_t>();
    const auto type = args.extract<int32_t>();
      ASSERT_OR_THROW(type >= FilterType::Tag);
      ASSERT_OR_THROW(type < FilterType::MAX);
    const auto subtype = args.extract<int32_t>();
    const auto comparisonType = args.extract<int32_t>();
      ASSERT_OR_THROW(comparisonType >= ComparisonType::Equals);
      ASSERT_OR_THROW(comparisonType <= ComparisonType::LesserThanOrEquals);
    const auto invert = !!args.extract<int32_t>();
    const auto nParam1 = args.extract<int32_t>();
    const auto nParam2 = args.extract<int32_t>();
    const auto sParam1 = args.extract<std::string>();
    const auto sParam2 = args.extract<std::string>();
    const auto fParam1 = args.extract<float>();
    const auto fParam2 = args.extract<float>();
    const auto oidParam1 = args.extract<ObjectID>();
    const auto oidParam2 = args.extract<ObjectID>();

    SnapshotFilter str = {(FilterType)type, (FilterSubtype)subtype, (ComparisonType)comparisonType, invert,
                          nParam1, nParam2, sParam1, sParam2, fParam1, fParam2, oidParam1, oidParam2};
    s_FilterLists[snapshotID].emplace_back(str);

    return {};
}

NWNX_EXPORT ArgumentStack ClearFilters(ArgumentStack &&args)
{
    s_FilterLists.erase(args.extract<int32_t>());
    return {};
}
