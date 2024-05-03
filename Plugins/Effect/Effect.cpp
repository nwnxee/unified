#include "nwnx.hpp"

#include "API/CGameEffect.hpp"
#include "API/CNWSObject.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

ArgumentStack ResolveUnpack(CGameEffect *eff, bool bLink)
{
    ArgumentStack stack;

    stack.push(std::to_string(eff->m_nID));
    stack.push((int32_t)eff->m_nType);
    stack.push((int32_t)eff->m_nSubType);
    stack.push((float)eff->m_fDuration);
    stack.push((int32_t)eff->m_nExpiryCalendarDay);
    stack.push((int32_t)eff->m_nExpiryTimeOfDay);
    stack.push((ObjectID)eff->m_oidCreator);
    stack.push((int32_t)eff->m_nSpellId);
    stack.push((int32_t)eff->m_bExpose);
    stack.push((int32_t)eff->m_bShowIcon);
    stack.push((int32_t)eff->m_nCasterLevel);

    if (bLink)
    {
        CGameEffect *leftLinkEff = nullptr;
        if (eff->m_pLinkLeft != nullptr)
        {
            leftLinkEff = new CGameEffect(true);
            leftLinkEff->CopyEffect(eff->m_pLinkLeft, 0);
        }
        stack.push(leftLinkEff);
        stack.push(eff->m_pLinkLeft != nullptr);

        CGameEffect *rightLinkEff = nullptr;
        if (eff->m_pLinkRight != nullptr)
        {
            rightLinkEff = new CGameEffect(true);
            rightLinkEff->CopyEffect(eff->m_pLinkRight, 0);
        }
        stack.push(rightLinkEff);
        stack.push(eff->m_pLinkRight != nullptr);
    }

    stack.push((int32_t)eff->m_nNumIntegers);
    stack.push((int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    stack.push((float)eff->m_nParamFloat[0]);
    stack.push((float)eff->m_nParamFloat[1]);
    stack.push((float)eff->m_nParamFloat[2]);
    stack.push((float)eff->m_nParamFloat[3]);

    stack.push(std::string(eff->m_sParamString[0].CStr()));
    stack.push(std::string(eff->m_sParamString[1].CStr()));
    stack.push(std::string(eff->m_sParamString[2].CStr()));
    stack.push(std::string(eff->m_sParamString[3].CStr()));
    stack.push(std::string(eff->m_sParamString[4].CStr()));
    stack.push(std::string(eff->m_sParamString[5].CStr()));

    stack.push((ObjectID)eff->m_oidParamObjectID[0]);
    stack.push((ObjectID)eff->m_oidParamObjectID[1]);
    stack.push((ObjectID)eff->m_oidParamObjectID[2]);
    stack.push((ObjectID)eff->m_oidParamObjectID[3]);

    stack.push((Vector)eff->m_vParamVector[0]);
    stack.push((Vector)eff->m_vParamVector[1]);

    stack.push(std::string(eff->m_sCustomTag.CStr()));

    stack.push(std::to_string(eff->m_nItemPropertySourceId));

    return stack;
}

void ResolvePack(CGameEffect *eff, ArgumentStack& args, bool bReplace)
{
    eff->m_nItemPropertySourceId = std::stoull(args.extract<std::string>());

    eff->m_sCustomTag = args.extract<std::string>().c_str();

    eff->m_vParamVector[1] = args.extract<Vector>();
    eff->m_vParamVector[0] = args.extract<Vector>();

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

    bool bUpdateLinks = false;
    if (!bReplace)
    {
        auto bRightLinkValid = args.extract<int32_t>();
        auto *pRightLink = args.extract<CGameEffect*>();
        eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

        auto bLeftLinkValid = args.extract<int32_t>();
        auto *pLeftLink = args.extract<CGameEffect*>();
        eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

        if (bLeftLinkValid || bRightLinkValid)
            bUpdateLinks = true;
    }

    eff->m_nCasterLevel       = args.extract<int32_t>();
    eff->m_bShowIcon          = args.extract<int32_t>();
    eff->m_bExpose            = args.extract<int32_t>();
    eff->m_nSpellId           = args.extract<int32_t>();
    eff->m_oidCreator         = args.extract<ObjectID>();
    eff->m_nExpiryTimeOfDay   = args.extract<int32_t>();
    eff->m_nExpiryCalendarDay = args.extract<int32_t>();
    eff->m_fDuration          = args.extract<float>();
    eff->m_nSubType           = args.extract<int32_t>();

    if (!bReplace)
        eff->m_nType = args.extract<int32_t>();

    if (bUpdateLinks)
        eff->UpdateLinked();
}

NWNX_EXPORT ArgumentStack PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    ResolvePack(eff, args, false);

    return eff;
}

NWNX_EXPORT ArgumentStack UnpackEffect(ArgumentStack&& args)
{
    auto eff = args.extract<CGameEffect*>();
    SCOPEGUARD(Utils::DestroyGameEffect(eff));

    return ResolveUnpack(eff, true);
}

NWNX_EXPORT ArgumentStack ReplaceEffect(ArgumentStack&& args)
{
    int found = 0;
    auto objId = args.extract<ObjectID>();
    auto eOld  = args.extract<CGameEffect*>();
    auto eNew  = args.extract<CGameEffect*>();

    SCOPEGUARD(Utils::DestroyGameEffect(eOld));
    SCOPEGUARD(Utils::DestroyGameEffect(eNew));

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

NWNX_EXPORT ArgumentStack GetTrueEffectCount(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_appliedEffects.num;

    return 0;
}

NWNX_EXPORT ArgumentStack GetTrueEffect(ArgumentStack&& args)
{
    auto *pObject = Utils::PopObject(args);
      ASSERT_OR_THROW(pObject);
    auto it = args.extract<int32_t>();
      ASSERT_OR_THROW(it >= 0);
      ASSERT_OR_THROW(it < pObject->m_appliedEffects.num);

    return ResolveUnpack(pObject->m_appliedEffects[it], false);
}

NWNX_EXPORT ArgumentStack ReplaceEffectByIndex(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        auto index = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index < pObject->m_appliedEffects.num);

        ResolvePack(pObject->m_appliedEffects[index], args, true);
    }

    return {};
}

NWNX_EXPORT ArgumentStack RemoveEffectById(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        uint64_t id = std::stoull(args.extract<std::string>());
        return pObject->RemoveEffectById(id);
    }

    return false;
}

NWNX_EXPORT ArgumentStack Apply(ArgumentStack&& args)
{
    auto *pEffect = args.extract<CGameEffect*>();
    auto *pObject = Utils::PopObject(args);

    if(pObject && pEffect)
    {
        pObject->ApplyEffect(pEffect, false, true);
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetEffectCreator(ArgumentStack&& args)
{
    auto effect = args.extract<CGameEffect*>();
    ASSERT_OR_THROW(effect);
    auto creator = Utils::PopObject(args);
    ASSERT_OR_THROW(creator);

    effect->m_oidCreator = creator->m_idSelf;

    return effect;
}
