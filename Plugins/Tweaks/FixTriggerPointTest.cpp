#include "nwnx.hpp"

#include "API/CNWSTrigger.hpp"

// The engine test can count a corner on the ray twice; this counts each edge half-open.

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static BOOL InTriggerHook(CNWSTrigger*, Vector) __attribute__((hot));

void FixTriggerPointTest() __attribute__((constructor));
void FixTriggerPointTest()
{
    if (!Config::Get<bool>("FIX_TRIGGER_POINT_TEST", false))
        return;

    LOG_INFO("Testing whether a point is inside a trigger counts corners on the test ray correctly.");

    static Hooks::Hook s_InTriggerHook = Hooks::HookFunction(&CNWSTrigger::InTrigger, &InTriggerHook, Hooks::Order::Final);
}

// Ray north from the point; c * dx > 0 means the edge passes north of it.
static BOOL InTriggerHook(CNWSTrigger *pThis, Vector vPosition)
{
    const Vector *pVertices = pThis->m_pvVertices;
    const int32_t nVertices = pThis->m_nVertices;
    const float px = vPosition.x;
    const float py = vPosition.y;

    bool bInside = false;
    for (int32_t i = 0, j = nVertices - 1; i < nVertices; j = i++)
    {
        const float ax = pVertices[j].x, ay = pVertices[j].y;
        const float bx = pVertices[i].x, by = pVertices[i].y;
        if ((ax > px) != (bx > px))
        {
            const float dx = bx - ax;
            const float c = (ay - py) * dx + (px - ax) * (by - ay);
            bInside ^= (c * dx > 0.0f);
        }
    }
    return bInside;
}

}
