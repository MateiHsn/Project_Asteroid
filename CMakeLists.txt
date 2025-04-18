cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)
# set(CMAKE_PROJECT_VERSION_MAJOR 0)
# set(CMAKE_PROJECT_VERSION_MINOR 0)
# set(CMAKE_PROJECT_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake) 

###############################################################################

# external dependencies with FetchContent
include(FetchContent)
#
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
#
# NOTE: Also update env vars used for caching in
#         - .github/actions/configure-cmake/action.yml
#         - .github/workflows/cmake.yml
FetchContent_Declare(
         raylib
         GIT_REPOSITORY https://github.com/raysan5/raylib.git
         GIT_TAG        "master" # <which tag/branch @ <some_date>>
         GIT_SHALLOW    TRUE  # works only with branches or tags, not with arbitrary commit hashes
)
#
FetchContent_MakeAvailable(raylib)

###############################################################################

# external dependencies with find_package

# find_package(Threads REQUIRED)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME}
    main.cpp
    #generated/src/Helper.cpp
    code/headers/DefaultParameters.hpp
    code/src/DefaultParameters.cpp
    code/headers/Entity.hpp
    code/src/Entity.cpp
    code/headers/Menu.hpp
    code/src/Menu.cpp
    code/headers/Projectile.hpp
    code/src/Projectile.cpp
    code/headers/Enemy.hpp
    code/src/Enemy.cpp
    code/headers/CollisionBox.hpp
    code/src/CollisionBox.cpp
    code/headers/InvalidDimensionException.hpp
    code/src/InvalidDimensionException.cpp
    code/headers/NonLandscapeDimensionException.hpp
    code/src/NonLandscapeDimensionException.cpp
    code/headers/InvalidMultiplierException.hpp
    code/src/InvalidMultiplierException.cpp
    code/headers/EntityManager.hpp
    code/src/EntityManager.cpp
    code/src/TemplateFunction.cpp
)

include(cmake/CompilerFlags.cmake)

###############################################################################

# use SYSTEM so cppcheck and clang-tidy do not report warnings from these directories
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE generated/include)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ext/<SomeHppLib>/include)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
# target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
 target_link_libraries(${PROJECT_NAME} raylib)

###############################################################################

# copy binaries to "bin" folder; these are uploaded as artifacts on each release
# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
# copy_files(FILES tastatura.txt config.json DIRECTORY images sounds)
# copy_files(DIRECTORY images sounds)

