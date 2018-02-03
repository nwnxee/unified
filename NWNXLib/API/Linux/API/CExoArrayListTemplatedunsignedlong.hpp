#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedunsignedlong
{

    // The below are auto generated stubs.
    CExoArrayListTemplatedunsignedlong() = default;
    CExoArrayListTemplatedunsignedlong(const CExoArrayListTemplatedunsignedlong&) = default;

    ~CExoArrayListTemplatedunsignedlong();
    void Add(uint32_t);
    int32_t AddUnique(uint32_t);
    void Allocate(int32_t);
    CExoArrayListTemplatedunsignedlong& operator=(const CExoArrayListTemplatedunsignedlong&);
    void Remove(uint32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongDtor(CExoArrayListTemplatedunsignedlong* thisPtr);
void CExoArrayListTemplatedunsignedlong__Add(CExoArrayListTemplatedunsignedlong* thisPtr, uint32_t);
int32_t CExoArrayListTemplatedunsignedlong__AddUnique(CExoArrayListTemplatedunsignedlong* thisPtr, uint32_t);
void CExoArrayListTemplatedunsignedlong__Allocate(CExoArrayListTemplatedunsignedlong* thisPtr, int32_t);
CExoArrayListTemplatedunsignedlong& CExoArrayListTemplatedunsignedlong__OperatorAssignment(CExoArrayListTemplatedunsignedlong* thisPtr, const CExoArrayListTemplatedunsignedlong&);
void CExoArrayListTemplatedunsignedlong__Remove(CExoArrayListTemplatedunsignedlong* thisPtr, uint32_t);
void CExoArrayListTemplatedunsignedlong__SetSize(CExoArrayListTemplatedunsignedlong* thisPtr, int32_t);

}

}
