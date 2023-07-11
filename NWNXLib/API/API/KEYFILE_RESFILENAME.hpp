#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(KEYFILE_RESFILENAME)
#endif





class KEYFILE_RESFILENAME
{
public:
    uint32_t nFileSize;
    uint32_t nFileNameOffset;
    uint16_t nFileNameSize;
    uint16_t bDrives;



#ifdef NWN_CLASS_EXTENSION_KEYFILE_RESFILENAME
    NWN_CLASS_EXTENSION_KEYFILE_RESFILENAME
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(KEYFILE_RESFILENAME)
#endif

