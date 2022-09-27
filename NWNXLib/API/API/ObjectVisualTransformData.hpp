#pragma once
#include "nwn_api.hpp"

#include "CAurObjectVisualTransformData.hpp"
#include <map>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ObjectVisualTransformData)
#endif





struct ObjectVisualTransformData
{
    std::map<int32_t, CAurObjectVisualTransformData> m_scopes;
    ObjectVisualTransformData() {}

#ifdef NWN_CLASS_EXTENSION_ObjectVisualTransformData
    NWN_CLASS_EXTENSION_ObjectVisualTransformData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ObjectVisualTransformData)
#endif

