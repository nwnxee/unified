#include "Services/Commands/Commands.hpp"

namespace NWNXLib {
namespace Services {

Commands::Commands()
{
}

Commands::~Commands()
{
}


CommandsProxy::CommandsProxy(Commands& commands)
    : ServiceProxy<Commands>(commands)
{
}

CommandsProxy::~CommandsProxy()
{
}



}
}
