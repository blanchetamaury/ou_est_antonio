# sdl2_mixer cmake project-config input for CMakeLists.txt script

include(FeatureSummary)
set_package_properties(SDL2_mixer PROPERTIES
    URL "https://www.libsdl.org/projects/SDL_mixer/"
    DESCRIPTION "SDL_mixer is a sample multi-channel audio mixer library"
)

set(SDL2_mixer_FOUND                ON)

set(SDL2MIXER_VENDORED              OFF)

set(SDL2MIXER_CMD                   ON)

set(SDL2MIXER_FLAC_LIBFLAC          OFF)
set(SDL2MIXER_FLAC_DRFLAC           ON)

set(SDL2MIXER_GME                   OFF)

set(SDL2MIXER_MOD                   ON)
set(SDL2MIXER_MOD_MODPLUG           OFF)
set(SDL2MIXER_MOD_XMP               ON)
set(SDL2MIXER_MOD_XMP_LITE          OFF)

set(SDL2MIXER_MP3                   ON)
set(SDL2MIXER_MP3_MINIMP3           ON)
set(SDL2MIXER_MP3_MPG123            OFF)

set(SDL2MIXER_MIDI                  ON)
set(SDL2MIXER_MIDI_FLUIDSYNTH       ON)
set(SDL2MIXER_MIDI_NATIVE           OFF)
set(SDL2MIXER_MIDI_TIMIDITY         ON)

set(SDL2MIXER_OPUS                  ON)

set(SDL2MIXER_VORBIS                STB)
set(SDL2MIXER_VORBIS_STB            ON)
set(SDL2MIXER_VORBIS_TREMOR         OFF)
set(SDL2MIXER_VORBIS_VORBISFILE     OFF)

set(SDL2MIXER_WAVE                  ON)

set(SDL2MIXER_WAVPACK               ON)

set(SDL2MIXER_SDL2_REQUIRED_VERSION 2.0.9)

if(NOT SDL2MIXER_VENDORED)
    set(_sdl_cmake_module_path "${CMAKE_MODULE_PATH}")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
endif()

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL2_mixer-shared-targets.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/SDL2_mixer-shared-targets.cmake")
endif()

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL2_mixer-static-targets.cmake")
    set(_sdl_cmake_module_path "${CMAKE_MODULE_PATH}")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

    include(CMakeFindDependencyMacro)
    include(PkgConfigHelper)

    if(NOT DEFINED CMAKE_FIND_PACKAGE_PREFER_CONFIG)
        set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)
    endif()

    if(SDL2MIXER_FLAC_LIBFLAC AND NOT SDL2MIXER_VENDORED AND NOT TARGET FLAC::FLAC)
        find_dependency(FLAC)
    endif()

    if(SDL2MIXER_GME AND NOT SDL2MIXER_VENDORED AND NOT TARGET gme::gme)
        find_dependency(gme)
    endif()

    if(SDL2MIXER_MOD_MODPLUG AND NOT SDL2MIXER_VENDORED AND NOT TARGET modplug::modplug)
        find_dependency(modplug)
    endif()

    if(SDL2MIXER_MOD_XMP AND NOT SDL2MIXER_VENDORED AND NOT TARGET libxmp::libxmp)
        find_dependency(libxmp)
    endif()

    if(SDL2MIXER_MOD_XMP_LITE AND NOT SDL2MIXER_VENDORED AND NOT TARGET libxmp-lite::libxmp-lite)
        find_dependency(libxmp-lite)
    endif()

    if(SDL2MIXER_MP3_MPG123 AND NOT SDL2MIXER_VENDORED AND NOT TARGET MPG123::mpg123)
        find_dependency(mpg123)
    endif()

    if(SDL2MIXER_MIDI_FLUIDSYNTH AND NOT SDL2MIXER_VENDORED AND NOT TARGET FluidSynth::libfluidsynth)
        find_dependency(FluidSynth)
    endif()

    if(SDL2MIXER_VORBIS_TREMOR AND NOT SDL2MIXER_VENDORED AND NOT TARGET tremor::tremor)
        find_dependency(tremor)
    endif()

    if(SDL2MIXER_VORBIS_VORBISFILE AND NOT SDL2MIXER_VENDORED AND NOT TARGET Vorbis::vorbisfile)
        find_dependency(Vorbis)
    endif()

    if(SDL2MIXER_OPUS AND NOT SDL2MIXER_VENDORED AND NOT TARGET OpusFile::opusfile)
        find_dependency(OpusFile)
    endif()

    if(SDL2MIXER_WAVPACK AND NOT SDL2MIXER_VENDORED AND NOT TARGET WavPack::WavPack)
        find_dependency(wavpack)
    endif()

    set(CMAKE_MODULE_PATH "${_sdl_cmake_module_path}")
    unset(_sdl_cmake_module_path)

    if((NOT SDL2MIXER_VENDORED AND SDL2MIXER_MOD_MODPLUG) OR (HAIKU AND SDL2MIXER_MIDI_NATIVE))
        include(CheckLanguage)
        check_language(CXX)
        if(NOT CMAKE_CXX_COMPILER)
            message(WARNING "CXX language not enabled. Linking to SDL2_mixer::SDL2_mixer-static might fail.")
        endif()
    endif()
    include("${CMAKE_CURRENT_LIST_DIR}/SDL2_mixer-static-targets.cmake")
endif()

if(NOT SDL2MIXER_VENDORED)
    set(CMAKE_MODULE_PATH "${_sdl_cmake_module_path}")
    unset(_sdl_cmake_module_path)
endif()
