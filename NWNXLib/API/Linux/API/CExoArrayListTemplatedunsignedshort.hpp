#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedunsignedshort
{

    void Add(uint16_t);
    void Allocate(int32_t);
    void Insert(uint16_t, int32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedunsignedshort__Add(CExoArrayListTemplatedunsignedshort* thisPtr, uint16_t);
void CExoArrayListTemplatedunsignedshort__Allocate(CExoArrayListTemplatedunsignedshort* thisPtr, int32_t);
void CExoArrayListTemplatedunsignedshort__Insert(CExoArrayListTemplatedunsignedshort* thisPtr, uint16_t, int32_t);
void CExoArrayListTemplatedunsignedshort__SetSize(CExoArrayListTemplatedunsignedshort* thisPtr, int32_t);

}

}
