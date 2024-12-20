#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "CScriptCompilerIncludeFileStackEntry.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompiler)
#endif

struct CExoStringList;
struct CScriptCompilerIdListEntry;
struct CScriptCompilerIdentifierHashTableEntry;
struct CScriptCompilerKeyWordEntry;
struct CScriptCompilerStackEntry;
struct CScriptCompilerStructureEntry;
struct CScriptCompilerStructureFieldEntry;
struct CScriptCompilerSymbolTableEntry;
struct CScriptCompilerVarStackEntry;
struct CScriptParseTreeNode;
struct CScriptParseTreeNodeBlock;


typedef int BOOL;

//
// Compiler optimization flags.
// Note that some optimizations might interfere with NDB generation.
//

// Removes any functions that cannot possibly be called by any codepath
#define CSCRIPTCOMPILER_OPTIMIZE_DEAD_FUNCTIONS                       0x00000001
// Merges constant expressions into a single constant where possible.
// Note: Only affects runtime expressions, assignments to const variables are always folded.
#define CSCRIPTCOMPILER_OPTIMIZE_FOLD_CONSTANTS                       0x00000002
// Post processes generated instructions to merge sequences into shorter equivalents
#define CSCRIPTCOMPILER_OPTIMIZE_MELD_INSTRUCTIONS                    0x00000004

#define CSCRIPTCOMPILER_OPTIMIZE_NOTHING                              0x00000000
#define CSCRIPTCOMPILER_OPTIMIZE_EVERYTHING                           0xFFFFFFFF

struct CScriptCompilerAPI
{
    CScriptCompilerAPI() { memset(this, 0, sizeof(CScriptCompilerAPI)); }
    BOOL (*ResManUpdateResourceDirectory)(const char* sAlias);
    int32_t (*ResManWriteToFile)(const char* sFileName, RESTYPE nResType, const uint8_t* pData, size_t nSize, bool bBinary);
    const char* (*ResManLoadScriptSourceFile)(const char* sFileName, RESTYPE nResType);
    const char* (*TlkResolve)(STRREF strRef);
};

