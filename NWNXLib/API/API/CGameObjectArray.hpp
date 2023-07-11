#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameObjectArray)
#endif

class CGameObject;
class CGameObjectArrayNode;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CGameObjectArray
{
public:
    CGameObjectArrayNode * * m_pArray;
    uint32_t m_nNextObjectArrayID[2];
    uint32_t m_nNextCharArrayID[2];
    uint32_t m_nLogGameObjectCache;
    uint32_t m_nGameObjectCache;
    BOOL m_bClientMode;
    uint32_t m_nArraySize;

    CGameObjectArray(BOOL clientMode = true);
    ~CGameObjectArray();
    uint8_t AddCharacterObjectAtPos(OBJECT_ID ID, CGameObject * ptr);
    uint8_t AddObjectAtPos(OBJECT_ID ID, CGameObject * ptr);
    uint8_t AddExternalObject(OBJECT_ID & ID, CGameObject * ptr, BOOL CharacterObject = false);
    uint8_t AddInternalObject(OBJECT_ID & ID, CGameObject * ptr, BOOL CharacterObject = false);
    void Clean(uint16_t nList);
    uint8_t Delete(OBJECT_ID ID);
    uint8_t Delete(OBJECT_ID ID, CGameObject * * ptr);
    uint8_t GetGameObject(OBJECT_ID ID, CGameObject * * ptr);


#ifdef NWN_CLASS_EXTENSION_CGameObjectArray
    NWN_CLASS_EXTENSION_CGameObjectArray
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGameObjectArray)
#endif

