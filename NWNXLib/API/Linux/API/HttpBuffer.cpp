#include "HttpBuffer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "HttpBufferReceiver.hpp"

namespace NWNXLib {

namespace API {

HttpBuffer::HttpBuffer(const CExoString& a0, void* a1, HttpBufferReceiver* a2, uint32_t a3)
{
    HttpBuffer__HttpBufferCtor(this, a0, a1, a2, a3);
}

HttpBuffer::~HttpBuffer()
{
    HttpBuffer__HttpBufferDtor(this);
}

void HttpBuffer::Complete(CURLcode a0)
{
    return HttpBuffer__Complete(this, a0);
}

CExoString HttpBuffer::GetErrorMessage()
{
    return HttpBuffer__GetErrorMessage(this);
}

int32_t HttpBuffer::GetIsFinished()
{
    return HttpBuffer__GetIsFinished(this);
}

int32_t HttpBuffer::GetIsSuccessful()
{
    return HttpBuffer__GetIsSuccessful(this);
}

void HttpBuffer::Progress(int32_t a0, int32_t a1, int32_t a2)
{
    return HttpBuffer__Progress(this, a0, a1, a2);
}

void HttpBuffer__HttpBufferCtor(HttpBuffer* thisPtr, const CExoString& a0, void* a1, HttpBufferReceiver* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpBuffer*, const CExoString&, void*, HttpBufferReceiver*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__HttpBufferCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2, a3);
}

void HttpBuffer__HttpBufferDtor(HttpBuffer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpBuffer*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__HttpBufferDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void HttpBuffer__Complete(HttpBuffer* thisPtr, CURLcode a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpBuffer*, CURLcode);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__Complete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString HttpBuffer__GetErrorMessage(HttpBuffer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(HttpBuffer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__GetErrorMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t HttpBuffer__GetIsFinished(HttpBuffer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpBuffer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__GetIsFinished);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t HttpBuffer__GetIsSuccessful(HttpBuffer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpBuffer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__GetIsSuccessful);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void HttpBuffer__Progress(HttpBuffer* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpBuffer*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpBuffer__Progress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
