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

// Ignore ambigious types.
%ignore MIN;
%ignore MAX;
%ignore MASK;
%ignore ToString;

// Ignore multi-inheritance types.
%ignore CCallbackHandlerBase;
%ignore CNWArea;
%ignore CNWItem;

%import "API/CResHelper.hpp"
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

%rename("%(regex:/(?:NWNXLib::API::Constants)::\s*(\w+)(?:.+)$/\\1/)s", regextarget=1, fullname=1, %$isenum) "NWNXLib::API::Constants::*";

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

// Ignore APIs with no symbols.
%ignore CNWSObject::BindEventToHandler;
%ignore CAppManager::GetHostedModuleDescription;
%ignore CAppManager::GetHostedPublicInternetAddressAndPort;
%ignore CMessagePlayer::CMessagePlayer;
%ignore CMessagePlayer::~CMessagePlayer;
%ignore CMessageSysAdmin::CMessageSysAdmin;
%ignore CMessageSysAdmin::~CMessageSysAdmin;
%ignore CMessageSysAdmin::SendClientToServerMessage;
%ignore CMessageSysAdmin::SendServerToClientMessage;
%ignore CNetLayer::minPassword;
%ignore CNWSMessage::SendMessageToAllSysAdmins;
%ignore CNWSPortal::CNWSPortal;
%ignore CNWSTileSet::CNWSTileSet;
%ignore CNWTileSurfaceMesh::LocalToWorld;
%ignore CNWTileSurfaceMesh::NormalWorldToLocal;
%ignore CNWTileSurfaceMesh::NormalLocalToWorld;
%ignore CResMDL::CResMDL;
%ignore SqlQueryEngineStructure::SqlQueryEngineStructure;
%ignore CERFFile::WriteResource;
%ignore CVirtualMachine::ExecuteCode;
%ignore CVirtualMachine::InitializeScript;
%ignore CResStruct::SetIncludeWrittenStringHashTable;
%ignore CResStruct::HashSearch;
%ignore CExoEncrypt::MD5Init;
%ignore CExoEncrypt::MD5Update;
%ignore CExoEncrypt::MD5Final;
%ignore CExoEncrypt::Transform;
%ignore CExoResMan::AddManifest;
%ignore CExoResMan::RemoveManifest;
%ignore CExoString::string;
%ignore CExoString::Format;
%ignore CGameEffect::CopyLinked;
%ignore CItemRepository::CheckItem;
%ignore CMessagePlayer::HandleServerToClientMessage;
%ignore CMessagePlayer::SendClientToServerMessage;
%ignore CMessagePlayer::SendServerToClientMessage;
%ignore CMessagePlayer::HandleClientToServerMessage;
%ignore CMessageSysAdmin::HandleServerToClientMessage;
%ignore CMessageSysAdmin::HandleClientToServerMessage;
%ignore CNetLayer::EnumerateSessionsLoop;
%ignore CNetLayer::SetEnumerateSpecificOverRelay;
%ignore CNetLayer::SetNWSyncData;
%ignore CNWClass::GetAttacksPerRound;
%ignore CNWSCreature::AddDoorActions;
%ignore CNWSCreature::AddDoorActions;
%ignore CNWSCreature::ComputeDriveDestination;
%ignore CNWSCreature::GetPVPPlayerLikesMe;
%ignore CNWSCreatureStats::MemorizeAllNPCSpells;
%ignore CNWSCreatureStats_ClassInfo::MemorizeAllNPCSpells;
%ignore CNWSEffectListHandler::OnRemoveCutsceneImmobile;
%ignore CNWSEffectListHandler::OnRemoveDefensiveStance;
%ignore CNWSMessage::UpdateLastUpdateRepository;
%ignore CNWSMessage::UpdateLastUpdate_GuiFeats;
%ignore CNWSModule::PackPlayerCharacterListIntoMessage;
%ignore CNWSPlayerTURD::CopyActionQueue;
%ignore CNWSPortal::Load;
%ignore CNWSPortal::Save;
%ignore CNWSPortal::AddToArea;
%ignore CNWSPortal::RemoveFromArea;
%ignore CNWSPortal::PackIntoMessage;
%ignore CNWSScriptVar;
%ignore CNWSScriptVarTable;
%ignore CNWSTileSet::GetTileData;
%ignore CNWSTileSet::LoadTileSet;
%ignore CNWSTileSet::UnloadTileSet;
%ignore CNWSTileSet::ParseLine;
%ignore CNWSTileSet::SetTileValue;
%ignore CNWTileSurfaceMesh::Initialize;
%ignore CNWTileSurfaceMesh::IntersectCircle2d;
%ignore CNWVirtualMachineCommands::ExecuteCommandDeleteMe;
%ignore CNWVirtualMachineCommands::ExecuteCommandEventOnPerception;
%ignore CNWVirtualMachineCommands::ExecuteCommandGetLastPCToCancelCutscene;
%ignore CNWVirtualMachineCommands::ExecuteCommandIsClass;
%ignore CNWVirtualMachineCommands::ExecuteCommandPlayVisualAreaEffect;
%ignore CNWVirtualMachineCommands::ExecuteCommandSetFaction;
%ignore CResMDL::GetMDLDataPtr;
%ignore CResMDL::GetMDLSize;
%ignore CResMDL::IsLoaded;
%ignore CServerExoApp::GetIniFileName;
%ignore CServerExoApp::LoadAliases;
%ignore CTlkTable::CloseFile;
%ignore CVirtualMachine::ExecuteInstructions;
%ignore CVirtualMachineDebuggerInstance::GenerateWatchWindowView;
%ignore SqlQueryEngineStructure::GetId;

%include "NWNXLib.i"