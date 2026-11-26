// Standalone tests for the Chess plugin's rules (Game) and engine (Engine) code.
// Build: cmake --build <build dir> --target ChessTests
// Run:   <build dir>/Plugins/Chess/ChessTests [path to stockfish]
// Without a Stockfish binary (argument, NWNX_CHESS_STOCKFISH_PATH or `stockfish` on PATH) the engine
// tests that need a real engine are skipped; the rest still run.

#include "Engine.hpp"
#include "Game.hpp"

#include "chess.hpp"

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include <cerrno>

#include <dirent.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <unistd.h>

using Chess::Game;
using Chess::Status;

static int s_failures = 0;
static int s_checks = 0;

#define CHECK(cond)                                                                \
    do                                                                             \
    {                                                                              \
        s_checks++;                                                                \
        if (!(cond))                                                               \
        {                                                                          \
            s_failures++;                                                          \
            std::printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond);          \
        }                                                                          \
    } while (0)

#define CHECK_EQ(a, b)                                                             \
    do                                                                             \
    {                                                                              \
        s_checks++;                                                                \
        const auto _a = (a);                                                       \
        const auto _b = (b);                                                       \
        if (!(_a == _b))                                                           \
        {                                                                          \
            s_failures++;                                                          \
            std::printf("  FAIL %s:%d: %s == %s\n", __FILE__, __LINE__, #a, #b);   \
        }                                                                          \
    } while (0)

static bool Has(const std::vector<std::string>& v, const std::string& s)
{
    return std::find(v.begin(), v.end(), s) != v.end();
}

static bool Play(Game& g, const std::vector<std::string>& moves)
{
    for (const auto& m : moves)
    {
        if (!g.MakeMove(m))
        {
            std::printf("  move %s refused\n", m.c_str());
            return false;
        }
    }
    return true;
}

// Perft straight on the library.
static uint64_t PerftBoard(chess::Board& board, int depth)
{
    chess::Movelist moves;
    chess::movegen::legalmoves(moves, board);
    if (depth == 1)
        return moves.size();
    uint64_t nodes = 0;
    for (const auto& move : moves)
    {
        board.makeMove(move);
        nodes += PerftBoard(board, depth - 1);
        board.unmakeMove(move);
    }
    return nodes;
}

// Perft through the plugin's own API (UCI strings in and out), so the UCI round trip is covered too.
static uint64_t PerftGame(const std::string& fen, const std::vector<std::string>& line, int depth)
{
    Game g;
    g.Load(fen);
    Play(g, line);
    auto moves = g.GetLegalMoves();
    if (depth == 1)
        return moves.size();
    uint64_t nodes = 0;
    for (const auto& move : moves)
    {
        auto next = line;
        next.push_back(move);
        nodes += PerftGame(fen, next, depth - 1);
    }
    return nodes;
}

static void TestPerft()
{
    std::printf("perft\n");
    const std::string start = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    const std::string kiwipete = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
    const std::string pos3 = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1";
    const std::string pos4 = "r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1";

    chess::Board board(start);
    CHECK_EQ(PerftBoard(board, 1), 20u);
    CHECK_EQ(PerftBoard(board, 2), 400u);
    CHECK_EQ(PerftBoard(board, 3), 8902u);
    CHECK_EQ(PerftBoard(board, 4), 197281u);
    board = chess::Board(kiwipete);
    CHECK_EQ(PerftBoard(board, 3), 97862u);
    board = chess::Board(pos3);
    CHECK_EQ(PerftBoard(board, 4), 43238u);
    board = chess::Board(pos4);
    CHECK_EQ(PerftBoard(board, 3), 9467u);

    CHECK_EQ(PerftGame(start, {}, 3), 8902u);
    CHECK_EQ(PerftGame(kiwipete, {}, 2), 2039u);
    CHECK_EQ(PerftGame(pos4, {}, 2), 264u);
}

static void TestStart()
{
    std::printf("start position\n");
    Game g;
    CHECK_EQ(g.GetStatus(), Status::Playing);
    CHECK(g.GetSideToMove() == Chess::Side::White);
    CHECK_EQ(g.GetPieceAt("e1"), std::string("wk"));
    CHECK_EQ(g.GetPieceAt("d8"), std::string("bq"));
    CHECK_EQ(g.GetPieceAt("b1"), std::string("wn"));
    CHECK_EQ(g.GetPieceAt("h7"), std::string("bp"));
    CHECK_EQ(g.GetPieceAt("E2"), std::string("wp"));
    CHECK_EQ(g.GetPieceAt("e4"), std::string(""));
    CHECK_EQ(g.GetPieceAt("i9"), std::string(""));
    CHECK_EQ(g.GetPieceAt(""), std::string(""));
    CHECK_EQ(g.GetLegalMoves().size(), 20u);
    CHECK_EQ(g.GetLegalMoves("g1").size(), 2u);
    CHECK(Has(g.GetLegalMoves("g1"), "g1f3"));
    CHECK(g.GetLegalMoves("e1").empty());
    CHECK(g.GetLegalMoves("e7").empty()); // not black's turn
    CHECK(g.GetLegalMoves("z9").empty());
    CHECK(!g.MakeMove("e2e5"));
    CHECK(!g.MakeMove("e7e5"));
    CHECK(!g.MakeMove("garbage"));
    CHECK(!g.MakeMove(""));
    CHECK(g.MakeMove("E2E4"));
    CHECK(g.GetSideToMove() == Chess::Side::Black);
    CHECK_EQ(g.GetFEN(), std::string("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1"));
    CHECK(Play(g, {"e7e5", "g1f3"}));
    CHECK_EQ(g.GetPGN(), std::string("1. e4 e5 2. Nf3 *"));
    CHECK_EQ(g.GetUciPosition(),
             std::string("position fen rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves e2e4 e7e5 g1f3"));
    CHECK_EQ(g.GetMoves().size(), 3u);
}

static void TestMate()
{
    std::printf("checkmate\n");
    Game g;
    CHECK(Play(g, {"f2f3", "e7e5", "g2g4"}));
    CHECK_EQ(g.GetStatus(), Status::Playing);
    CHECK(g.MakeMove("d8h4"));
    CHECK_EQ(g.GetStatus(), Status::Checkmate);
    CHECK(g.IsOver());
    CHECK(g.GetLegalMoves().empty());
    CHECK(!g.MakeMove("e1f2"));
    CHECK_EQ(g.GetPGN(), std::string("1. f3 e5 2. g4 Qh4# 0-1"));

    // Scholar's mate, white wins.
    Game s;
    CHECK(Play(s, {"e2e4", "e7e5", "f1c4", "b8c6", "d1h5", "g8f6"}));
    CHECK(s.MakeMove("h5f7"));
    CHECK_EQ(s.GetStatus(), Status::Checkmate);
    CHECK_EQ(s.GetPGN(), std::string("1. e4 e5 2. Bc4 Nc6 3. Qh5 Nf6 4. Qxf7# 1-0"));

    // Check, not mate.
    Game c;
    CHECK(Play(c, {"e2e4", "f7f6", "d1h5"}));
    CHECK_EQ(c.GetStatus(), Status::Check);
    CHECK(!c.IsOver());
    CHECK_EQ(c.GetLegalMoves().size(), 1u); // only g7g6 blocks
    CHECK(Has(c.GetLegalMoves(), "g7g6"));
}

static void TestStalemate()
{
    std::printf("stalemate\n");
    Game g;
    CHECK(g.Load("7k/8/6K1/8/8/8/8/5Q2 w - - 0 1"));
    CHECK(g.MakeMove("f1f7"));
    CHECK_EQ(g.GetStatus(), Status::Stalemate);
    CHECK(g.IsOver());
    CHECK(g.GetLegalMoves().empty());
    CHECK_EQ(g.GetPGN(), std::string("[SetUp \"1\"]\n[FEN \"7k/8/6K1/8/8/8/8/5Q2 w - - 0 1\"]\n\n1. Qf7 1/2-1/2"));
}

static void TestEnPassant()
{
    std::printf("en passant\n");
    Game g;
    CHECK(Play(g, {"e2e4", "a7a6", "e4e5", "d7d5"}));
    CHECK(Has(g.GetLegalMoves("e5"), "e5d6"));
    CHECK(g.MakeMove("e5d6"));
    CHECK_EQ(g.GetPieceAt("d5"), std::string(""));
    CHECK_EQ(g.GetPieceAt("d6"), std::string("wp"));
    CHECK_EQ(g.GetPGN(), std::string("1. e4 a6 2. e5 d5 3. exd6 *"));

    // Only right after the double step.
    Game late;
    CHECK(Play(late, {"e2e4", "a7a6", "e4e5", "d7d5", "a2a3", "a6a5"}));
    CHECK(!Has(late.GetLegalMoves("e5"), "e5d6"));
    CHECK(!late.MakeMove("e5d6"));

    // Not when it would expose the king along the rank.
    Game pinned;
    CHECK(pinned.Load("8/8/8/KPp4r/8/8/8/7k w - c6 0 2"));
    CHECK(!Has(pinned.GetLegalMoves("b5"), "b5c6"));
    CHECK(Has(pinned.GetLegalMoves("b5"), "b5b6"));

    // From a FEN with the en passant square.
    Game fen;
    CHECK(fen.Load("rnbqkbnr/ppp1p1pp/8/3pPp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3"));
    CHECK(Has(fen.GetLegalMoves("e5"), "e5f6"));
    CHECK(!Has(fen.GetLegalMoves("e5"), "e5d6"));
}

static void TestCastling()
{
    std::printf("castling\n");
    Game g;
    CHECK(g.Load("r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1"));
    CHECK(Has(g.GetLegalMoves("e1"), "e1g1"));
    CHECK(Has(g.GetLegalMoves("e1"), "e1c1"));
    CHECK(g.MakeMove("e1g1"));
    CHECK_EQ(g.GetPieceAt("g1"), std::string("wk"));
    CHECK_EQ(g.GetPieceAt("f1"), std::string("wr"));
    CHECK_EQ(g.GetPieceAt("h1"), std::string(""));
    CHECK_EQ(g.GetPieceAt("e1"), std::string(""));
    CHECK(g.MakeMove("e8c8"));
    CHECK_EQ(g.GetPieceAt("c8"), std::string("bk"));
    CHECK_EQ(g.GetPieceAt("d8"), std::string("br"));
    CHECK_EQ(g.GetPieceAt("a8"), std::string(""));
    CHECK_EQ(g.GetFEN(), std::string("2kr3r/8/8/8/8/8/8/R4RK1 w - - 2 2"));
    CHECK_EQ(g.GetPGN(), std::string("[SetUp \"1\"]\n[FEN \"r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1\"]\n\n1. O-O O-O-O *"));

    // Through check: f1 is attacked by the rook on f8.
    Game through;
    CHECK(through.Load("4kr2/8/8/8/8/8/8/R3K2R w KQ - 0 1"));
    CHECK(!Has(through.GetLegalMoves("e1"), "e1g1"));
    CHECK(!through.MakeMove("e1g1"));
    CHECK(Has(through.GetLegalMoves("e1"), "e1c1"));

    // Into check: g1 attacked.
    Game into;
    CHECK(into.Load("4k1r1/8/8/8/8/8/8/R3K2R w KQ - 0 1"));
    CHECK(!into.MakeMove("e1g1"));
    CHECK(into.MakeMove("e1c1"));

    // Out of check.
    Game out;
    CHECK(out.Load("4r1k1/8/8/8/8/8/8/R3K2R w KQ - 0 1"));
    CHECK_EQ(out.GetStatus(), Status::Check);
    CHECK(!out.MakeMove("e1g1"));
    CHECK(!out.MakeMove("e1c1"));

    // Queenside through b1 is fine (only the king's path matters), a piece in between is not.
    Game b1;
    CHECK(b1.Load("1r2k3/8/8/8/8/8/8/R3K3 w Q - 0 1"));
    CHECK(b1.MakeMove("e1c1"));
    Game blocked;
    CHECK(blocked.Load("4k3/8/8/8/8/8/8/RN2K3 w Q - 0 1"));
    CHECK(!blocked.MakeMove("e1c1"));

    // Rights lost after the king or rook moves.
    Game lost;
    CHECK(lost.Load("r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1"));
    CHECK(Play(lost, {"h1h2", "a8a7", "h2h1", "a7a8"}));
    CHECK(!Has(lost.GetLegalMoves("e1"), "e1g1"));
    CHECK(Has(lost.GetLegalMoves("e1"), "e1c1"));
    CHECK(Play(lost, {"e1d1", "e8d8", "d1e1", "d8e8"}));
    CHECK(!Has(lost.GetLegalMoves("e1"), "e1c1"));
}

static void TestPromotion()
{
    std::printf("promotion\n");
    Game g;
    CHECK(g.Load("8/P7/8/8/8/8/8/k6K w - - 0 1"));
    auto moves = g.GetLegalMoves("a7");
    CHECK_EQ(moves.size(), 4u);
    CHECK(Has(moves, "a7a8q") && Has(moves, "a7a8r") && Has(moves, "a7a8b") && Has(moves, "a7a8n"));
    CHECK(!g.MakeMove("a7a8"));  // the piece must be given
    CHECK(!g.MakeMove("a7a8k"));
    CHECK(g.MakeMove("a7a8N"));
    CHECK_EQ(g.GetPieceAt("a8"), std::string("wn"));
    CHECK_EQ(g.GetPieceAt("a7"), std::string(""));

    Game q;
    CHECK(q.Load("1n6/P7/8/8/8/8/8/k6K w - - 0 1"));
    CHECK(q.MakeMove("a7b8q")); // capture and promote
    CHECK_EQ(q.GetPieceAt("b8"), std::string("wq"));
    CHECK_EQ(q.GetPGN(), std::string("[SetUp \"1\"]\n[FEN \"1n6/P7/8/8/8/8/8/k6K w - - 0 1\"]\n\n1. axb8=Q *"));

    Game black;
    CHECK(black.Load("K6k/8/8/8/8/8/p7/8 b - - 0 1"));
    CHECK(black.MakeMove("a2a1q"));
    CHECK_EQ(black.GetPieceAt("a1"), std::string("bq"));
}

static void TestDraws()
{
    std::printf("draws\n");
    // Threefold repetition: the start position occurs a third time after 8 plies.
    Game r;
    CHECK(Play(r, {"g1f3", "g8f6", "f3g1", "f6g8"}));
    CHECK_EQ(r.GetStatus(), Status::Playing); // twice
    CHECK(Play(r, {"g1f3", "g8f6", "f3g1"}));
    CHECK_EQ(r.GetStatus(), Status::Playing);
    CHECK(r.MakeMove("f6g8"));
    CHECK_EQ(r.GetStatus(), Status::DrawRepetition);
    CHECK(r.IsOver());
    CHECK(!r.MakeMove("e2e4"));
    CHECK(r.GetPGN().size() > 0 && r.GetPGN().substr(r.GetPGN().size() - 7) == "1/2-1/2");

    // Fifty-move rule.
    Game f;
    CHECK(f.Load("4k3/8/8/8/8/8/8/R3K3 w - - 99 80"));
    CHECK_EQ(f.GetStatus(), Status::Playing);
    CHECK(f.MakeMove("a1a2"));
    CHECK_EQ(f.GetStatus(), Status::DrawFiftyMove);
    Game pawnMove;
    CHECK(pawnMove.Load("4k3/8/8/8/8/8/P7/R3K3 w - - 99 80"));
    CHECK(pawnMove.MakeMove("a2a3")); // resets the clock
    CHECK_EQ(pawnMove.GetStatus(), Status::Playing);

    // Mate on the hundredth half-move is mate.
    Game m;
    CHECK(m.Load("k7/8/1K6/8/8/8/8/7R w - - 99 80"));
    CHECK(m.MakeMove("h1h8"));
    CHECK_EQ(m.GetStatus(), Status::Checkmate);

    // Insufficient material.
    Game kk;
    CHECK(kk.Load("8/8/8/8/8/8/8/K1k5 w - - 0 1"));
    CHECK_EQ(kk.GetStatus(), Status::DrawInsufficient);
    Game kn;
    CHECK(kn.Load("8/8/8/8/8/8/8/KNk5 b - - 0 1"));
    CHECK_EQ(kn.GetStatus(), Status::DrawInsufficient);
    Game kb;
    CHECK(kb.Load("8/8/8/4b3/8/8/8/K1k5 w - - 0 1"));
    CHECK_EQ(kb.GetStatus(), Status::DrawInsufficient);
    Game kbkb;
    CHECK(kbkb.Load("8/4b3/8/8/8/2B5/8/K1k5 w - - 0 1")); // e7 and c3 are both dark
    CHECK_EQ(kbkb.GetStatus(), Status::DrawInsufficient);
    Game kbkbOpp;
    CHECK(kbkbOpp.Load("8/4b3/8/8/8/3B4/8/K1k5 w - - 0 1")); // e7 dark, d3 light
    CHECK_EQ(kbkbOpp.GetStatus(), Status::Playing);
    Game kr;
    CHECK(kr.Load("8/8/8/8/8/8/8/KRk5 b - - 0 1"));
    CHECK(kr.GetStatus() != Status::DrawInsufficient);
    Game kp;
    CHECK(kp.Load("8/8/8/8/8/8/P7/K1k5 w - - 0 1"));
    CHECK_EQ(kp.GetStatus(), Status::Playing);
    // By capture.
    Game cap;
    CHECK(cap.Load("8/8/8/8/8/8/8/Kq5k w - - 0 1"));
    CHECK(cap.MakeMove("a1b1"));
    CHECK_EQ(cap.GetStatus(), Status::DrawInsufficient);
}

static void TestFen()
{
    std::printf("FEN\n");
    Game g;
    const std::string fen = "r1bqkbnr/pppp1ppp/2n5/4p3/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq - 2 3";
    CHECK(g.Load(fen));
    CHECK_EQ(g.GetFEN(), fen);
    CHECK_EQ(g.GetSideToMove(), Chess::Side::White);
    CHECK(g.Load("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -")); // counters optional
    CHECK_EQ(g.GetFEN(), std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));

    // Black to move: PGN numbering starts with "N...".
    Game b;
    CHECK(b.Load("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1"));
    CHECK(Play(b, {"c7c5", "g1f3"}));
    CHECK_EQ(b.GetPGN().substr(b.GetPGN().find("\n\n") + 2), std::string("1... c5 2. Nf3 *"));

    const std::vector<std::string> bad = {
        "garbage",
        "8/8/8/8/8/8/8/8 w - - 0 1",                                   // no kings
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1BNR w kq - 0 1",      // no white king
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR x KQkq - 0 1",    // side
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq e9 0 1",   // ep square
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBN1 w KQkq - 0 1",    // K right without the h1 rook
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkqX - 0 1",   // castling field
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNRR w KQkq - 0 1",   // 9 files
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP w KQkq - 0 1",             // 7 ranks
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/8 w KQkq - 0 1",  // 9 ranks
        "rnbqkbnP/pppppppp/8/8/8/8/PPPPPPP1/RNBQKBNR w KQq - 0 1",     // pawn on the 8th rank
        "4k3/8/8/8/8/8/8/4K2R b K - 0 1",                              // fine, as a control
        "4k2R/8/8/8/8/8/8/4K3 w - - 0 1",                              // white to move, black in check
        "4k3/8/8/8/8/8/8/4K3 w - - x 1",                               // counter
        "4k3/8/8/8/8/8/8/4K3 w - - 0 0",                               // full move 0
    };
    for (size_t i = 0; i < bad.size(); i++)
    {
        Game t;
        const bool loaded = t.Load(bad[i]);
        if (bad[i] == "4k3/8/8/8/8/8/8/4K2R b K - 0 1")
            CHECK(loaded);
        else if (loaded)
        {
            s_failures++;
            std::printf("  FAIL: accepted bad FEN '%s'\n", bad[i].c_str());
        }
        s_checks++;
    }

    // A failed load leaves the game as it was.
    Game keep;
    CHECK(keep.MakeMove("e2e4"));
    CHECK(!keep.Load("garbage"));
    CHECK_EQ(keep.GetMoves().size(), 1u);
    CHECK_EQ(keep.GetPieceAt("e4"), std::string("wp"));
}

