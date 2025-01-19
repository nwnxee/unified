%module NWNXLib

%include <stdint.i>
%include <std_string.i>
%include <std_vector.i>
%include <std_shared_ptr.i>
%include <swiginterface.i>

%include "DotNETExtensions.i"
%include "DotNETPrimitives.i"
%include "DotNETArrays.i"
%include "std_unordered_map.i"
%include "CExoArrayList.i"

#pragma SWIG nowarn=317
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNX_SWIG_PARSING

// Mark module class as static
%pragma(csharp) moduleclassmodifiers="public static unsafe class"
%pragma(csharp) imclassclassmodifiers="public unsafe class"
%typemap(csclassmodifiers) SWIGTYPE "public unsafe class"

// Use NwStringPInvokeMarshaller for marshalling of cp1252 strings.
namespace std {
%typemap(imtype, inattributes="[global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NWNX.NET.Native.Interop.NwStringPInvokeMarshaller))]", outattributes="[return: global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NWNX.NET.Native.Interop.NwStringPInvokeMarshaller))]") string "string"
%typemap(imtype, inattributes="[global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NWNX.NET.Native.Interop.NwStringPInvokeMarshaller))]", outattributes="[return: global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NWNX.NET.Native.Interop.NwStringPInvokeMarshaller))]") const string & "string"
}

// Marshal pointer types as void* for easier dereferencing
%define MarshalPtr(CTYPE, CSTYPE)
%typemap(ctype)  CTYPE*,CTYPE& "CTYPE*"
%typemap(imtype) CTYPE*,CTYPE& "global::System.IntPtr"
%typemap(cstype) CTYPE*,CTYPE& "CSTYPE*"
%typemap(csin)   CTYPE*,CTYPE& "(global::System.IntPtr)$csinput"
%typemap(in)     CTYPE*,CTYPE& %{ $1 = $input; %}
%typemap(out)    CTYPE*,CTYPE& %{ $result = $1; %}

%typemap(csout, excode=SWIGEXCODE) CTYPE*,CTYPE& {
    global::System.IntPtr retVal = $imcall;$excode
    return (CSTYPE*)retVal;
  }

%typemap(csvarout, excode=SWIGEXCODE2) CTYPE*,CTYPE& %{
    get {
        global::System.IntPtr retVal = $imcall;$excode
        return (CSTYPE*)retVal;
    }
%}
%enddef

// Marshal pointer types.
MarshalPtr(void, void)
MarshalPtr(void*, void*) // void**
MarshalPtr(C2DA*, void*)
MarshalPtr(CAppManager*, void*)
MarshalPtr(CCombatInformationNode*, void*)
MarshalPtr(CEffectIconObject*, void*)
MarshalPtr(CExoBase*, void*)
MarshalPtr(CExoResMan*, void*)
MarshalPtr(CExoKeyTable*, void*)
MarshalPtr(CExoLinkedListNode*, void*)
MarshalPtr(CExoPackedFile*, void*)
MarshalPtr(CExoString*, void*)
MarshalPtr(CFeatUseListEntry*, void*)
MarshalPtr(CGameEffect*, void*)
MarshalPtr(CGameObject*, void*)
MarshalPtr(CGameObjectArrayNode*, void*)
MarshalPtr(CItemRepository*, global::System.IntPtr)
MarshalPtr(CKeyTableEntry*, void*)
MarshalPtr(CLastUpdateObject*, void*)
MarshalPtr(CLastUpdatePartyObject*, void*)
MarshalPtr(CLoopingVisualEffect*, void*)
MarshalPtr(CNWCCMessageData*, void*)
MarshalPtr(CNWItemProperty*, void*)
MarshalPtr(CNWLevelStats*, void*)
MarshalPtr(CNWPlaceableSurfaceMesh*, void*)
MarshalPtr(CNWRules*, void*)
MarshalPtr(CNWSAreaGridSuccessors*, void*)
MarshalPtr(CNWSExpression*, void*)
MarshalPtr(CNWSFaction*, void*)
MarshalPtr(CNWSItem*, void*)
MarshalPtr(CNWSObjectActionNode*, void*)
MarshalPtr(CNWSSpellScriptData*, void*)
MarshalPtr(CNWSStats_Spell*, void*)
MarshalPtr(CNWTileSet*, void*)
MarshalPtr(CNWVisibilityNode*, void*)
MarshalPtr(CObjectLookupTable*, void*)
MarshalPtr(CPathfindInfoIntraTileSuccessors*, void*)
MarshalPtr(CScriptCompiler*, void*)
MarshalPtr(CScriptParseTreeNode*, void*)
MarshalPtr(CSpell_Add*, void*)
MarshalPtr(CSpell_Delete*, void*)
MarshalPtr(CStoreCustomer*, void*)
MarshalPtr(CTlkFile*, void*)
MarshalPtr(CTlkTable*, void*)
MarshalPtr(CVirtualMachine*, void*)
MarshalPtr(CVirtualMachineScript*, void*)
MarshalPtr(ENCAPSULATED_KEYLISTENTRY*, void*)
MarshalPtr(NWPlayerCharacterList_st*, void*)
MarshalPtr(SSubNetProfile*, void*)
MarshalPtr(Task::CExoTaskManager*, void*)

