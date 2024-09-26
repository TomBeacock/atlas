project(tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests)
target_sources(tests
	PRIVATE
		"main.cpp"
		"math/vector2.cpp" "math/vector3.cpp" "math/vector4.cpp"
		"math/vector_func.cpp" 
		"math/quaternion.cpp"
		"math/matrix4x4.cpp"
		"math/matrix_func.cpp"
		"math/matrix_transform.cpp"
)
target_link_libraries(tests PRIVATE atlas GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)