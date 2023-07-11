#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameObjectArrayNode)
#endif

class CGameObject;




class CGameObjectArrayNode
{
    uint32_t m_objectId;
    CGameObject * m_objectPtr;
    CGameObjectArrayNode * m_nextNode;



#ifdef NWN_CLASS_EXTENSION_CGameObjectArrayNode
    NWN_CLASS_EXTENSION_CGameObjectArrayNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGameObjectArrayNode)
#endif