struct CScriptCompiler
{
    static CScriptCompilerAPI MakeDefaultAPI();
    CScriptCompilerAPI m_cAPI;
    RESTYPE m_nResTypeSource;
    RESTYPE m_nResTypeCompiled;
    RESTYPE m_nResTypeDebug;
    int32_t m_nKeyWords;
    CScriptCompilerKeyWordEntry * m_pcKeyWords;
    int32_t m_nParseTreeNodeBlockEmptyNodes;
    CScriptParseTreeNodeBlock * m_pCurrentParseTreeNodeBlock;
    CScriptParseTreeNodeBlock * m_pParseTreeNodeBlockHead;
    CScriptParseTreeNodeBlock * m_pParseTreeNodeBlockTail;
    CExoString * * m_ppsParseTreeFileNames;
    int32_t m_nNextParseTreeFileName;
    int32_t m_nCurrentParseTreeFileName;
    int32_t m_nCurrentLineNumber;
    int32_t m_nCurrentLineNumberFileReference;
    int32_t m_nCurrentLineNumberReferences;
    int32_t m_nCurrentLineNumberBinaryStartInstruction;
    int32_t m_nCurrentLineNumberBinaryEndInstruction;
    int32_t m_nTableFileNames;
    CExoString m_psTableFileNames[512];
    int32_t m_nLineNumberEntries;
    int32_t m_nFinalLineNumberEntries;
    std::vector<int32_t> m_pnTableInstructionFileReference;
    std::vector<int32_t> m_pnTableInstructionLineNumber;
    std::vector<int32_t> m_pnTableInstructionBinaryStart;
    std::vector<int32_t> m_pnTableInstructionBinaryEnd;
    std::vector<int32_t> m_pnTableInstructionBinaryFinal;
    std::vector<int32_t> m_pnTableInstructionBinarySortedOrder;
    int32_t m_nSymbolTableVariables;
    int32_t m_nFinalSymbolTableVariables;
    std::vector<int32_t> m_pnSymbolTableVarType;
    std::vector<CExoString> m_psSymbolTableVarName;
    std::vector<CExoString> m_psSymbolTableVarStructureName;
    std::vector<int32_t> m_pnSymbolTableVarStackLoc;
    std::vector<int32_t> m_pnSymbolTableVarBegin;
    std::vector<int32_t> m_pnSymbolTableVarEnd;
    std::vector<int32_t> m_pnSymbolTableBinaryFinal;
    std::vector<int32_t> m_pnSymbolTableBinarySortedOrder;
    BOOL m_bCompileConditionalFile;
    BOOL m_bOldCompileConditionalFile;
    BOOL m_bCompileConditionalOrMain;
    CExoString m_sLanguageSource;
    CExoString m_sOutputAlias;
    CExoString m_sGraphvizPath;
    int32_t m_nLines;
    int32_t m_nCharacterOnLine;
    int32_t * m_pnHashString;
    CScriptCompilerIdentifierHashTableEntry * m_pIdentifierHashTable;
    int32_t m_nTokenStatus;
    int32_t m_nTokenCharacters;
    char m_pchToken[65536];
    CScriptCompilerStackEntry * m_pSRStack;
    int32_t m_nSRStackEntries;
    int32_t m_nSRStackStates;
    CExoString m_sCurrentFunction;
    int32_t m_bCompileIdentifierList;
    int32_t m_bCompileIdentifierConstants;
    int32_t m_nIdentifierListState;
    int32_t m_nIdentifierListVector;
    int32_t m_nIdentifierListEngineStructure;
    int32_t m_nIdentifierListReturnType;
    CScriptCompilerIdListEntry * m_pcIdentifierList;
    int32_t m_nOccupiedIdentifiers;
    int32_t m_nMaxPredefinedIdentifierId;
    int32_t m_nPredefinedIdentifierOrder;
    int32_t m_nCompileFileLevel;
    CScriptCompilerIncludeFileStackEntry m_pcIncludeFileStack[200];
    int32_t m_nMaxIncludeDepth;
    int32_t m_nVarStackRecursionLevel;
    CScriptCompilerVarStackEntry * m_pcVarStackList;
    int32_t m_nOccupiedVariables;
    int32_t m_nVarStackVariableType;
    CExoString m_sVarStackVariableTypeName;
    CScriptCompilerStructureEntry * m_pcStructList;
    CScriptCompilerStructureFieldEntry * m_pcStructFieldList;
    int32_t m_nMaxStructures;
    int32_t m_nMaxStructureFields;
    int32_t m_nStructureDefinition;
    int32_t m_nStructureDefinitionFieldStart;
    BOOL m_bGlobalVariableDefinition;
    int32_t m_nGlobalVariables;
    int32_t m_nGlobalVariableSize;
    CScriptParseTreeNode * m_pGlobalVariableParseTree;
    BOOL m_bConstantVariableDefinition;
    int32_t m_nLoopIdentifier;
    int32_t m_nLoopStackDepth;
    int32_t m_nSwitchLevel;
    int32_t m_nSwitchIdentifier;
    int32_t m_nSwitchStackDepth;
    CExoString m_sUndefinedIdentifier;
    CExoString m_sParserErrorExtraInfo;
    BOOL m_bSwitchLabelDefault;
    int32_t m_nSwitchLabelNumber;
    int32_t m_nSwitchLabelArraySize;
    int32_t * m_pnSwitchLabelStatements;
    int32_t m_nNumEngineDefinedStructures;
    BOOL * m_pbEngineDefinedStructureValid;
    CExoString * m_psEngineDefinedStructureName;
    int32_t m_bAssignmentToVariable;
    BOOL m_bInStructurePart;
    BOOL m_bFunctionImp;
    CExoString m_sFunctionImpName;
    int32_t m_nFunctionImpReturnType;
    CExoString m_sFunctionImpReturnStructureName;
    int32_t m_nFunctionImpAbortStackPointer;
    int32_t m_nStackCurrentDepth;
    char m_pchStackTypes[8192];
    int32_t m_nRunTimeIntegers;
    int32_t m_nRunTimeFloats;
    int32_t m_nRunTimeStrings;
    int32_t m_nRunTimeObjects;
    int32_t m_nRunTimeActions;
    int32_t m_nSymbolQueryListSize;
    int32_t m_nSymbolQueryList;
    CScriptCompilerSymbolTableEntry * m_pSymbolQueryList;
    int32_t m_nSymbolLabelListSize;
    int32_t m_nSymbolLabelList;
    CScriptCompilerSymbolTableEntry * m_pSymbolLabelList;
    int32_t m_pSymbolLabelStartEntry[512];
    int32_t m_nGenerateDebuggerOutput;
    BOOL m_bAutomaticCleanUpAfterCompiles;
    uint32_t m_nOptimizationFlags;
    int32_t m_nTotalCompileNodes;
    BOOL m_bCompilingConditional;
    char * m_pchOutputCode;
    int32_t m_nOutputCodeSize;
    int32_t m_nOutputCodeLength;
    std::vector<int32_t> m_aOutputCodeInstructionBoundaries;
    char * m_pchResolvedOutputBuffer;
    int32_t m_nResolvedOutputBufferSize;
    char * m_pchDebuggerCode;
    int32_t m_nDebuggerCodeSize;
    int32_t m_nDebuggerCodeLength;
    char m_pchActionParameters[32];
    CExoString m_pchActionParameterStructureNames[32];
    int32_t m_nFinalBinarySize;
    CExoString m_sCapturedError;
    STRREF m_nCapturedErrorStrRef;

