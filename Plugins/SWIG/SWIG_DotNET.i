%module NWNXLib

%include <stdint.i>

#pragma SWIG nowarn=317

%typemap(cscode) CExoString %{
  public override string ToString() {
    return CStr();
  }
%};

%nodefaultctor;
%nodefaultdtor;

// Rename constants to unique classes.
%rename("%(regex:/(?:NWNXLib::API::Constants)::\s*(\w+)(?:.+)$/\\1/)s", regextarget=1, fullname=1, %$isenum) "NWNXLib::API::Constants::*";

// Rename/ignore operators methods
%rename(__Not) operator!;
%rename(__Equals) operator==;
%rename(__NotEquals) operator!=;
%rename(__Assign) operator=;
%rename(__Add) operator+;
%rename(__Subtract) operator-;
%rename(__LessThan) operator<;
%rename(__GreaterThan) operator>;
%rename(__LessThanOrEqual) operator<=;
%rename(__GreaterThanOrEqual) operator>=;
%rename(__Increment) operator+=;
%rename(__Decrement) operator-=;
%rename(__Index) operator[];
%ignore CExoString::operator std::string;

// Ignore ambigious types.
%ignore MIN;
%ignore MAX;
%ignore MASK;
%ignore ToString;

// Ignore multi-inheritance types.
%ignore CCallbackHandlerBase;
%ignore CNWArea;
%ignore CNWItem;
%ignore CResHelper<CRes2DA,2017>;
%ignore CResHelper<CResDWK,2052>;
%ignore CResHelper<CResLTR,2036>;
%ignore CResHelper<CResPWK,2053>;
%ignore CResHelper<CResARE,2012>;
%ignore CResHelper<CResIFO,2014>;
%ignore CResHelper<CResSET,2013>;
%ignore CResHelper<CResWOK,2016>;
%ignore CResHelper<CResNSS,2009>;
%ignore CResHelper<CResTLK,2018>;
%ignore CResHelper<CResNDB,2064>;
%ignore CResHelper<CResNCS,2010>;

// Ignore template methods with missing type implementations.
%ignore CExoArrayList::DerefContains;
%ignore CExoArrayList::IndexOf;
%ignore CExoArrayList::Contains;
%ignore CExoArrayList::AddUnique;
%ignore CExoArrayList::Remove;

// Template defines
%include "API/CExoArrayList.hpp"
%include "API/CExoLinkedList.hpp"
%include "API/CResHelper.hpp"

%template(CExoArrayListCCombatInformationNodePtr) CExoArrayList<CCombatInformationNode *>;
%template(CExoArrayListCEffectIconObjectPtr) CExoArrayList<CEffectIconObject *>;
%template(CExoArrayListCExoKeyTablePtr) CExoArrayList<CExoKeyTable *>;
%template(CExoArrayListCExoString) CExoArrayList<CExoString>;
%template(CExoArrayListCExoStringPtr) CExoArrayList<CExoString *>;
%template(CExoArrayListCFeatUseListEntryPtr) CExoArrayList<CFeatUseListEntry *>;
%template(CExoArrayListCFileInfo) CExoArrayList<CFileInfo>;
%template(CExoArrayListCGameEffectPtr) CExoArrayList<CGameEffect *>;
%template(CExoArrayListCGameObjectPtr) CExoArrayList<CGameObject *>;
%template(CExoArrayListCLoopingVisualEffectPtr) CExoArrayList<CLoopingVisualEffect *>;
%template(CExoArrayListCNetLayerPlayerCDKeyInfo) CExoArrayList<CNetLayerPlayerCDKeyInfo>;
%template(CExoArrayListCNWCCMessageDataPtr) CExoArrayList<CNWCCMessageData *>;
%template(CExoArrayListCNWItemProperty) CExoArrayList<CNWItemProperty>;
%template(CExoArrayListCNWLevelStatsPtr) CExoArrayList<CNWLevelStats *>;
%template(CExoArrayListCNWSExpressionPtr) CExoArrayList<CNWSExpression *>;
%template(CExoArrayListCNWSFactionPtr) CExoArrayList<CNWSFaction *>;
%template(CExoArrayListCNWSInvitationDetails) CExoArrayList<CNWSInvitationDetails>;
%template(CExoArrayListCNWSPersonalReputation) CExoArrayList<CNWSPersonalReputation>;
%template(CExoArrayListCNWSPlayerJournalQuestUpdates) CExoArrayList<CNWSPlayerJournalQuestUpdates>;
%template(CExoArrayListCNWSPVPEntry) CExoArrayList<CNWSPVPEntry>;
%template(CExoArrayListCNWSSpellScriptDataPtr) CExoArrayList<CNWSSpellScriptData *>;
%template(CExoArrayListCNWSStatsSpellLikeAbility) CExoArrayList<CNWSStats_SpellLikeAbility>;
%template(CExoArrayListCNWSStatsSpellPtr) CExoArrayList<CNWSStats_Spell *>;
%template(CExoArrayListCNWSTagNode) CExoArrayList<CNWSTagNode>;
%template(CExoArrayListCNWVisibilityNodePtr) CExoArrayList<CNWVisibilityNode *>;
%template(CExoArrayListCResRef) CExoArrayList<CResRef>;
%template(CExoArrayListCScriptLogPtr) CExoArrayList<CScriptLog *>;
%template(CExoArrayListCSpellAddPtr) CExoArrayList<CSpell_Add *>;
%template(CExoArrayListCSpellDeletePtr) CExoArrayList<CSpell_Delete *>;
%template(CExoArrayListCStoreCustomerPtr) CExoArrayList<CStoreCustomer *>;
%template(CExoArrayListCWorldJournalEntry) CExoArrayList<CWorldJournalEntry>;
%template(CExoArrayListFloat) CExoArrayList<float>;
%template(CExoArrayListInt32) CExoArrayList<int32_t>;
%template(CExoArrayListMaterialShaderParam) CExoArrayList<MaterialShaderParam>;
%template(CExoArrayListNWPlayerCharacterListPtr) CExoArrayList<NWPlayerCharacterList_st *>;
%template(CExoArrayListNWPlayerCharacterListClass) CExoArrayList<NWPlayerCharacterListClass_st>;
%template(CExoArrayListObjectId) CExoArrayList<OBJECT_ID>;
%template(CExoArrayListScriptParam) CExoArrayList<ScriptParam>;
%template(CExoArrayListSJournalEntry) CExoArrayList<SJournalEntry>;
%template(CExoArrayListSSubNetProfilePtr) CExoArrayList<SSubNetProfile *>;
%template(CExoArrayListTextureReplaceInfo) CExoArrayList<TextureReplaceInfo>;
%template(CExoArrayListUInt16) CExoArrayList<uint16_t>;
%template(CExoArrayListUInt32) CExoArrayList<uint32_t>;

