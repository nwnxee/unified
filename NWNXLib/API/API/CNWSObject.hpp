#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CGameObject.hpp"
#include "CNWSObjectActionNode.hpp"
#include "CNWSScriptVarTable.hpp"
#include "CNWSTransition.hpp"
#include "CNWSUUID.hpp"
#include "CResRef.hpp"
#include "CScriptLocation.hpp"
#include "MaterialShaderParam.hpp"
#include "ObjectVisualTransformData.hpp"
#include "TextureReplaceInfo.hpp"
#include "Vector.hpp"
#include "Database.hpp"
#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSObject)
#endif

struct CExoString;
struct CGameEffect;
struct CLoopingVisualEffect;
struct CNWCCMessageData;
struct CNWSAnimBase;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSCreature;
struct CNWSDialog;
struct CNWSExpression;
struct CNWSPlayer;
struct CNWSpell;
struct CResGFF;
struct CResStruct;


typedef TextureReplaceInfo AnimationReplaceInfo;
typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;
typedef uint32_t OBJECT_ID;
typedef uint32_t STRREF;


struct CNWSObject : CGameObject
{
    static CExoLocString m_sForGCC;
    uint16_t m_nGroupID;
    uint16_t m_nLastGroupID;
    CExoString m_sTag;
    CExoString m_sTemplate;
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    CNWSDialog * m_pDialog;
    uint32_t m_nDialogDelayCalendar;
    uint32_t m_nDialogDelayTimeOfDay;
    BOOL m_bDialogStored;
    uint32_t m_nDialogStoredEntry;
    BOOL m_bDialogPaused;
    OBJECT_ID m_oidDialogOwner;
    int32_t m_nDialogAnimation;
    int32_t m_nAILevel;
    BOOL m_bLock;
    CExoLinkedListPosition m_pAIPosList;
    uint16_t m_nCurrentAction;
    OBJECT_ID m_oidCurrentActionTarget;
    CNWSAnimBase * m_pAnimation;
    OBJECT_ID m_oidArea;
    Vector m_vPosition;
    Vector m_vOrientation;
    uint32_t m_nLastUpdateCalendarDay;
    uint32_t m_nLastUpdateTimeOfDay;
    uint32_t m_nStartActionCalendarDay;
    uint32_t m_nStartActionTimeOfDay;
    uint32_t m_nLastAnimationCalendarDay;
    uint32_t m_nLastAnimationTimeOfDay;
    uint32_t m_nAIUpdateDifference;
    int32_t m_nAnimation;
    float m_fAnimSpeed;
    int32_t m_nCurrentHitPoints;
    int32_t m_nBaseHitPoints;
    int32_t m_nTemporaryHitPoints;
    BOOL m_bAbleToModifyActionQueue;
    BOOL m_bDestroyable;
    BOOL m_bRaiseable;
    BOOL m_bSelectableWhenDead;
    BOOL m_bPlotObject;
    CExoLinkedList<CNWSObjectActionNode> m_lQueuedActions;
    CNWSScriptVarTable m_ScriptVars;
    CExoArrayList<CGameEffect *> m_appliedEffects;
    CExoArrayList<CLoopingVisualEffect> m_lstLoopingVisualEffects;
    CExoArrayList<OBJECT_ID> m_lstEffectTargets;
    BOOL m_bPendingEffectRemoval;
    uint32_t m_nSavingThrowSpellId;
    int32_t m_nCustomScriptEventId;
    OBJECT_ID m_oidKiller;
    OBJECT_ID m_oidLastHostileActor;
    OBJECT_ID m_oidLastAttacker;
    OBJECT_ID m_oidLastDamager;
    OBJECT_ID m_oidLastDisturbed;
    int32_t * m_pLastDamageList;
    uint16_t m_nLastAttackType;
    uint8_t m_nLastAttackMode;
    OBJECT_ID m_oidLastWeaponAttackedWith;
    OBJECT_ID m_oidInventoryDisturbItem;
    int32_t m_nInventoryDisturbType;
    OBJECT_ID m_oidLastSpeaker;
    BOOL m_bPrivateConversation;
    int32_t m_nConversationPlayHello;
    CExoString m_sLastConversationResref;
    CExoArrayList<CNWSExpression *> m_aListenExpressions;
    int32_t m_nMatchedPos;
    BOOL m_bListening;
    CExoArrayList<CExoString *> m_aExpressionStrings;
    char * m_nDamageImmunity;
    Vector m_vLastSpellTarget;
    OBJECT_ID m_oidLastSpellTarget;
    uint32_t m_nLastSpellId;
    uint8_t m_nLastDomainLevel;
    uint32_t m_nLastSpellProjectileTime;
    BOOL m_bLastSpellCast;
    BOOL m_bLastSpellCastSpontaneous;
    uint8_t m_nLastSpellCastMulticlass;
    uint8_t m_nLastSpellCastMetaType;
    OBJECT_ID m_oidLastSpellCastAtMeCaster;
    uint32_t m_nLastSpellCastAtMe;
    BOOL m_bLastSpellCastAtMeHarmful;
    uint16_t m_nLastSpellCastFeat;
    CNWSObjectActionNode * m_pExecutingAIAction;
    uint16_t m_nEffectArrayIndex;
    BOOL m_bApplyingPostProcessEffects;
    BOOL m_bOpenDoorAnimationPlayed;
    Vector m_vHiliteColor;
    int32_t m_nMouseCursor;
    BOOL m_bUseable;
    float m_fVisibleDistance;
    int32_t m_nUiDiscoveryMask;
    int32_t m_nTextBubbleOverrideType;
    CExoString m_sTextBubbleOverrideText;
    CNWSTransition m_pTransition;
    std::shared_ptr<NWSQLite::Database> m_sqlite_db;
    ObjectVisualTransformData * m_pVisualTransformData;
    CExoArrayList<MaterialShaderParam> m_lMaterialShaderParameters;
    CExoArrayList<TextureReplaceInfo> m_lTextureReplaceInfo;
    CExoArrayList<AnimationReplaceInfo> m_lAnimationReplaceInfo;
    CNWSUUID m_pUUID;

