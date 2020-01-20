#pragma once
#include "nwn_api.hpp"

#include "CNWAnimBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSAnimBase)
#endif





struct CNWSAnimBase : CNWAnimBase
{

    CNWSAnimBase();
    virtual ~CNWSAnimBase();


#ifdef NWN_CLASS_EXTENSION_CNWSAnimBase
    NWN_CLASS_EXTENSION_CNWSAnimBase
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSAnimBase)
#endif