// Smart Pointers
%shared_ptr(NWSQLite::Database)
%shared_ptr(CVirtualMachineDebuggerInstance)
%shared_ptr(DataView)
%shared_ptr(DataBlock)
%shared_ptr(DataView::Shared)
%shared_ptr(sqlite3)

// Rename constants to unique classes.
%rename("%(regex:/(?:NWNXLib::API::Constants)::\s*(\w+)(?:.+)$/\\1/)s", regextarget=1, fullname=1, %$isenum) "NWNXLib::API::Constants::*";
%rename(SqliteDatabase) sqlite::database;

// Rename/ignore operators methods
%rename(_OpNot) operator!;
%rename(_OpEquals) operator==;
%rename(_Equals) Equals;
%rename(_OpNotEquals) operator!=;
%rename(_OpAssign) operator=;
%rename(_OpAdd) operator+;
%rename(_OpSubtract) operator-;
%rename(_OpLessThan) operator<;
%rename(_OpGreaterThan) operator>;
%rename(_OpLessThanOrEqual) operator<=;
%rename(_OpGreaterThanOrEqual) operator>=;
%rename(_OpIncrement) operator+=;
%rename(_OpDecrement) operator-=;
%rename(_OpIndex) operator[];
%ignore CExoString::operator std::string;

// Exclude default constructors for undefined references.
%nodefaultctor CVirtualMachineCmdImplementer;
%nodefaultctor CGameEffectApplierRemover;
%nodefaultctor CBaseExoApp;
%nodefaultctor CItemPropertyApplierRemover;
%nodefaultctor CNWAmbientSound;
%nodefaultctor CNWSEffectListHandler;
%nodefaultctor CNWVirtualMachineCommands;
%nodefaultctor CVirtualMachineDebugLoader;
%nodefaultctor CResARE;
%nodefaultctor CResIFO;
%nodefaultctor JsonEngineStructureShared;
%nodefaultctor Hash::SHA1;

// Ignore ambigious types.
%ignore MIN;
%ignore MAX;
%ignore MASK;
%ignore ToString;
%ignore NWN_CLASS_EXTENSION_CGameObject;

// Ignore complex types
%ignore CNWSync;
%ignore CNWTileSetManager;

// Interfaces for multi-inheritance types.
%interface_custom("CGameObject", "ICGameObject", CGameObject);
%interface_custom("CNWItem", "ICNWItem", CNWItem);

// Ignored multi-inheritance types.
%ignore CCallbackHandlerBase;
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

// Template defines
%include "API/CExoLinkedList.hpp"
%include "API/CResHelper.hpp"

