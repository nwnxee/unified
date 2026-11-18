#include "nwnx.hpp"

#include "API/CNWSTrigger.hpp"

// CNWSTrigger::InTrigger casts a ray north from the point and counts edge crossings, but a corner
// lying exactly on the ray can be counted twice. A point straight south of a corner then gets the
// wrong answer: outside below a bottom corner reads as inside, inside below a top corner as outside.
// This replaces it with a crossing test that counts each edge by a half-open rule, so a corner on
// the ray counts once when the boundary crosses it and zero or two times when it only touches.

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

// Ray north (+y) from the point, z ignored, like the original. An edge counts when exactly one end
// is east of the point and the edge passes north of it. The sign of c tells which side of the edge
// the point is on and flips with the edge's direction, so c * dx > 0 means the edge is north of
// the point. A point exactly on an edge gives c == 0 and is not counted for that edge.
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
