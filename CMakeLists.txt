cmake_minimum_required(VERSION 3.24)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "install_dir" CACHE PATH "..." FORCE)
endif()

# disable sanitizers when releasing executables without explicitly requested debug info
# use generator expressions to set flags correctly in both single and multi config generators
set(is_debug "$<CONFIG:Debug>")
set(is_rel_with_deb "$<CONFIG:RelWithDebInfo>")
set(debug_mode "$<OR:${is_debug},${is_rel_with_deb}>")

###############################################################################

# custom functions

function(set_custom_stdlib_and_sanitizers target add_apple_asan)
    if(MSVC)
        # see https://gitlab.kitware.com/cmake/cmake/-/issues/24922
        set_target_properties(${target} PROPERTIES VS_USER_PROPS "${CMAKE_SOURCE_DIR}/disable_modules.props")
        target_compile_options(${target} PRIVATE "$<${debug_mode}:/fsanitize=address>" /experimental:module-)
        return()
    endif()

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        target_compile_options(${target} PRIVATE -stdlib=libc++)
        target_link_options(${target} PRIVATE -stdlib=libc++)
    endif()

    if(APPLE)
        # first check Apple since Apple is also a kind of Unix
        if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND add_apple_asan MATCHES true)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
        endif()
    elseif(UNIX)
        if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
            if("${CMAKE_CXX_COMPILER_VERSION}" MATCHES "12.")
                # check leaks on Linux since macOS does not support the leaks sanitizer yet
                # leaks sanitizer is enabled by default on Linux, so we do not need to enable it explicitly
                target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
                target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            endif()
        elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
            if("${CMAKE_CXX_COMPILER_VERSION}" MATCHES "14.")
                # use semi-colons instead of spaces to separate arguments
                # it is recommended to quote generator expressions in order to avoid unintentional splitting
                target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins>")
                target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins;-Wl,-rpath,tools/llvm-project/build/lib>")
            else()
                message("No matching Clang version to add sanitizer flags!")
            endif()
        endif()
    endif()
endfunction()

###############################################################################

# external dependencies with FetchContent
# include(FetchContent)
#
# NOTE: Also update env vars used for caching in
#         - .github/actions/configure-cmake/action.yml
#         - .github/workflows/cmake.yml
# FetchContent_Declare(
#         SomeLib
#         GIT_REPOSITORY https://github.com/<SomeUser>/<SomeLib>.git
#         GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>>
#         GIT_SHALLOW    1  # works only with branches or tags, not with arbitrary commit hashes
# )
#
# FetchContent_MakeAvailable(SomeLib)

###############################################################################

# external dependencies with find_package

# find_package(Threads REQUIRED)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME} main.cpp
        Headers/Item.h
        CPPs/Item.cpp
        Headers/Sword.h
        CPPs/Sword.cpp
        Headers/CrescentSword.h
        CPPs/CrescentSword.cpp
        Headers/SilverSword.h
        CPPs/SilverSword.cpp
        Headers/FullMoonSword.h
        CPPs/FullMoonSword.cpp
        CPPs/HPsmall.cpp
        Headers/HPsmall.h
        CPPs/HPmedium.cpp
        Headers/HPmedium.h
        CPPs/HPbig.cpp
        Headers/HPbig.h
        Headers/InventorySlot.h
        CPPs/InventorySlot.cpp
        Headers/Inventory.h
        CPPs/Inventory.cpp
        CPPs/Maps.cpp
        Headers/Maps.h
        CPPs/Player.cpp
        Headers/Player.h
        CPPs/BlackSmith.cpp
        Headers/BlackSmith.h
        CPPs/Joan.cpp
        Headers/Joan.h
        CPPs/Bakra.cpp
        Headers/Bakra.h
        CPPs/Seungryong.cpp
        Headers/Seungryong.h
        CPPs/Monsters.cpp
        Headers/Monsters.h
        CPPs/WildDog.cpp
        Headers/WildDog.h
        Headers/Wolf.h
        CPPs/Wolf.cpp
        Headers/Boar.h
        CPPs/Boar.cpp
        CPPs/Soldier.cpp
        Headers/Soldier.h
        CPPs/Tiger.cpp
        Headers/Tiger.h
        CPPs/Ork.cpp
        Headers/Ork.h
        CPPs/DarkFanatic.cpp
        Headers/DarkFanatic.h
        CPPs/Shop.cpp
        Headers/Shop.h
        Headers/Fight.h
        CPPs/Fight.cpp
        "CPPs/Teleport Function.cpp"
        "Headers/Teleport Function.h"
        "CPPs/Decision Function.cpp"
        "Headers/Decision Function.h"
        "CPPs/Correct Read Function.cpp"
        "Headers/Correct Read Function.h"
        Headers/GameManager.h
        CPPs/GameManager.cpp
        Headers/GameManagerBuilder.h
        Headers/ConcreteGameManagerBuilder.h
        CPPs/ConcreteGameManagerBuilder.cpp
        CPPs/GameManagerBuilder.cpp
        "Headers/MonsterFactory.h"
        Headers/WildDogFactory.h
        Headers/WolfFactory.h
        Headers/BoarFactory.h
        Headers/SoldierFactory.h
        Headers/TigerFactory.h
        Headers/OrkFactory.h
        Headers/DarkFanaticFactory.h
        CPPs/MonsterFactory.cpp
        CPPs/BoarFactory.cpp
        CPPs/DarkFanaticFactory.cpp
        CPPs/OrkFactory.cpp
        CPPs/SoldierFactory.cpp
        CPPs/TigerFactory.cpp
        CPPs/WildDogFactory.cpp
        CPPs/WolfFactory.cpp
)

###############################################################################

# target definitions

if(GITHUB_ACTIONS)
  message("NOTE: GITHUB_ACTIONS defined")
  target_compile_definitions(${PROJECT_NAME} PRIVATE GITHUB_ACTIONS)
endif()

###############################################################################

if(WARNINGS_AS_ERRORS)
    set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_WARNING_AS_ERROR ON)
endif()

# custom compiler flags
message("Compiler: ${CMAKE_CXX_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /wd4244 /wd4267 /wd4996 /external:anglebrackets /external:W0)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

###############################################################################

# sanitizers
set_custom_stdlib_and_sanitizers(${PROJECT_NAME} true)

###############################################################################

# use SYSTEM so cppcheck/clang-tidy does not report warnings from these directories
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ext/<SomeHppLib>/include)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
# target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
# target_link_libraries(${PROJECT_NAME} <SomeLib>)

###############################################################################

# copy binaries to "bin" folder; these are uploaded as artifacts on each release
# update name in .github/workflows/cmake.yml:29 when changing "bin" name here
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# install(DIRECTORY some_dir1 some_dir2 DESTINATION bin)
# install(FILES some_file1.txt some_file2.md DESTINATION bin)
