#include "CScriptCompiler.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoStringList.hpp"
#include "CScriptCompilerIdListEntry.hpp"
#include "CScriptCompilerIdentifierHashTableEntry.hpp"
#include "CScriptCompilerKeyWordEntry.hpp"
#include "CScriptCompilerStackEntry.hpp"
#include "CScriptCompilerStructureEntry.hpp"
#include "CScriptCompilerStructureFieldEntry.hpp"
#include "CScriptCompilerSymbolTableEntry.hpp"
#include "CScriptCompilerVarStackEntry.hpp"
#include "CScriptParseTreeNode.hpp"
#include "CScriptParseTreeNodeBlock.hpp"

namespace NWNXLib {

namespace API {

CScriptCompiler::CScriptCompiler()
{
    CScriptCompiler__CScriptCompilerCtor(this);
}

CScriptCompiler::~CScriptCompiler()
{
    CScriptCompiler__CScriptCompilerDtor(this);
}

void CScriptCompiler::AddStructureToStack(const CExoString& a0, int32_t a1)
{
    return CScriptCompiler__AddStructureToStack(this, a0, a1);
}

int32_t CScriptCompiler::AddSymbolToLabelList(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CScriptCompiler__AddSymbolToLabelList(this, a0, a1, a2, a3);
}

int32_t CScriptCompiler::AddSymbolToQueryList(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CScriptCompiler__AddSymbolToQueryList(this, a0, a1, a2, a3);
}

int32_t CScriptCompiler::AddToGlobalVariableList(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__AddToGlobalVariableList(this, a0);
}

void CScriptCompiler::AddToSymbolTableVarStack(int32_t a0, int32_t a1, int32_t a2)
{
    return CScriptCompiler__AddToSymbolTableVarStack(this, a0, a1, a2);
}

int32_t CScriptCompiler::AddUserDefinedIdentifier(CScriptParseTreeNode* a0, int32_t a1)
{
    return CScriptCompiler__AddUserDefinedIdentifier(this, a0, a1);
}

void CScriptCompiler::AddVariableToStack(int32_t a0, CExoString* a1, int32_t a2)
{
    return CScriptCompiler__AddVariableToStack(this, a0, a1, a2);
}

int32_t CScriptCompiler::CheckForBadLValue(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__CheckForBadLValue(this, a0);
}

int32_t CScriptCompiler::CleanUpAfterCompile(int32_t a0, CScriptParseTreeNode* a1)
{
    return CScriptCompiler__CleanUpAfterCompile(this, a0, a1);
}

void CScriptCompiler::CleanUpAfterCompiles()
{
    return CScriptCompiler__CleanUpAfterCompiles(this);
}

int32_t CScriptCompiler::CleanUpDuringCompile(int32_t a0)
{
    return CScriptCompiler__CleanUpDuringCompile(this, a0);
}

void CScriptCompiler::ClearAllSymbolLists()
{
    return CScriptCompiler__ClearAllSymbolLists(this);
}

void CScriptCompiler::ClearCompiledScriptCode()
{
    return CScriptCompiler__ClearCompiledScriptCode(this);
}

void CScriptCompiler::ClearSwitchLabelList()
{
    return CScriptCompiler__ClearSwitchLabelList(this);
}

void CScriptCompiler::ClearUserDefinedIdentifiers()
{
    return CScriptCompiler__ClearUserDefinedIdentifiers(this);
}

int32_t CScriptCompiler::CompileFile(const CExoString& a0)
{
    return CScriptCompiler__CompileFile(this, a0);
}

int32_t CScriptCompiler::CompileScriptChunk(const CExoString& a0)
{
    return CScriptCompiler__CompileScriptChunk(this, a0);
}

int32_t CScriptCompiler::CompileScriptConditional(const CExoString& a0)
{
    return CScriptCompiler__CompileScriptConditional(this, a0);
}

CScriptParseTreeNode* CScriptCompiler::CreateScriptParseTreeNode(int32_t a0, CScriptParseTreeNode* a1, CScriptParseTreeNode* a2)
{
    return CScriptCompiler__CreateScriptParseTreeNode(this, a0, a1, a2);
}

void CScriptCompiler::DeleteCompileStack()
{
    return CScriptCompiler__DeleteCompileStack(this);
}

void CScriptCompiler::DeleteParseTree(int32_t a0, CScriptParseTreeNode* a1)
{
    return CScriptCompiler__DeleteParseTree(this, a0, a1);
}

void CScriptCompiler::DeleteScriptParseTreeNode(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__DeleteScriptParseTreeNode(this, a0);
}

int32_t CScriptCompiler::DetermineLocationOfCode()
{
    return CScriptCompiler__DetermineLocationOfCode(this);
}

CScriptParseTreeNode* CScriptCompiler::DuplicateScriptParseTree(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__DuplicateScriptParseTree(this, a0);
}

void CScriptCompiler::EndLineNumberAtBinaryInstruction(int32_t a0, int32_t a1, int32_t a2)
{
    return CScriptCompiler__EndLineNumberAtBinaryInstruction(this, a0, a1, a2);
}

void CScriptCompiler::FinalizeFinalCode()
{
    return CScriptCompiler__FinalizeFinalCode(this);
}

int32_t CScriptCompiler::FoundReturnStatementOnAllBranches(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__FoundReturnStatementOnAllBranches(this, a0);
}

int32_t CScriptCompiler::GenerateCodeForSwitchLabels(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__GenerateCodeForSwitchLabels(this, a0);
}

CExoString CScriptCompiler::GenerateDebuggerTypeAbbreviation(int32_t a0, CExoString a1)
{
    return CScriptCompiler__GenerateDebuggerTypeAbbreviation(this, a0, a1);
}

int32_t CScriptCompiler::GenerateFinalCodeFromParseTree(CExoString a0)
{
    return CScriptCompiler__GenerateFinalCodeFromParseTree(this, a0);
}

int32_t CScriptCompiler::GenerateIdentifierList()
{
    return CScriptCompiler__GenerateIdentifierList(this);
}

int32_t CScriptCompiler::GenerateIdentifiersFromConstantVariables(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__GenerateIdentifiersFromConstantVariables(this, a0);
}

int32_t CScriptCompiler::GenerateParseTree()
{
    return CScriptCompiler__GenerateParseTree(this);
}

int32_t CScriptCompiler::GetCompiledScriptCode(char** a0, int32_t* a1)
{
    return CScriptCompiler__GetCompiledScriptCode(this, a0, a1);
}

CExoString CScriptCompiler::GetFunctionNameFromSymbolSubTypes(int32_t a0, int32_t a1)
{
    return CScriptCompiler__GetFunctionNameFromSymbolSubTypes(this, a0, a1);
}

int32_t CScriptCompiler::GetHashEntryByName(const char* a0)
{
    return CScriptCompiler__GetHashEntryByName(this, a0);
}

int32_t CScriptCompiler::GetIdentifierByName(const CExoString& a0)
{
    return CScriptCompiler__GetIdentifierByName(this, a0);
}

CScriptParseTreeNode* CScriptCompiler::GetNewScriptParseTreeNode()
{
    return CScriptCompiler__GetNewScriptParseTreeNode(this);
}

int32_t CScriptCompiler::GetStructureField(const CExoString& a0, const CExoString& a1)
{
    return CScriptCompiler__GetStructureField(this, a0, a1);
}

int32_t CScriptCompiler::GetStructureSize(const CExoString& a0)
{
    return CScriptCompiler__GetStructureSize(this, a0);
}

int32_t CScriptCompiler::HandleIdentifierToken()
{
    return CScriptCompiler__HandleIdentifierToken(this);
}

int32_t CScriptCompiler::HandleToken()
{
    return CScriptCompiler__HandleToken(this);
}

uint32_t CScriptCompiler::HashManagerAdd(uint32_t a0, uint32_t a1)
{
    return CScriptCompiler__HashManagerAdd(this, a0, a1);
}

uint32_t CScriptCompiler::HashManagerDelete(uint32_t a0, uint32_t a1)
{
    return CScriptCompiler__HashManagerDelete(this, a0, a1);
}

uint32_t CScriptCompiler::HashString(const CExoString& a0)
{
    return CScriptCompiler__HashString__0(this, a0);
}

uint32_t CScriptCompiler::HashString(const char* a0)
{
    return CScriptCompiler__HashString__1(this, a0);
}

void CScriptCompiler::Initialize()
{
    return CScriptCompiler__Initialize(this);
}

void CScriptCompiler::InitializeFinalCode()
{
    return CScriptCompiler__InitializeFinalCode(this);
}

void CScriptCompiler::InitializeIncludeFile(int32_t a0)
{
    return CScriptCompiler__InitializeIncludeFile(this, a0);
}

void CScriptCompiler::InitializePreDefinedStructures()
{
    return CScriptCompiler__InitializePreDefinedStructures(this);
}

void CScriptCompiler::InitializeSwitchLabelList()
{
    return CScriptCompiler__InitializeSwitchLabelList(this);
}

CScriptParseTreeNode* CScriptCompiler::InsertGlobalVariablesInParseTree(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__InsertGlobalVariablesInParseTree(this, a0);
}

int32_t CScriptCompiler::InstallLoader()
{
    return CScriptCompiler__InstallLoader(this);
}

int32_t CScriptCompiler::InVisitGenerateCode(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__InVisitGenerateCode(this, a0);
}

void CScriptCompiler::ModifySRStackReturnTree(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__ModifySRStackReturnTree(this, a0);
}

int32_t CScriptCompiler::OutputError(int32_t a0, CExoString* a1, int32_t a2, const CExoString& a3)
{
    return CScriptCompiler__OutputError(this, a0, a1, a2, a3);
}

int32_t CScriptCompiler::OutputIdentifierError(const CExoString& a0, int32_t a1, int32_t a2)
{
    return CScriptCompiler__OutputIdentifierError(this, a0, a1, a2);
}

int32_t CScriptCompiler::OutputWalkTreeError(int32_t a0, CScriptParseTreeNode* a1)
{
    return CScriptCompiler__OutputWalkTreeError(this, a0, a1);
}

int32_t CScriptCompiler::ParseCharacterAlphabet(int32_t a0)
{
    return CScriptCompiler__ParseCharacterAlphabet(this, a0);
}

int32_t CScriptCompiler::ParseCharacterAmpersand(int32_t a0)
{
    return CScriptCompiler__ParseCharacterAmpersand(this, a0);
}

int32_t CScriptCompiler::ParseCharacterAsterisk(int32_t a0)
{
    return CScriptCompiler__ParseCharacterAsterisk(this, a0);
}

int32_t CScriptCompiler::ParseCharacterCarat(int32_t a0)
{
    return CScriptCompiler__ParseCharacterCarat(this, a0);
}

int32_t CScriptCompiler::ParseCharacterColon()
{
    return CScriptCompiler__ParseCharacterColon(this);
}

int32_t CScriptCompiler::ParseCharacterComma()
{
    return CScriptCompiler__ParseCharacterComma(this);
}

int32_t CScriptCompiler::ParseCharacterEllipsis()
{
    return CScriptCompiler__ParseCharacterEllipsis(this);
}

int32_t CScriptCompiler::ParseCharacterEqualSign(int32_t a0)
{
    return CScriptCompiler__ParseCharacterEqualSign(this, a0);
}

int32_t CScriptCompiler::ParseCharacterExclamationPoint(int32_t a0)
{
    return CScriptCompiler__ParseCharacterExclamationPoint(this, a0);
}

int32_t CScriptCompiler::ParseCharacterHyphen(int32_t a0)
{
    return CScriptCompiler__ParseCharacterHyphen(this, a0);
}

int32_t CScriptCompiler::ParseCharacterLeftAngle(int32_t a0)
{
    return CScriptCompiler__ParseCharacterLeftAngle(this, a0);
}

int32_t CScriptCompiler::ParseCharacterLeftBrace()
{
    return CScriptCompiler__ParseCharacterLeftBrace(this);
}

int32_t CScriptCompiler::ParseCharacterLeftBracket()
{
    return CScriptCompiler__ParseCharacterLeftBracket(this);
}

int32_t CScriptCompiler::ParseCharacterLeftSquareBracket()
{
    return CScriptCompiler__ParseCharacterLeftSquareBracket(this);
}

int32_t CScriptCompiler::ParseCharacterNumeric(int32_t a0)
{
    return CScriptCompiler__ParseCharacterNumeric(this, a0);
}

int32_t CScriptCompiler::ParseCharacterPercentSign(int32_t a0)
{
    return CScriptCompiler__ParseCharacterPercentSign(this, a0);
}

int32_t CScriptCompiler::ParseCharacterPeriod()
{
    return CScriptCompiler__ParseCharacterPeriod(this);
}

int32_t CScriptCompiler::ParseCharacterPlusSign(int32_t a0)
{
    return CScriptCompiler__ParseCharacterPlusSign(this, a0);
}

int32_t CScriptCompiler::ParseCharacterQuestionMark()
{
    return CScriptCompiler__ParseCharacterQuestionMark(this);
}

int32_t CScriptCompiler::ParseCharacterQuotationMark()
{
    return CScriptCompiler__ParseCharacterQuotationMark(this);
}

int32_t CScriptCompiler::ParseCharacterRightAngle(int32_t a0)
{
    return CScriptCompiler__ParseCharacterRightAngle(this, a0);
}

int32_t CScriptCompiler::ParseCharacterRightBrace()
{
    return CScriptCompiler__ParseCharacterRightBrace(this);
}

int32_t CScriptCompiler::ParseCharacterRightBracket()
{
    return CScriptCompiler__ParseCharacterRightBracket(this);
}

int32_t CScriptCompiler::ParseCharacterRightSquareBracket()
{
    return CScriptCompiler__ParseCharacterRightSquareBracket(this);
}

int32_t CScriptCompiler::ParseCharacterSemicolon()
{
    return CScriptCompiler__ParseCharacterSemicolon(this);
}

int32_t CScriptCompiler::ParseCharacterSlash(int32_t a0)
{
    return CScriptCompiler__ParseCharacterSlash(this, a0);
}

int32_t CScriptCompiler::ParseCharacterTilde()
{
    return CScriptCompiler__ParseCharacterTilde(this);
}

int32_t CScriptCompiler::ParseCharacterVerticalBar(int32_t a0)
{
    return CScriptCompiler__ParseCharacterVerticalBar(this, a0);
}

int32_t CScriptCompiler::ParseCommentedOutCharacter(int32_t a0)
{
    return CScriptCompiler__ParseCommentedOutCharacter(this, a0);
}

float CScriptCompiler::ParseFloatFromTokenString()
{
    return CScriptCompiler__ParseFloatFromTokenString(this);
}

int32_t CScriptCompiler::ParseIdentifierFile()
{
    return CScriptCompiler__ParseIdentifierFile(this);
}

int32_t CScriptCompiler::ParseNextCharacter(int32_t a0, int32_t a1)
{
    return CScriptCompiler__ParseNextCharacter(this, a0, a1);
}

int32_t CScriptCompiler::ParseSource(char* a0, int32_t a1)
{
    return CScriptCompiler__ParseSource(this, a0, a1);
}

int32_t CScriptCompiler::ParseStringCharacter(int32_t a0, int32_t a1)
{
    return CScriptCompiler__ParseStringCharacter(this, a0, a1);
}

int32_t CScriptCompiler::PopSRStack(int32_t* a0, int32_t* a1, int32_t* a2, CScriptParseTreeNode** a3, CScriptParseTreeNode** a4)
{
    return CScriptCompiler__PopSRStack(this, a0, a1, a2, a3, a4);
}

int32_t CScriptCompiler::PostVisitGenerateCode(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__PostVisitGenerateCode(this, a0);
}

int32_t CScriptCompiler::PreVisitGenerateCode(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__PreVisitGenerateCode(this, a0);
}

void CScriptCompiler::PrintBinaryAddress()
{
    return CScriptCompiler__PrintBinaryAddress(this);
}

int32_t CScriptCompiler::PrintParseIdentifierFileError(int32_t a0)
{
    return CScriptCompiler__PrintParseIdentifierFileError(this, a0);
}

int32_t CScriptCompiler::PrintParseSourceError(int32_t a0)
{
    return CScriptCompiler__PrintParseSourceError(this, a0);
}

void CScriptCompiler::PushSRStack(int32_t a0, int32_t a1, int32_t a2, CScriptParseTreeNode* a3)
{
    return CScriptCompiler__PushSRStack(this, a0, a1, a2, a3);
}

void CScriptCompiler::RemoveFromSymbolTableVarStack(int32_t a0, int32_t a1, int32_t a2)
{
    return CScriptCompiler__RemoveFromSymbolTableVarStack(this, a0, a1, a2);
}

void CScriptCompiler::ResolveDebuggingInformation()
{
    return CScriptCompiler__ResolveDebuggingInformation(this);
}

void CScriptCompiler::ResolveDebuggingInformationForIdentifier(int32_t a0)
{
    return CScriptCompiler__ResolveDebuggingInformationForIdentifier(this, a0);
}

int32_t CScriptCompiler::ResolveLabels()
{
    return CScriptCompiler__ResolveLabels(this);
}

void CScriptCompiler::SetAutomaticCleanUpAfterCompiles(int32_t a0)
{
    return CScriptCompiler__SetAutomaticCleanUpAfterCompiles(this, a0);
}

void CScriptCompiler::SetCompileConditionalFile(int32_t a0)
{
    return CScriptCompiler__SetCompileConditionalFile(this, a0);
}

void CScriptCompiler::SetCompileConditionalOrMain(int32_t a0)
{
    return CScriptCompiler__SetCompileConditionalOrMain(this, a0);
}

void CScriptCompiler::SetCompileDebugLevel(int32_t a0)
{
    return CScriptCompiler__SetCompileDebugLevel(this, a0);
}

void CScriptCompiler::SetCompileSymbolicOutput(int32_t a0)
{
    return CScriptCompiler__SetCompileSymbolicOutput(this, a0);
}

void CScriptCompiler::SetGenerateDebuggerOutput(int32_t a0)
{
    return CScriptCompiler__SetGenerateDebuggerOutput(this, a0);
}

void CScriptCompiler::SetIdentifierSpecification(const CExoString& a0)
{
    return CScriptCompiler__SetIdentifierSpecification(this, a0);
}

void CScriptCompiler::SetOptimizeBinaryCodeLength(int32_t a0)
{
    return CScriptCompiler__SetOptimizeBinaryCodeLength(this, a0);
}

void CScriptCompiler::SetOutputAlias(const CExoString& a0)
{
    return CScriptCompiler__SetOutputAlias(this, a0);
}

void CScriptCompiler::ShutDown()
{
    return CScriptCompiler__ShutDown(this);
}

void CScriptCompiler::ShutdownIncludeFile(int32_t a0)
{
    return CScriptCompiler__ShutdownIncludeFile(this, a0);
}

void CScriptCompiler::StartLineNumberAtBinaryInstruction(int32_t a0, int32_t a1, int32_t a2)
{
    return CScriptCompiler__StartLineNumberAtBinaryInstruction(this, a0, a1, a2);
}

int32_t CScriptCompiler::Test_CompareDirectoryContents(CExoString& a0, CExoString& a1)
{
    return CScriptCompiler__Test_CompareDirectoryContents(this, a0, a1);
}

int32_t CScriptCompiler::Test_CompareFileInclusion(CExoString& a0, CExoString& a1, CExoStringList* a2, uint16_t a3)
{
    return CScriptCompiler__Test_CompareFileInclusion(this, a0, a1, a2, a3);
}

void CScriptCompiler::Test_CompileAllScriptsInDirectory(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CScriptCompiler__Test_CompileAllScriptsInDirectory(this, a0, a1, a2);
}

int32_t CScriptCompiler::TestIdentifierToken()
{
    return CScriptCompiler__TestIdentifierToken(this);
}

void CScriptCompiler::TokenInitialize()
{
    return CScriptCompiler__TokenInitialize(this);
}

int32_t CScriptCompiler::TraverseTreeForSwitchLabels(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__TraverseTreeForSwitchLabels(this, a0);
}

int32_t CScriptCompiler::ValidateLocationOfIdentifier(const CExoString& a0)
{
    return CScriptCompiler__ValidateLocationOfIdentifier(this, a0);
}

int32_t CScriptCompiler::WalkParseTree(CScriptParseTreeNode* a0)
{
    return CScriptCompiler__WalkParseTree(this, a0);
}

int32_t CScriptCompiler::WriteDebuggerOutputToFile(CExoString a0)
{
    return CScriptCompiler__WriteDebuggerOutputToFile(this, a0);
}

int32_t CScriptCompiler::WriteFinalCodeToFile(const CExoString& a0)
{
    return CScriptCompiler__WriteFinalCodeToFile(this, a0);
}

int32_t CScriptCompiler::WriteResolvedOutput()
{
    return CScriptCompiler__WriteResolvedOutput(this);
}

void CScriptCompiler__CScriptCompilerCtor(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CScriptCompilerCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptCompiler__CScriptCompilerDtor(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CScriptCompilerDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CScriptCompiler__AddStructureToStack(CScriptCompiler* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddStructureToStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__AddSymbolToLabelList(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddSymbolToLabelList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CScriptCompiler__AddSymbolToQueryList(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddSymbolToQueryList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CScriptCompiler__AddToGlobalVariableList(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddToGlobalVariableList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__AddToSymbolTableVarStack(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddToSymbolTableVarStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CScriptCompiler__AddUserDefinedIdentifier(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddUserDefinedIdentifier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptCompiler__AddVariableToStack(CScriptCompiler* thisPtr, int32_t a0, CExoString* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__AddVariableToStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CScriptCompiler__CheckForBadLValue(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CheckForBadLValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__CleanUpAfterCompile(CScriptCompiler* thisPtr, int32_t a0, CScriptParseTreeNode* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CleanUpAfterCompile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptCompiler__CleanUpAfterCompiles(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CleanUpAfterCompiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__CleanUpDuringCompile(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CleanUpDuringCompile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__ClearAllSymbolLists(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ClearAllSymbolLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__ClearCompiledScriptCode(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ClearCompiledScriptCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__ClearSwitchLabelList(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ClearSwitchLabelList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__ClearUserDefinedIdentifiers(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ClearUserDefinedIdentifiers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__CompileFile(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CompileFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__CompileScriptChunk(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CompileScriptChunk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__CompileScriptConditional(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CompileScriptConditional);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CScriptParseTreeNode* CScriptCompiler__CreateScriptParseTreeNode(CScriptCompiler* thisPtr, int32_t a0, CScriptParseTreeNode* a1, CScriptParseTreeNode* a2)
{
    using FuncPtrType = CScriptParseTreeNode*(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CScriptParseTreeNode*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__CreateScriptParseTreeNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CScriptCompiler__DeleteCompileStack(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__DeleteCompileStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__DeleteParseTree(CScriptCompiler* thisPtr, int32_t a0, CScriptParseTreeNode* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__DeleteParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptCompiler__DeleteScriptParseTreeNode(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__DeleteScriptParseTreeNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__DetermineLocationOfCode(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__DetermineLocationOfCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CScriptParseTreeNode* CScriptCompiler__DuplicateScriptParseTree(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = CScriptParseTreeNode*(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__DuplicateScriptParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__EndLineNumberAtBinaryInstruction(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__EndLineNumberAtBinaryInstruction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CScriptCompiler__FinalizeFinalCode(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__FinalizeFinalCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__FoundReturnStatementOnAllBranches(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__FoundReturnStatementOnAllBranches);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__GenerateCodeForSwitchLabels(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateCodeForSwitchLabels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CScriptCompiler__GenerateDebuggerTypeAbbreviation(CScriptCompiler* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateDebuggerTypeAbbreviation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__GenerateFinalCodeFromParseTree(CScriptCompiler* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateFinalCodeFromParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__GenerateIdentifierList(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateIdentifierList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__GenerateIdentifiersFromConstantVariables(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateIdentifiersFromConstantVariables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__GenerateParseTree(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GenerateParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__GetCompiledScriptCode(CScriptCompiler* thisPtr, char** a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, char**, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetCompiledScriptCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CScriptCompiler__GetFunctionNameFromSymbolSubTypes(CScriptCompiler* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetFunctionNameFromSymbolSubTypes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__GetHashEntryByName(CScriptCompiler* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetHashEntryByName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__GetIdentifierByName(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetIdentifierByName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CScriptParseTreeNode* CScriptCompiler__GetNewScriptParseTreeNode(CScriptCompiler* thisPtr)
{
    using FuncPtrType = CScriptParseTreeNode*(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetNewScriptParseTreeNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__GetStructureField(CScriptCompiler* thisPtr, const CExoString& a0, const CExoString& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetStructureField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__GetStructureSize(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__GetStructureSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__HandleIdentifierToken(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HandleIdentifierToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__HandleToken(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HandleToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CScriptCompiler__HashManagerAdd(CScriptCompiler* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CScriptCompiler*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HashManagerAdd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CScriptCompiler__HashManagerDelete(CScriptCompiler* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CScriptCompiler*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HashManagerDelete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CScriptCompiler__HashString__0(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HashString__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CScriptCompiler__HashString__1(CScriptCompiler* thisPtr, const char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__HashString__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__Initialize(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__InitializeFinalCode(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InitializeFinalCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__InitializeIncludeFile(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InitializeIncludeFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__InitializePreDefinedStructures(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InitializePreDefinedStructures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__InitializeSwitchLabelList(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InitializeSwitchLabelList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CScriptParseTreeNode* CScriptCompiler__InsertGlobalVariablesInParseTree(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = CScriptParseTreeNode*(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InsertGlobalVariablesInParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__InstallLoader(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InstallLoader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__InVisitGenerateCode(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__InVisitGenerateCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__ModifySRStackReturnTree(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ModifySRStackReturnTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__OutputError(CScriptCompiler* thisPtr, int32_t a0, CExoString* a1, int32_t a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CExoString*, int32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__OutputError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CScriptCompiler__OutputIdentifierError(CScriptCompiler* thisPtr, const CExoString& a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__OutputIdentifierError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CScriptCompiler__OutputWalkTreeError(CScriptCompiler* thisPtr, int32_t a0, CScriptParseTreeNode* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__OutputWalkTreeError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__ParseCharacterAlphabet(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterAlphabet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterAmpersand(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterAmpersand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterAsterisk(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterAsterisk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterCarat(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterCarat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterColon(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterColon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterComma(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterComma);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterEllipsis(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterEllipsis);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterEqualSign(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterEqualSign);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterExclamationPoint(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterExclamationPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterHyphen(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterHyphen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterLeftAngle(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterLeftAngle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterLeftBrace(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterLeftBrace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterLeftBracket(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterLeftBracket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterLeftSquareBracket(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterLeftSquareBracket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterNumeric(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterNumeric);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterPercentSign(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterPercentSign);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterPeriod(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterPeriod);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterPlusSign(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterPlusSign);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterQuestionMark(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterQuestionMark);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterQuotationMark(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterQuotationMark);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterRightAngle(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterRightAngle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterRightBrace(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterRightBrace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterRightBracket(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterRightBracket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterRightSquareBracket(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterRightSquareBracket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterSemicolon(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterSemicolon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterSlash(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterSlash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCharacterTilde(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterTilde);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseCharacterVerticalBar(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCharacterVerticalBar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ParseCommentedOutCharacter(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseCommentedOutCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CScriptCompiler__ParseFloatFromTokenString(CScriptCompiler* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseFloatFromTokenString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseIdentifierFile(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseIdentifierFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__ParseNextCharacter(CScriptCompiler* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseNextCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__ParseSource(CScriptCompiler* thisPtr, char* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseSource);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__ParseStringCharacter(CScriptCompiler* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ParseStringCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__PopSRStack(CScriptCompiler* thisPtr, int32_t* a0, int32_t* a1, int32_t* a2, CScriptParseTreeNode** a3, CScriptParseTreeNode** a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t*, int32_t*, int32_t*, CScriptParseTreeNode**, CScriptParseTreeNode**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PopSRStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CScriptCompiler__PostVisitGenerateCode(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PostVisitGenerateCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__PreVisitGenerateCode(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PreVisitGenerateCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__PrintBinaryAddress(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PrintBinaryAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__PrintParseIdentifierFileError(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PrintParseIdentifierFileError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__PrintParseSourceError(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PrintParseSourceError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__PushSRStack(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2, CScriptParseTreeNode* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__PushSRStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CScriptCompiler__RemoveFromSymbolTableVarStack(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__RemoveFromSymbolTableVarStack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CScriptCompiler__ResolveDebuggingInformation(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ResolveDebuggingInformation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__ResolveDebuggingInformationForIdentifier(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ResolveDebuggingInformationForIdentifier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ResolveLabels(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ResolveLabels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__SetAutomaticCleanUpAfterCompiles(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetAutomaticCleanUpAfterCompiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetCompileConditionalFile(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetCompileConditionalFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetCompileConditionalOrMain(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetCompileConditionalOrMain);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetCompileDebugLevel(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetCompileDebugLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetCompileSymbolicOutput(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetCompileSymbolicOutput);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetGenerateDebuggerOutput(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetGenerateDebuggerOutput);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetIdentifierSpecification(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetIdentifierSpecification);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetOptimizeBinaryCodeLength(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetOptimizeBinaryCodeLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__SetOutputAlias(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__SetOutputAlias);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__ShutDown(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ShutDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__ShutdownIncludeFile(CScriptCompiler* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ShutdownIncludeFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CScriptCompiler__StartLineNumberAtBinaryInstruction(CScriptCompiler* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__StartLineNumberAtBinaryInstruction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CScriptCompiler__Test_CompareDirectoryContents(CScriptCompiler* thisPtr, CExoString& a0, CExoString& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__Test_CompareDirectoryContents);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptCompiler__Test_CompareFileInclusion(CScriptCompiler* thisPtr, CExoString& a0, CExoString& a1, CExoStringList* a2, uint16_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CExoString&, CExoString&, CExoStringList*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__Test_CompareFileInclusion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CScriptCompiler__Test_CompileAllScriptsInDirectory(CScriptCompiler* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__Test_CompileAllScriptsInDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CScriptCompiler__TestIdentifierToken(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__TestIdentifierToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CScriptCompiler__TokenInitialize(CScriptCompiler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__TokenInitialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CScriptCompiler__TraverseTreeForSwitchLabels(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__TraverseTreeForSwitchLabels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__ValidateLocationOfIdentifier(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__ValidateLocationOfIdentifier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__WalkParseTree(CScriptCompiler* thisPtr, CScriptParseTreeNode* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__WalkParseTree);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__WriteDebuggerOutputToFile(CScriptCompiler* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__WriteDebuggerOutputToFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__WriteFinalCodeToFile(CScriptCompiler* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__WriteFinalCodeToFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptCompiler__WriteResolvedOutput(CScriptCompiler* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompiler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompiler__WriteResolvedOutput);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
