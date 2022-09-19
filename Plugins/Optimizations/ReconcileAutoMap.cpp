#include "nwnx.hpp"
#include "HashTable32.hpp"

#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static HashTable32<CNWSPlayer> s_playerobjects;

static Hooks::Hook s_VMAreaManagement;
static Hooks::Hook s_ReconcileAutoMapData;

static void ReconcileAutoMapData(CNWSCreature*);
static int32_t ExecuteCommandAreaManagement(CNWVirtualMachineCommands*, int32_t, int32_t);

static uint64_t s_AreaListSeq = 1;
static HashTable32<void, 64 * 1024> s_SeqTable;

void ReconcileAutoMap() __attribute__((constructor));
void ReconcileAutoMap()
{
    if (Config::Get<bool>("RECONCILE_AUTOMAP_DATA", false))
    {
        LOG_INFO("AutoMap data fixup optimization enabled");

        s_ReconcileAutoMapData = Hooks::HookFunction(&CNWSCreature::ReconcileAutoMapData, ReconcileAutoMapData, Hooks::Order::Early);
        s_VMAreaManagement     = Hooks::HookFunction(&CNWVirtualMachineCommands::ExecuteCommandAreaManagement, ExecuteCommandAreaManagement, Hooks::Order::Early);
        s_SeqTable.Initialize();
    }
}

static int32_t ExecuteCommandAreaManagement(CNWVirtualMachineCommands* pThis, int32_t nCommandId, int32_t nParameters)
{
    if (nCommandId == Constants::VMCommand::CreateArea  ||
        nCommandId == Constants::VMCommand::DestroyArea ||
        nCommandId == Constants::VMCommand::CopyArea)
    {
        s_AreaListSeq++;
    }

    return s_VMAreaManagement->CallOriginal<int32_t>(pThis, nCommandId, nParameters);
}

static void ReconcileAutoMapData(CNWSCreature* pThis)
{
    uint64_t seq = (uint64_t)s_SeqTable.Get(pThis->m_idSelf);
    if (seq != s_AreaListSeq)
    {
        s_ReconcileAutoMapData->CallOriginal<void>(pThis);
        s_SeqTable.Add(pThis->m_idSelf, (void*) s_AreaListSeq);
    }
}

}
