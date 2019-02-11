#include "Serialize.hpp"

#include "Assert.hpp"
#include "API/Types.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWSArea.hpp"
#include "API/Constants.hpp"
#include "API/CResGFF.hpp"
#include "API/CResStruct.hpp"

#include <string.h>

static const char base64_key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static std::string base64_encode(const std::vector<uint8_t>& in)
{
    std::string out;

    int val=0, valb=-6;
    for (uint8_t c : in) {
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back(base64_key[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6)
        out.push_back(base64_key[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4)
        out.push_back('=');
    return out;
}

static std::vector<uint8_t> base64_decode(const std::string &in)
{
    std::vector<uint8_t> out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++)
        T[(uint8_t)(base64_key[i])] = i;

    int val=0, valb=-8;
    for (char c : in) {
        if (T[(uint8_t)c] == -1)
            break;
        val = (val<<6) + T[(uint8_t)c];
        valb += 6;
        if (valb>=0) {
            out.push_back(uint8_t((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}


namespace NWNXLib {

std::vector<uint8_t> SerializeGameObject(API::CGameObject *pObject, bool bStripPCFlags)
{
    uint8_t *pData = nullptr;
    int32_t dataLength = 0;

    if (!pObject)
        return std::vector<uint8_t>();

    API::CResGFF    resGff;
    API::CResStruct resStruct;

    switch (pObject->m_nObjectType)
    {
        case API::Constants::ObjectType::Creature:
        {
            API::CNWSCreature *pCreature = static_cast<API::CNWSCreature*>(pObject);
            if (resGff.CreateGFFFile(&resStruct, "BIC ", "V2.0"))
            {
                int32_t bPlayerCharacter = 0, bIsPC = 0;
                if (bStripPCFlags) {
                    std::swap(bPlayerCharacter, pCreature->m_bPlayerCharacter);
                    std::swap(bIsPC, pCreature->m_pStats->m_bIsPC);
                }

                if (pCreature->SaveCreature(&resGff, &resStruct, 0, 0, 0, 0))
                    resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength);

                if (bStripPCFlags) {
                    std::swap(bPlayerCharacter, pCreature->m_bPlayerCharacter);
                    std::swap(bIsPC, pCreature->m_pStats->m_bIsPC);
                }
            }
            break;
        }

// These all use a common implementation, but unfortunately can't be called polymorphically.
#define SERIALIZE(_type, _gff_header, ...)                                       \
        do {                                                                     \
            API::CNWS##_type *p = static_cast<API::CNWS##_type*>(pObject);       \
            if (resGff.CreateGFFFile(&resStruct, _gff_header, "V2.0"))           \
            {                                                                    \
                if (p->Save##_type(&resGff, &resStruct, ##__VA_ARGS__))          \
                    resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength); \
            }                                                                    \
        } while(0)

        case API::Constants::ObjectType::Item:      SERIALIZE(Item,      "UTI ", 0); break;
        case API::Constants::ObjectType::Placeable: SERIALIZE(Placeable, "UTP ", 0);    break;
        case API::Constants::ObjectType::Waypoint:  SERIALIZE(Waypoint,  "UTW ");    break;
        case API::Constants::ObjectType::Store:     SERIALIZE(Store,     "UTM ", 0);    break;
        case API::Constants::ObjectType::Door:      SERIALIZE(Door,      "UTD ");    break;
        case API::Constants::ObjectType::Trigger:   SERIALIZE(Trigger,   "UTT ");    break;
#undef SERIALIZE

        default:
            ASSERT_FAIL_MSG("Invalid object type for SerializeGameObject");
            break;
    }

    return std::vector<uint8_t>(pData, pData+dataLength);
}

API::CGameObject *DeserializeGameObject(const std::vector<uint8_t>& serialized)
{
    if (serialized.size() == 0)
        return nullptr;

    API::CResGFF    resGff;
    API::CResStruct resStruct;

    if (serialized.size() < 14*4) // GFF header size
        return nullptr;

    // resGff/resman will claim ownership of this pointer and free it in resGff destructor,
    // so need a copy for them to play with since the vector can't relinquish its own.
    uint8_t *data = new uint8_t[serialized.size()];
    memcpy(data, serialized.data(), serialized.size());
    if (!resGff.GetDataFromPointer((void*)data, (int32_t)serialized.size()))
        return nullptr;

    resGff.InitializeForWriting();
    if (!resGff.GetTopLevelStruct(&resStruct))
        return nullptr;

    API::CExoString sFileType, sFileVersion;
    resGff.GetGFFFileInfo(&sFileType, &sFileVersion);

    if (sFileType == "BIC " || sFileType == "GFF " || sFileType == "UTC ")
    {
        API::CNWSCreature *pCreature = new API::CNWSCreature(API::Constants::OBJECT_INVALID, 0, 1);

        if (!pCreature->LoadCreature(&resGff, &resStruct, 0, 0, 0, 0))
        {
            delete pCreature;
            return nullptr;
        }
        return static_cast<API::CGameObject*>(pCreature);
    }

#define DESERIALIZE(_type, ...)                                                             \
    do {                                                                                    \
        API::CNWS##_type *p = new API::CNWS##_type(API::Constants::OBJECT_INVALID);         \
        if (!p->Load##_type(&resGff, &resStruct, ##__VA_ARGS__))                            \
        {                                                                                   \
            delete p;                                                                       \
            return nullptr;                                                                 \
        }                                                                                   \
        return static_cast<API::CGameObject*>(p);                                           \
    } while(0)

    else if (sFileType == "UTI ")
        DESERIALIZE(Item, 0);
    else if (sFileType == "UTP ")
        DESERIALIZE(Placeable, nullptr);
    else if (sFileType == "UTW ")
        DESERIALIZE(Waypoint, nullptr);
    else if (sFileType == "UTM ")
        DESERIALIZE(Store, nullptr);
    else if (sFileType == "UTD ")
        DESERIALIZE(Door);
    else if (sFileType == "UTT ")
        DESERIALIZE(Trigger);
    else
    {
        ASSERT_FAIL_MSG("Unknown file type for DeserializeGameObject()");
    }

#undef DESERIALIZE

    return nullptr;
}

std::string SerializeGameObjectB64(API::CGameObject *pObject, bool bStripPCFlags)
{
    return base64_encode(SerializeGameObject(pObject, bStripPCFlags));
}

API::CGameObject *DeserializeGameObjectB64(const std::string& serializedB64)
{
    return DeserializeGameObject(base64_decode(serializedB64));
}

} // NWNXLib
