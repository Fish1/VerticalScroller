cmake_minimum_required(VERSION 2.6)
project(myproject)

file(GLOB SRC src/*.cpp)

set(EXECUTABLE_NAME "app")
add_executable(${EXECUTABLE_NAME} ${SRC})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics network audio)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

target_compile_options(app PRIVATE "-c")
target_compile_options(app PRIVATE "-Werror")
target_compile_options(app PRIVATE "-Wall")

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")

add_custom_target("BUILD")

if(WIN32)
	
	set(EXECUTABLE_NAME "app.exe")

endif(WIN32)

add_custom_command(
	TARGET "BUILD" POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_DIR}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy_directory res ${BUILD_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_NAME} ${BUILD_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${SFML_ROOT}/bin ${BUILD_DIR}
	)

