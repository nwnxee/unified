#include "nwnx.hpp"

#include "Engine.hpp"
#include "Game.hpp"

#include "API/CNWSModule.hpp"
#include "API/JsonEngineStructure.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Core {
    extern bool g_CoreShuttingDown;
}

namespace {

// Keep in sync with the NWNX_CHESS_ENGINE_* constants in nwnx_chess.nss.
enum class EngineState : int32_t
{
    None     = 0, // nothing requested since the last move
    Thinking = 1,
    Done     = 2,
    Failed   = 3,
};

struct GameEntry
{
    Chess::Game game;
    uint64_t pendingRequest = 0;
    EngineState engineState = EngineState::None;
    std::string bestMove;
};

// Main thread only.
std::unordered_map<int32_t, std::unique_ptr<GameEntry>> s_games;
int32_t s_nextGameId = 1;
uint64_t s_nextRequestId = 1;
std::unique_ptr<Chess::Engine> s_engine;

const auto s_maxGames = static_cast<size_t>(std::max(Config::Get<int>("MAX_GAMES", 1000), 1));
const auto s_maxMoveTimeMs = std::max(Config::Get<int>("MAX_MOVETIME_MS", 10000), 1);

auto s_shutdown = MessageBus::Subscribe("NWNX_CORE_SIGNAL",
    [](const std::vector<std::string>& message)
    {
        if (message[0] == "ON_DESTROY_SERVER" && s_engine)
        {
            s_engine->Stop();
            s_engine.reset();
        }
    });

GameEntry* GetGame(int32_t id)
{
    auto it = s_games.find(id);
    if (it == s_games.end())
    {
        LOG_DEBUG("No chess game with id %d", id);
        return nullptr;
    }
    return it->second.get();
}

// Forgets any engine result for the game: its position has changed or it is gone.
void ResetEngine(int32_t id, GameEntry& entry)
{
    entry.pendingRequest = 0;
    entry.engineState = EngineState::None;
    entry.bestMove.clear();
    if (s_engine)
        s_engine->Cancel(id);
}

void OnEngineResult(Chess::EngineResult&& result)
{
    if (Core::g_CoreShuttingDown)
        return;

    auto it = s_games.find(result.gameId);
    if (it == s_games.end() || it->second->pendingRequest != result.requestId)
        return; // the game ended or moved on while the engine was thinking

    auto& entry = *it->second;
    entry.pendingRequest = 0;
    if (result.success)
    {
        entry.engineState = EngineState::Done;
        entry.bestMove = result.move;
    }
    else
    {
        entry.engineState = EngineState::Failed;
        entry.bestMove.clear();
        LOG_WARNING("Engine move for chess game %d failed: %s", result.gameId, result.error);
    }

    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"GAME_ID", std::to_string(result.gameId)});
    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"MOVE", entry.bestMove});
    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"SUCCESS", result.success ? "1" : "0"});
    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT",
                          {"NWNX_ON_CHESS_BESTMOVE", Utils::ObjectIDToString(Utils::GetModule()->m_idSelf)});
}

Chess::Engine* GetEngine()
{
    if (!s_engine)
    {
        Chess::EngineConfig config;
        config.path = Config::Get<std::string>("STOCKFISH_PATH", "stockfish");
        config.threads = Config::Get<int>("ENGINE_THREADS", 1);
        config.hashMb = Config::Get<int>("ENGINE_HASH_MB", 16);
        config.nice = Config::Get<int>("ENGINE_NICE", 10);

        s_engine = std::make_unique<Chess::Engine>(
            config,
            [](Chess::EngineResult&& result)
            {
                // On the engine's worker thread: hand the result to the main thread.
                Tasks::QueueOnMainThread([result = std::move(result)]() mutable { OnEngineResult(std::move(result)); });
            },
            [](Chess::Engine::LogLevel level, const std::string& message)
            {
                Tasks::QueueOnMainThread([level, message]()
                {
                    switch (level)
                    {
                        case Chess::Engine::LogLevel::Error:   LOG_ERROR("%s", message); break;
                        case Chess::Engine::LogLevel::Warning: LOG_WARNING("%s", message); break;
                        case Chess::Engine::LogLevel::Notice:  LOG_NOTICE("%s", message); break;
                        case Chess::Engine::LogLevel::Info:    LOG_INFO("%s", message); break;
                        case Chess::Engine::LogLevel::Debug:   LOG_DEBUG("%s", message); break;
                    }
                });
            });
    }
    return s_engine.get();
}

