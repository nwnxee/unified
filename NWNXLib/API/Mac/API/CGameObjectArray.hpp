#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameObject;
struct CGameObjectArrayNode;

struct CGameObjectArray
{
    CGameObjectArrayNode** m_pArray;
    uint32_t m_nNextObjectArrayID[2];
    uint32_t m_nNextCharArrayID[2];
    uint32_t m_nLogGameObjectCache;
    uint32_t m_nGameObjectCache;
    int32_t m_bClientMode;
    uint32_t m_nArraySize;

    // The below are auto generated stubs.
    CGameObjectArray() = default;
    CGameObjectArray(const CGameObjectArray&) = default;
    CGameObjectArray& operator=(const CGameObjectArray&) = default;

    CGameObjectArray(int32_t);
    ~CGameObjectArray();
    unsigned char AddCharacterObjectAtPos(uint32_t, CGameObject*);
    unsigned char AddExternalObject(uint32_t&, CGameObject*, int32_t);
    unsigned char AddInternalObject(uint32_t&, CGameObject*, int32_t);
    unsigned char AddObjectAtPos(uint32_t, CGameObject*);
    void Clean(uint16_t);
    unsigned char Delete(uint32_t);
    unsigned char Delete(uint32_t, CGameObject**);
    unsigned char GetGameObject(uint32_t, CGameObject**);
};

void CGameObjectArray__CGameObjectArrayCtor__0(CGameObjectArray* thisPtr, int32_t);
void CGameObjectArray__CGameObjectArrayDtor__0(CGameObjectArray* thisPtr);
unsigned char CGameObjectArray__AddCharacterObjectAtPos(CGameObjectArray* thisPtr, uint32_t, CGameObject*);
unsigned char CGameObjectArray__AddExternalObject(CGameObjectArray* thisPtr, uint32_t&, CGameObject*, int32_t);
unsigned char CGameObjectArray__AddInternalObject(CGameObjectArray* thisPtr, uint32_t&, CGameObject*, int32_t);
unsigned char CGameObjectArray__AddObjectAtPos(CGameObjectArray* thisPtr, uint32_t, CGameObject*);
void CGameObjectArray__Clean(CGameObjectArray* thisPtr, uint16_t);
unsigned char CGameObjectArray__Delete__0(CGameObjectArray* thisPtr, uint32_t);
unsigned char CGameObjectArray__Delete__1(CGameObjectArray* thisPtr, uint32_t, CGameObject**);
unsigned char CGameObjectArray__GetGameObject(CGameObjectArray* thisPtr, uint32_t, CGameObject**);

}

}
