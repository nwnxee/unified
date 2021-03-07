#include "nwnx.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"

#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::string s_effectExpiredData;
static uint32_t s_effectExpiredDepth;
static ObjectID s_effectExpiredCreator;


NWNX_EXPORT ArgumentStack PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    eff->m_sCustomTag = args.extract<std::string>().c_str();

    auto vector1z = args.extract<float>();
    auto vector1y = args.extract<float>();
    auto vector1x = args.extract<float>();
    eff->m_vParamVector[1] = {vector1x, vector1y, vector1z};

    auto vector0z = args.extract<float>();
    auto vector0y = args.extract<float>();
    auto vector0x = args.extract<float>();
    eff->m_vParamVector[0] = {vector0x, vector0y, vector0z};

    eff->m_oidParamObjectID[3] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[2] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[1] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[0] = args.extract<ObjectID>();

    eff->m_sParamString[5] = args.extract<std::string>().c_str();
    eff->m_sParamString[4] = args.extract<std::string>().c_str();
    eff->m_sParamString[3] = args.extract<std::string>().c_str();
    eff->m_sParamString[2] = args.extract<std::string>().c_str();
    eff->m_sParamString[1] = args.extract<std::string>().c_str();
    eff->m_sParamString[0] = args.extract<std::string>().c_str();

    eff->m_nParamFloat[3] = args.extract<float>();
    eff->m_nParamFloat[2] = args.extract<float>();
    eff->m_nParamFloat[1] = args.extract<float>();
    eff->m_nParamFloat[0] = args.extract<float>();

    eff->SetNumIntegers(8); // allocate array
    eff->m_nParamInteger[7] = args.extract<int32_t>();
    eff->m_nParamInteger[6] = args.extract<int32_t>();
    eff->m_nParamInteger[5] = args.extract<int32_t>();
    eff->m_nParamInteger[4] = args.extract<int32_t>();
    eff->m_nParamInteger[3] = args.extract<int32_t>();
    eff->m_nParamInteger[2] = args.extract<int32_t>();
    eff->m_nParamInteger[1] = args.extract<int32_t>();
    eff->m_nParamInteger[0] = args.extract<int32_t>();
    // Overwrite num integers from 8
    eff->m_nNumIntegers = args.extract<int32_t>();

    auto bRightLinkValid = args.extract<int32_t>();
    auto *pRightLink = args.extract<CGameEffect*>();
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    auto bLeftLinkValid = args.extract<int32_t>();
    auto *pLeftLink = args.extract<CGameEffect*>();
    eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

    eff->m_nCasterLevel       = args.extract<int32_t>();
    eff->m_bShowIcon          = args.extract<int32_t>();
    eff->m_bExpose            = args.extract<int32_t>();
    eff->m_nSpellId           = args.extract<int32_t>();
    eff->m_oidCreator         = args.extract<ObjectID>();
    eff->m_nExpiryTimeOfDay   = args.extract<int32_t>();
    eff->m_nExpiryCalendarDay = args.extract<int32_t>();
    eff->m_fDuration          = args.extract<float>();
    eff->m_nSubType           = args.extract<int32_t>();
    eff->m_nType              = args.extract<int32_t>();

    if (bLeftLinkValid || bRightLinkValid)
        eff->UpdateLinked();

    return Events::Arguments(eff);
}
NWNX_EXPORT ArgumentStack UnpackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto eff = Events::ExtractArgument<CGameEffect*>(args);

    Events::InsertArgument(stack, (int32_t)eff->m_nType);
    Events::InsertArgument(stack, (int32_t)eff->m_nSubType);
    Events::InsertArgument(stack, (float)eff->m_fDuration);
    Events::InsertArgument(stack, (int32_t)eff->m_nExpiryCalendarDay);
    Events::InsertArgument(stack, (int32_t)eff->m_nExpiryTimeOfDay);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidCreator);
    Events::InsertArgument(stack, (int32_t)eff->m_nSpellId);
    Events::InsertArgument(stack, (int32_t)eff->m_bExpose);
    Events::InsertArgument(stack, (int32_t)eff->m_bShowIcon);
    Events::InsertArgument(stack, (int32_t)eff->m_nCasterLevel);

    // The DestroyGameEffect at the end of this function will delete any linked effects
    // as well so we make a copy of the linked effects and send those for unpacking
    CGameEffect *leftLinkEff = nullptr;
    if (eff->m_pLinkLeft != nullptr)
    {
        leftLinkEff = new CGameEffect(true);
        leftLinkEff->CopyEffect(eff->m_pLinkLeft, 0);
    }
    Events::InsertArgument(stack, leftLinkEff);
    Events::InsertArgument(stack, eff->m_pLinkLeft != nullptr);

    CGameEffect *rightLinkEff = nullptr;
    if (eff->m_pLinkRight != nullptr)
    {
        rightLinkEff = new CGameEffect(true);
        rightLinkEff->CopyEffect(eff->m_pLinkRight, 0);
    }
    Events::InsertArgument(stack, rightLinkEff);
    Events::InsertArgument(stack, eff->m_pLinkRight != nullptr);

    Events::InsertArgument(stack, (int32_t)eff->m_nNumIntegers);
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    Events::InsertArgument(stack, (float)eff->m_nParamFloat[0]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[1]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[2]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[3]);

    Events::InsertArgument(stack, std::string(eff->m_sParamString[0].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[1].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[2].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[3].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[4].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[5].CStr()));

    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[0]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[1]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[2]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[3]);

    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].x);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].y);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].z);

    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].x);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].y);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].z);

    Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));

    Utils::DestroyGameEffect(eff);
    return stack;
}

