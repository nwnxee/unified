#include "HttpConnection.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

HttpConnection::HttpConnection()
{
    HttpConnection__HttpConnectionCtor__0(this);
}

HttpConnection::~HttpConnection()
{
    HttpConnection__HttpConnectionDtor__0(this);
}

void HttpConnection::Cancel()
{
    return HttpConnection__Cancel(this);
}

CExoString HttpConnection::Escape(const CExoString& a0)
{
    return HttpConnection__Escape(a0);
}

int32_t HttpConnection::GetIsFinished()
{
    return HttpConnection__GetIsFinished(this);
}

int32_t HttpConnection::GetIsRunning()
{
    return HttpConnection__GetIsRunning(this);
}

int32_t HttpConnection::RecycleHandle(void* a0)
{
    return HttpConnection__RecycleHandle(this, a0);
}

void HttpConnection::SetBufferSize(int32_t a0)
{
    return HttpConnection__SetBufferSize(this, a0);
}

int32_t HttpConnection::StartDownloadsAsNeeded()
{
    return HttpConnection__StartDownloadsAsNeeded(this);
}

CExoString HttpConnection::Unescape(const CExoString& a0)
{
    return HttpConnection__Unescape(a0);
}

int32_t HttpConnection::Update()
{
    return HttpConnection__Update(this);
}

uint32_t HttpConnection::WriteCallback(char* a0, uint32_t a1, uint32_t a2, void* a3)
{
    return HttpConnection__WriteCallback(a0, a1, a2, a3);
}

uint32_t HttpConnection::WriteHeaderCallback(char* a0, uint32_t a1, uint32_t a2, void* a3)
{
    return HttpConnection__WriteHeaderCallback(a0, a1, a2, a3);
}

void HttpConnection__HttpConnectionCtor__0(HttpConnection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__HttpConnectionCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void HttpConnection__HttpConnectionDtor__0(HttpConnection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpConnection*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__HttpConnectionDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void HttpConnection__Cancel(HttpConnection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__Cancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString HttpConnection__Escape(const CExoString& a0)
{
    using FuncPtrType = CExoString(*)(const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__Escape);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0);
}

int32_t HttpConnection__GetIsFinished(HttpConnection* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__GetIsFinished);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t HttpConnection__GetIsRunning(HttpConnection* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__GetIsRunning);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t HttpConnection__RecycleHandle(HttpConnection* thisPtr, void* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpConnection*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__RecycleHandle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void HttpConnection__SetBufferSize(HttpConnection* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(HttpConnection*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__SetBufferSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t HttpConnection__StartDownloadsAsNeeded(HttpConnection* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__StartDownloadsAsNeeded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString HttpConnection__Unescape(const CExoString& a0)
{
    using FuncPtrType = CExoString(*)(const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__Unescape);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0);
}

int32_t HttpConnection__Update(HttpConnection* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(HttpConnection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t HttpConnection__WriteCallback(char* a0, uint32_t a1, uint32_t a2, void* a3)
{
    using FuncPtrType = uint32_t(*)(char*, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__WriteCallback);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1, a2, a3);
}

uint32_t HttpConnection__WriteHeaderCallback(char* a0, uint32_t a1, uint32_t a2, void* a3)
{
    using FuncPtrType = uint32_t(*)(char*, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::HttpConnection__WriteHeaderCallback);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1, a2, a3);
}

}

}