JsonEngineStructure ToJsonArray(const std::vector<std::string>& values)
{
    json array = json::array();
    for (const auto& value : values)
        array.push_back(value);
    return JsonEngineStructure(std::move(array), CExoString(""));
}

}

NWNX_EXPORT ArgumentStack NewGame(ArgumentStack&& args)
{
    const auto fen = args.extract<std::string>();

    if (s_games.size() >= s_maxGames)
    {
        LOG_ERROR("NewGame: there are already %zu chess games (NWNX_CHESS_MAX_GAMES); end some with EndGame()",
                  s_games.size());
        return 0;
    }

    auto entry = std::make_unique<GameEntry>();
    if (!entry->game.Load(fen))
    {
        LOG_WARNING("NewGame: invalid FEN '%s'", fen);
        return 0;
    }

    // Skip ids still in use after a (very unlikely) wrap-around.
    while (s_nextGameId <= 0 || s_games.count(s_nextGameId))
        s_nextGameId = s_nextGameId <= 0 ? 1 : s_nextGameId + 1;

    const auto id = s_nextGameId++;
    s_games.emplace(id, std::move(entry));
    return id;
}

NWNX_EXPORT ArgumentStack EndGame(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    if (auto* entry = GetGame(id))
    {
        ResetEngine(id, *entry);
        s_games.erase(id);
    }
    return {};
}

NWNX_EXPORT ArgumentStack MakeMove(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    const auto move = args.extract<std::string>();

    auto* entry = GetGame(id);
    if (!entry || !entry->game.MakeMove(move))
        return 0;

    ResetEngine(id, *entry);
    return 1;
}

NWNX_EXPORT ArgumentStack GetLegalMoves(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    const auto square = args.extract<std::string>();

    auto* entry = GetGame(id);
    return ToJsonArray(entry ? entry->game.GetLegalMoves(square) : std::vector<std::string>{});
}

NWNX_EXPORT ArgumentStack GetMoves(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return ToJsonArray(entry ? entry->game.GetMoves() : std::vector<std::string>{});
}

NWNX_EXPORT ArgumentStack GetFEN(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry ? entry->game.GetFEN() : std::string();
}

NWNX_EXPORT ArgumentStack GetPGN(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry ? entry->game.GetPGN() : std::string();
}

NWNX_EXPORT ArgumentStack GetStatus(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry ? static_cast<int32_t>(entry->game.GetStatus()) : -1;
}

NWNX_EXPORT ArgumentStack GetSideToMove(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry ? static_cast<int32_t>(entry->game.GetSideToMove()) : -1;
}

NWNX_EXPORT ArgumentStack GetPieceAt(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    const auto square = args.extract<std::string>();
    auto* entry = GetGame(id);
    return entry ? entry->game.GetPieceAt(square) : std::string();
}

NWNX_EXPORT ArgumentStack RequestBestMove(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    const auto skill = args.extract<int32_t>();
    const auto moveTimeMs = args.extract<int32_t>();

    auto* entry = GetGame(id);
    if (!entry)
        return 0;
    if (entry->game.IsOver())
    {
        LOG_WARNING("RequestBestMove: chess game %d is over (%s)", id, Chess::StatusName(entry->game.GetStatus()));
        return 0;
    }

    Chess::EngineRequest request;
    request.requestId = s_nextRequestId++;
    request.gameId = id;
    request.position = entry->game.GetUciPosition();
    request.skill = std::clamp(skill, 0, 20);
    request.moveTimeMs = std::clamp(moveTimeMs, 1, s_maxMoveTimeMs);

    if (Core::g_CoreShuttingDown)
        return 0;

    std::string error;
    if (!GetEngine()->Submit(request, error))
    {
        LOG_ERROR("RequestBestMove: chess game %d: %s", id, error);
        entry->pendingRequest = 0;
        entry->engineState = EngineState::Failed;
        entry->bestMove.clear();
        return 0;
    }

    entry->pendingRequest = request.requestId;
    entry->engineState = EngineState::Thinking;
    entry->bestMove.clear();
    return 1;
}

NWNX_EXPORT ArgumentStack GetBestMoveResult(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry && entry->engineState == EngineState::Done ? entry->bestMove : std::string();
}

NWNX_EXPORT ArgumentStack GetBestMoveState(ArgumentStack&& args)
{
    const auto id = args.extract<int32_t>();
    auto* entry = GetGame(id);
    return entry ? static_cast<int32_t>(entry->engineState) : -1;
}
