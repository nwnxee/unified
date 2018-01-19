#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "KeyFileHeader_st.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoFile;
struct KeyFileResFileName_st;

struct CKeyTableInfo
{
    CExoString m_sName;
    CExoFile* m_pFile;
    KeyFileHeader_st m_header;
    KeyFileResFileName_st* m_pResFileNames;
};

}

}
