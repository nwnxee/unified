#include "CNetLayerWindow.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNetLayerInternal.hpp"
#include "z_stream.hpp"

namespace NWNXLib {

namespace API {

CNetLayerWindow::CNetLayerWindow()
{
    CNetLayerWindow__CNetLayerWindowCtor__0(this);
}

CNetLayerWindow::~CNetLayerWindow()
{
    CNetLayerWindow__CNetLayerWindowDtor__0(this);
}

int32_t CNetLayerWindow::AddToHighOutgoingQueue(uint16_t a0)
{
    return CNetLayerWindow__AddToHighOutgoingQueue(this, a0);
}

int32_t CNetLayerWindow::AddToLowOutgoingQueue(uint16_t a0)
{
    return CNetLayerWindow__AddToLowOutgoingQueue(this, a0);
}

void CNetLayerWindow::CutOutgoingBufferSize()
{
    return CNetLayerWindow__CutOutgoingBufferSize(this);
}

void CNetLayerWindow::DoubleOutgoingBufferSize()
{
    return CNetLayerWindow__DoubleOutgoingBufferSize(this);
}

int32_t CNetLayerWindow::FauxNagle()
{
    return CNetLayerWindow__FauxNagle(this);
}

int32_t CNetLayerWindow::FrameNumberBetween(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNetLayerWindow__FrameNumberBetween(this, a0, a1, a2);
}

int32_t CNetLayerWindow::FrameReceive(unsigned char* a0, uint32_t a1)
{
    return CNetLayerWindow__FrameReceive(this, a0, a1);
}

void CNetLayerWindow::FrameSend(unsigned char a0, uint16_t a1, uint16_t a2)
{
    return CNetLayerWindow__FrameSend(this, a0, a1, a2);
}

int32_t CNetLayerWindow::FrameTimeout(uint32_t a0)
{
    return CNetLayerWindow__FrameTimeout(this, a0);
}

void CNetLayerWindow::Initialize(CNetLayerInternal* a0)
{
    return CNetLayerWindow__Initialize(this, a0);
}

void CNetLayerWindow::InitializeCompressionBuffers()
{
    return CNetLayerWindow__InitializeCompressionBuffers(this);
}

void CNetLayerWindow::LoadWindowWithFrames()
{
    return CNetLayerWindow__LoadWindowWithFrames(this);
}

void CNetLayerWindow::PlaceFrameInOutgoingBuffers(uint16_t a0)
{
    return CNetLayerWindow__PlaceFrameInOutgoingBuffers(this, a0);
}

void CNetLayerWindow::SetAckTimer()
{
    return CNetLayerWindow__SetAckTimer(this);
}

void CNetLayerWindow::SetFauxNagleTimer()
{
    return CNetLayerWindow__SetFauxNagleTimer(this);
}

void CNetLayerWindow::SetInFrameTimer()
{
    return CNetLayerWindow__SetInFrameTimer(this);
}

void CNetLayerWindow::SetOutFrameTimer(uint32_t a0)
{
    return CNetLayerWindow__SetOutFrameTimer(this, a0);
}

void CNetLayerWindow::ShutDown()
{
    return CNetLayerWindow__ShutDown(this);
}

int32_t CNetLayerWindow::TestAckTimer(uint32_t a0)
{
    return CNetLayerWindow__TestAckTimer(this, a0);
}

int32_t CNetLayerWindow::TestFauxNagleTimer(uint32_t a0)
{
    return CNetLayerWindow__TestFauxNagleTimer(this, a0);
}

int32_t CNetLayerWindow::TestInFrameTimer(uint32_t a0)
{
    return CNetLayerWindow__TestInFrameTimer(this, a0);
}

int32_t CNetLayerWindow::TestOutFrameTimer(uint32_t a0, uint32_t a1)
{
    return CNetLayerWindow__TestOutFrameTimer(this, a0, a1);
}

int32_t CNetLayerWindow::UnpacketizeFullMessages(int32_t a0)
{
    return CNetLayerWindow__UnpacketizeFullMessages(this, a0);
}

void CNetLayerWindow__CNetLayerWindowCtor__0(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__CNetLayerWindowCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNetLayerWindow__CNetLayerWindowDtor__0(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__CNetLayerWindowDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNetLayerWindow__AddToHighOutgoingQueue(CNetLayerWindow* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__AddToHighOutgoingQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerWindow__AddToLowOutgoingQueue(CNetLayerWindow* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__AddToLowOutgoingQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerWindow__CutOutgoingBufferSize(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__CutOutgoingBufferSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__DoubleOutgoingBufferSize(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__DoubleOutgoingBufferSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerWindow__FauxNagle(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__FauxNagle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerWindow__FrameNumberBetween(CNetLayerWindow* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__FrameNumberBetween);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerWindow__FrameReceive(CNetLayerWindow* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__FrameReceive);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayerWindow__FrameSend(CNetLayerWindow* thisPtr, unsigned char a0, uint16_t a1, uint16_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*, unsigned char, uint16_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__FrameSend);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerWindow__FrameTimeout(CNetLayerWindow* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__FrameTimeout);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerWindow__Initialize(CNetLayerWindow* thisPtr, CNetLayerInternal* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*, CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerWindow__InitializeCompressionBuffers(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__InitializeCompressionBuffers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__LoadWindowWithFrames(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__LoadWindowWithFrames);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__PlaceFrameInOutgoingBuffers(CNetLayerWindow* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__PlaceFrameInOutgoingBuffers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerWindow__SetAckTimer(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__SetAckTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__SetFauxNagleTimer(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__SetFauxNagleTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__SetInFrameTimer(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__SetInFrameTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerWindow__SetOutFrameTimer(CNetLayerWindow* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__SetOutFrameTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerWindow__ShutDown(CNetLayerWindow* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerWindow*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__ShutDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerWindow__TestAckTimer(CNetLayerWindow* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__TestAckTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerWindow__TestFauxNagleTimer(CNetLayerWindow* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__TestFauxNagleTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerWindow__TestInFrameTimer(CNetLayerWindow* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__TestInFrameTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerWindow__TestOutFrameTimer(CNetLayerWindow* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__TestOutFrameTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerWindow__UnpacketizeFullMessages(CNetLayerWindow* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerWindow*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerWindow__UnpacketizeFullMessages);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
