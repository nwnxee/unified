return() # TODO: Upgrade Most of these are unnecessary now. Will we delete this plugin?

add_plugin(Optimizations
    "Optimizations.cpp"
    "Optimizations/AIMasterOptimizations.cpp"
    "Optimizations/BroadcastCombatStateToPartyOptimization.cpp"
    "Optimizations/CGameObjectArrayOptimization.cpp"
    "Optimizations/GetClientObjectByObjectIdOptimization.cpp"
    "Optimizations/GetHRTOptimization.cpp"
    "Optimizations/MainLoopSleepOptimization.cpp"
    "Optimizations/SortObjectsForGameObjectUpdateOptimization.cpp")

target_include_directories(Optimizations PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/External")