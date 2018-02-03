return() # TODO: Make these work when the release schedule is less nuts

add_plugin(Optimizations
    "Optimizations.cpp"
    "Optimizations/BroadcastCombatStateToPartyOptimization.cpp"
    "Optimizations/CGameObjectArrayOptimization.cpp"
    "Optimizations/GetClientObjectByObjectIdOptimization.cpp"
    "Optimizations/GetHRTOptimization.cpp"
    "Optimizations/MainLoopSleepOptimization.cpp"
    "Optimizations/SortObjectsForGameObjectUpdateOptimization.cpp")

target_include_directories(Optimizations PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/External")