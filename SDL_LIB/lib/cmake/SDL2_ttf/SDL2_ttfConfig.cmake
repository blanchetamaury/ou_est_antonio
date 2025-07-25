# sdl2_ttf cmake project-config input for CMakeLists.txt script

include(FeatureSummary)
set_package_properties(SDL2_ttf PROPERTIES
    URL "https://www.libsdl.org/projects/SDL_ttf/"
    DESCRIPTION "Support for TrueType (.ttf) font files with Simple Directmedia Layer"
)

set(SDL2_ttf_FOUND ON)

set(SDL2TTF_VENDORED  OFF)

set(SDL2TTF_HARFBUZZ OFF)
set(SDL2TTF_FREETYPE ON)

set(SDL2TTF_HARFBUZZ_REQUIRED_VERSION    2.3.1)
set(SDL2TTF_SDL2_REQUIRED_VERSION        2.0.10)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL2_ttf-shared-targets.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/SDL2_ttf-shared-targets.cmake")
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL2_ttf-static-targets.cmake")
    if(SDL2TTF_VENDORED)
        include(CheckLanguage)
        check_language(CXX)
        if(NOT CMAKE_CXX_COMPILER AND NOT _sdl2ttf_nowarning)
            message(WARNING "CXX language not enabled. Linking to SDL2_ttf::SDL2_ttf-static might fail.")
        endif()
    endif()
    include("${CMAKE_CURRENT_LIST_DIR}/SDL2_ttf-static-targets.cmake")
endif()


if(NOT SDL2TTF_VENDORED)
    set(_sdl_cmake_module_path "${CMAKE_MODULE_PATH}")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

    include(CMakeFindDependencyMacro)
    include(PkgConfigHelper)

    if(TARGET SDL2_ttf::SDL2_ttf-static)
        if(SDL2TTF_FREETYPE AND NOT Freetype::Freetype)
            find_dependency(Freetype)
        endif()

        if(SDL2TTF_HARFBUZZ AND NOT harfbuzz::harfbuzz)
            list(APPEND harfbuzz_ROOT "${CMAKE_CURRENT_LIST_DIR}")
            find_dependency(harfbuzz ${SDL2TTF_HARFBUZZ_REQUIRED_VERSION})
        endif()
    endif()

    set(CMAKE_MODULE_PATH "${_sdl_cmake_module_path}")
    unset(_sdl_cmake_module_path)
endif()
