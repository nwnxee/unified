%module NWNXLib

%include <stdint.i>
%include <swiginterface.i>

#pragma SWIG nowarn=317
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNX_SWIG_PARSING

// Mark module class as static
%pragma(csharp) moduleclassmodifiers="public static unsafe class"
%pragma(csharp) imclassclassmodifiers="public unsafe class"
%typemap(csclassmodifiers) SWIGTYPE "public unsafe class"

#undef SWIG_CSBODY_PROXY
%define SWIG_CSBODY_PROXY(PTRCTOR_VISIBILITY, CPTR_VISIBILITY, TYPE...)
// Proxy classes (base classes, ie, not derived classes)
%typemap(csbody) TYPE %{
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  PTRCTOR_VISIBILITY $csclassname(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  PTRCTOR_VISIBILITY $csclassname(void* cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, (global::System.IntPtr)cPtr);
  }

  CPTR_VISIBILITY static global::System.Runtime.InteropServices.HandleRef getCPtr($csclassname obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }
%}

// Derived proxy classes
%typemap(csbody_derived) TYPE %{
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  PTRCTOR_VISIBILITY $csclassname(global::System.IntPtr cPtr, bool cMemoryOwn) : base($imclassname.$csclazznameSWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  PTRCTOR_VISIBILITY $csclassname(void* cPtr, bool cMemoryOwn) : base($imclassname.$csclazznameSWIGUpcast((global::System.IntPtr)cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, (global::System.IntPtr)cPtr);
  }

  CPTR_VISIBILITY static global::System.Runtime.InteropServices.HandleRef getCPtr($csclassname obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }
%}
%enddef

// Extensions
%typemap(cscode) SWIGTYPE, SWIGTYPE *, SWIGTYPE &, SWIGTYPE [], SWIGTYPE (CLASS::*) %{
  public System.IntPtr Pointer {
    get {
      return swigCPtr.Handle;
    }
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
%}

%typemap(cscode) CExoString %{
  public System.IntPtr Pointer {
    get {
      return swigCPtr.Handle;
    }
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
    return swigCPtr.GetHashCode();
  }

  public static bool operator ==($csclassname left, $csclassname right) {
    return Equals(left, right);
  }

  public static bool operator !=($csclassname left, $csclassname right) {
    return !Equals(left, right);
  }

  public override string ToString() {
    return CStr();
  }
%}

// Expose Managed Constructor
SWIG_CSBODY_PROXY(public, internal, SWIGTYPE)

// Typemap void* to IntPtr
%define MarshalType(CTYPE, CSTYPE)
%typemap(ctype)  CTYPE*,CTYPE&,CTYPE[ANY] "CTYPE*"
%typemap(imtype) CTYPE*,CTYPE& "global::System.IntPtr"
%typemap(imtype, inattributes="[global::System.Runtime.InteropServices.In, global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.LPArray)]") CTYPE[ANY] "CSTYPE[]"
%typemap(cstype) CTYPE*,CTYPE& "CSTYPE*"
%typemap(cstype) CTYPE[ANY] "CSTYPE[]"
%typemap(csin)   CTYPE*,CTYPE& "(global::System.IntPtr)$csinput"
%typemap(csin)   CTYPE[ANY] "$csinput"
%typemap(in)     CTYPE*,CTYPE&,CTYPE[ANY] %{ $1 = $input; %}
%typemap(out)    CTYPE*,CTYPE& %{ $result = $1; %}

%typemap(csout, excode=SWIGEXCODE) CTYPE*,CTYPE& { 
    System.IntPtr retVal = $imcall;$excode
    return (CSTYPE*)retVal;
  }
%typemap(csvarout, excode=SWIGEXCODE2) CTYPE*,CTYPE& %{ 
    get {
        System.IntPtr retVal = $imcall;$excode 
        return (CSTYPE*)retVal; 
    }
%}
%typemap(csout, excode=SWIGEXCODE) CTYPE[ANY] { 
    CSTYPE[] retVal = $imcall;$excode
    return retVal;
  }
%typemap(csvarout, excode=SWIGEXCODE2) CTYPE[ANY] %{ 
    get {
        CSTYPE[] retVal = $imcall;$excode
        return retVal;
    }
%}
%enddef

MarshalType(void, void)
MarshalType(void*, void*) // void**
MarshalType(signed char, sbyte)
MarshalType(char*, char*) // char**
MarshalType(short int, short)
MarshalType(int, int)
MarshalType(int*, int*) // int**
MarshalType(float, float)
MarshalType(float*, float*) //float**
MarshalType(float**, float**) //float***
MarshalType(long, long)
MarshalType(unsigned char, byte)
MarshalType(unsigned char*, byte*) //unsigned char**
MarshalType(unsigned short int, ushort)
MarshalType(unsigned int, uint)
MarshalType(unsigned int*, uint*) //unsigned int**
MarshalType(unsigned long, ulong)

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

// Add function defines to subclass in module.
%pragma(csharp) modulecode="public static class Functions {\n"
%include "Functions.hpp"
%include "FunctionsLinux.hpp"
%pragma(csharp) modulecode="}\n"

%include "NWNXLib.i"
