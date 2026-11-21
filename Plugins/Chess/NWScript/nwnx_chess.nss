/// @addtogroup chess Chess
/// @brief Chess games (rules, FEN/PGN) and engine moves from Stockfish.
/// @{
/// @file nwnx_chess.nss

const string NWNX_Chess = "NWNX_Chess"; ///< @private

/// @name Game Status
/// @anchor chess_status
/// @{
const int NWNX_CHESS_STATUS_INVALID           = -1; ///< No game with this id.
const int NWNX_CHESS_STATUS_PLAYING           = 0;
const int NWNX_CHESS_STATUS_CHECK             = 1;  ///< The side to move is in check (the game goes on).
const int NWNX_CHESS_STATUS_CHECKMATE         = 2;  ///< The side to move has lost.
const int NWNX_CHESS_STATUS_STALEMATE         = 3;
const int NWNX_CHESS_STATUS_DRAW_REPETITION   = 4;  ///< The same position for the third time.
const int NWNX_CHESS_STATUS_DRAW_FIFTY_MOVE   = 5;  ///< 50 moves each without a capture or pawn move.
const int NWNX_CHESS_STATUS_DRAW_INSUFFICIENT = 6;  ///< Neither side can mate (K v K, K+B v K, K+N v K, same-colour bishops).
/// @}

/// @name Colors
/// @anchor chess_color
/// @{
const int NWNX_CHESS_COLOR_WHITE = 0;
const int NWNX_CHESS_COLOR_BLACK = 1;
/// @}

/// @name Engine State
/// @anchor chess_engine_state
/// @{
const int NWNX_CHESS_ENGINE_NONE     = 0; ///< Nothing requested since the last move.
const int NWNX_CHESS_ENGINE_THINKING = 1;
const int NWNX_CHESS_ENGINE_DONE     = 2; ///< The move is ready: NWNX_Chess_GetBestMoveResult().
const int NWNX_CHESS_ENGINE_FAILED   = 3; ///< No engine, or it crashed or timed out; see the server log.
/// @}

/// @brief Starts a game.
/// @param sFEN The position to start from in FEN, or "" for the standard start position.
/// A game restored from a FEN has no move history, so repetitions before it don't count; to keep them,
/// start from the original FEN and replay the moves from NWNX_Chess_GetMoves() with NWNX_Chess_MakeMove().
/// @return The game id, or 0 if sFEN is invalid or there are too many games (NWNX_CHESS_MAX_GAMES).
int NWNX_Chess_NewGame(string sFEN = "");

/// @brief Ends a game and frees it. Any engine request for it is dropped.
/// @param nGameId The game id.
void NWNX_Chess_EndGame(int nGameId);

/// @brief Plays a move for the side to move.
/// @param nGameId The game id.
/// @param sUCI The move in UCI notation: from and to square ("e2e4"), castling as the king's move
/// ("e1g1"), promotion with the piece letter ("e7e8q", also r, b, n).
/// @return TRUE if the move was played, FALSE if it is illegal, malformed or the game is over.
int NWNX_Chess_MakeMove(int nGameId, string sUCI);

/// @brief Gets the legal moves in the current position.
/// @param nGameId The game id.
/// @param sSquare Only the moves of the piece on this square ("e2"), or "" for all moves.
/// @return A json array of moves in UCI notation, empty if there are none (game over, empty square,
/// the other side's piece, invalid game).
json NWNX_Chess_GetLegalMoves(int nGameId, string sSquare = "");

/// @brief Gets the moves played since NWNX_Chess_NewGame().
/// @param nGameId The game id.
/// @return A json array of moves in UCI notation.
json NWNX_Chess_GetMoves(int nGameId);

/// @brief Gets the current position.
/// @param nGameId The game id.
/// @return The position in FEN, "" for an invalid game.
string NWNX_Chess_GetFEN(int nGameId);

/// @brief Gets the game's moves as PGN movetext with the result ("1. e4 e5 2. Nf3 *").
/// @note A game that didn't start from the standard position starts with SetUp and FEN tags.
/// Add other tags (Event, White, Black, ...) in front yourself.
/// @param nGameId The game id.
/// @return The PGN, "" for an invalid game.
string NWNX_Chess_GetPGN(int nGameId);

