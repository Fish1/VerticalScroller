cmake_minimum_required(VERSION 2.6)
project(myproject)

file(GLOB SRC src/*.cpp)

set(EXECUTABLE "app")

add_executable(${EXECUTABLE} ${SRC})

message("THIS IS A TEST MESSAGE !!! !!!")

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED system window graphics network audio)

if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
elseif()
	message(STATUS "THIS FAILED TO DO SHIT")
endif()

message(STATUS "${EXECUTABLE}")
message(STATUS "${SFML_FOUND}")
message(STATUS "${SFML_ROOT}")
message(STATUS "${SFML_INCLUDE_DIR}")
message(STATUS "${SFML_LIBRARIES}")
message(STATUS "${SFML_DEPENDENCIES}")

target_compile_options(app PRIVATE "-Werror")
target_compile_options(app PRIVATE "-Wall")
target_compile_options(app PRIVATE "-std=c++11")

install(TARGETS ${EXECUTABLE} DESTINATION bin)

set(RELEASE_DIR "${CMAKE_SOURCE_DIR}/build/release")

add_custom_target(RELEASE)
add_dependencies(RELEASE ${EXECUTABLE})

if(WIN32)
	set(EXECUTABLE "${EXECUTABLE}.exe")
endif(WIN32)

add_custom_command(
	TARGET RELEASE POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build
	COMMAND ${CMAKE_COMMAND} -E make_directory ${RELEASE_DIR}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${RELEASE_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res ${RELEASE_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE} ${RELEASE_DIR}
	)

