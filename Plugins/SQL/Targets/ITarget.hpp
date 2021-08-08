#pragma once

#include "nwnx.hpp"

#include <queue>
#include <string>
#include <vector>
#include <optional>

namespace SQL {

using Query = std::string;
using Result = std::string;
using ResultRow = std::vector<Result>;
using ResultSet = std::queue<ResultRow>; // Queue is row, vector is column

struct ITarget
{
    virtual ~ITarget() { }
    virtual void Connect() = 0;
    virtual bool IsConnected() = 0;
    virtual bool PrepareQuery(const Query& query) = 0;
    virtual std::optional<ResultSet> ExecuteQuery() = 0;
    virtual void PrepareInt(int32_t position, int32_t value) = 0;
    virtual void PrepareFloat(int32_t position, float value) = 0;
    virtual void PrepareString(int32_t position, const std::string& value) = 0;
    virtual void PrepareBinary(int32_t position, const std::vector<uint8_t>& value) = 0;
    virtual void PrepareNULL(int32_t position) = 0;
    virtual int  GetAffectedRows() = 0;
    virtual std::string GetLastError(bool bClear = false) = 0;
    virtual int32_t GetPreparedQueryParamCount() = 0;
    virtual void DestroyPreparedQuery() = 0;

};

}
