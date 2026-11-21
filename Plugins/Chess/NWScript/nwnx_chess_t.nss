#include "nwnx_chess"
#include "nwnx_tests"

void CheckEngine(int nGameId, int nTries)
{
    int nState = NWNX_Chess_GetBestMoveState(nGameId);
    if (nState == NWNX_CHESS_ENGINE_THINKING && nTries < 50)
    {
        DelayCommand(0.2f, CheckEngine(nGameId, nTries + 1));
        return;
    }

    string sMove = NWNX_Chess_GetBestMoveResult(nGameId);
    if (nState == NWNX_CHESS_ENGINE_FAILED)
        WriteTimestampedLogEntry("NWNX_Chess: the engine failed; is Stockfish installed (NWNX_CHESS_STOCKFISH_PATH)?");
    NWNX_Tests_Report("NWNX_Chess", "GetBestMoveState", nState == NWNX_CHESS_ENGINE_DONE);
    NWNX_Tests_Report("NWNX_Chess", "GetBestMoveResult", sMove == "a1a8");
    NWNX_Tests_Report("NWNX_Chess", "MakeMove (engine move)", NWNX_Chess_MakeMove(nGameId, sMove));
    NWNX_Tests_Report("NWNX_Chess", "GetStatus (engine mate)", NWNX_Chess_GetStatus(nGameId) == NWNX_CHESS_STATUS_CHECKMATE);
    NWNX_Chess_EndGame(nGameId);

    WriteTimestampedLogEntry("NWNX_Chess unit test end.");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Chess unit test begin..");

    int nGame = NWNX_Chess_NewGame();
    NWNX_Tests_Report("NWNX_Chess", "NewGame", nGame > 0);
    NWNX_Tests_Report("NWNX_Chess", "GetStatus", NWNX_Chess_GetStatus(nGame) == NWNX_CHESS_STATUS_PLAYING);
    NWNX_Tests_Report("NWNX_Chess", "GetSideToMove", NWNX_Chess_GetSideToMove(nGame) == NWNX_CHESS_COLOR_WHITE);
    NWNX_Tests_Report("NWNX_Chess", "GetPieceAt", NWNX_Chess_GetPieceAt(nGame, "e1") == "wk" &&
                                                  NWNX_Chess_GetPieceAt(nGame, "d8") == "bq" &&
                                                  NWNX_Chess_GetPieceAt(nGame, "e4") == "");
    NWNX_Tests_Report("NWNX_Chess", "GetLegalMoves", JsonGetLength(NWNX_Chess_GetLegalMoves(nGame)) == 20);
    NWNX_Tests_Report("NWNX_Chess", "GetLegalMoves (square)", NWNX_Chess_GetLegalMoves(nGame, "g1") == JsonParse("[\"g1h3\",\"g1f3\"]") ||
                                                              NWNX_Chess_GetLegalMoves(nGame, "g1") == JsonParse("[\"g1f3\",\"g1h3\"]"));
    NWNX_Tests_Report("NWNX_Chess", "MakeMove (illegal)", !NWNX_Chess_MakeMove(nGame, "e2e5"));

    // Fool's mate.
    NWNX_Tests_Report("NWNX_Chess", "MakeMove", NWNX_Chess_MakeMove(nGame, "f2f3") &&
                                                NWNX_Chess_MakeMove(nGame, "e7e5") &&
                                                NWNX_Chess_MakeMove(nGame, "g2g4"));
    NWNX_Tests_Report("NWNX_Chess", "GetSideToMove (black)", NWNX_Chess_GetSideToMove(nGame) == NWNX_CHESS_COLOR_BLACK);
    NWNX_Tests_Report("NWNX_Chess", "GetFEN", NWNX_Chess_GetFEN(nGame) == "rnbqkbnr/pppp1ppp/8/4p3/6P1/5P2/PPPPP2P/RNBQKBNR b KQkq - 0 2");
    NWNX_Tests_Report("NWNX_Chess", "MakeMove (mate)", NWNX_Chess_MakeMove(nGame, "d8h4"));
    NWNX_Tests_Report("NWNX_Chess", "GetStatus (checkmate)", NWNX_Chess_GetStatus(nGame) == NWNX_CHESS_STATUS_CHECKMATE);
    NWNX_Tests_Report("NWNX_Chess", "GetPGN", NWNX_Chess_GetPGN(nGame) == "1. f3 e5 2. g4 Qh4# 0-1");
    NWNX_Tests_Report("NWNX_Chess", "GetMoves", NWNX_Chess_GetMoves(nGame) == JsonParse("[\"f2f3\",\"e7e5\",\"g2g4\",\"d8h4\"]"));
    NWNX_Tests_Report("NWNX_Chess", "GetLegalMoves (game over)", JsonGetLength(NWNX_Chess_GetLegalMoves(nGame)) == 0);
    NWNX_Tests_Report("NWNX_Chess", "RequestBestMove (game over)", !NWNX_Chess_RequestBestMove(nGame, 20, 100));
    NWNX_Chess_EndGame(nGame);
    NWNX_Tests_Report("NWNX_Chess", "EndGame", NWNX_Chess_GetStatus(nGame) == NWNX_CHESS_STATUS_INVALID);

    // Stalemate from a FEN.
    nGame = NWNX_Chess_NewGame("7k/8/6K1/8/8/8/8/5Q2 w - - 0 1");
    NWNX_Tests_Report("NWNX_Chess", "NewGame (FEN)", nGame > 0);
    NWNX_Chess_MakeMove(nGame, "f1f7");
    NWNX_Tests_Report("NWNX_Chess", "GetStatus (stalemate)", NWNX_Chess_GetStatus(nGame) == NWNX_CHESS_STATUS_STALEMATE);
    NWNX_Chess_EndGame(nGame);

    // Promotion.
    nGame = NWNX_Chess_NewGame("8/P7/8/8/8/8/8/k6K w - - 0 1");
    NWNX_Tests_Report("NWNX_Chess", "MakeMove (promotion without piece)", !NWNX_Chess_MakeMove(nGame, "a7a8"));
    NWNX_Tests_Report("NWNX_Chess", "MakeMove (promotion)", NWNX_Chess_MakeMove(nGame, "a7a8q") && NWNX_Chess_GetPieceAt(nGame, "a8") == "wq");
    NWNX_Chess_EndGame(nGame);

    NWNX_Tests_Report("NWNX_Chess", "NewGame (bad FEN)", NWNX_Chess_NewGame("not a fen") == 0);
    NWNX_Tests_Report("NWNX_Chess", "GetStatus (invalid game)", NWNX_Chess_GetStatus(-5) == NWNX_CHESS_STATUS_INVALID);

    // The engine: mate in one, polled.
    nGame = NWNX_Chess_NewGame("6k1/5ppp/8/8/8/8/5PPP/R5K1 w - - 0 1");
    NWNX_Tests_Report("NWNX_Chess", "GetBestMoveState (none)", NWNX_Chess_GetBestMoveState(nGame) == NWNX_CHESS_ENGINE_NONE);
    int bRequested = NWNX_Chess_RequestBestMove(nGame, 20, 300);
    NWNX_Tests_Report("NWNX_Chess", "RequestBestMove", bRequested);
    if (bRequested)
    {
        NWNX_Tests_Report("NWNX_Chess", "GetBestMoveResult (thinking)", NWNX_Chess_GetBestMoveResult(nGame) == "");
        DelayCommand(0.2f, CheckEngine(nGame, 0));
    }
    else
    {
        WriteTimestampedLogEntry("NWNX_Chess: RequestBestMove failed; is Stockfish installed (NWNX_CHESS_STOCKFISH_PATH)?");
        NWNX_Chess_EndGame(nGame);
        WriteTimestampedLogEntry("NWNX_Chess unit test end.");
    }
}
