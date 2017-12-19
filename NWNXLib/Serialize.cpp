#include "Serialize.hpp"

#include "API/Types.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/Constants.hpp"
#include "API/CResGFF.hpp"
#include "API/CResStruct.hpp"

#include <assert.h>
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
        T[base64_key[i]] = i;

    int val=0, valb=-8;
    for (uint8_t c : in) {
        if (T[c] == -1)
            break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
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

    if (pObject->m_nObjectType == API::Constants::OBJECT_TYPE_CREATURE)
    {
        API::CNWSCreature *pCreature = static_cast<API::CNWSCreature*>(pObject);
        if (resGff.CreateGFFFile(&resStruct, "BIC ", "V2.0"))
        {
            int32_t bPlayerCharacter = 0, bIsPC = 0;
            if (bStripPCFlags) {
                std::swap(bPlayerCharacter, pCreature->m_bPlayerCharacter);
                std::swap(bIsPC, pCreature->m_pStats->m_bIsPC);
            }

            if (pCreature->SaveCreature(&resGff, &resStruct, 0, 0, 0))
                resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength);

            if (bStripPCFlags) {
                std::swap(bPlayerCharacter, pCreature->m_bPlayerCharacter);
                std::swap(bIsPC, pCreature->m_pStats->m_bIsPC);
            }
        }
    }
    else if (pObject->m_nObjectType == API::Constants::OBJECT_TYPE_ITEM)
    {
        API::CNWSItem *pItem = static_cast<API::CNWSItem*>(pObject);
        if (resGff.CreateGFFFile(&resStruct, "UTI ", "V2.0"))
        {
            if (pItem->SaveItem(&resGff, &resStruct, 0))
                resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength);
        }
    }
    else
    {
        assert(!"SerializeGameObject only works on creatures and items");
    }

    return std::vector<uint8_t>(pData, pData+dataLength);
}

API::CGameObject *DeserializeGameObject(const std::vector<uint8_t>& serialized)
{
    if (serialized.size() == 0)
        return nullptr;

    API::CResGFF    resGff;
    API::CResStruct resStruct;

    if (!resGff.GetDataFromPointer((void*)serialized.data(), serialized.size()))
        return nullptr;

    resGff.InitializeForWriting();
    if (!resGff.GetTopLevelStruct(&resStruct))
        return nullptr;

    API::CExoString sFileType, sFileVersion;
    resGff.GetGFFFileInfo(&sFileType, &sFileVersion);

    if (sFileType == "BIC " || sFileType == "GFF ")
    {
        // TODO: Clean up once traps are removed from the constructors...
        //API::CNWSCreature *pCreature = new API::CNWSCreature(API::Constants::OBJECT_INVALID, 0, 1);
        API::CNWSCreature *pCreature = reinterpret_cast<API::CNWSCreature*>(new uint8_t[sizeof(*pCreature)]);
        memset(pCreature, 0, sizeof(*pCreature));
        API::CNWSCreature__CNWSCreatureCtor(pCreature, API::Constants::OBJECT_INVALID, 0, 1);

        if (!pCreature->LoadCreature(&resGff, &resStruct, 0, 0, 0, 0))
        {
            delete pCreature;
            return nullptr;
        }
        return static_cast<API::CGameObject*>(pCreature);
    }
    else if (sFileType == "UTI ")
    {
        API::CNWSItem *pItem = new API::CNWSItem(API::Constants::OBJECT_INVALID);
        if (!pItem->LoadItem(&resGff, &resStruct, 0))
        {
            delete pItem;
            return nullptr;
        }
        pItem->m_bDroppable = 1;
        return static_cast<API::CGameObject*>(pItem);
    }
    else
    {
        assert(!"Unknown file type for DeserializeGameObject()");
    }

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
