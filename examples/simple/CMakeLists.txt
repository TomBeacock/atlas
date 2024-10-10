project(simple)

add_executable(simple)
target_link_libraries(simple PRIVATE atlas::atlas)
target_sources(simple
	PRIVATE
		"src/main.cpp"
		"src/app.cpp"
		"src/main_layer.cpp"

	PRIVATE FILE_SET HEADERS BASE_DIRS "src" FILES
		"src/app.hpp"
		"src/main_layer.hpp"
)