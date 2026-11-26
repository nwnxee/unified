#pragma once

// A UCI engine child process driven by a worker thread; never blocks the caller. No NWNX dependencies (Tests/).

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <functional>
#include <mutex>
#include <string>
#include <thread>

#include <sys/types.h>

namespace Chess {

struct EngineConfig
{
    std::string path = "stockfish"; // a path, or a name looked up on PATH (and /usr/games)
    int32_t threads = 1;            // UCI "Threads"
    int32_t hashMb = 16;            // UCI "Hash"
    int32_t nice = 10;              // added to the engine process's nice value, so it yields to nwserver
    size_t maxQueue = 64;           // requests waiting at most; more are refused
};

struct EngineRequest
{
    uint64_t requestId = 0;
    int32_t gameId = 0;
    std::string position;   // "position fen ... moves ..."
    int32_t skill = 20;     // Stockfish "Skill Level", 0-20
    int32_t moveTimeMs = 1000;
};

struct EngineResult
{
    uint64_t requestId = 0;
    int32_t gameId = 0;
    bool success = false;
    std::string move;       // UCI move, set on success
    std::string error;      // set on failure
};

class Engine
{
public:
    enum class LogLevel { Error, Warning, Notice, Info, Debug };
    using ResultCallback = std::function<void(EngineResult&&)>;
    using LogCallback = std::function<void(LogLevel, const std::string&)>;

    Engine(EngineConfig config, ResultCallback onResult, LogCallback onLog);
    ~Engine();
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    // Resolves the configured path or name to an executable file, "" if there is none.
    static std::string FindBinary(const std::string& configured);

    // Supersedes a queued request for the same game; false with error if no engine binary or the queue is full.
    bool Submit(EngineRequest request, std::string& error);

    // Drops a game's queued requests and stops its running search (which then fails with "cancelled").
    void Cancel(int32_t gameId);

    // Stops the worker thread and the engine process. Called by the destructor.
    void Stop();

private:
    void Run();
    void CancelLocked(int32_t gameId);
    EngineResult Search(const EngineRequest& request);
    bool EnsureStarted(std::string& error);
    bool StartProcess(std::string& error);
    void KillProcess();
    bool Send(const std::string& line);
    // Reads lines until one starts with prefix; false on EOF, error, timeout or stop.
    bool WaitFor(const std::string& prefix, int32_t timeoutMs, std::string* lineOut = nullptr);
    bool ReadLine(std::string& line, int32_t timeoutMs);
    void Log(LogLevel level, const std::string& message);

    EngineConfig m_config;
    std::string m_binary;
    ResultCallback m_onResult;
    LogCallback m_onLog;

    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::deque<EngineRequest> m_queue;
    std::atomic<bool> m_stop{false};
    int32_t m_searchingGameId = 0;       // guarded by m_mutex
    std::atomic<bool> m_abortSearch{false};
    std::thread m_thread;

    // Worker thread only.
    pid_t m_pid = -1;
    int m_toEngine = -1;
    int m_fromEngine = -1;
    std::string m_readBuffer;
    int32_t m_currentSkill = -1;
    int32_t m_lastGameId = 0;
    bool m_stopSent = false;
};

}
