#pragma once
#include "nwn_api.hpp"

#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SqlQueryEngineStructure)
#endif





struct SqlQueryEngineStructure
{
    std::shared_ptr<void*> m_shared;

    uint64_t GetId() const;
    SqlQueryEngineStructure();


#ifdef NWN_CLASS_EXTENSION_SqlQueryEngineStructure
    NWN_CLASS_EXTENSION_SqlQueryEngineStructure
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SqlQueryEngineStructure)
#endif

