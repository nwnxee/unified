#pragma once

#include "nwnx.hpp"
#include <memory>

namespace Data {

class Array;

class Data : public NWNXLib::Plugin
{
public:
    Data(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Data();

private:
    std::unique_ptr<Array> m_arrayProvider;
};

}
