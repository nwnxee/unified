#include "JVM.hpp"
#include "Internal.hpp"

#include "Services/Log/Log.hpp"
#include "Services/Config/Config.hpp"

#include "Util.h"

namespace JVM
{

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;

void JVM::Reconfigure()
{
    using namespace std::placeholders;

    {
        // std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);

        // GetServices()->m_log->Info("%s", "Reconfigured!");
    }
}

}
