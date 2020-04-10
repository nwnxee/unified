cmake_policy(SET CMP0054 NEW)

# Look for Doxygen package
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME NWNX:EE)
    set(DOXYGEN_PROJECT_NUMBER 8193.10)
    set(DOXYGEN_PROJECT_LOGO ${CMAKE_SOURCE_DIR}/docgen/logo-transparent.png)
    set(DOXYGEN_LAYOUT_FILE ${CMAKE_SOURCE_DIR}/docgen/DoxygenLayout.xml)
    set(DOXYGEN_FILE_PATTERNS *.nss;*.md)
    set(DOXYGEN_EXCLUDE_PATTERNS */*-nwnx/*; */Plugins/*/NWScript/*_t.nss; */Plugins/*/NWScript/*_t?.nss;
                                 */Plugins/Redis/cpp_redis)
    set(DOXYGEN_EXTENSION_MAPPING nss=C++)
    set(DOXYGEN_DISABLE_INDEX YES)
    set(DOXYGEN_SOURCE_BROWSER YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_INCLUDE_GRAPH NO)
    set(DOXYGEN_SORT_MEMBER_DOCS NO)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR}/)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Documentation)
    set(DOXYGEN_ALIASES [[nwn{1}="<a href='https://nwnlexicon.com/index.php?title=\1' target='_blank'>\1</a>"]])
    set(DOXYGEN_VERBATIM_VARS DOXYGEN_ALIASES)
    set(DOXYGEN_HTML_OUTPUT light)
    set(DOXYGEN_HTML_HEADER ${CMAKE_SOURCE_DIR}/docgen/html_header.html)
    set(DOXYGEN_HTML_FOOTER ${CMAKE_SOURCE_DIR}/docgen/html_light_footer.html)
    set(DOXYGEN_HTML_EXTRA_STYLESHEET ${CMAKE_SOURCE_DIR}/docgen/custom.css)
    # Run "make docs" to create the doxygen documentation
    doxygen_add_docs(
            docs
            ${CMAKE_SOURCE_DIR}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docgen
            COMMENT "Generate API-documents."
    )
    set(DOXYGEN_HTML_EXTRA_STYLESHEET ${CMAKE_SOURCE_DIR}/docgen/custom_dark_theme.css)
    set(DOXYGEN_HTML_OUTPUT dark)
    set(DOXYGEN_HTML_FOOTER ${CMAKE_SOURCE_DIR}/docgen/html_dark_footer.html)
    doxygen_add_docs(
            dark-docs
            ${CMAKE_SOURCE_DIR}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docgen
            COMMENT "Generate Dark API-documents."
    )
endif(DOXYGEN_FOUND)
