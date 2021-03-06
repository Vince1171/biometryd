option(
  BIOMETRYD_ENABLE_DOC_GENERATION
  "Generate package documentation with doxygen"
  OFF
)

if (BIOMETRYD_ENABLE_DOC_GENERATION)

# Please note that we are creating documentation within the source tree
# as we are hosting our documentation on readthedocs.org. For their build machinery to work
# properly, we need to generate doxygen XML output within the source tree.
  
find_package(Doxygen)

if (DOXYGEN_FOUND)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in 
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc ALL
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)
  install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
    DESTINATION ${CMAKE_INSTALL_DOCDIR})

endif ()
endif ()
