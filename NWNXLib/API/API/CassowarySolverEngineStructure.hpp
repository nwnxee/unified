#pragma once
#include "nwn_api.hpp"

#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CassowarySolverEngineStructure)
#endif





struct CassowarySolverEngineStructure
{
    std::shared_ptr<void*> m_shared;


#ifdef NWN_CLASS_EXTENSION_CassowarySolverEngineStructure
    NWN_CLASS_EXTENSION_CassowarySolverEngineStructure
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CassowarySolverEngineStructure)
#endif