// ---------------------------------------------------------------- engine

struct Collector
{
    std::mutex mutex;
    std::condition_variable cv;
    std::map<uint64_t, Chess::EngineResult> results;

    void Add(Chess::EngineResult&& r)
    {
        std::lock_guard<std::mutex> lock(mutex);
        results[r.requestId] = std::move(r);
        cv.notify_all();
    }

    bool Wait(uint64_t id, int ms, Chess::EngineResult& out)
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (!cv.wait_for(lock, std::chrono::milliseconds(ms), [&]() { return results.count(id) > 0; }))
            return false;
        out = results[id];
        return true;
    }
};

static std::unique_ptr<Chess::Engine> MakeEngine(const std::string& path, Collector& c)
{
    Chess::EngineConfig config;
    config.path = path;
    return std::make_unique<Chess::Engine>(
        config, [&c](Chess::EngineResult&& r) { c.Add(std::move(r)); },
        [](Chess::Engine::LogLevel, const std::string& msg) { std::printf("  [engine] %s\n", msg.c_str()); });
}

static void TestEngineMissing()
{
    std::printf("engine: missing binary\n");
    CHECK_EQ(Chess::Engine::FindBinary("no-such-chess-engine-xyz"), std::string(""));
    CHECK_EQ(Chess::Engine::FindBinary("/nonexistent/stockfish"), std::string(""));
    CHECK(Chess::Engine::FindBinary("sh") != "");

    Collector c;
    auto engine = MakeEngine("/nonexistent/stockfish", c);
    Chess::EngineRequest req;
    req.requestId = 1;
    req.gameId = 1;
    req.position = "position startpos";
    std::string error;
    CHECK(!engine->Submit(req, error));
    CHECK(!error.empty());
    std::printf("  error: %s\n", error.c_str());
}

