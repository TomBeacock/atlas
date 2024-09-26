cmake_minimum_required(VERSION 3.23)

project(Atlas C CXX)

set(CMAKE_CXX_STANDARD 23)

if(${CMAKE_SOURCE_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
	set(ATLAS_IS_ROOT true)
else()
	set(ATLAS_IS_ROOT false)
endif()

string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)

option(ATLAS_BUILD_TESTS "Build test suite" ${ATLAS_IS_ROOT})
option(ATLAS_BUILD_EXAMPLES "Build example applications" ${ATLAS_IS_ROOT})
option(ATLAS_BUILD_DOCS "Build documentation" ${ATLAS_IS_ROOT})

add_library(atlas STATIC)
add_library(atlas::atlas ALIAS atlas)
target_compile_definitions(atlas PUBLIC
	$<$<CONFIG:Debug,RelWithDebInfo>:ATLAS_CONFIG_DEBUG>
)
set_target_properties(atlas PROPERTIES
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED true
)
target_sources(atlas 
	PRIVATE
		"src/atlas/application.cpp"

		"src/atlas/debug/log.cpp"
		"src/atlas/debug/assert.cpp"
		"src/atlas/debug/break.cpp"

		"src/atlas/window/window.cpp"

	PUBLIC FILE_SET pubilc_headers TYPE HEADERS BASE_DIRS "include" FILES
		"include/atlas/atlas.hpp"
		"include/atlas/core.hpp"
		"include/atlas/types.hpp"
		"include/atlas/application.hpp"

		"include/atlas/debug.hpp"
		"include/atlas/debug/log.hpp"
		"include/atlas/debug/assert.hpp"
		"include/atlas/debug/break.hpp"

		"include/atlas/math.hpp"
		"include/atlas/math/common.hpp"
		"include/atlas/math/constants.hpp"
		"include/atlas/math/trigonometric.hpp"
		"include/atlas/math/vector2.hpp"
		"include/atlas/math/vector3.hpp"
		"include/atlas/math/vector4.hpp"
		"include/atlas/math/vector_func.hpp"
		"include/atlas/math/matrix4x4.hpp"
		"include/atlas/math/matrix_func.hpp"
		"include/atlas/math/matrix_transform.hpp"
		"include/atlas/math/quaternion.hpp"
		"include/atlas/math/quaternion_func.hpp"

		"include/atlas/window/window.hpp"
		"include/atlas/window/stage.hpp"

	PRIVATE FILE_SET private_headers TYPE HEADERS BASE_DIRS "src" FILES

)

# Platform
if(WIN32)
	message("Platform detected: Win32")
	target_compile_definitions(atlas PUBLIC ATLAS_PLATFORM_WIN32)
	set(CMAKE_WIN32_EXECUTABLE true)
	set(D3D12 true)
	target_link_options(atlas PUBLIC "/ENTRY:wWinMainCRTStartup" "/SUBSYSTEM:$<IF:$<CONFIG:Debug>,CONSOLE,WINDOWS>")
	target_sources(atlas
		PRIVATE
			"src/atlas/main/win32/main.cpp"
			"src/atlas/system/win32/string.cpp"
			"src/atlas/system/win32/error.cpp"
			"src/atlas/window/win32/window.cpp"

		PRIVATE FILE_SET private_headers TYPE HEADERS BASE_DIRS "src" FILES
			"src/atlas/system/win32/win32.hpp"
			"src/atlas/system/win32/string.hpp"
			"src/atlas/system/win32/error.hpp"
			"src/atlas/window/win32/window.hpp"
	)
endif()

# Graphics API
if(D3D12)
	target_compile_definitions(atlas PUBLIC ATLAS_GRAPHICS_D3D12)
endif()

# Tests
if(ATLAS_BUILD_TESTS)
	message("Building tests...")
	add_subdirectory(tests)
endif()

# Examples
if(ATLAS_BUILD_EXAMPLES)
	message("Building examples...")
	add_subdirectory(examples)
endif()

# Compiler
if(MSVC)
	target_compile_options(atlas PUBLIC /Zc:preprocessor)
endif()