%template(CExoLinkedListC2DA) CExoLinkedList<C2DA>;
%template(CExoLinkedListCERFKey) CExoLinkedList<CERFKey>;
%template(CExoLinkedListCERFRes) CExoLinkedList<CERFRes>;
%template(CExoLinkedListCERFString) CExoLinkedList<CERFString>;
%template(CExoLinkedListCExoInputEventDesc) CExoLinkedList<CExoInputEventDesc>;
%template(CExoLinkedListCExoString) CExoLinkedList<CExoString>;
%template(CExoLinkedListCKeyTableInfo) CExoLinkedList<CKeyTableInfo>;
%template(CExoLinkedListCLastUpdateObject) CExoLinkedList<CLastUpdateObject>;
%template(CExoLinkedListCLastUpdatePartyObject) CExoLinkedList<CLastUpdatePartyObject>;
%template(CExoLinkedListCNWSCombatRoundAction) CExoLinkedList<CNWSCombatRoundAction>;
%template(CExoLinkedListCNWSDialogPlayer) CExoLinkedList<CNWSDialogPlayer>;
%template(CExoLinkedListCNWSObjectActionNode) CExoLinkedList<CNWSObjectActionNode>;
%template(CExoLinkedListCNWSPlayerLUOInventoryItem) CExoLinkedList<CNWSPlayerLUOInventoryItem>;
%template(CExoLinkedListCNWSPlayerTURD) CExoLinkedList<CNWSPlayerTURD>;
%template(CExoLinkedListCRes) CExoLinkedList<CRes>;
%template(CExoLinkedListCResRef) CExoLinkedList<CResRef>;
%template(CExoLinkedListCServerAIEventNode) CExoLinkedList<CServerAIEventNode>;
%template(CExoLinkedListEXOLOCSTRING) CExoLinkedList<EXOLOCSTRING>;
%template(CExoLinkedListNWModuleCutscene) CExoLinkedList<NWMODULECUTSCENE>;
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

// Array wrappers for structures
MapArray(CExoArrayList<CNWSStats_Spell *>, CExoArrayListCNWSStatsSpellPtr, CExoArrayListCNWSStatsSpellPtrArray)
MapArray(CExoArrayList<CSpell_Add *>, CExoArrayListCSpellAddPtr, CExoArrayListCSpellAddPtrArray)
MapArray(CExoArrayList<CSpell_Delete *>, CExoArrayListCSpellDeletePtr, CExoArrayListCSpellDeletePtrArray)
MapArray(CExoArrayList<ScriptParam>, CExoArrayListScriptParam, CExoArrayListScriptParamArray)
MapArray(CExoArrayList<uint32_t>, CExoArrayListUInt32, CExoArrayListUInt32Array)
MapArray(CExoString, CExoString, CExoStringArray);
MapArray(CItemRepository*, CItemRepository, CItemRepositoryPtrArray);
MapArray(CNWActionNode, CNWActionNode, CNWActionNodeArray);
MapArray(CNWSCombatAttackData, CNWSCombatAttackData, CNWSCombatAttackDataArray);
MapArray(CNWSCreatureStats_ClassInfo, CNWSCreatureStats_ClassInfo, CNWSCreatureStats_ClassInfoArray);
MapArray(CNWTileSet*, CNWTileSet, CNWTileSetPtrArray);
MapArray(CScriptCompilerIncludeFileStackEntry, CScriptCompilerIncludeFileStackEntry, CScriptCompilerIncludeFileStackEntryArray);
MapArray(CScriptParseTreeNode, CScriptParseTreeNode, CScriptParseTreeNodeArray);
MapArray(CServerAIList, CServerAIList, CServerAIListArray);
MapArray(CServerOptionLookup, CServerOptionLookup, CServerOptionLookupArray);
MapArray(CTlkFile*, CTlkFile, CTlkFilePtrArray);
MapArray(CVirtualMachineScript, CVirtualMachineScript, CVirtualMachineScriptArray);
MapArray(Vector, Vector, VectorArray);

MapArray(CNWSTile, CNWSTile, CNWSTileArray);
MapArray(CNWSQuickbarButton, CNWSQuickbarButton, CNWSQuickbarButtonArray);
MapArray(CTlkTableToken, CTlkTableToken, CTlkTableTokenArray);
MapArray(CTlkTableTokenCustom, CTlkTableTokenCustom, CTlkTableTokenCustomArray);
MapArray(CNWSDialogEntry, CNWSDialogEntry, CNWSDialogEntryArray);
MapArray(CNWSDialogReply, CNWSDialogReply, CNWSDialogReplyArray);
MapArray(CNWSDialogLinkEntry, CNWSDialogLinkEntry, CNWSDialogLinkEntryArray);
MapArray(CNWSDialogLinkReply, CNWSDialogLinkReply, CNWSDialogLinkReplyArray);
MapArray(CNWRace, CNWRace, CNWRaceArray);
MapArray(CNWFeat, CNWFeat, CNWFeatArray);
MapArray(CResRef, CResRef, CResRefArray);
MapArray(CNWClass, CNWClass, CNWClassArray);
MapArray(CNWSkill, CNWSkill, CNWSkillArray);
MapArray(CNWDomain, CNWDomain, CNWDomainArray);
MapArray(CEncounterListEntry, CEncounterListEntry, CEncounterListEntryArray);
MapArray(CEncounterSpawnPoint, CEncounterSpawnPoint, CEncounterSpawnPointArray);
MapArray(CNWClass_Feat, CNWClass_Feat, CNWClass_FeatArray);
MapArray(CNWClass_Skill, CNWClass_Skill, CNWClass_SkillArray);