static void TestEngineNotUci()
{
    std::printf("engine: not a UCI engine (/bin/true)\n");
    Collector c;
    auto engine = MakeEngine("/bin/true", c);
    Chess::EngineRequest req;
    req.requestId = 1;
    req.gameId = 1;
    req.position = "position startpos";
    std::string error;
    CHECK(engine->Submit(req, error));
    Chess::EngineResult r;
    CHECK(c.Wait(1, 15000, r));
    CHECK(!r.success);
    std::printf("  error: %s\n", r.error.c_str());
}

static void TestEngineHang(const std::string& dir)
{
    std::printf("engine: hangs while searching (fake engine)\n");
    const auto script = dir + "/fake-engine.sh";
    {
        std::ofstream out(script);
        out << "#!/bin/sh\n"
               "while read line; do\n"
               "  case \"$line\" in\n"
               "    uci) echo uciok ;;\n"
               "    isready) echo readyok ;;\n"
               "    quit) exit 0 ;;\n"
               "  esac\n"
               "done\n";
    }
    chmod(script.c_str(), 0755);

    Collector c;
    auto engine = MakeEngine(script, c);
    Chess::EngineRequest req;
    req.requestId = 7;
    req.gameId = 3;
    req.position = "position startpos";
    req.moveTimeMs = 100;
    std::string error;
    const auto start = std::chrono::steady_clock::now();
    CHECK(engine->Submit(req, error));
    Chess::EngineResult r;
    CHECK(c.Wait(7, 20000, r));
    CHECK(!r.success);
    std::printf("  error after %lld ms: %s\n",
                (long long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count(),
                r.error.c_str());
    // Stopping while idle is quick.
    const auto stopStart = std::chrono::steady_clock::now();
    engine->Stop();
    CHECK(std::chrono::steady_clock::now() - stopStart < std::chrono::seconds(2));
}

static void TestEngineStockfish(const std::string& path)
{
    std::printf("engine: stockfish (%s)\n", path.c_str());
    Collector c;
    auto engine = MakeEngine(path, c);
    std::string error;

    // Best move from the start: legal.
    Game g;
    Chess::EngineRequest req;
    req.requestId = 1;
    req.gameId = 1;
    req.position = g.GetUciPosition();
    req.skill = 20;
    req.moveTimeMs = 200;
    const auto start = std::chrono::steady_clock::now();
    CHECK(engine->Submit(req, error));
    const auto submitTime = std::chrono::steady_clock::now() - start;
    CHECK(submitTime < std::chrono::milliseconds(50)); // never blocks the caller
    Chess::EngineResult r;
    CHECK(c.Wait(1, 15000, r));
    CHECK(r.success);
    CHECK(Has(g.GetLegalMoves(), r.move));
    std::printf("  start position: %s (%s)\n", r.move.c_str(), r.error.c_str());

    // Every thread of the engine runs at the configured nice (it is per thread on Linux).
    int engineTasks = 0, lowNice = 0;
    if (DIR* proc = opendir("/proc"))
    {
        while (auto* p = readdir(proc))
        {
            const std::string dir = std::string("/proc/") + p->d_name;
            std::ifstream status(dir + "/status");
            std::string field;
            int ppid = -1;
            while (status >> field)
                if (field == "PPid:") { status >> ppid; break; }
            if (ppid != getpid())
                continue;
            if (DIR* tasks = opendir((dir + "/task").c_str()))
            {
                while (auto* t = readdir(tasks))
                {
                    if (t->d_name[0] == '.')
                        continue;
                    engineTasks++;
                    errno = 0;
                    const int ni = getpriority(PRIO_PROCESS, static_cast<id_t>(std::atoi(t->d_name)));
                    if (errno == 0 && ni < getpriority(PRIO_PROCESS, 0) + 10)
                        lowNice++;
                }
                closedir(tasks);
            }
        }
        closedir(proc);
    }
    std::printf("  engine threads: %d, below the configured nice: %d\n", engineTasks, lowNice);
    CHECK(engineTasks > 1);
    CHECK_EQ(lowNice, 0);

    // Mate in one at full strength.
    Game m;
    CHECK(m.Load("6k1/5ppp/8/8/8/8/5PPP/R5K1 w - - 0 1"));
    req.requestId = 2;
    req.gameId = 2;
    req.position = m.GetUciPosition();
    req.moveTimeMs = 300;
    CHECK(engine->Submit(req, error));
    CHECK(c.Wait(2, 15000, r));
    CHECK(r.success);
    CHECK_EQ(r.move, std::string("a1a8"));
    CHECK(m.MakeMove(r.move));
    CHECK_EQ(m.GetStatus(), Status::Checkmate);

    // Promotion comes back with the piece letter (a8=Q or a8=R mates).
    Game p;
    CHECK(p.Load("7k/P5pp/8/8/8/8/8/K7 w - - 0 1"));
    req.requestId = 3;
    req.gameId = 3;
    req.position = p.GetUciPosition();
    CHECK(engine->Submit(req, error));
    CHECK(c.Wait(3, 15000, r));
    CHECK(r.success && r.move.size() == 5);
    CHECK(p.MakeMove(r.move));

    // Several games queued at once, low skill: all answered with legal moves.
    std::vector<Game> games(6);
    for (size_t i = 0; i < games.size(); i++)
    {
        Play(games[i], {"e2e4", "e7e5"});
        req.requestId = 100 + i;
        req.gameId = 100 + static_cast<int32_t>(i);
        req.position = games[i].GetUciPosition();
        req.skill = static_cast<int32_t>(i);
        req.moveTimeMs = 50;
        CHECK(engine->Submit(req, error));
    }
    for (size_t i = 0; i < games.size(); i++)
    {
        CHECK(c.Wait(100 + i, 15000, r));
        CHECK(r.success && Has(games[i].GetLegalMoves(), r.move));
    }

    // A new request for the same game drops the one still queued.
    req.gameId = 50;
    req.position = g.GetUciPosition();
    req.moveTimeMs = 300;
    req.requestId = 200; // takes the engine
    CHECK(engine->Submit(req, error));
    req.gameId = 51;
    req.requestId = 201; // queued
    CHECK(engine->Submit(req, error));
    req.requestId = 202; // replaces 201
    CHECK(engine->Submit(req, error));
    CHECK(c.Wait(202, 15000, r));
    CHECK(r.success);
    {
        std::lock_guard<std::mutex> lock(c.mutex);
        CHECK_EQ(c.results.count(201), 0u);
    }
    // Cancel drops a queued request.
    req.gameId = 60;
    req.requestId = 300;
    CHECK(engine->Submit(req, error));
    req.gameId = 61;
    req.requestId = 301;
    CHECK(engine->Submit(req, error));
    engine->Cancel(61);
    CHECK(c.Wait(300, 15000, r));
    CHECK(!c.Wait(301, 1000, r));

    // Cancel a long search that is running: it ends at once instead of after 10 seconds.
    req.gameId = 70;
    req.requestId = 350;
    req.moveTimeMs = 10000;
    CHECK(engine->Submit(req, error));
    usleep(300000);
    auto cancelStart = std::chrono::steady_clock::now();
    engine->Cancel(70);
    CHECK(c.Wait(350, 3000, r));
    CHECK(!r.success && r.error == "cancelled");
    std::printf("  cancel during a search took %lld ms\n",
                (long long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - cancelStart).count());
    // A new request for the game being searched replaces it, and the engine then answers the new one.
    req.requestId = 351;
    CHECK(engine->Submit(req, error));
    usleep(300000);
    req.requestId = 352;
    req.moveTimeMs = 100;
    cancelStart = std::chrono::steady_clock::now();
    CHECK(engine->Submit(req, error));
    CHECK(c.Wait(351, 3000, r));
    CHECK(!r.success && r.error == "cancelled");
    CHECK(c.Wait(352, 3000, r));
    CHECK(r.success && Has(g.GetLegalMoves(), r.move));
    CHECK(std::chrono::steady_clock::now() - cancelStart < std::chrono::seconds(3));
    // Cancelling another game leaves the search alone.
    req.requestId = 353;
    req.moveTimeMs = 500;
    CHECK(engine->Submit(req, error));
    usleep(100000);
    engine->Cancel(71);
    CHECK(c.Wait(353, 5000, r));
    CHECK(r.success);

    // Kill the engine process: the next request starts a new one.
    std::printf("  killing the engine process\n");
    const auto cmd = "exec pkill -KILL -P " + std::to_string(getpid());
    CHECK(std::system(cmd.c_str()) == 0);
    usleep(200000);
    req.gameId = 1;
    req.requestId = 400;
    req.moveTimeMs = 100;
    CHECK(engine->Submit(req, error));
    CHECK(c.Wait(400, 20000, r));
    CHECK(r.success && Has(g.GetLegalMoves(), r.move));
    std::printf("  after restart: %s %s\n", r.move.c_str(), r.error.c_str());

    // Stop in the middle of a long search returns promptly.
    req.requestId = 500;
    req.moveTimeMs = 10000;
    CHECK(engine->Submit(req, error));
    usleep(300000);
    const auto stopStart = std::chrono::steady_clock::now();
    engine->Stop();
    const auto stopMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - stopStart).count();
    std::printf("  stop during a search took %lld ms\n", (long long)stopMs);
    CHECK(stopMs < 2000);
    CHECK(!engine->Submit(req, error));
}

int main(int argc, char** argv)
{
    TestPerft();
    TestStart();
    TestMate();
    TestStalemate();
    TestEnPassant();
    TestCastling();
    TestPromotion();
    TestDraws();
    TestFen();

    TestEngineMissing();
    TestEngineNotUci();
    char dir[] = "/tmp/chess-tests-XXXXXX";
    if (const char* d = mkdtemp(dir))
    {
        TestEngineHang(d);
        std::remove((std::string(d) + "/fake-engine.sh").c_str());
        rmdir(d);
    }

    std::string stockfish = argc > 1 ? argv[1] : "";
    if (stockfish.empty())
        if (const char* env = std::getenv("NWNX_CHESS_STOCKFISH_PATH"))
            stockfish = env;
    if (stockfish.empty())
        stockfish = "stockfish";
    stockfish = Chess::Engine::FindBinary(stockfish);
    if (stockfish.empty())
        std::printf("engine: stockfish not found, SKIPPED the Stockfish tests\n");
    else
        TestEngineStockfish(stockfish);

    std::printf("\n%d checks, %d failed\n", s_checks, s_failures);
    return s_failures == 0 ? 0 : 1;
}
