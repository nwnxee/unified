#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSTagNode)
#endif



typedef uint32_t OBJECT_ID;


class CNWSTagNode
{
public:
    char m_szTag[64+1];
    OBJECT_ID m_oidObjectId;



#ifdef NWN_CLASS_EXTENSION_CNWSTagNode
    NWN_CLASS_EXTENSION_CNWSTagNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSTagNode)
#endif

