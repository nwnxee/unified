%module NWNXLib

%include <stdint.i>
%include <std_string.i>
%include <std_vector.i>
%include <swiginterface.i>

%include "std_unordered_map.i"

#pragma SWIG nowarn=317
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNX_SWIG_PARSING

// Mark module class as static
%pragma(csharp) moduleclassmodifiers="public static unsafe class"
%pragma(csharp) imclassclassmodifiers="public unsafe class"
%typemap(csclassmodifiers) SWIGTYPE "public unsafe class"

namespace std {
%typemap(imtype, inattributes="[global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NativeStringMarshaler))]", outattributes="[return: global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NativeStringMarshaler))]") string "string"
%typemap(imtype, inattributes="[global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NativeStringMarshaler))]", outattributes="[return: global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(NativeStringMarshaler))]") const string & "string"
}

// C# Wrapper Class Extensions
%define SWIG_DOTNET_EXTENSIONS

  public global::System.IntPtr Pointer {
    get {
      return swigCPtr.Handle;
    }
  }

  public static unsafe implicit operator void*($csclassname self) {
    return (void*)self.swigCPtr.Handle;
  }

  public static unsafe $csclassname FromPointer(void* pointer, bool memoryOwn = false) {
    return pointer != null ? new $csclassname((global::System.IntPtr)pointer, memoryOwn) : null;
  }

  public static $csclassname FromPointer(global::System.IntPtr pointer, bool memoryOwn = false) {
    return pointer != global::System.IntPtr.Zero ? new $csclassname(pointer, memoryOwn) : null;
  }

  public bool Equals($csclassname other) {
    if (ReferenceEquals(null, other)) {
      return false;
    }

    if (ReferenceEquals(this, other)) {
      return true;
    }

    return Pointer.Equals(other.Pointer);
  }

  public override bool Equals(object obj) {
    return ReferenceEquals(this, obj) || obj is $csclassname other && Equals(other);
  }

  public override int GetHashCode() {
    return swigCPtr.Handle.GetHashCode();
  }

  public static bool operator ==($csclassname left, $csclassname right) {
    return Equals(left, right);
  }

  public static bool operator !=($csclassname left, $csclassname right) {
    return !Equals(left, right);
  }
%enddef

// C# Wrapper Class Extensions - Default
%typemap(cscode, noblock=1) SWIGTYPE, SWIGTYPE *, SWIGTYPE &, SWIGTYPE (CLASS::*) {
SWIG_DOTNET_EXTENSIONS
}

// C# Wrapper Class Extensions - CExoString
%typemap(cscode, noblock=1) CExoString {
SWIG_DOTNET_EXTENSIONS

  public CExoString(string source) : this(source.GetNullTerminatedString()) {
  }

  /// <summary>
  /// Converts this CExoString to a C# string.
  /// </summary>
  /// <returns>The equivalent C# string for this CExoString.</returns>
  public override string ToString() {
    return StringHelper.ReadNullTerminatedString(CStr());
  }
}

// C# Wrapper Class Extensions - CResRef
%typemap(cscode, noblock=1) CResRef {
SWIG_DOTNET_EXTENSIONS

  public CResRef(string source) : this(source.GetNullTerminatedString()) {
  }

  /// <summary>
  /// Gets a C# string representing this ResRef (GetResRefStr())
  /// </summary>
  /// <returns>A C# string representing this ResRef.</returns>
  public override string ToString() {
    return StringHelper.ReadNullTerminatedString(GetResRefStr());
  }
}

// Marshal Blittable types without wrapper class.
%define MarshalType(CTYPE, CSTYPE, CSARRAYTYPE)
%typemap(ctype)  CTYPE*,CTYPE&,CTYPE[ANY] "CTYPE*"
%typemap(imtype) CTYPE*,CTYPE&,CTYPE[ANY] "global::System.IntPtr"
%typemap(cstype) CTYPE*,CTYPE& "CSTYPE*"
%typemap(cstype) CTYPE[ANY] "NativeArray<CSARRAYTYPE>"
%typemap(csin)   CTYPE*,CTYPE& "(global::System.IntPtr)$csinput"
%typemap(csin)   CTYPE[ANY] "$csinput"
%typemap(in)     CTYPE*,CTYPE&,CTYPE[ANY] %{ $1 = $input; %}
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

%typemap(csout, excode=SWIGEXCODE) CTYPE[ANY] {
    global::System.IntPtr arrayPtr = $imcall;$excode
    NativeArray<CSARRAYTYPE> retVal = new NativeArray<CSARRAYTYPE>(arrayPtr, $1_dim0);

    return retVal; // CSTYPE[$1_dim0]
  }

