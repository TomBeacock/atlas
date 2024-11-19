<p align="center">
	<picture align="center">
		<source media="(prefers-color-scheme: dark)" srcset="res/branding/atlas_logo_dark_mode.png">
		<source media="(prefers-color-scheme: light)" srcset="res/branding/atlas_logo_light_mode.png">
		<img alt="atlas logo" src="res/branding/atlas_logo_light_mode.png" width="256" height="256">
	</picture>
</p>

Atlas is a multimedia application framework designed as a foundation for graphical applications.

---

# Linking Atlas

## CMake

### FetchContent

Fetch Atlas from repository:
```CMake
include(FetchContent)

FetchContent_Declare(
    atlas
    GIT_REPOSITORY https://github.com/TomBeacock/atlas.git
    GIT_TAG origin/main
)

FetchContent_MakeAvailable(atlas)
```

Link Atlas:
```CMake
target_link_libraries(your_target PRIVATE atlas::atlas)
```

### Git Submodule

Add Atlas as a submodule:
```Shell
git submodule add https://github.com/TomBeacock/atlas.git your/submodule/directory
```

Add Atlas subdirectory:
```CMake
add_subdirectory(your/submodule/directory/atlas)
```

Link Atlas:
```CMake
target_link_libraries(your_target PRIVATE atlas::atlas)
```
