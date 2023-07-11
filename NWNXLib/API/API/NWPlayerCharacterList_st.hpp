#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CResRef.hpp"
#include "NWPlayerCharacterListClass_st.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWPlayerCharacterList_st)
#endif





class NWPlayerCharacterList_st
{
public:
    CExoLocString sLocFirstName;
    CExoLocString sLocLastName;
    uint8_t nType;
    CResRef resFileName;
    uint16_t nPortraitId;
    CResRef resPortrait;
    CExoArrayList<NWPlayerCharacterListClass_st> lstClasses;



#ifdef NWN_CLASS_EXTENSION_NWPlayerCharacterList_st
    NWN_CLASS_EXTENSION_NWPlayerCharacterList_st
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWPlayerCharacterList_st)
#endif

