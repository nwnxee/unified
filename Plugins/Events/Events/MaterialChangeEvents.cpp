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

static std::unordered_map<ObjectID, int32_t> m_objectCurrentMaterial;

MaterialChangeEvents::MaterialChangeEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN10CNWSObject11SetPositionE6Vectori, void,
                CNWSObject*, Vector, int32_t>(&SetPositionHook);
    });
}

void MaterialChangeEvents::SetPositionHook(bool before, CNWSObject* thisPtr, Vector vPos, int32_t)
{
    if (thisPtr->m_nObjectType == API::Constants::ObjectType::Creature)
    {
        auto pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(thisPtr->m_oidArea);
        if (pArea == nullptr)
            return;
        auto iMat = pArea->GetSurfaceMaterial(vPos);
        if (!m_objectCurrentMaterial.count(thisPtr->m_idSelf) || iMat != m_objectCurrentMaterial[thisPtr->m_idSelf])
        {
            Events::PushEventData("MATERIAL_TYPE", std::to_string(iMat));
            Events::SignalEvent(before ? "NWNX_ON_MATERIALCHANGE_BEFORE" : "NWNX_ON_MATERIALCHANGE_AFTER", thisPtr->m_idSelf);

            if (!before)
                m_objectCurrentMaterial[thisPtr->m_idSelf] = iMat;
        }
    }
}

}
