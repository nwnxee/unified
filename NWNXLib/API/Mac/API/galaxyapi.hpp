#pragma once

#include <cstdint>

#include "unknown_galaxyapiIApps.hpp"
#include "unknown_galaxyapiIError.hpp"
#include "unknown_galaxyapiIFriends.hpp"
#include "unknown_galaxyapiIListenerRegistrar.hpp"
#include "unknown_galaxyapiIUser.hpp"

namespace NWNXLib {

namespace API {

struct galaxyapi
{

    galaxyapiIApps* Apps();
    galaxyapiIFriends* Friends();
    const galaxyapiIError* GetError();
    galaxyapiIListenerRegistrar* ListenerRegistrar();
    void ProcessData();
    void Shutdown();
    galaxyapiIUser* User();
};

galaxyapiIApps* galaxyapi__Apps(galaxyapi* thisPtr);
galaxyapiIFriends* galaxyapi__Friends(galaxyapi* thisPtr);
const galaxyapiIError* galaxyapi__GetError(galaxyapi* thisPtr);
galaxyapiIListenerRegistrar* galaxyapi__ListenerRegistrar(galaxyapi* thisPtr);
void galaxyapi__ProcessData(galaxyapi* thisPtr);
void galaxyapi__Shutdown(galaxyapi* thisPtr);
galaxyapiIUser* galaxyapi__User(galaxyapi* thisPtr);

}

}
