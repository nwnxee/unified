#pragma once
#include "nwnx.hpp"

namespace Events {
    void PushEventData(const std::string& tag, const std::string& data);
    bool SignalEvent(const std::string& eventName, ObjectID target, std::string* result = nullptr);
    void InitOnFirstSubscribe(const std::string& eventName, std::function<void(void)> init);
    bool IsIDInWhitelist(const std::string& eventName, int32_t id);
    void ForceEnableWhitelist(const std::string& eventName);
}
