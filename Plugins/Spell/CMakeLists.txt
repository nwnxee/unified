find_package(HUNSPELL)
if(HUNSPELL_FOUND)
	add_plugin(Spell
		"Spell.cpp")
	target_include_directories(Spell PRIVATE "${HUNSPELL_INCLUDE_DIR}")	
	target_link_libraries(Spell "${HUNSPELL_LIBRARIES}")
endif(HUNSPELL_FOUND)
