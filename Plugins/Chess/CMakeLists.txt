add_plugin(Chess
    "Chess.cpp"
    "Game.cpp"
    "Engine.cpp")
# Vendored chess-library (MIT): SYSTEM keeps its warnings out of our build.
target_include_directories(Chess SYSTEM PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/External/chess-library")

# Standalone rules and engine tests, not built by default: `cmake --build <dir> --target ChessTests`.
# Run: <dir>/Plugins/Chess/ChessTests [path to stockfish]
find_package(Threads)
add_executable(ChessTests EXCLUDE_FROM_ALL
    "Tests/ChessTests.cpp"
    "Game.cpp"
    "Engine.cpp")
target_include_directories(ChessTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ChessTests SYSTEM PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/External/chess-library")
target_link_libraries(ChessTests Threads::Threads)
set_target_properties(ChessTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
