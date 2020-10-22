#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(TextureReplaceInfo)
#endif





struct TextureReplaceInfo
{
    char m_sOldName[16+1];
    char m_sNewName[16+1];



#ifdef NWN_CLASS_EXTENSION_TextureReplaceInfo
    NWN_CLASS_EXTENSION_TextureReplaceInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(TextureReplaceInfo)
#endif

