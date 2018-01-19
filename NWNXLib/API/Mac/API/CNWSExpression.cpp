#include "CNWSExpression.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSExpressionList.hpp"
#include "CNWSExpressionNode.hpp"

namespace NWNXLib {

namespace API {

CNWSExpression::CNWSExpression()
{
    CNWSExpression__CNWSExpressionCtor__0(this);
}

CNWSExpression::~CNWSExpression()
{
    CNWSExpression__CNWSExpressionDtor__0(this);
}

void CNWSExpression::ClearAlternate(CNWSExpressionNode* a0)
{
    return CNWSExpression__ClearAlternate(this, a0);
}

void CNWSExpression::ClearGraph()
{
    return CNWSExpression__ClearGraph(this);
}

CNWSExpressionNode* CNWSExpression::NewNode(int32_t a0)
{
    return CNWSExpression__NewNode(this, a0);
}

int32_t CNWSExpression::ParseString(CExoString a0)
{
    return CNWSExpression__ParseString(this, a0);
}

int32_t CNWSExpression::TestString(const CExoString& a0, int32_t a1)
{
    return CNWSExpression__TestString(this, a0, a1);
}

void CNWSExpression__CNWSExpressionCtor__0(CNWSExpression* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpression*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__CNWSExpressionCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSExpression__CNWSExpressionDtor__0(CNWSExpression* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpression*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__CNWSExpressionDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSExpression__ClearAlternate(CNWSExpression* thisPtr, CNWSExpressionNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpression*, CNWSExpressionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__ClearAlternate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSExpression__ClearGraph(CNWSExpression* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpression*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__ClearGraph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSExpressionNode* CNWSExpression__NewNode(CNWSExpression* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSExpressionNode*(__attribute__((cdecl)) *)(CNWSExpression*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__NewNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSExpression__ParseString(CNWSExpression* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSExpression*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__ParseString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSExpression__TestString(CNWSExpression* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSExpression*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpression__TestString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