/// @brief Gets the game status.
/// @param nGameId The game id.
/// @return A @ref chess_status "NWNX_CHESS_STATUS_*" constant.
int NWNX_Chess_GetStatus(int nGameId);

/// @brief Gets the side to move.
/// @param nGameId The game id.
/// @return NWNX_CHESS_COLOR_WHITE or NWNX_CHESS_COLOR_BLACK, -1 for an invalid game.
int NWNX_Chess_GetSideToMove(int nGameId);

/// @brief Gets the piece on a square.
/// @param nGameId The game id.
/// @param sSquare The square, "a1" to "h8".
/// @return The colour (w or b) and the piece (p, n, b, r, q, k), e.g. "wq" or "bn"; "" if the square
/// is empty or invalid.
string NWNX_Chess_GetPieceAt(int nGameId, string sSquare);

/// @brief Asks the chess engine (Stockfish) for a move for the side to move. Returns at once: the
/// engine thinks on its own thread. When it is done, NWNX_Chess_GetBestMoveResult() returns the move
/// and the NWNX_ON_CHESS_BESTMOVE event fires (see the plugin's README).
/// @note The move isn't played: play it with NWNX_Chess_MakeMove(). A move played, a new request or
/// NWNX_Chess_EndGame() before the engine is done stops the search and discards its answer.
/// @param nGameId The game id.
/// @param nSkill Stockfish's Skill Level, 0 (weakest) to 20 (full strength).
/// @param nMoveTimeMs How long the engine may think, in milliseconds (capped by NWNX_CHESS_MAX_MOVETIME_MS).
/// @return TRUE if the request was queued; FALSE if the game is invalid or over, Stockfish is not
/// installed or too many requests are waiting (logged).
int NWNX_Chess_RequestBestMove(int nGameId, int nSkill = 20, int nMoveTimeMs = 1000);

/// @brief Gets the engine's move for the last NWNX_Chess_RequestBestMove().
/// @param nGameId The game id.
/// @return The move in UCI notation, or "" while the engine is thinking, if it failed or nothing
/// was requested (see NWNX_Chess_GetBestMoveState()).
string NWNX_Chess_GetBestMoveResult(int nGameId);

/// @brief Gets the state of the last NWNX_Chess_RequestBestMove().
/// @param nGameId The game id.
/// @return A @ref chess_engine_state "NWNX_CHESS_ENGINE_*" constant, -1 for an invalid game.
int NWNX_Chess_GetBestMoveState(int nGameId);

/// @}

int NWNX_Chess_NewGame(string sFEN = "")
{
    NWNXPushString(sFEN);
    NWNXCall(NWNX_Chess, "NewGame");
    return NWNXPopInt();
}

void NWNX_Chess_EndGame(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "EndGame");
}

int NWNX_Chess_MakeMove(int nGameId, string sUCI)
{
    NWNXPushString(sUCI);
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "MakeMove");
    return NWNXPopInt();
}

json NWNX_Chess_GetLegalMoves(int nGameId, string sSquare = "")
{
    NWNXPushString(sSquare);
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetLegalMoves");
    return NWNXPopJson();
}

json NWNX_Chess_GetMoves(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetMoves");
    return NWNXPopJson();
}

string NWNX_Chess_GetFEN(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetFEN");
    return NWNXPopString();
}

string NWNX_Chess_GetPGN(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetPGN");
    return NWNXPopString();
}

int NWNX_Chess_GetStatus(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetStatus");
    return NWNXPopInt();
}

int NWNX_Chess_GetSideToMove(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetSideToMove");
    return NWNXPopInt();
}

string NWNX_Chess_GetPieceAt(int nGameId, string sSquare)
{
    NWNXPushString(sSquare);
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetPieceAt");
    return NWNXPopString();
}

int NWNX_Chess_RequestBestMove(int nGameId, int nSkill = 20, int nMoveTimeMs = 1000)
{
    NWNXPushInt(nMoveTimeMs);
    NWNXPushInt(nSkill);
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "RequestBestMove");
    return NWNXPopInt();
}

string NWNX_Chess_GetBestMoveResult(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetBestMoveResult");
    return NWNXPopString();
}

int NWNX_Chess_GetBestMoveState(int nGameId)
{
    NWNXPushInt(nGameId);
    NWNXCall(NWNX_Chess, "GetBestMoveState");
    return NWNXPopInt();
}
