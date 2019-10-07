#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <map>
#include <bitset>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Appearance {

class Appearance : public NWNXLib::Plugin
{
public:
    Appearance(const Plugin::CreateParams& params);
    virtual ~Appearance();

private:
    static NWNXLib::API::CNWSPlayer *Player(ArgumentStack& args);
    static void ComputeGameObjectUpdateForObjectHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*,
        NWNXLib::API::CNWSPlayer*, NWNXLib::API::CNWSObject*, NWNXLib::API::CGameObjectArray*, NWNXLib::API::Types::ObjectID);

    enum OverrideType {
        AppearanceType  = 0,
        Gender          = 1,
        HitPoints       = 2,
        HairColor       = 3,
        SkinColor       = 4,
        PhenoType       = 5,
        HeadType        = 6,
        SoundSet        = 7,
        TailType        = 8,
        WingType        = 9,
        FootstepSound   = 10,
        Portrait        = 11,
        OverrideType_MAX // Keep as last
    };

    struct AppearanceOverrideData
    {
        std::bitset<OverrideType_MAX> bitSet;

        uint16_t appearanceType     = 0;
        uint8_t gender              = 0;
        int32_t currentHitPoints    = 0;
        uint8_t hairColor           = 0;
        uint8_t skinColor           = 0;
        uint8_t phenoType           = 0;
        uint8_t headType            = 0;
        uint16_t soundSet           = 0;
        uint32_t tailType           = 0;
        uint32_t wingType           = 0;
        int32_t footstepSound       = 0;
        uint16_t portraitId         = 0;
    };

    template <typename T>
    static void SwapIntValue(bool, T&, T&);
    template <typename T>
    static void SetIntValue(int32_t, int32_t, std::bitset<OverrideType_MAX>&, T&);

    ArgumentStack SetOverride (ArgumentStack&& args);
    ArgumentStack GetOverride (ArgumentStack&& args);
};

}