NWNX_EXPORT ArgumentStack SetEffectExpiredScript(ArgumentStack&& args)
{
    static Hooks::Hook pOnEffectRemovedHook =
            Hooks::HookFunction(API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
            (void*)+[](CNWSEffectListHandler *pEffectListHandler, CNWSObject* pObject, CGameEffect* pEffect) -> int32_t
            {
                CExoString &sScriptName = pEffect->m_sParamString[4];
                if (!sScriptName.IsEmpty())
                {
                    s_effectExpiredData = std::string(pEffect->m_sParamString[5].CStr());
                    s_effectExpiredCreator = pEffect->m_oidCreator;

                    LOG_DEBUG("(SetEffectExpiredScript) Running script '%s' on object '%x' with data '%s'",
                        sScriptName.CStr(), pObject->m_idSelf, s_effectExpiredData);

                    ++s_effectExpiredDepth;
                    Globals::VirtualMachine()->RunScript(&sScriptName, pObject->m_idSelf, 1);
                    --s_effectExpiredDepth;
                }
                return pOnEffectRemovedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect);
            }, Hooks::Order::Early);

    auto effect = Events::ExtractArgument<CGameEffect*>(args);

    // Script name
    effect->m_sParamString[4] = args.extract<std::string>().c_str();
    // Data
    effect->m_sParamString[5] = args.extract<std::string>().c_str();

    return effect;
}

NWNX_EXPORT ArgumentStack GetEffectExpiredData(ArgumentStack&&)
{
    if (s_effectExpiredDepth == 0)
        throw std::runtime_error("Attempted to get effect expired data in an invalid context.");

    return s_effectExpiredData;
}

NWNX_EXPORT ArgumentStack GetEffectExpiredCreator(ArgumentStack&&)
{
    if (s_effectExpiredDepth == 0)
        throw std::runtime_error("Attempted to get effect expired creator in an invalid context.");

    return s_effectExpiredCreator;
}

NWNX_EXPORT ArgumentStack ReplaceEffect(ArgumentStack&& args)
{
    int found = 0;
    auto objId = args.extract<ObjectID>();
    auto eOld  = args.extract<CGameEffect*>();
    auto eNew  = args.extract<CGameEffect*>();

    ASSERT_OR_THROW(eNew->m_nType == eOld->m_nType);

    if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(objId)))
    {
        for (auto* eff : obj->m_appliedEffects)
        {
            if (eff->m_nID == eOld->m_nID)
            {
                eff->m_nSubType              = eNew->m_nSubType;
                eff->m_fDuration             = eNew->m_fDuration;
                eff->m_nExpiryCalendarDay    = eNew->m_nExpiryCalendarDay;
                eff->m_nExpiryTimeOfDay      = eNew->m_nExpiryTimeOfDay;
                eff->m_oidCreator            = eNew->m_oidCreator;
                eff->m_nSpellId              = eNew->m_nSpellId;
                eff->m_nCasterLevel          = eNew->m_nCasterLevel;
                eff->m_nItemPropertySourceId = eNew->m_nItemPropertySourceId;
                eff->m_sCustomTag            = eNew->m_sCustomTag;
                eff->UpdateLinked();
                found++;
            }
        }
    }
    return found;
}