    CNWSObject(uint8_t nObjectType, OBJECT_ID oidId = 0x7f000000, BOOL bCharacterObject = false, BOOL bAddObjectToArray = true);
    ~CNWSObject();
    virtual CNWSObject * AsNWSObject();
    void TestActionList();
    void AddAction(uint32_t nActionId, uint16_t nGroupId, uint32_t nParamType1 = 0, void * pParameter1 = nullptr, uint32_t nParamType2 = 0, void * pParameter2 = nullptr, uint32_t nParamType3 = 0, void * pParameter3 = nullptr, uint32_t nParamType4 = 0, void * pParameter4 = nullptr, uint32_t nParamType5 = 0, void * pParameter5 = nullptr, uint32_t nParamType6 = 0, void * pParameter6 = nullptr, uint32_t nParamType7 = 0, void * pParameter7 = nullptr, uint32_t nParamType8 = 0, void * pParameter8 = nullptr, uint32_t nParamType9 = 0, void * pParameter9 = nullptr, uint32_t nParamType10 = 0, void * pParameter10 = nullptr, uint32_t nParamType11 = 0, void * pParameter11 = nullptr, uint32_t nParamType12 = 0, void * pParameter12 = nullptr);
    void AddActionToFront(uint32_t nActionId, uint16_t nGroupId, uint32_t nParamType1 = 0, void * pParameter1 = nullptr, uint32_t nParamType2 = 0, void * pParameter2 = nullptr, uint32_t nParamType3 = 0, void * pParameter3 = nullptr, uint32_t nParamType4 = 0, void * pParameter4 = nullptr, uint32_t nParamType5 = 0, void * pParameter5 = nullptr, uint32_t nParamType6 = 0, void * pParameter6 = nullptr, uint32_t nParamType7 = 0, void * pParameter7 = nullptr, uint32_t nParamType8 = 0, void * pParameter8 = nullptr, uint32_t nParamType9 = 0, void * pParameter9 = nullptr, uint32_t nParamType10 = 0, void * pParameter10 = nullptr, uint32_t nParamType11 = 0, void * pParameter11 = nullptr, uint32_t nParamType12 = 0, void * pParameter12 = nullptr);
    void AddActionAfterFront(uint32_t nActionId, uint16_t nGroupId, uint32_t nParamType1 = 0, void * pParameter1 = nullptr, uint32_t nParamType2 = 0, void * pParameter2 = nullptr, uint32_t nParamType3 = 0, void * pParameter3 = nullptr, uint32_t nParamType4 = 0, void * pParameter4 = nullptr, uint32_t nParamType5 = 0, void * pParameter5 = nullptr, uint32_t nParamType6 = 0, void * pParameter6 = nullptr, uint32_t nParamType7 = 0, void * pParameter7 = nullptr, uint32_t nParamType8 = 0, void * pParameter8 = nullptr, uint32_t nParamType9 = 0, void * pParameter9 = nullptr, uint32_t nParamType10 = 0, void * pParameter10 = nullptr, uint32_t nParamType11 = 0, void * pParameter11 = nullptr, uint32_t nParamType12 = 0, void * pParameter12 = nullptr);
    void SetGroupInterruptable(uint16_t nGroupId, BOOL bActionInterruptable = true);
    BOOL AddUseObjectAction(OBJECT_ID oidObjectToUse);
    BOOL AddDoCommandAction(void * pScript);
    BOOL AddGiveItemActions(OBJECT_ID oidItem, OBJECT_ID oidGiveTo, BOOL bOriginatingFromScript = false);
    BOOL AddTakeItemActions(OBJECT_ID oidItem, OBJECT_ID oidTakeFrom, BOOL bOriginatingFromScript = false);
    BOOL AddOpenDoorAction(OBJECT_ID oidDoor, int32_t bRunToDoor = false);
    BOOL AddCloseDoorAction(OBJECT_ID oidDoor, int32_t bRunToDoor = false);
    BOOL AddUnlockObjectAction(OBJECT_ID oidTarget, OBJECT_ID oidThievesTool = 0x7f000000, int32_t nActivePropertyIndex = 0);
    BOOL AddLockObjectAction(OBJECT_ID oidTarget);
    BOOL AnimationStationary(uint16_t nAnimation);
    virtual void AIUpdate();
    void ClearAllActions();
    void ClearAllHostileActions(OBJECT_ID oidTarget);
    virtual BOOL ClearAction(CNWSObjectActionNode * pNode, BOOL bIsTopmostAction);
    virtual void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL GetAcceptableAction(uint32_t nActionId);
    uint16_t GetActionByGroupId(uint16_t nGroupId, CNWSObjectActionNode * * pReturnNode);
    CExoLinkedListPosition GetPositionByGroupIndex(int32_t nIndex);
    CNWSObjectActionNode * GetNodeById(uint16_t nActionId, uint16_t nGroupId);
    int32_t GetNumActionGroups();
    void RemoveGroup(uint16_t nGroupId);
    uint16_t GetAQActionIDByID(uint16_t nId, BOOL bFeat);
    uint16_t GetIDByAQActionID(uint16_t nAQActionId);
    CNWSArea * GetArea();
    void LoadObjectState(CResGFF * pRes, CResStruct * pStruct);
    void SaveObjectState(CResGFF * pRes, CResStruct * pStruct);
    void CopyScriptVars(CNWSScriptVarTable * pVarTable);
    virtual void SetAnimation(int32_t nAnimation);
    void SetArea(CNWSArea * pArea);
    void SetOrientation(Vector vOrientation);
    void SetPosition(Vector vPosition, BOOL bDoingCharacterCopy = false);
    void SetDialogDelay(float fDialogDelaySec);
    BOOL IsDialogDelay();
    BOOL StartDialog(OBJECT_ID oidObjectToDialog, const CExoString & sDialogResRef, BOOL bPrivate, BOOL bPlayHello);
    BOOL RunDialogOneLiner(const CExoString & sDialogResRef, OBJECT_ID oidTarget);
    BOOL SendDialogEntry(uint32_t iEntry, BOOL bPlayHelloSound);
    BOOL SendDialogReplies();
    BOOL ReplyDialog(uint32_t nPlayerId, uint32_t nReplyIndex, BOOL bEscapeDialog, uint32_t currentEntryIndex);
    BOOL UpdateDialog();
    BOOL StopDialog();
    BOOL RemoveObjectFromDialog(OBJECT_ID oidRemove);
    void PlaySoundSet(CNWSPlayer * pPlayer, uint8_t nVoiceSetId);
    OBJECT_ID GetNearestObjectByName(const CExoString & sName, float fRange = 0.0f);
    CScriptLocation GetScriptLocation();
    void SetDialogOwner(OBJECT_ID oidDialogOwner);
    virtual CResRef GetDialogResref();
    virtual BOOL GetDialogInterruptable();
    virtual uint8_t GetGender();
    virtual CExoLocString & GetFirstName();
    virtual CExoLocString & GetLastName();
    BOOL GetDead();
    BOOL GetIsPCDying();
    virtual int16_t GetMaxHitPoints(BOOL bIncludeToughness = true);
    virtual int16_t GetCurrentHitPoints(BOOL bExcludeTemporaryHits = false);
    virtual void DoDamage(int32_t nDamage);
    virtual int32_t DoDamageReduction(CNWSCreature * pDamager, int32_t nDamage, uint8_t nDamagePower, BOOL bSimulation, BOOL bCombatDamage, BOOL bRangedAttack);
    virtual int32_t DoDamageResistance(CNWSCreature * pDamager, int32_t nDamage, uint32_t nFlags, BOOL bSimulation, BOOL bCombatDamage, BOOL bBaseWeaponDamage, BOOL bRangedAttack);
    virtual int32_t GetMaximumDamageResistanceVsDamageFlag(uint32_t nDamageFlag, int32_t * nBestIndex, BOOL bRangedAttack);
    virtual int32_t DoDamageImmunity(CNWSCreature * pDamager, int32_t nDamage, uint32_t nFlags, BOOL bSimulation, BOOL bCombatDamage);
    virtual char GetDamageImmunity(uint8_t nType);
    virtual char GetDamageImmunityByFlags(uint32_t nFlags);
    void SetDamageImmunity(uint32_t nFlags, int32_t nValue);
    int32_t DoSpellLevelAbsorption(CNWSObject * pCaster, CNWSAreaOfEffectObject * pAoEObject = nullptr);
    int32_t DoSpellImmunity(CNWSObject * pCaster, CNWSAreaOfEffectObject * pAoEObject = nullptr);
    int32_t GetCasterLevel();
    uint8_t GetDamageLevel();
    void DeleteCurrentAIAction();
    void ApplyEffect(CGameEffect * e, BOOL bLoadingGame = false, BOOL bInitialApplication = false);
    void RemoveEffect(CGameEffect * e);
    BOOL RemoveEffectById(uint64_t pId);
    void RemoveEffectByCreator(OBJECT_ID oidCreator);
    void RemoveSomeEffectsOfDurationType(uint16_t nDurationType);
    void UpdateEffectList(uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void RemoveEffectTarget(OBJECT_ID oidTarget);
    void ClearSpellEffectsOnOthers();
    BOOL HasSpellEffectApplied(uint32_t nSpellId);
    void RemoveEffectBySpellId(uint32_t nSpellId);
    BOOL GetHasFeatEffectApplied(uint16_t nFeatId);
    virtual uint32_t GetEffectSpellId();
    virtual void SetEffectSpellId(uint32_t n);
    void AddLoopingVisualEffect(uint16_t nVisEffectID, OBJECT_ID oidOriginator = 0x7f000000, uint8_t nBodyPart = 0, ObjectVisualTransformData ovtd = ObjectVisualTransformData());
    void RemoveLoopingVisualEffect(uint16_t nVisEffectID, OBJECT_ID oidOriginator = 0x7f000000, uint8_t nBodyPart = 0, const ObjectVisualTransformData& ovtd = ObjectVisualTransformData());
    void BroadcastDialog(CExoString sSpokenString, float fRadius);
    Vector CalculateSpellRangedMissTarget(OBJECT_ID oidSource, OBJECT_ID oidTarget);
    int32_t GetLastDamageAmountByFlags(uint32_t nDamageFlags);
    void SetLastHostileActor(OBJECT_ID oidHostileActor, BOOL bForceSet = false);
    int32_t SetListenExpression(CExoString sExpression, int32_t nPos);
    int32_t TestListenExpression(CExoString sStringToTest);
    CNWSExpression * GetListenExpressionObj(int32_t n);
    void AddMatchedExpressionString(const CExoString & sString);
    void ClearMatchedExpressionStrings();
    virtual void SetLockOrientationToObject(OBJECT_ID oidLockOnObj);
    virtual OBJECT_ID GetLockOrientationToObject();
    virtual CResRef GetPortrait();
    virtual void SetPortrait(CResRef cPortrait);
    virtual uint16_t GetPortraitId();
    virtual void SetPortraitId(uint16_t nPortraitId);
    int32_t GetReputation(OBJECT_ID oidSource, BOOL & bIsInParty, BOOL bUseOriginalFaction = false);
    uint8_t GetAIStateReaction(OBJECT_ID oidTarget);
    void BroadcastCounterSpellData(CNWSpell * pSpell, CNWCCMessageData * pMessageData);
    void BroadcastSpellData(CNWSpell * pSpell, CNWCCMessageData * pMessageData);
    void BroadcastSafeProjectile(OBJECT_ID oidOriginator, OBJECT_ID oidTarget, Vector vOriginator, Vector vTarget, uint32_t nDelta, uint8_t nProjectileType, uint32_t nSpellID, uint8_t nAttackResult, uint8_t nProjectilePathType = 0);
    virtual void BroadcastFloatyData(CNWCCMessageData * pMessageData);
    virtual void BroadcastFloatyDataSTRREF(STRREF nStrRef);
    void SpellCastAndImpact(uint32_t nSpellId, Vector vTargetPosition, OBJECT_ID oidTarget, uint8_t nMultiClass, OBJECT_ID oidItem = 0x7f000000, BOOL bSpellCountered = false, BOOL bCounteringSpell = false, uint8_t nProjectilePathType = 0, BOOL bInstantSpell = false);
    void CalculateLastSpellProjectileTime(uint8_t nProjectilePathType = 0);
    void SpawnBodyBag();
    void ReportOverflow(int32_t nOverflowFeedbackType, int32_t nTotal, int32_t nError, BOOL bCritical = false);
    std::shared_ptr<NWSQLite::Database> GetObjectSqlDatabase();
    virtual bool GetCanCarrySqlDatabase();
    void DestroyObjectSqlDatabase();
    void SaveVisualTransform(CResGFF * pRes, CResStruct * pStruct);
    void LoadVisualTransform(CResGFF * pRes, CResStruct * pStruct);
    void SaveMaterialOverrides(CResGFF * pRes, CResStruct * pStruct);
    void LoadMaterialOverrides(CResGFF * pRes, CResStruct * pStruct);
    void SaveMiscVisuals(CResGFF * pRes, CResStruct * pStruct);
    void LoadMiscVisuals(CResGFF * pRes, CResStruct * pStruct);
    void SaveTextureOverrides(CResGFF * pRes, CResStruct * pStruct);
    void LoadTextureOverrides(CResGFF * pRes, CResStruct * pStruct);
    void SaveAnimationOverrides(CResGFF * pRes, CResStruct * pStruct);
    void LoadAnimationOverrides(CResGFF * pRes, CResStruct * pStruct);
    void LoadSqliteDatabase(CResGFF * pRes, CResStruct * pStruct);
    void SaveSqliteDatabase(CResGFF * pRes, CResStruct * pStruct);
    BOOL RunEventScript(int32_t nScript, CExoString * psOverrideScriptName = nullptr);
    void SetVisualTransformData(const ObjectVisualTransformData & data);
    void SetMaterialShaderParamI(const CExoString & sMaterialName, const CExoString & sParamName, int nValue);
    void SetMaterialShaderParamVec4(const CExoString & sMaterialName, const CExoString & sParamName, float fValue1, float fValue2, float fValue3, float fValue4);
    void ResetMaterialShaderParams(const CExoString & sMaterialName = "", const CExoString & sParamName = "");
    void SetTextureReplace(const CExoString & sOld, const CExoString & sNew);
    void SetAnimationReplace(const CExoString & sOld, const CExoString & sNew);
    void AddActionNodeParameter(CNWSObjectActionNode * pNode, uint32_t nParameterNumber, uint32_t nParameterType, void * pParameter);
    void RunActions(uint32_t nCalendarDay, uint32_t nTimeOfDay, uint64_t nStartOfUpdate);
    BOOL TerminateAISliceAfterAction(uint32_t nActionId);
    void LoadActionQueue(CResGFF * pRes, CResStruct * pStruct);
    void SaveActionQueue(CResGFF * pRes, CResStruct * pStruct);
    void LoadVarTable(CResGFF * pRes, CResStruct * pStruct);
    void SaveVarTable(CResGFF * pRes, CResStruct * pStruct);
    void LoadEffectList(CResGFF * pRes, CResStruct * pStruct);
    void SaveEffectList(CResGFF * pRes, CResStruct * pStruct);
    void SaveListenData(CResGFF * pRes, CResStruct * pStruct);
    void LoadListenData(CResGFF * pRes, CResStruct * pStruct);
    uint16_t GetNewGroupID();
    uint32_t AIActionDialogObject(CNWSObjectActionNode * pNode);
    uint32_t AIActionPauseDialog(CNWSObjectActionNode * pNode);
    uint32_t AIActionResumeDialog(CNWSObjectActionNode * pNode);
    uint32_t AIActionSpeakStrRef(CNWSObjectActionNode * pNode);
    uint32_t AIActionSpeak(CNWSObjectActionNode * pNode);
    uint32_t AIActionWait(CNWSObjectActionNode * pNode);
    uint32_t AIActionDoCommand(CNWSObjectActionNode * pNode);
    uint32_t AIActionPlaySound(CNWSObjectActionNode * pNode);
    uint32_t AIActionPlayAnimation(CNWSObjectActionNode * pNode);
    uint32_t AIActionGiveItem(CNWSObjectActionNode * pNode);
    uint32_t AIActionTakeItem(CNWSObjectActionNode * pNode);
    uint32_t AIActionCloseDoor(CNWSObjectActionNode * pNode);
    uint32_t AIActionOpenDoor(CNWSObjectActionNode * pNode);
    uint32_t AIActionUnlockObject(CNWSObjectActionNode * pNode);
    uint32_t AIActionLockObject(CNWSObjectActionNode * pNode);
    uint32_t AIActionUseObject(CNWSObjectActionNode * pNode);
    uint32_t AIActionSetCommandable(CNWSObjectActionNode * pNode);
    virtual void UpdateEffectPtrs();
    virtual void UpdateAttributesOnEffect(CGameEffect * e, BOOL bLoadingGame = false);
    virtual CExoString * GetScriptName(int32_t nScript);


#ifdef NWN_CLASS_EXTENSION_CNWSObject
    NWN_CLASS_EXTENSION_CNWSObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSObject)
#endif
