#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameEffectApplierRemover)
#endif

class CGameEffect;
class CNWSObject;


typedef int BOOL;


class CGameEffectApplierRemover
{
public:
    virtual ~CGameEffectApplierRemover();
    virtual void InitializeEffects();
    virtual int32_t OnEffectApplied(CNWSObject * object, CGameEffect * effect, BOOL bLoadingGame = false);
    virtual int32_t OnEffectRemoved(CNWSObject * object, CGameEffect * effect);


#ifdef NWN_CLASS_EXTENSION_CGameEffectApplierRemover
    NWN_CLASS_EXTENSION_CGameEffectApplierRemover
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGameEffectApplierRemover)
#endif

