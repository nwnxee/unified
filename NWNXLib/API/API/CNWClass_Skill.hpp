#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWClass_Skill)
#endif



typedef int BOOL;


class CNWClass_Skill
{
public:
    uint16_t nSkill;
    BOOL bClassSkill;



#ifdef NWN_CLASS_EXTENSION_CNWClass_Skill
    NWN_CLASS_EXTENSION_CNWClass_Skill
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWClass_Skill)
#endif

