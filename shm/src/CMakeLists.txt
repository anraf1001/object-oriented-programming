cmake_minimum_required(VERSION 3.10)

set(SOURCES
    alcohol.cpp
    cargo.cpp
    coordinates.cpp
    dryfruit.cpp
    fruit.cpp
    game.cpp
    globaltime.cpp
    island.cpp
    item.cpp
    map.cpp
    player.cpp
    ship.cpp
    store.cpp
    time.cpp
    )

add_library(${shm_lib} STATIC ${SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_link_libraries(${PROJECT_NAME} ${shm_lib})
