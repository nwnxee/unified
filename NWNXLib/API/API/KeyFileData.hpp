#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(KeyFileData)
#endif





class KeyFileData
{
    int month;
    int day;
    int year;
    int build;
    char program[16];
    char description[988];



#ifdef NWN_CLASS_EXTENSION_KeyFileData
    NWN_CLASS_EXTENSION_KeyFileData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(KeyFileData)
#endif

