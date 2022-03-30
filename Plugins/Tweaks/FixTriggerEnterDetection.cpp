#include "nwnx.hpp"

#include "API/CNWSTrigger.hpp"
#include "API/CScriptEvent.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

bool VectorInTriggerBounds(CNWSTrigger* trigger, Vector point)
{
    Vector* vertices = trigger->m_pvVertices;
    int numVertices = trigger->m_nVertices;

    int i, j;
    bool inside = false;

    for (i = 0, j = numVertices - 1; i < numVertices; j = i++)
    {
        if ((vertices[i].y >= point.y ) != (vertices[j].y >= point.y))
        {
            if ((point.x <= (vertices[j].x - vertices[i].x) * (point.y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x))
            {
                inside = !inside;
            }
        }
    }

    return inside;
}

void FixTriggerEnterDetection() __attribute__((constructor));
void FixTriggerEnterDetection()
{
    if (!Config::Get<bool>("FIX_TRIGGER_ENTER_DETECTION", false))
        return;

    LOG_INFO("Will additionally validate trigger enter events to fix a trigger enter detection bug.");

    static Hooks::Hook s_TriggerEventHandlerHook = Hooks::HookFunction(Functions::_ZN11CNWSTrigger12EventHandlerEjjPvjj,
    (void*)+[](CNWSTrigger *thisPtr, uint32_t nEventId, OBJECT_ID nCallerObjectId, void* pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay) -> void
    {
        if (nEventId == AIMasterEvent::SignalEvent)
        {
            auto* pScriptEvent = static_cast<CScriptEvent*>(pScript);
            if (pScriptEvent->m_nType == ScriptEvent::OnObjectEnter)
            {
                auto* pEntered = Utils::AsNWSObject(Utils::GetGameObject(pScriptEvent->GetObjectID(0)));
                if (pEntered != nullptr && !VectorInTriggerBounds(thisPtr, pEntered->m_vPosition))
                {
                    delete pScriptEvent;
                    return;
                }
            }
        }

        s_TriggerEventHandlerHook->CallOriginal<void>(thisPtr, nEventId, nCallerObjectId, pScript, nCalendarDay, nTimeOfDay);
    }, Hooks::Order::Early);
}

}
