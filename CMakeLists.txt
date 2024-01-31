cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(src/Entities src/Player src/Game ${Windows_SDK_INCLUDE_DIR}/ucrt)

# add_executable(CMakeSFMLProject src/main.cpp src/Entities/Entity.h)
file(GLOB_RECURSE sources      src/*.cpp src/*.h)
file(GLOB_RECURSE extsources      imgui-sfml-2.6/*.cpp imgui-sfml-2.6/*.h imgui-sfml-2.6/*.hpp)
add_executable(CMakeSFMLProject ${sources} ${extsources})
# add_subdirectory("imgui-sfml-2.6")

# add_executable(CMakeSFMLProject src/main.cpp)

target_include_directories(CMakeSFMLProject PRIVATE imgui-sfml-2.6 imgui-sfml-2.6/imgui-1.90.1)
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
