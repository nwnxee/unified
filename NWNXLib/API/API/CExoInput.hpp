#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoInput)
#endif

struct CExoFile;
struct CExoInputEvent;
struct CExoInputInternal;


typedef int BOOL;


struct CExoInput
{
    CExoInputInternal * m_pcExoInputInternal;

    CExoInput();
    virtual ~CExoInput();
    virtual void Configure();
    BOOL AddEvent(void * pEvent);
    void AddEvent(int32_t nInputDevice, uint32_t nInputDeviceElement, uint32_t nValue, uint32_t nTimeStamp);
    void AddInputEventDesc(CExoString label, uint32_t id, int32_t inputDeviceType, int32_t activeInputMode, int32_t inputClass, int32_t inputDevice = - 1, uint32_t inputElement = 0);
    void ClearAllInputEventDesc();
    void ClearEvents();
    void DumpEventsToFile(CExoString fileName);
    void DumpEventsToFile(CExoFile * file);
    void WriteEventToFile(uint32_t nProcessTime, int32_t nEvent, CExoFile * file);
    BOOL GetActive();
    CExoInputEvent * GetEvents(int32_t & numberEvents, int32_t activeInputMode, int32_t inputClass);
    CExoInputEvent * GetButtonStates(int32_t & numberEvents, int32_t activeInputMode, int32_t inputClass);
    void KeyboardModeOn();
    void KeyboardModeOff();
    BOOL GetKeyboardMode();
    BOOL * GetModalKeys();
    void CheckModalKeys();
    uint8_t GetNumberJoysticks();
    BOOL IsJoystickActive();
    void SetCaptureKeyboardScanCodes(BOOL bCaptureKeyboardScanCodes);
    uint16_t GetLastCapturedKeyboardScanCode();
    void SetActive(BOOL Active);
    void ResetModalKeys();
    void SetMousePos(int32_t nX, int32_t nY);
    BOOL SetMouseMode(uint8_t nMode);
    uint8_t GetMouseMode();
    BOOL IsRemappableKey(uint8_t nKey);
    uint32_t GetMilliSecondsSinceLastUserActivity() const;


#ifdef NWN_CLASS_EXTENSION_CExoInput
    NWN_CLASS_EXTENSION_CExoInput
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoInput)
#endif