%include "NWNXLib.i"

%template(CExoArrayListCCombatInformationNodePtr) CExoArrayList<CCombatInformationNode *>;
%template(CExoArrayListCEffectIconObjectPtr) CExoArrayList<CEffectIconObject *>;
%template(CExoArrayListCExoKeyTablePtr) CExoArrayList<CExoKeyTable *>;
%template(CExoArrayListCExoString) CExoArrayList<CExoString>;
%template(CExoArrayListCExoStringPtr) CExoArrayList<CExoString *>;
%template(CExoArrayListCFeatUseListEntryPtr) CExoArrayList<CFeatUseListEntry *>;
%template(CExoArrayListCFileInfo) CExoArrayList<CFileInfo>;
%template(CExoArrayListCGameEffectPtr) CExoArrayList<CGameEffect *>;
%template(CExoArrayListCGameObjectPtr) CExoArrayList<CGameObject *>;
%template(CExoArrayListCLoopingVisualEffect) CExoArrayList<CLoopingVisualEffect>;
%template(CExoArrayListCLoopingVisualEffectPtr) CExoArrayList<CLoopingVisualEffect *>;
%template(CExoArrayListCNetLayerPlayerCDKeyInfo) CExoArrayList<CNetLayerPlayerCDKeyInfo>;
%template(CExoArrayListCNWCCMessageDataPtr) CExoArrayList<CNWCCMessageData *>;
%template(CExoArrayListCNWItemProperty) CExoArrayList<CNWItemProperty>;
%template(CExoArrayListCNWLevelStatsPtr) CExoArrayList<CNWLevelStats *>;
%template(CExoArrayListCNWSExpressionPtr) CExoArrayList<CNWSExpression *>;
%template(CExoArrayListCNWSFactionPtr) CExoArrayList<CNWSFaction *>;
%template(CExoArrayListCNWSInvitationDetails) CExoArrayList<CNWSInvitationDetails>;
%template(CExoArrayListCNWSPersonalReputation) CExoArrayList<CNWSPersonalReputation>;
%template(CExoArrayListCNWSPlayerPtr) CExoArrayList<CNWSPlayer *>;
%template(CExoArrayListCNWSPlayerJournalQuestUpdates) CExoArrayList<CNWSPlayerJournalQuestUpdates>;
%template(CExoArrayListCNWSPVPEntry) CExoArrayList<CNWSPVPEntry>;
%template(CExoArrayListCNWSSpellScriptDataPtr) CExoArrayList<CNWSSpellScriptData *>;
%template(CExoArrayListCNWSStatsSpellLikeAbility) CExoArrayList<CNWSStats_SpellLikeAbility>;
%template(CExoArrayListCNWSStatsSpellPtr) CExoArrayList<CNWSStats_Spell *>;
%template(CExoArrayListCNWSTagNode) CExoArrayList<CNWSTagNode>;
%template(CExoArrayListCNWVisibilityNodePtr) CExoArrayList<CNWVisibilityNode *>;
%template(CExoArrayListCNWVisibilityNode) CExoArrayList<CNWVisibilityNode>;
%template(CExoArrayListCResRef) CExoArrayList<CResRef>;
%template(CExoArrayListCSpellAddPtr) CExoArrayList<CSpell_Add *>;
%template(CExoArrayListCSpellDeletePtr) CExoArrayList<CSpell_Delete *>;
%template(CExoArrayListCStoreCustomerPtr) CExoArrayList<CStoreCustomer *>;
%template(CExoArrayListCWorldJournalEntry) CExoArrayList<CWorldJournalEntry>;
%template(CExoArrayListFloat) CExoArrayList<float>;
%template(CExoArrayListInt32) CExoArrayList<int32_t>;
%template(CExoArrayListMaterialShaderParam) CExoArrayList<MaterialShaderParam>;
%template(CExoArrayListNWPlayerCharacterListPtr) CExoArrayList<NWPlayerCharacterList_st *>;
%template(CExoArrayListNWPlayerCharacterListClass) CExoArrayList<NWPlayerCharacterListClass_st>;
%template(CExoArrayListScriptParam) CExoArrayList<ScriptParam>;
%template(CExoArrayListSJournalEntry) CExoArrayList<SJournalEntry>;
%template(CExoArrayListTextureReplaceInfo) CExoArrayList<TextureReplaceInfo>;
%template(CExoArrayListUInt16) CExoArrayList<uint16_t>;
%template(CExoArrayListUInt32) CExoArrayList<uint32_t>;
%template(CExoArrayListCLastUpdateObjectPtr) CExoArrayList<CLastUpdateObject*>;
%template(CExoArrayListCLastUpdatePartyObjectPtr) CExoArrayList<CLastUpdatePartyObject*>;

