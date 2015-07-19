cmake_minimum_required (VERSION 3.2)

# Use c++11
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# Set up project
project (BossBattle)

# Set up vars
set(TIM_GAME_LIB_ROOT "$ENV{TIM_GAME_LIB_ROOT}")
if (NOT TIM_GAME_LIB_ROOT)
	message(FATAL_ERROR "TIM_GAME_LIB_ROOT not defined")
endif()
set(SFML_ROOT "$ENV{SFML_ROOT}")
if (NOT SFML_ROOT)
	message(FATAL_ERROR "SFML_ROOT not defined")
endif()

# CCMake modules
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake;${TIM_GAME_LIB_ROOT}/CMake")

# Set up source file list
include(BossBattle)

# We want to use cotire for precompiled header
include(cotire)

# Find and include SFML
find_package(SFML 2.2 COMPONENTS graphics window system audio network)
include_directories(${SFML_INCLUDE_DIR})

# Include TimGameLib
include(TimGameLib)
include_directories(${TIM_GAME_LIB_ROOT}/Source)

# Include self
include_directories(Source)

# Locate all recourses
FILE(GLOB RESOURCE_FILES ${PROJECT_SOURCE_DIR}/Data/*)

# Mark resource files as resources
if (APPLE)
  set_source_files_properties(
    "${RESOURCE_FILES}"
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
  )
endif()

# BossBattle executable target
add_executable(BossBattle MACOSX_BUNDLE ${BB_SOURCES} ${RESOURCE_FILES})

# TimGameLib library target depency
add_library(TimGameLib ${TIM_GAME_LIB_SOURCES})
add_dependencies(BossBattle TimGameLib)

if (WIN32)
	# Link Shlwapi.lib for finding exe path
	target_link_libraries(BossBattle Shlwapi.lib)

  # Copy resource files to exe folder
  foreach(RES ${RESOURCE_FILES})
    add_custom_command(
      TARGET BossBattle POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E
        copy_if_different ${RES} $<TARGET_FILE_DIR:BossBattle>
    )
  endforeach()
elseif(APPLE)
	# Link Foundation.framework for finding bundle path
	find_library(FOUNDATION_FRAMEWORK Foundation)
	target_link_libraries(BossBattle ${FOUNDATION_FRAMEWORK})

  # Add the resources to the bundle
  set_target_properties(BossBattle PROPERTIES RESOURCE "${RESOURCE_FILES}")
endif()

# Link SFML
target_link_libraries(BossBattle ${SFML_LIBRARIES})

# Link TimGameLib
target_link_libraries(BossBattle TimGameLib)

# Use cotire for precompiled header
set_target_properties(BossBattle PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Source/BossBattle-Prefix.pch")
cotire(BossBattle)
set_target_properties(TimGameLib PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${TIM_GAME_LIB_ROOT}/Source/TimGameLib_Prefix.pch")
cotire(TimGameLib)