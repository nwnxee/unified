#pragma once
#include "nwn_api.hpp"

#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(out_of_space_error)
#endif





struct out_of_space_error : std::runtime_error
{



#ifdef NWN_CLASS_EXTENSION_out_of_space_error
    NWN_CLASS_EXTENSION_out_of_space_error
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(out_of_space_error)
#endif

