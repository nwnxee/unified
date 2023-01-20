#include "nwnx.hpp"

#include "API/CNWSMessage.hpp"
#include "API/CNWVisibilityNode.hpp"
#include "API/CNWSPlayerLastUpdateObject.hpp"
#include "API/CLoopingVisualEffect.hpp"
#include "API/ObjectVisualTransformData.hpp"
#include "API/CNWSCreature.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

void UpdateListComparisons() __attribute__((constructor));
void UpdateListComparisons()
{
    if (Config::Get<bool>("UPDATE_LIST_COMPARISONS", false))
    {
        LOG_INFO("Optimizing visibility and vfx list comparisons.");

        static Hooks::Hook s_ComputeVisibilityListsHook = Hooks::HookFunction(Functions::_ZN11CNWSMessage22ComputeVisibilityListsEP12CNWSCreatureP26CNWSPlayerLastUpdateObject,
        (void*)+[](CNWSMessage*, CNWSCreature *pCreature, CNWSPlayerLastUpdateObject *pLastUpdateObject) -> BOOL
        {
            CExoArrayList<CNWVisibilityNode*> *pSourceList = &pCreature->m_pVisibleCreaturesList;
            CExoArrayList<CNWVisibilityNode*> *pTargetList = &pLastUpdateObject->m_lstVisibilityList;

            if (pSourceList->num != pTargetList->num)
                return true;

            for (int nCount = 0; nCount < pSourceList->num; nCount++)
            {
                CNWVisibilityNode *pSourceNode = (*pSourceList)[nCount];
                CNWVisibilityNode *pTargetNode = nullptr;

                for (int nTargetCount = 0; nTargetCount < pTargetList->num; nTargetCount++)
                {
                    int nListOffset = (nCount + nTargetCount) % pTargetList->num;
                    if (pSourceNode->m_oidCreature == (*pTargetList)[nListOffset]->m_oidCreature)
                    {
                        pTargetNode = (*pTargetList)[nListOffset];
                        break;
                    }
                }

                if (pTargetNode)
                {
                    if (pSourceNode->m_bSeen != pTargetNode->m_bSeen ||
                        pSourceNode->m_bHeard != pTargetNode->m_bHeard ||
                        pSourceNode->m_bInvisible != pTargetNode->m_bInvisible)
                        return true;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }, Hooks::Order::Final);

        static Hooks::Hook s_CompareVisualEffectListsHook = Hooks::HookFunction(Functions::_ZN11CNWSMessage24CompareVisualEffectListsEP13CExoArrayListIP20CLoopingVisualEffectES4_,
        (void*)+[](CNWSMessage*, CExoArrayList<CLoopingVisualEffect*> *pSourceList1, CExoArrayList<CLoopingVisualEffect*> *pSourceList2) -> BOOL
        {
            if (pSourceList1->num != pSourceList2->num)
                return false;

            for (int nListCount1 = 0; nListCount1 < pSourceList1->num; nListCount1++)
            {
                bool bFound = false;
                CLoopingVisualEffect *pLVE1 = pSourceList1->element[nListCount1];

                for (int nListCount2 = 0; nListCount2 < pSourceList2->num; nListCount2++)
                {
                    int nListOffset = (nListCount1 + nListCount2) % pSourceList2->num;
                    CLoopingVisualEffect *pLVE2 = pSourceList2->element[nListOffset];

                    if (pLVE1->m_nId == pLVE2->m_nId && pLVE1->m_ovtd == pLVE2->m_ovtd)
                    {
                        if (!pLVE1->GetIsBeam() || (pLVE1->m_oOriginator == pLVE2->m_oOriginator))
                        {
                            bFound = true;
                            break;
                        }
                    }
                }

                if (!bFound)
                    return false;
            }

            for (int nListCount2 = 0; nListCount2 < pSourceList2->num; nListCount2++)
            {
                bool bFound = false;
                CLoopingVisualEffect *pLVE2 = pSourceList2->element[nListCount2];

                for (int nListCount1 = 0; nListCount1 < pSourceList1->num; nListCount1++)
                {
                    int nListOffset = (nListCount1 + nListCount2) % pSourceList1->num;
                    CLoopingVisualEffect *pLVE1 = pSourceList1->element[nListOffset];

                    if (pLVE2->m_nId == pLVE1->m_nId && pLVE2->m_ovtd == pLVE1->m_ovtd)
                    {
                        if (!pLVE2->GetIsBeam() || (pLVE2->m_oOriginator == pLVE1->m_oOriginator))
                        {
                            bFound = true;
                            break;
                        }
                    }
                }

                if (!bFound)
                    return false;
            }

            return true;
        }, Hooks::Order::Final);
    }
}

}