// Array wrappers for structures
DefineArray(CExoArrayList<CNWSStats_Spell *>, CExoArrayListCNWSStatsSpellPtr, CExoArrayListCNWSStatsSpellPtrArray)
DefineArray(CExoArrayList<CSpell_Add *>, CExoArrayListCSpellAddPtr, CExoArrayListCSpellAddPtrArray)
DefineArray(CExoArrayList<CSpell_Delete *>, CExoArrayListCSpellDeletePtr, CExoArrayListCSpellDeletePtrArray)
DefineArray(CExoArrayList<ScriptParam>, CExoArrayListScriptParam, CExoArrayListScriptParamArray)
DefineArray(CExoArrayList<uint32_t>, CExoArrayListUInt32, CExoArrayListUInt32Array)
DefineArray(CExoString, CExoString, CExoStringArray);
DefineArray(CItemRepository*, CItemRepository, CItemRepositoryPtrArray);
DefineArray(CNWActionNode, CNWActionNode, CNWActionNodeArray);
DefineArray(CNWSCombatAttackData, CNWSCombatAttackData, CNWSCombatAttackDataArray);
DefineArray(CNWSCreatureStats_ClassInfo, CNWSCreatureStats_ClassInfo, CNWSCreatureStats_ClassInfoArray);
DefineArray(CNWTileSet*, CNWTileSet, CNWTileSetPtrArray);
DefineArray(CScriptCompilerIncludeFileStackEntry, CScriptCompilerIncludeFileStackEntry, CScriptCompilerIncludeFileStackEntryArray);
DefineArray(CScriptParseTreeNode, CScriptParseTreeNode, CScriptParseTreeNodeArray);
DefineArray(CServerAIList, CServerAIList, CServerAIListArray);
DefineArray(CServerOptionLookup, CServerOptionLookup, CServerOptionLookupArray);
DefineArray(CTlkFile*, CTlkFile, CTlkFilePtrArray);
DefineArray(CVirtualMachineScript, CVirtualMachineScript, CVirtualMachineScriptArray);
DefineArray(Vector, Vector, VectorArray);

DefineArrayPtr(CNWSTile, CNWSTile, CNWSTileArray);
DefineArrayPtr(CNWSQuickbarButton, CNWSQuickbarButton, CNWSQuickbarButtonArray);
DefineArrayPtr(CTlkTableToken, CTlkTableToken, CTlkTableTokenArray);
DefineArrayPtr(CTlkTableTokenCustom, CTlkTableTokenCustom, CTlkTableTokenCustomArray);
DefineArrayPtr(CNWSDialogEntry, CNWSDialogEntry, CNWSDialogEntryArray);
DefineArrayPtr(CNWSDialogReply, CNWSDialogReply, CNWSDialogReplyArray);
DefineArrayPtr(CNWSDialogLinkEntry, CNWSDialogLinkEntry, CNWSDialogLinkEntryArray);
DefineArrayPtr(CNWSDialogLinkReply, CNWSDialogLinkReply, CNWSDialogLinkReplyArray);
DefineArrayPtr(CNWRace, CNWRace, CNWRaceArray);
DefineArrayPtr(CNWFeat, CNWFeat, CNWFeatArray);
DefineArrayPtr(CResRef, CResRef, CResRefArray);
DefineArrayPtr(CNWClass, CNWClass, CNWClassArray);
DefineArrayPtr(CNWSkill, CNWSkill, CNWSkillArray);
DefineArrayPtr(CNWDomain, CNWDomain, CNWDomainArray);
DefineArrayPtr(CEncounterListEntry, CEncounterListEntry, CEncounterListEntryArray);
DefineArrayPtr(CEncounterSpawnPoint, CEncounterSpawnPoint, CEncounterSpawnPointArray);
DefineArrayPtr(CNWClass_Feat, CNWClass_Feat, CNWClass_FeatArray);
DefineArrayPtr(CNWClass_Skill, CNWClass_Skill, CNWClass_SkillArray);

