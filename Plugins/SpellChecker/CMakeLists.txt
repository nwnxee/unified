find_package(HUNSPELL)
if(HUNSPELL_FOUND)
	add_plugin(SpellChecker
		"SpellChecker.cpp")
	target_include_directories(SpellChecker PRIVATE "${HUNSPELL_INCLUDE_DIR}")	
	target_link_libraries(SpellChecker "${HUNSPELL_LIBRARIES}")
endif(HUNSPELL_FOUND)
