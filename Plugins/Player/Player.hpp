#pragma once

#include "nwnx.hpp"
#include "API/ObjectVisualTransformData.hpp"
#include "API/CExoLocString.hpp"
#include <map>
#include <set>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Player {

class Player : public NWNXLib::Plugin
{
public:
    Player(NWNXLib::Services::ProxyServiceList* services);
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
    ArgumentStack PossessCreature                   (ArgumentStack&& args);
    ArgumentStack GetPlatformId                     (ArgumentStack&& args);
    ArgumentStack GetLanguage                       (ArgumentStack&& args);
    ArgumentStack SetResManOverride                 (ArgumentStack&& args);
    ArgumentStack SetCustomToken                    (ArgumentStack&& args);
    ArgumentStack SetCreatureNameOverride           (ArgumentStack&& args);
    ArgumentStack FloatingTextStringOnCreature      (ArgumentStack&& args);
    ArgumentStack ToggleDM                          (ArgumentStack&& args);
    ArgumentStack SetObjectMouseCursorOverride      (ArgumentStack&& args);
    ArgumentStack SetObjectHiliteColorOverride      (ArgumentStack&& args);
    ArgumentStack RemoveEffectFromTURD              (ArgumentStack&& args);
    ArgumentStack SetSpawnLocation                  (ArgumentStack&& args);
    ArgumentStack SendDMAllCreatorLists             (ArgumentStack&& args);
    ArgumentStack AddCustomJournalEntry             (ArgumentStack&& args);
    ArgumentStack GetJournalEntry                   (ArgumentStack&& args);
    ArgumentStack CloseStore                        (ArgumentStack&& args);

    CNWSPlayer *player(ArgumentStack& args);

    std::unordered_map<std::string, std::pair<ObjectID, bool>> m_PersistentLocationWP;
};

}