%typemap(csvarout, excode=SWIGEXCODE2) CTYPE[ANY] %{
    get {
      global::System.IntPtr arrayPtr = $imcall;$excode
      NativeArray<CSARRAYTYPE> retVal = new NativeArray<CSARRAYTYPE>(arrayPtr, $1_dim0);

      return retVal; // CSTYPE[$1_dim0]
    }
%}
%enddef

// Marshal pointer to pointer as void* for easier dereferencing
%define MarshalPtrPtr(CTYPE, CSTYPE)
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

// C# code for accessing native arrays
%define MapArray(TYPE, CSTYPE, NAME)
%typemap(cstype) TYPE[ANY] "NAME"
%typemap(csin)   TYPE[ANY] "NAME.getCPtr($csinput)"
%typemap(csout, excode=SWIGEXCODE) TYPE[ANY] {
    global::System.IntPtr cPtr = $imcall;$excode;
    NAME ret = (cPtr == global::System.IntPtr.Zero) ? null : new NAME(cPtr, false);
    return ret;
  }

%typemap(csvarout, excode=SWIGEXCODE2) TYPE[ANY] %{
    get {
        global::System.IntPtr cPtr = $imcall;$excode;
        NAME ret = (cPtr == global::System.IntPtr.Zero) ? null : new NAME(cPtr, false);
        return ret;
    }
%}

%typemap(cscode, noblock=1) NAME {
SWIG_DOTNET_EXTENSIONS

  public CSTYPE this[int index] {
    get {
      return GetItem(index);
    }
    set {
      SetItem(index, value);
    }
  }
}
%enddef

// Native array definition for a C-style array define.
%define DefineArray(TYPE, CSTYPE, NAME)
%{
typedef TYPE NAME;
%}
typedef struct {} NAME;

%extend NAME {
NAME(int nElements) {
  return new TYPE[nElements]();
}

~NAME() {
  delete [] self;
}

TYPE GetItem(int index) {
  return self[index];
}

void SetItem(int index, TYPE value) {
  self[index] = value;
}

static NAME* FromPointer(TYPE *ptr) {
  return (NAME *) ptr;
}

};
%enddef

// Native array definition for an array defined as a pointer, with a separate length variable.
%define DefineArrayPtr(TYPE, CSTYPE, NAME)
%{
typedef TYPE NAME;
%}
typedef struct {} NAME;

%extend NAME {
NAME(int nElements) {
  return new TYPE[nElements]();
}

~NAME() {
  delete [] self;
}

TYPE* GetItem(int index) {
  return &self[index];
}

void SetItem(int index, TYPE* value) {
  self[index] = *value;
}

static NAME* FromPointer(TYPE *ptr) {
  return static_cast<NAME*>(ptr);
}

};
%enddef

// Marshal native types to managed types.
MarshalType(void, void, global::System.IntPtr)
MarshalType(void*, void*, global::System.IntPtr) // void**
MarshalType(signed char, sbyte, sbyte)
MarshalType(char*, char*, global::System.IntPtr) // char**
MarshalType(short int, short, short)
MarshalType(int, int, int)
MarshalType(int*, int*, global::System.IntPtr) // int**
MarshalType(float, float, float)
MarshalType(float*, float*, global::System.IntPtr) //float**
MarshalType(float**, float**, global::System.IntPtr) //float***
MarshalType(long, long, long)
MarshalType(char, byte, byte)
MarshalType(char*, byte*, global::System.IntPtr) // char**
MarshalType(unsigned char, byte, byte)
MarshalType(unsigned char*, byte*, global::System.IntPtr) //unsigned char**
MarshalType(unsigned short int, ushort, ushort)
MarshalType(unsigned int, uint, uint)
MarshalType(unsigned int*, uint*, global::System.IntPtr) //unsigned int**
MarshalType(unsigned long, ulong, ulong)

