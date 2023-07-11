#pragma once
#include "nwn_api.hpp"

#include "CNWRules.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSRules)
#endif





class CNWSRules : CNWRules
{

    CNWSRules();
    ~CNWSRules();


#ifdef NWN_CLASS_EXTENSION_CNWSRules
    NWN_CLASS_EXTENSION_CNWSRules
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSRules)
#endif

