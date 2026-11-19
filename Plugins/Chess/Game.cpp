#include "Game.hpp"

#include "chess.hpp"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <sstream>

namespace Chess {

static const char* STARTPOS = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const char* StatusName(Status status)
{
    switch (status)
    {
        case Status::Playing:          return "playing";
        case Status::Check:            return "check";
        case Status::Checkmate:        return "checkmate";
        case Status::Stalemate:        return "stalemate";
        case Status::DrawRepetition:   return "draw by threefold repetition";
        case Status::DrawFiftyMove:    return "draw by the fifty-move rule";
        case Status::DrawInsufficient: return "draw by insufficient material";
    }
    return "unknown";
}

static std::vector<std::string> SplitFields(const std::string& s)
{
    std::vector<std::string> fields;
    std::istringstream in(s);
    std::string field;
    while (in >> field)
        fields.push_back(field);
    return fields;
}

static bool IsSquare(const std::string& s)
{
    return s.size() == 2 && s[0] >= 'a' && s[0] <= 'h' && s[1] >= '1' && s[1] <= '8';
}

// chess-library is lenient with FENs, so validate them here, including positions no legal game reaches.
static bool ValidateFen(const std::string& fen, std::string& normalized)
{
    auto fields = SplitFields(fen);
    if (fields.size() < 4 || fields.size() > 6)
        return false;
    if (fields.size() < 5) fields.push_back("0");
    if (fields.size() < 6) fields.push_back("1");

    // Piece placement: 8 ranks of 8 squares.
    char board[8][8] = {}; // [rank][file], rank 0 = rank 8
    int rank = 0, file = 0;
    for (char c : fields[0])
    {
        if (c == '/')
        {
            if (file != 8 || ++rank > 7) return false;
            file = 0;
        }
        else if (c >= '1' && c <= '8')
        {
            file += c - '0';
            if (file > 8) return false;
        }
        else if (std::strchr("pnbrqkPNBRQK", c) && c != '\0')
        {
            if (file > 7) return false;
            board[rank][file++] = c;
        }
        else
            return false;
    }
    if (rank != 7 || file != 8)
        return false;

    int whiteKings = 0, blackKings = 0;
    for (int r = 0; r < 8; r++)
    {
        for (int f = 0; f < 8; f++)
        {
            const char c = board[r][f];
            if (c == 'K') whiteKings++;
            if (c == 'k') blackKings++;
            if ((c == 'P' || c == 'p') && (r == 0 || r == 7))
                return false;
        }
    }
    if (whiteKings != 1 || blackKings != 1)
        return false;

    if (fields[1] != "w" && fields[1] != "b")
        return false;

    // Castling rights need the king and the rook on their starting squares.
    if (fields[2] != "-")
    {
        std::string seen;
        for (char c : fields[2])
        {
            if (!std::strchr("KQkq", c) || c == '\0' || seen.find(c) != std::string::npos)
                return false;
            seen += c;
            const bool white = c == 'K' || c == 'Q';
            const int r = white ? 7 : 0;
            const char king = white ? 'K' : 'k';
            const char rook = white ? 'R' : 'r';
            const int rookFile = (c == 'K' || c == 'k') ? 7 : 0;
            if (board[r][4] != king || board[r][rookFile] != rook)
                return false;
        }
    }

    if (fields[3] != "-")
    {
        if (!IsSquare(fields[3]))
            return false;
        // The square a pawn just skipped: rank 6 when white is to move, rank 3 when black is.
        if (fields[3][1] != (fields[1] == "w" ? '6' : '3'))
            return false;
    }

    for (int i = 4; i < 6; i++)
    {
        if (fields[i].empty() || fields[i].size() > 5 ||
            !std::all_of(fields[i].begin(), fields[i].end(), [](char c) { return std::isdigit((unsigned char)c); }))
            return false;
    }
    if (std::stoi(fields[5]) < 1)
        return false;

    normalized = fields[0] + " " + fields[1] + " " + fields[2] + " " + fields[3] + " " + fields[4] + " " + fields[5];
    return true;
}

Game::Game() : m_board(std::make_unique<chess::Board>())
{
    Load("");
}

Game::~Game() = default;

bool Game::Load(const std::string& fenIn)
{
    std::string fen;
    if (fenIn.empty())
        fen = STARTPOS;
    else if (!ValidateFen(fenIn, fen))
        return false;

    auto board = std::make_unique<chess::Board>();
    if (!board->setFen(fen))
        return false;

    // The side that isn't to move can't be in check.
    if (board->isAttacked(board->kingSq(~board->sideToMove()), board->sideToMove()))
        return false;

    m_board = std::move(board);
    m_startFen = m_board->getFen();
    m_standardStart = m_startFen == STARTPOS;
    m_startFullMove = m_board->fullMoveNumber();
    m_startBlack = m_board->sideToMove() == chess::Color::BLACK;
    m_uciMoves.clear();
    m_sanMoves.clear();
    return true;
}

static std::string ToLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

bool Game::MakeMove(const std::string& uciIn)
{
    if (IsOver())
        return false;

    const auto uci = ToLower(uciIn);
    if (uci.size() != 4 && uci.size() != 5)
        return false;

    chess::Movelist moves;
    chess::movegen::legalmoves(moves, *m_board);
    for (const auto& move : moves)
    {
        if (chess::uci::moveToUci(move) != uci)
            continue;

        std::string san;
        try
        {
            san = chess::uci::moveToSan(*m_board, move);
        }
        catch (...)
        {
            san = uci;
        }
        m_board->makeMove(move);
        m_uciMoves.push_back(uci);
        m_sanMoves.push_back(san);
        return true;
    }
    return false;
}

std::vector<std::string> Game::GetLegalMoves(const std::string& squareIn) const
{
    std::vector<std::string> result;
    if (IsOver())
        return result;

    const auto square = ToLower(squareIn);
    if (!square.empty() && !IsSquare(square))
        return result;

    chess::Movelist moves;
    chess::movegen::legalmoves(moves, *m_board);
    for (const auto& move : moves)
    {
        auto uci = chess::uci::moveToUci(move);
        if (square.empty() || uci.compare(0, 2, square) == 0)
            result.push_back(std::move(uci));
    }
    return result;
}

std::string Game::GetFEN() const
{
    return m_board->getFen();
}

Status Game::GetStatus() const
{
    // Mate and stalemate first: a mate on the 100th half-move is still a mate.
    chess::Movelist moves;
    chess::movegen::legalmoves(moves, *m_board);
    const bool inCheck = m_board->inCheck();
    if (moves.empty())
        return inCheck ? Status::Checkmate : Status::Stalemate;
    if (m_board->isInsufficientMaterial())
        return Status::DrawInsufficient;
    if (m_board->isHalfMoveDraw())
        return Status::DrawFiftyMove;
    // Seen twice before means threefold; only counts positions since the game was loaded.
    if (m_board->isRepetition(2))
        return Status::DrawRepetition;
    return inCheck ? Status::Check : Status::Playing;
}

bool Game::IsOver() const
{
    const auto status = GetStatus();
    return status != Status::Playing && status != Status::Check;
}

Side Game::GetSideToMove() const
{
    return m_board->sideToMove() == chess::Color::WHITE ? Side::White : Side::Black;
}

std::string Game::GetPieceAt(const std::string& squareIn) const
{
    const auto square = ToLower(squareIn);
    if (!IsSquare(square))
        return "";

    const auto piece = m_board->at(chess::Square(square));
    if (piece == chess::Piece::NONE)
        return "";

    std::string result = piece.color() == chess::Color::WHITE ? "w" : "b";
    result += static_cast<std::string>(piece.type());
    return result;
}

std::string Game::GetPGN() const
{
    std::string pgn;
    if (!m_standardStart)
        pgn += "[SetUp \"1\"]\n[FEN \"" + m_startFen + "\"]\n\n";

    uint32_t moveNumber = m_startFullMove;
    bool black = m_startBlack;
    for (size_t i = 0; i < m_sanMoves.size(); i++)
    {
        if (!black)
            pgn += std::to_string(moveNumber) + ". ";
        else if (i == 0)
            pgn += std::to_string(moveNumber) + "... ";
        pgn += m_sanMoves[i] + " ";
        if (black)
            moveNumber++;
        black = !black;
    }

    const auto status = GetStatus();
    if (status == Status::Checkmate)
        pgn += GetSideToMove() == Side::White ? "0-1" : "1-0";
    else if (status == Status::Playing || status == Status::Check)
        pgn += "*";
    else
        pgn += "1/2-1/2";
    return pgn;
}

std::string Game::GetUciPosition() const
{
    std::string position = "position fen " + m_startFen;
    if (!m_uciMoves.empty())
    {
        position += " moves";
        for (const auto& move : m_uciMoves)
            position += " " + move;
    }
    return position;
}

}