// Std templates
%template(VectorNWSyncAdvertisementManifest) std::vector<NWSync::AdvertisementManifest>;
%template(VectorCExoString) std::vector<CExoString>;
%template(VectorNWSQLiteMigrationsDefinitionMigrationDef) std::vector<NWSQLite::Migrations::Definition::MigrationDef>;
%template(UnorderedMapCExoStringCNWSScriptVar) std::unordered_map<CExoString, CNWSScriptVar>;
%template(UnorderedMapUInt32CExoString) std::unordered_map<unsigned int, CExoString>;
%template(UnorderedMapUInt32STR_RES) std::unordered_map<unsigned int, STR_RES>;
%template(UnorderedMapStringCachedRulesetEntry) std::unordered_map<std::string, CachedRulesetEntry>;
%template(UnorderedMapInt32CNWSAreaGrassOverride) std::unordered_map<int, CNWSAreaGrassOverride>;
%template(UnorderedMapUInt64CachedRulesetEntry) std::unordered_map<unsigned long long, CachedRulesetEntry>;

// Destructors
SWIG_DOTNET_DESTRUCTORS(CExoString)
SWIG_DOTNET_DESTRUCTORS(C2DA)
SWIG_DOTNET_DESTRUCTORS(CAppManager)
SWIG_DOTNET_DESTRUCTORS(SharedPtrEngineStructure)
SWIG_DOTNET_DESTRUCTORS(CassowarySolverEngineStructure)
SWIG_DOTNET_DESTRUCTORS(CCombatInformation)
SWIG_DOTNET_DESTRUCTORS(CERFFile)
SWIG_DOTNET_DESTRUCTORS(CERFKey)
SWIG_DOTNET_DESTRUCTORS(CERFRes)
SWIG_DOTNET_DESTRUCTORS(CERFString)
SWIG_DOTNET_DESTRUCTORS(CExoAliasList)
SWIG_DOTNET_DESTRUCTORS(CExoArrayList)
SWIG_DOTNET_DESTRUCTORS(CExoBase)
SWIG_DOTNET_DESTRUCTORS(CExoBaseInternal)
SWIG_DOTNET_DESTRUCTORS(CExoCriticalSection)
SWIG_DOTNET_DESTRUCTORS(CExoDebug)
SWIG_DOTNET_DESTRUCTORS(CExoDebugInternal)
SWIG_DOTNET_DESTRUCTORS(CExoEncapsulatedFile)
SWIG_DOTNET_DESTRUCTORS(CExoFile)
SWIG_DOTNET_DESTRUCTORS(CExoIni)
SWIG_DOTNET_DESTRUCTORS(CExoIniInternal)
SWIG_DOTNET_DESTRUCTORS(CExoKeyTable)
SWIG_DOTNET_DESTRUCTORS(CExoLinkedList)
SWIG_DOTNET_DESTRUCTORS(CExoLinkedListInternal)
SWIG_DOTNET_DESTRUCTORS(CExoLocString)
SWIG_DOTNET_DESTRUCTORS(CExoLocStringInternal)
SWIG_DOTNET_DESTRUCTORS(CExoPackedFile)
SWIG_DOTNET_DESTRUCTORS(CExoRand)
SWIG_DOTNET_DESTRUCTORS(CExoRandInternal)
SWIG_DOTNET_DESTRUCTORS(CExoResFile)
SWIG_DOTNET_DESTRUCTORS(CExoResMan)
SWIG_DOTNET_DESTRUCTORS(CExoResourceImageFile)
SWIG_DOTNET_DESTRUCTORS(CExoString)
SWIG_DOTNET_DESTRUCTORS(CExoStringList)
SWIG_DOTNET_DESTRUCTORS(CExoTimers)
SWIG_DOTNET_DESTRUCTORS(CExoTimersInternal)
SWIG_DOTNET_DESTRUCTORS(CFactionManager)
SWIG_DOTNET_DESTRUCTORS(CGameEffect)
SWIG_DOTNET_DESTRUCTORS(CGameEffectApplierRemover)
SWIG_DOTNET_DESTRUCTORS(CGameObject)
SWIG_DOTNET_DESTRUCTORS(CGameObjectArray)
SWIG_DOTNET_DESTRUCTORS(CItemPropertyApplierRemover)
SWIG_DOTNET_DESTRUCTORS(CItemRepository)
SWIG_DOTNET_DESTRUCTORS(CLastUpdateObject)
SWIG_DOTNET_DESTRUCTORS(CNetLayer)
SWIG_DOTNET_DESTRUCTORS(CNetLayerSessionInfo)
SWIG_DOTNET_DESTRUCTORS(CNetLayerWindow)
SWIG_DOTNET_DESTRUCTORS(CNWArea)
SWIG_DOTNET_DESTRUCTORS(CNWBaseItem)
SWIG_DOTNET_DESTRUCTORS(CNWBaseItemArray)
SWIG_DOTNET_DESTRUCTORS(CNWCCMessageData)
SWIG_DOTNET_DESTRUCTORS(CNWClass)
SWIG_DOTNET_DESTRUCTORS(CNWCreatureStatsUpdate)
SWIG_DOTNET_DESTRUCTORS(CNWDomain)
SWIG_DOTNET_DESTRUCTORS(CNWDoorSurfaceMesh)
SWIG_DOTNET_DESTRUCTORS(CNWFeat)
SWIG_DOTNET_DESTRUCTORS(CNWItem)
SWIG_DOTNET_DESTRUCTORS(CNWLevelStats)
SWIG_DOTNET_DESTRUCTORS(CNWMessage)
SWIG_DOTNET_DESTRUCTORS(CNWNameGen)
SWIG_DOTNET_DESTRUCTORS(CNWPlaceableSurfaceMesh)
SWIG_DOTNET_DESTRUCTORS(CNWPlaceMeshManager)
SWIG_DOTNET_DESTRUCTORS(CNWRace)
SWIG_DOTNET_DESTRUCTORS(CNWRules)
SWIG_DOTNET_DESTRUCTORS(CNWSAmbientSound)
SWIG_DOTNET_DESTRUCTORS(CNWSArea)
SWIG_DOTNET_DESTRUCTORS(CNWSAreaOfEffectObject)
SWIG_DOTNET_DESTRUCTORS(CNWSBarter)
SWIG_DOTNET_DESTRUCTORS(CNWSCombatAttackData)
SWIG_DOTNET_DESTRUCTORS(CNWSCombatRound)
SWIG_DOTNET_DESTRUCTORS(CNWSCombatRoundAction)
SWIG_DOTNET_DESTRUCTORS(CNWSCreature)
SWIG_DOTNET_DESTRUCTORS(CNWSCreatureStats)
SWIG_DOTNET_DESTRUCTORS(CNWSCreatureStats_ClassInfo)
SWIG_DOTNET_DESTRUCTORS(CNWSDialog)
SWIG_DOTNET_DESTRUCTORS(CNWSDoor)
SWIG_DOTNET_DESTRUCTORS(CNWSEffectListHandler)
SWIG_DOTNET_DESTRUCTORS(CNWSEncounter)
SWIG_DOTNET_DESTRUCTORS(CNWSExpression)
SWIG_DOTNET_DESTRUCTORS(CNWSExpressionList)
SWIG_DOTNET_DESTRUCTORS(CNWSExpressionNode)
SWIG_DOTNET_DESTRUCTORS(CNWSFaction)
SWIG_DOTNET_DESTRUCTORS(CNWSForcedAction)
SWIG_DOTNET_DESTRUCTORS(CNWSInventory)
SWIG_DOTNET_DESTRUCTORS(CNWSItem)
SWIG_DOTNET_DESTRUCTORS(CNWSJournal)
SWIG_DOTNET_DESTRUCTORS(CNWSkill)
SWIG_DOTNET_DESTRUCTORS(CNWSMessage)
SWIG_DOTNET_DESTRUCTORS(CNWSModule)
SWIG_DOTNET_DESTRUCTORS(CNWSObject)
SWIG_DOTNET_DESTRUCTORS(CNWSObjectActionNode)
SWIG_DOTNET_DESTRUCTORS(CNWSpell)
SWIG_DOTNET_DESTRUCTORS(CNWSpellArray)
SWIG_DOTNET_DESTRUCTORS(CNWSPlaceable)
SWIG_DOTNET_DESTRUCTORS(CNWSPlayer)
SWIG_DOTNET_DESTRUCTORS(CNWSPlayerInventoryGUI)
SWIG_DOTNET_DESTRUCTORS(CNWSPlayerLastUpdateObject)
SWIG_DOTNET_DESTRUCTORS(CNWSPlayerLUOInventory)
SWIG_DOTNET_DESTRUCTORS(CNWSPlayerTURD)
SWIG_DOTNET_DESTRUCTORS(CNWSRules)
SWIG_DOTNET_DESTRUCTORS(CNWSSoundObject)
SWIG_DOTNET_DESTRUCTORS(CNWSStore)
SWIG_DOTNET_DESTRUCTORS(CNWSTile)
SWIG_DOTNET_DESTRUCTORS(CNWSTrigger)
SWIG_DOTNET_DESTRUCTORS(CNWSUUID)
SWIG_DOTNET_DESTRUCTORS(CNWSWaypoint)
SWIG_DOTNET_DESTRUCTORS(CNWTile)
SWIG_DOTNET_DESTRUCTORS(CNWTileData)
SWIG_DOTNET_DESTRUCTORS(CNWTileSet)
SWIG_DOTNET_DESTRUCTORS(CNWTileSetManager)
SWIG_DOTNET_DESTRUCTORS(CNWTileSurfaceMesh)
SWIG_DOTNET_DESTRUCTORS(CNWVirtualMachineCommands)
SWIG_DOTNET_DESTRUCTORS(CObjectLookupTable)
SWIG_DOTNET_DESTRUCTORS(CObjectTableManager)
SWIG_DOTNET_DESTRUCTORS(CPathfindInformation)
SWIG_DOTNET_DESTRUCTORS(CRes)
SWIG_DOTNET_DESTRUCTORS(CRes2DA)
SWIG_DOTNET_DESTRUCTORS(CResDWK)
SWIG_DOTNET_DESTRUCTORS(CResGFF)
SWIG_DOTNET_DESTRUCTORS(CResHelper)
SWIG_DOTNET_DESTRUCTORS(CResLTR)
SWIG_DOTNET_DESTRUCTORS(CResNCS)
SWIG_DOTNET_DESTRUCTORS(CResNDB)
SWIG_DOTNET_DESTRUCTORS(CResNSS)
SWIG_DOTNET_DESTRUCTORS(CResPWK)
SWIG_DOTNET_DESTRUCTORS(CResSET)
SWIG_DOTNET_DESTRUCTORS(CResStruct)
SWIG_DOTNET_DESTRUCTORS(CResTLK)
SWIG_DOTNET_DESTRUCTORS(CResWOK)
SWIG_DOTNET_DESTRUCTORS(CScriptCompiler)
SWIG_DOTNET_DESTRUCTORS(CScriptCompilerIdListEntry)
SWIG_DOTNET_DESTRUCTORS(CScriptEvent)
SWIG_DOTNET_DESTRUCTORS(CScriptTalent)
SWIG_DOTNET_DESTRUCTORS(CServerAIList)
SWIG_DOTNET_DESTRUCTORS(CServerAIMaster)
SWIG_DOTNET_DESTRUCTORS(CServerExoApp)
SWIG_DOTNET_DESTRUCTORS(CServerExoAppInternal)
SWIG_DOTNET_DESTRUCTORS(CTlkFile)
SWIG_DOTNET_DESTRUCTORS(CTlkResFile)
SWIG_DOTNET_DESTRUCTORS(CTlkTable)
SWIG_DOTNET_DESTRUCTORS(CTwoDimArrays)
SWIG_DOTNET_DESTRUCTORS(CVirtualMachine)
SWIG_DOTNET_DESTRUCTORS(CVirtualMachineCmdImplementer)
SWIG_DOTNET_DESTRUCTORS(CVirtualMachineDebuggerInstance)
SWIG_DOTNET_DESTRUCTORS(CVirtualMachineFile)
SWIG_DOTNET_DESTRUCTORS(CVirtualMachineStack)
SWIG_DOTNET_DESTRUCTORS(CWorldTimer)
