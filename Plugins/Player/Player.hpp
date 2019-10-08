#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/ObjectVisualTransformData.hpp"
#include <map>
#include <set>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Player {

class Player : public NWNXLib::Plugin
{
public:
    Player(const Plugin::CreateParams& params);
    virtual ~Player();

private:
    ArgumentStack ForcePlaceableExamineWindow       (ArgumentStack&& args);
    ArgumentStack ForcePlaceableInventoryWindow     (ArgumentStack&& args);
    ArgumentStack StartGuiTimingBar                 (ArgumentStack&& args);
    ArgumentStack StopGuiTimingBar                  (ArgumentStack&& args);
    ArgumentStack SetAlwaysWalk                     (ArgumentStack&& args);
    ArgumentStack GetQuickBarSlot                   (ArgumentStack&& args);
    ArgumentStack SetQuickBarSlot                   (ArgumentStack&& args);
    ArgumentStack GetBicFileName                    (ArgumentStack&& args);
    ArgumentStack ShowVisualEffect                  (ArgumentStack&& args);
    ArgumentStack ChangeBackgroundMusic             (ArgumentStack&& args);
    ArgumentStack PlayBackgroundMusic               (ArgumentStack&& args);
    ArgumentStack ChangeBattleMusic                 (ArgumentStack&& args);
    ArgumentStack PlayBattleMusic                   (ArgumentStack&& args);
    ArgumentStack PlaySound                         (ArgumentStack&& args);
    ArgumentStack SetPlaceableUsable                (ArgumentStack&& args);
    ArgumentStack SetRestDuration                   (ArgumentStack&& args);
    ArgumentStack ApplyInstantVisualEffectToObject  (ArgumentStack&& args);
    ArgumentStack UpdateCharacterSheet              (ArgumentStack&& args);
    ArgumentStack OpenInventory                     (ArgumentStack&& args);
    ArgumentStack GetAreaExplorationState           (ArgumentStack&& args);
    ArgumentStack SetAreaExplorationState           (ArgumentStack&& args);
    ArgumentStack SetRestAnimation                  (ArgumentStack&& args);
    ArgumentStack SetObjectVisualTransformOverride  (ArgumentStack&& args);
    ArgumentStack ApplyLoopingVisualEffectToObject  (ArgumentStack&& args);
    ArgumentStack SetPlaceableNameOverride          (ArgumentStack&& args);
    ArgumentStack GetQuestCompleted                 (ArgumentStack&& args);
    ArgumentStack SetPersistentLocation             (ArgumentStack&& args);
    ArgumentStack UpdateItemName                    (ArgumentStack&& args);

    NWNXLib::API::CNWSPlayer *player(ArgumentStack& args);

    std::unordered_map<std::string, std::pair<NWNXLib::API::Types::ObjectID, bool>> m_PersistentLocationWP;
};

}
