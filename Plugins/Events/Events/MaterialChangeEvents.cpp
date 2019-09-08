#include "Events/MaterialChangeEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

static std::unordered_map<API::Types::ObjectID, int32_t> m_objectCurrentMaterial;

MaterialChangeEvents::MaterialChangeEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CNWSObject__SetPosition, void,
                API::CNWSObject*, API::Vector, int32_t>(&SetPositionHook);
    });
}

void MaterialChangeEvents::SetPositionHook(Services::Hooks::CallType type, API::CNWSObject* thisPtr, API::Vector vPos, int32_t)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    if (thisPtr->m_nObjectType == API::Constants::ObjectType::Creature)
    {
        auto oArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(thisPtr->m_oidArea);
        auto iMat = oArea->GetSurfaceMaterial(vPos);
        if (!m_objectCurrentMaterial.count(thisPtr->m_idSelf) || iMat != m_objectCurrentMaterial[thisPtr->m_idSelf])
        {
            Events::PushEventData("MATERIAL_TYPE", std::to_string(iMat));
            Events::SignalEvent(before ? "NWNX_ON_MATERIALCHANGE_BEFORE" : "NWNX_ON_MATERIALCHANGE_AFTER", thisPtr->m_idSelf);
            m_objectCurrentMaterial[thisPtr->m_idSelf] = iMat;
        }
    }
}

}
