#include "nwnx.hpp"

#include <dlfcn.h>
#include <unistd.h>
#include <sys/mman.h>

extern "C" NWNXLib::API::Globals::NWNXExportedGlobals NWNXEntryPoint();

namespace NWNXLib::API::Globals {
    NWNXExportedGlobals ExportedGlobals;
}

namespace NWNXLib::Platform {

void CalculateBaseAddress()
{
    // TODO: move elsewhere or get rid and use direct references like base game.
    NWNXLib::API::Globals::ExportedGlobals = NWNXEntryPoint();
}

}