    explicit CScriptCompiler(RESTYPE nSource, RESTYPE nCompiled, RESTYPE nDebug, CScriptCompilerAPI api = MakeDefaultAPI());
    ~CScriptCompiler();
    void SetIdentifierSpecification(const CExoString & sLanguageSource);
    void SetOutputAlias(const CExoString & sAlias);
    void SetGenerateDebuggerOutput(int32_t nValue);
    void SetAutomaticCleanUpAfterCompiles(BOOL bValue);
    void CleanUpAfterCompiles();
    void SetCompileConditionalFile(BOOL nValue);
    void SetCompileConditionalOrMain(BOOL nValue);
    int32_t CompileFile(const CExoString & sFileName);
    int32_t CompileScriptChunk(const CExoString & sScriptChunk, BOOL bWrapIntoMain);
    int32_t CompileScriptConditional(const CExoString & sScriptConditional);
    int32_t GetCompiledScriptCode(char * * pnCode, int32_t * nCodeSize);
    void ClearCompiledScriptCode();
    void Initialize();
    void ShutDown();
    uint32_t HashString(const CExoString & sString);
    uint32_t HashString(const char * pString);
    void InitializePreDefinedStructures();
    void InitializeIncludeFile(int32_t nCompileFileLevel);
    void ShutdownIncludeFile(int32_t nCompileFileLevel);
    void TokenInitialize();
    void PushSRStack(int32_t nState, int32_t nRule, int32_t nTerm, CScriptParseTreeNode * pCurrentTree);
    int32_t PopSRStack(int32_t * nState, int32_t * nRule, int32_t * nTerm, CScriptParseTreeNode * * pCurrentTree, CScriptParseTreeNode * * pReturnTree);
    void ModifySRStackReturnTree(CScriptParseTreeNode * pReturnTree);
    int32_t GenerateParseTree();
    float ParseFloatFromTokenString();
    int32_t HandleToken();
    int32_t TestIdentifierToken();
    int32_t HandleIdentifierToken();
    int32_t ParseCharacterNumeric(int32_t ch);
    int32_t ParseCharacterPeriod(int32_t chNext);
    int32_t ParseCharacterSlash(int32_t chNext);
    int32_t ParseCharacterAsterisk(int32_t chNext);
    int32_t ParseCharacterAmpersand(int32_t chNext);
    int32_t ParseCharacterVerticalBar(int32_t chNext);
    int32_t ParseCharacterAlphabet(int32_t ch);
    int32_t ParseStringCharacter(int32_t ch, int32_t chNext, const char * pScript, int32_t nScriptLength);
    int32_t ParseRawStringCharacter(int32_t ch, int32_t chNext);
    int32_t ParseCharacterQuotationMark();
    int32_t ParseCharacterHyphen(int32_t chNext);
    int32_t ParseCharacterLeftBrace();
    int32_t ParseCharacterRightBrace();
    int32_t ParseCharacterLeftBracket();
    int32_t ParseCharacterRightBracket();
    int32_t ParseCharacterLeftSquareBracket();
    int32_t ParseCharacterRightSquareBracket();
    int32_t ParseCharacterLeftAngle(int32_t chNext);
    int32_t ParseCharacterRightAngle(int32_t chNext);
    int32_t ParseCharacterExclamationPoint(int32_t chNext);
    int32_t ParseCharacterEqualSign(int32_t chNext);
    int32_t ParseCharacterPlusSign(int32_t chNext);
    int32_t ParseCharacterPercentSign(int32_t chNext);
    int32_t ParseCharacterSemicolon();
    int32_t ParseCharacterComma();
    int32_t ParseCharacterCarat(int32_t chNext);
    int32_t ParseCharacterTilde();
    int32_t ParseCharacterEllipsis();
    int32_t ParseCharacterQuestionMark();
    int32_t ParseCharacterColon();
    int32_t ParseCommentedOutCharacter(int32_t ch);
    int32_t ParseNextCharacter(int32_t ch, int32_t chNext, const char * pScript, int32_t nScriptLength);
    int32_t PrintParseSourceError(int32_t nParseCharacterError);
    int32_t ParseSource(const char * pScript, int32_t nScriptLength);
    int32_t OutputError(int32_t nError, CExoString * psFileName, int32_t nLineNumber, const CExoString & sErrorText);
    CScriptParseTreeNode * DuplicateScriptParseTree(CScriptParseTreeNode * pNode);
    CScriptParseTreeNode * CreateScriptParseTreeNode(int32_t nNodeOperation, CScriptParseTreeNode * pNodeLeft, CScriptParseTreeNode * pNodeRight);
    BOOL CheckForBadLValue(CScriptParseTreeNode * pNode);
    void DeleteScriptParseTreeNode(CScriptParseTreeNode * pParseTreeNode);
    CScriptParseTreeNode * GetNewScriptParseTreeNode();
    int32_t OutputWalkTreeError(int32_t nError, CScriptParseTreeNode * pNode);
    int32_t PreVisitGenerateCode(CScriptParseTreeNode * pNode);
    int32_t InVisitGenerateCode(CScriptParseTreeNode * pNode);
    int32_t PostVisitGenerateCode(CScriptParseTreeNode * pNode);
    void WriteByteSwap16(char *buffer, int16_t value);
    void WriteByteSwap32(char *buffer, int32_t value);
    int32_t ReadByteSwap32(char *buffer);
    int16_t ReadByteSwap16(char *buffer);
    char *EmitInstruction(uint8_t nOpCode, uint8_t nAuxCode = 0, int32_t nDataSize = 0);
    void EmitModifyStackPointer(int32_t nModifyBy);
    void StartLineNumberAtBinaryInstruction(int32_t nFileReference, int32_t nLineNumber, int32_t nBinaryInstruction);
    void EndLineNumberAtBinaryInstruction(int32_t nFileReference, int32_t nLineNumber, int32_t nBinaryInstruction);
    void ResolveDebuggingInformation();
    void ResolveDebuggingInformationForIdentifier(int32_t nIdentifier);
    void DeleteCompileStack();
    void DeleteParseTree(BOOL bStack, CScriptParseTreeNode * pNode);
    int32_t WalkParseTree(CScriptParseTreeNode * pNode);
    void InitializeFinalCode();
    void FinalizeFinalCode();
    int32_t GenerateFinalCodeFromParseTree(CExoString sFileName);
    int32_t WriteFinalCodeToFile(const CExoString & sFileName);
    CExoString GenerateDebuggerTypeAbbreviation(int32_t nType, CExoString sStructureName);
    int32_t WriteDebuggerOutputToFile(CExoString sFileName);
    uint32_t HashManagerAdd(uint32_t nType, uint32_t nTypeIndice);
    uint32_t HashManagerDelete(uint32_t nType, uint32_t nTypeIndice);
    int32_t GetHashEntryByName(const char * psIdentifierName);
    int32_t PrintParseIdentifierFileError(int32_t nParseCharacterError);
    int32_t ParseIdentifierFile();
    int32_t GenerateIdentifierList();
    int32_t AddUserDefinedIdentifier(CScriptParseTreeNode * pFunctionDeclaration, BOOL bFunctionImplementation);
    void ClearUserDefinedIdentifiers();
    int32_t GetStructureField(const CExoString & sStructureName, const CExoString & sFieldName);
    int32_t GetStructureSize(const CExoString & sStructureName);
    int32_t GetIdentifierByName(const CExoString & sIdentifierName);
    int32_t AddToGlobalVariableList(CScriptParseTreeNode * pGlobalVariableNode);
    BOOL ConstantFoldNode(CScriptParseTreeNode *pNode, BOOL bForce = false);
    CScriptParseTreeNode *TrimParseTree(CScriptParseTreeNode *pNode);
    void InitializeSwitchLabelList();
    int32_t TraverseTreeForSwitchLabels(CScriptParseTreeNode * pNode);
    void ClearSwitchLabelList();
    int32_t GenerateCodeForSwitchLabels(CScriptParseTreeNode * pNode);
    int32_t GenerateIdentifiersFromConstantVariables(CScriptParseTreeNode * pNode);
    int32_t FoundReturnStatementOnAllBranches(CScriptParseTreeNode * pNode);
    void AddVariableToStack(int32_t nVariableType, CExoString * psVariableTypeName, BOOL bGenerateCode);
    void AddStructureToStack(const CExoString & sStructureName, BOOL bGenerateCode);
    void AddToSymbolTableVarStack(int32_t nOccupiedIdentifier, int32_t nStackCurrentDepth, int32_t nGlobalVariableSize);
    void RemoveFromSymbolTableVarStack(int32_t nOccupiedIdentifier, int32_t nStackCurrentDepth, int32_t nGlobalVariableSize);
    CExoString GetFunctionNameFromSymbolSubTypes(int32_t nSubType1, int32_t nSubType2);
    int32_t AddSymbolToQueryList(int32_t nLocationPointer, int32_t nSymbolType, int32_t nSymbolSubType1, int32_t nSymbolSubType2 = 0);
    int32_t AddSymbolToLabelList(int32_t nLocationPointer, int32_t nSymbolType, int32_t nSymbolSubType1, int32_t nSymbolSubType2 = 0);
    void ClearAllSymbolLists();
    int32_t CleanUpDuringCompile(int32_t nReturnValue);
    int32_t CleanUpAfterCompile(int32_t nReturnValue, CScriptParseTreeNode * pReturnTree);
    char *InstructionLookback(uint32_t last = 1);
    int32_t InstallLoader();
    CScriptParseTreeNode * InsertGlobalVariablesInParseTree(CScriptParseTreeNode * pOldTree);
    int32_t OutputIdentifierError(const CExoString & sFunctionName, int32_t nError, int32_t nFileStackDrop = 0);
    int32_t ValidateLocationOfIdentifier(const CExoString & sFunctionName);
    int32_t DetermineLocationOfCode();
    int32_t ResolveLabels();
    int32_t WriteResolvedOutput();

    void SetOptimizationFlags(uint32_t nFlags) { m_nOptimizationFlags = nFlags; }
    uint32_t GetOptimizationFlags() { return m_nOptimizationFlags; }

#ifdef NWN_CLASS_EXTENSION_CScriptCompiler
    NWN_CLASS_EXTENSION_CScriptCompiler
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompiler)
#endif