// Marshal pointer to pointer types.
MarshalPtrPtr(C2DA*, void*)
MarshalPtrPtr(CAppManager*, void*)
MarshalPtrPtr(CCombatInformationNode*, void*)
MarshalPtrPtr(CEffectIconObject*, void*)
MarshalPtrPtr(CExoBase*, void*)
MarshalPtrPtr(CExoResMan*, void*)
MarshalPtrPtr(CExoKeyTable*, void*)
MarshalPtrPtr(CExoLinkedListNode*, void*)
MarshalPtrPtr(CExoPackedFile*, void*)
MarshalPtrPtr(CExoString*, void*)
MarshalPtrPtr(CFeatUseListEntry*, void*)
MarshalPtrPtr(CGameEffect*, void*)
MarshalPtrPtr(CGameObject*, void*)
MarshalPtrPtr(CGameObjectArrayNode*, void*)
MarshalPtrPtr(CItemRepository*, global::System.IntPtr)
MarshalPtrPtr(CKeyTableEntry*, void*)
MarshalPtrPtr(CLastUpdateObject*, void*)
MarshalPtrPtr(CLastUpdatePartyObject*, void*)
MarshalPtrPtr(CLoopingVisualEffect*, void*)
MarshalPtrPtr(CNWCCMessageData*, void*)
MarshalPtrPtr(CNWItemProperty*, void*)
MarshalPtrPtr(CNWLevelStats*, void*)
MarshalPtrPtr(CNWPlaceableSurfaceMesh*, void*)
MarshalPtrPtr(CNWRules*, void*)
MarshalPtrPtr(CNWSAreaGridSuccessors*, void*)
MarshalPtrPtr(CNWSExpression*, void*)
MarshalPtrPtr(CNWSFaction*, void*)
MarshalPtrPtr(CNWSItem*, void*)
MarshalPtrPtr(CNWSObjectActionNode*, void*)
MarshalPtrPtr(CNWSSpellScriptData*, void*)
MarshalPtrPtr(CNWSStats_Spell*, void*)
MarshalPtrPtr(CNWTileSet*, void*)
MarshalPtrPtr(CNWVisibilityNode*, void*)
MarshalPtrPtr(CObjectLookupTable*, void*)
MarshalPtrPtr(CPathfindInfoIntraTileSuccessors*, void*)
MarshalPtrPtr(CScriptCompiler*, void*)
MarshalPtrPtr(CScriptLog*, void*)
MarshalPtrPtr(CScriptParseTreeNode*, void*)
MarshalPtrPtr(CSpell_Add*, void*)
MarshalPtrPtr(CSpell_Delete*, void*)
MarshalPtrPtr(CStoreCustomer*, void*)
MarshalPtrPtr(CTlkFile*, void*)
MarshalPtrPtr(CTlkTable*, void*)
MarshalPtrPtr(CVirtualMachine*, void*)
MarshalPtrPtr(CVirtualMachineScript*, void*)
MarshalPtrPtr(ENCAPSULATED_KEYLISTENTRY*, void*)
MarshalPtrPtr(NWPlayerCharacterList_st*, void*)
MarshalPtrPtr(SSubNetProfile*, void*)
MarshalPtrPtr(Task::CExoTaskManager*, void*)

// Rename constants to unique classes.
%rename("%(regex:/(?:NWNXLib::API::Constants)::\s*(\w+)(?:.+)$/\\1/)s", regextarget=1, fullname=1, %$isenum) "NWNXLib::API::Constants::*";

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

// Ignore ambigious types.
%ignore MIN;
%ignore MAX;
%ignore MASK;
%ignore ToString;
%ignore NWSync::CNWSync;
%ignore NWN_CLASS_EXTENSION_CGameObject;

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

// Ignore template methods with missing type implementations.
%ignore CExoArrayList::DerefContains;
%ignore CExoArrayList::IndexOf;
%ignore CExoArrayList::Contains;
%ignore CExoArrayList::AddUnique;
%ignore CExoArrayList::Remove;
%ignore CExoArrayList::begin() const;
%ignore CExoArrayList::end() const;

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
MapArray(CObjectLookupTable*, CObjectLookupTable, CObjectLookupTablePtrArray);
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

%include "NWNXLib.i"

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
DefineArray(CObjectLookupTable*, CObjectLookupTable, CObjectLookupTablePtrArray);
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

// Std templates
%template(VectorNWSyncAdvertisementManifest) std::vector<NWSyncAdvertisementManifest>;
%template(VectorCExoString) std::vector<CExoString>;
%template(UnorderedMapCExoStringCNWSScriptVar) std::unordered_map<CExoString, CNWSScriptVar>;
%template(UnorderedMapUInt32CExoString) std::unordered_map<uint32_t, CExoString>;
%template(UnorderedMapUInt32STR_RES) std::unordered_map<uint32_t, STR_RES>;
%template(UnorderedMapStringCachedRulesetEntry) std::unordered_map<std::string, CachedRulesetEntry>;
