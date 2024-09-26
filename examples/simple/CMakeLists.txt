project(simple)

add_executable(simple)
target_link_libraries(simple PRIVATE atlas::atlas)
target_sources(simple
	PRIVATE
		"src/main.cpp"
		"src/application.cpp"
		"src/main_stage.cpp"

	PRIVATE FILE_SET HEADERS BASE_DIRS "src" FILES
		"src/application.hpp"
		"src/main_stage.hpp"
)