%template(CExoLinkedListC2DA) CExoLinkedList<C2DA>;
%template(CExoLinkedListCERFKey) CExoLinkedList<CERFKey>;
%template(CExoLinkedListCERFRes) CExoLinkedList<CERFRes>;
%template(CExoLinkedListCERFString) CExoLinkedList<CERFString>;
%template(CExoLinkedListCExoInputEventDesc) CExoLinkedList<CExoInputEventDesc>;
%template(CExoLinkedListCExoString) CExoLinkedList<CExoString>;
%template(CExoLinkedListCKeyTableInfo) CExoLinkedList<CKeyTableInfo>;
%template(CExoLinkedListCLastUpdateObject) CExoLinkedList<CLastUpdateObject>;
%template(CExoLinkedListCLastUpdatePartyObject) CExoLinkedList<CLastUpdatePartyObject>;
%template(CExoLinkedListCNWSClient) CExoLinkedList<CNWSClient>;
%template(CExoLinkedListCNWSCombatRoundAction) CExoLinkedList<CNWSCombatRoundAction>;
%template(CExoLinkedListCNWSDialogPlayer) CExoLinkedList<CNWSDialogPlayer>;
%template(CExoLinkedListCNWSObjectActionNode) CExoLinkedList<CNWSObjectActionNode>;
%template(CExoLinkedListCNWSPlayerLUOInventoryItem) CExoLinkedList<CNWSPlayerLUOInventoryItem>;
%template(CExoLinkedListCNWSPlayerTURD) CExoLinkedList<CNWSPlayerTURD>;
%template(CExoLinkedListCRes) CExoLinkedList<CRes>;
%template(CExoLinkedListCResRef) CExoLinkedList<CResRef>;
%template(CExoLinkedListCServerAIEventNode) CExoLinkedList<CServerAIEventNode>;
%template(CExoLinkedListEXOLOCSTRING) CExoLinkedList<EXOLOCSTRING>;
%template(CExoLinkedListNWAreaExpansion) CExoLinkedList<NWAREAEXPANSION>;
%template(CExoLinkedListNWModuleCutscene) CExoLinkedList<NWMODULECUTSCENE>;
%template(CExoLinkedListNWModuleExpansion) CExoLinkedList<NWMODULEEXPANSION>;
%template(CExoLinkedListNWPlayerListItem) CExoLinkedList<NWPLAYERLISTITEM>;
%template(CExoLinkedListObjectId) CExoLinkedList<OBJECT_ID>;

%template(CResHelper2DA) CResHelper<CRes2DA,2017>;
%template(CResHelperDWK) CResHelper<CResDWK,2052>;
%template(CResHelperLTR) CResHelper<CResLTR,2036>;
%template(CResHelperPWK) CResHelper<CResPWK,2053>;
%template(CResHelperARE) CResHelper<CResARE,2012>;
%template(CResHelperIFO) CResHelper<CResIFO,2014>;
%template(CResHelperSET) CResHelper<CResSET,2013>;
%template(CResHelperWOK) CResHelper<CResWOK,2016>;
%template(CResHelperNSS) CResHelper<CResNSS,2009>;
%template(CResHelperTLK) CResHelper<CResTLK,2018>;
%template(CResHelperNDB) CResHelper<CResNDB,2064>;
%template(CResHelperNCS) CResHelper<CResNCS,2010>;

%include "NWNXLib.i"
