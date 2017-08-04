cmake_minimum_required(VERSION 2.6)
project(myproject)

file(GLOB SRC src/*.cpp)

set(EXECUTABLE_NAME "app")
add_executable(${EXECUTABLE_NAME} ${SRC})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

target_compile_options(app PRIVATE "-c")
target_compile_options(app PRIVATE "-Werror")
target_compile_options(app PRIVATE "-Wall")

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
