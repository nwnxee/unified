#pragma once

#include "Plugin.hpp"
#include <memory>

namespace Data {

class Array;

class Data : public NWNXLib::Plugin
{
public:
    Data(const Plugin::CreateParams& params);
    virtual ~Data();

private:
    std::unique_ptr<Array> m_arrayProvider;
};

}
