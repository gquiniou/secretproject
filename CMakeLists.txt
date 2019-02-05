project(SecretProject)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "c:/devtools/mingw-w64/Libs/SFML-2.5.1/lib/cmake/SFML")
#set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/")

find_package(SFML 2.4 COMPONENTS graphics audio REQUIRED)
add_executable(SecretProject src/main.cpp src/Application.cpp src/GameScreen.cpp include/GameScreen.hpp src/ScreenManager.cpp src/PauseScreen.cpp include/PauseScreen.hpp src/GameWorld.cpp include/GameWorld.hpp src/MenuScreen.cpp include/MenuScreen.hpp)

target_include_directories(SecretProject PRIVATE include)
target_link_libraries(SecretProject sfml-graphics)
