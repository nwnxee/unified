#pragma once

#include "Services/Services.hpp"

namespace NWNXLib {
namespace Services {

class Commands : public ServiceBase
{
public:
    Commands();
    ~Commands();
};

class CommandsProxy : public ServiceProxy<Commands>
{
public:
    CommandsProxy(Commands&);
    ~CommandsProxy();
};

}
}
