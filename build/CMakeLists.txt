# This cmake is responsible for installing cmake config and other version
# files.

# This sets the package specific versioning
set(LIBKOF_MAJOR_VERSION 1)
set(LIBKOF_MINOR_VERSION 0)
set(LIBKOF_PATCH_VERSION 0)

# This allows easy creation of the directories within /usr/local or another install
# prefix
set(LIBKOF_NAMED_VERSION libkof-${LIBKOF_MAJOR_VERSION}.${LIBKOF_MINOR_VERSION})
set(LIBKOF_NAMED_VERSION ${LIBKOF_NAMED_VERSION} PARENT_SCOPE)

# These statements will create the directories needed for installs
install(DIRECTORY DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${LIBKOF_NAMED_VERSION})
install(DIRECTORY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIBKOF_NAMED_VERSION})

# This tracks the name of the in files used to generate the package cmake files
set(LIBKOF_CONFIG_FILE libkof-config.cmake.in)
set(LIBKOF_CONFIG_VERSION_FILE libkof-config-version.cmake.in)

# The configure_file statements will exchange the variables for the values in this cmake file.
configure_file(${LIBKOF_CONFIG_FILE} libkof-config.cmake @ONLY)
configure_file(${LIBKOF_CONFIG_VERSION_FILE} libkof-config-version.cmake @ONLY)

# Installs to the output locations so they can be found with find_package()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libkof-config-version.cmake DESTINATION include/${LIBKOF_NAMED_VERSION})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libkof-config.cmake DESTINATION lib/${LIBKOF_NAMED_VERSION})
