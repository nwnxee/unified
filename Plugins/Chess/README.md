@page chess Readme
@ingroup chess

Chess games in plugin memory (move generation, check, mate, stalemate, the draw rules, FEN and PGN)
and engine moves from [Stockfish](https://stockfishchess.org/) for games against an NPC.

The rules come from the header-only [chess-library](https://github.com/Disservin/chess-library)
(MIT, vendored in `External/chess-library` with its licence), so castling, en passant, promotion and
the draw rules are not hand-written.

Stockfish is not part of NWNX or its Docker image; only engine moves need it, the rules work without it.
Install it on the server (`apt-get install stockfish` on Debian and Ubuntu, or a binary from the
Stockfish site), or in your own image built on `nwnxee/unified`:

```Dockerfile
FROM nwnxee/unified:latest
RUN apt-get update && apt-get install -y --no-install-recommends stockfish && rm -rf /var/lib/apt/lists/*
```

## Environment Variables

| Variable Name                     | Value  | Default     | Notes |
| --------------------------------- | :----: | ----------- | ----- |
| `NWNX_CHESS_STOCKFISH_PATH`       | string | `stockfish` | A path, or a name looked up on `PATH` and in `/usr/games` (where Debian's `stockfish` package puts it). |
| `NWNX_CHESS_ENGINE_THREADS`       | int    | 1           | Stockfish `Threads`. |
| `NWNX_CHESS_ENGINE_HASH_MB`       | int    | 16          | Stockfish `Hash` in MB. |
| `NWNX_CHESS_ENGINE_NICE`          | int    | 10          | Added to the engine's nice value so it yields the CPU to nwserver. |
| `NWNX_CHESS_MAX_MOVETIME_MS`      | int    | 10000       | Upper limit for `nMoveTimeMs` in `NWNX_Chess_RequestBestMove()`. |
| `NWNX_CHESS_MAX_GAMES`            | int    | 1000        | Games that can exist at once; `NWNX_Chess_NewGame()` returns 0 beyond it. |

## Games

`NWNX_Chess_NewGame()` returns a game id; the game lives in plugin memory until `NWNX_Chess_EndGame()`
or a server restart. Moves are in UCI notation: `e2e4`, castling as the king's move (`e1g1`),
promotion with the piece letter (`e7e8q`). `NWNX_Chess_GetPieceAt()` and `NWNX_Chess_GetLegalMoves()`
give what a board UI needs.

`NWNX_Chess_GetStatus()` returns `NWNX_CHESS_STATUS_*`: playing, check, checkmate, stalemate, or a draw
by threefold repetition, the fifty-move rule or insufficient material. The draws end the game at once
(no claim needed). The game is over for any status other than playing and check: moves are refused then.

**Persistence:** to keep a game over a restart, store its start FEN (`""` for the normal start) and
`NWNX_Chess_GetMoves()` (a json array), and replay the moves into `NWNX_Chess_NewGame(sStartFEN)` with
`NWNX_Chess_MakeMove()`. That keeps the PGN and the repetition history. Restoring from
`NWNX_Chess_GetFEN()` alone works too, but repetitions before it don't count and the PGN starts there.

## Engine moves

`NWNX_Chess_RequestBestMove(nGameId, nSkill, nMoveTimeMs)` queues a request and returns at once.
One Stockfish process, started on the first request, serves all games one request at a time on its own
thread, so the server never waits for it. `nSkill` is Stockfish's Skill Level (0-20), `nMoveTimeMs`
how long it thinks. If Stockfish isn't installed the call logs an error and returns FALSE; if it
crashes or hangs (no answer within the move time plus 5 seconds) it is killed, the request fails, and
the next request starts a new process.

The answer reaches the module on the main thread in two ways; use either:

- **Polling:** `NWNX_Chess_GetBestMoveState()` is `NWNX_CHESS_ENGINE_THINKING` until it is `DONE` (or
  `FAILED`); then `NWNX_Chess_GetBestMoveResult()` returns the move. Poll with `DelayCommand()`.
- **Event:** `NWNX_ON_CHESS_BESTMOVE` fires on the module when the engine has answered (needs the
  Events plugin). Subscribe with `NWNX_Events_SubscribeEvent("NWNX_ON_CHESS_BESTMOVE", "my_script")`.

| Event Data | Type   | Notes |
| ---------- | ------ | ----- |
| `GAME_ID`  | int    | The game id. |
| `MOVE`     | string | The move in UCI notation, "" if the engine failed. |
| `SUCCESS`  | int    | TRUE if there is a move. |

The engine's move isn't played: the module plays it with `NWNX_Chess_MakeMove()` (after an animation,
say). A move played, a new request, or `NWNX_Chess_EndGame()` while the engine is thinking stops that search
and discards its answer; no event fires for it.

## Tests

`NWScript/nwnx_chess_t.nss` is the in-game test. The rules and engine code also have a standalone test
(perft, mate, stalemate, en passant, castling, promotion, the draw rules, FEN checks, and the engine with
a real Stockfish, a missing one, a hanging one and one killed mid-game):

```
cmake --build <build dir> --target ChessTests
<build dir>/Plugins/Chess/ChessTests [path to stockfish]
```
