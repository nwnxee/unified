#pragma once
#include "nwn_api.hpp"

#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CassowarySolverEngineStructure)
#endif

template<typename T>
struct SharedPtrEngineStructure
{
    std::shared_ptr<T> m_shared;
    virtual ~SharedPtrEngineStructure() {}
};


struct CassowarySolverEngineStructureShared;
struct CassowarySolverEngineStructure : public SharedPtrEngineStructure<CassowarySolverEngineStructureShared>
{
    virtual ~CassowarySolverEngineStructure() {}

#ifdef NWN_CLASS_EXTENSION_CassowarySolverEngineStructure
    NWN_CLASS_EXTENSION_CassowarySolverEngineStructure
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CassowarySolverEngineStructure)
#endif

