cmake_minimum_required(VERSION 3.10)
project(2D_GameEngine)

#find_package(SDL2_REQUIRED)

#file(GLOB SOURCES src/*.cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(2D_GameEngine src/main.cpp src/Game.cpp src/Game.h src/ECS/TextureManager.h src/ECS/TextureManager.cpp src/Map.cpp src/Map.h src/ECS/EntityComponentSystem.h src/ECS/Components.h src/ECS/SpriteComponent.h src/ECS/PositionComponent.h)

target_link_libraries(2D_GameEngine -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -mwindows)


