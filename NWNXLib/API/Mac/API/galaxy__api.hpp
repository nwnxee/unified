#pragma once

#include <cstdint>

#include "unknown_galaxyapiIApps.hpp"
#include "unknown_galaxyapiIError.hpp"
#include "unknown_galaxyapiIFriends.hpp"
#include "unknown_galaxyapiIListenerRegistrar.hpp"
#include "unknown_galaxyapiIStats.hpp"
#include "unknown_galaxyapiIUser.hpp"

namespace NWNXLib {

namespace API {

struct galaxy__api
{

    galaxyapiIApps* Apps();
    galaxyapiIFriends* Friends();
    const galaxyapiIError* GetError();
    galaxyapiIListenerRegistrar* ListenerRegistrar();
    void ProcessData();
    void Shutdown();
    galaxyapiIStats* Stats();
    galaxyapiIUser* User();
};

galaxyapiIApps* galaxy__api__Apps(galaxy__api* thisPtr);
galaxyapiIFriends* galaxy__api__Friends(galaxy__api* thisPtr);
const galaxyapiIError* galaxy__api__GetError(galaxy__api* thisPtr);
galaxyapiIListenerRegistrar* galaxy__api__ListenerRegistrar(galaxy__api* thisPtr);
void galaxy__api__ProcessData(galaxy__api* thisPtr);
void galaxy__api__Shutdown(galaxy__api* thisPtr);
galaxyapiIStats* galaxy__api__Stats(galaxy__api* thisPtr);
galaxyapiIUser* galaxy__api__User(galaxy__api* thisPtr);

}

}
