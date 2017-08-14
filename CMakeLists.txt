cmake_minimum_required(VERSION 2.6)
project(myproject)

file(GLOB SRC src/*.cpp)

set(EXECUTABLE "app")

add_executable(${EXECUTABLE} ${SRC})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics network audio)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE} ${SFML_LIBRARIES})

target_compile_options(app PRIVATE "-Werror")
target_compile_options(app PRIVATE "-Wall")

install(TARGETS ${EXECUTABLE} DESTINATION bin)

set(RELEASE_DIR "${CMAKE_SOURCE_DIR}/release")

add_custom_target(RELEASE)
add_dependencies(RELEASE ${EXECUTABLE})

if(WIN32)
	set(EXECUTABLE "${EXECUTABLE}.exe")
endif(WIN32)

add_custom_command(
	TARGET RELEASE POST_RELEASE
	COMMAND ${CMAKE_COMMAND} -E make_directory ${RELEASE_DIR}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${RELEASE_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy_directory res ${RELEASE_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE} ${RELEASE_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${SFML_ROOT}/bin ${RELEASE_DIR}
	)

