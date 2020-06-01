cmake_minimum_required(VERSION 3.16)
project(VkRt VERSION 1.0 DESCRIPTION "Vulkan Raytracer" LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB CPP_FILES src/cpp/**/*.cpp)
add_executable(${PROJECT_NAME} src/cpp/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(ext/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

install(TARGETS ${PROJECT_NAME} glfw RUNTIME DESTINATION bin)
