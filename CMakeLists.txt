cmake_minimum_required(VERSION 3.29.2)
project(v_win_1 VERSION 0.1.0 LANGUAGES CXX)

include (build/build/generators/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_CXX_MODULE_E_MAPPER_MODE ".cpp")
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("/experimental:module")
add_compile_options("/std:c++latest")

file(GLOB_RECURSE __file "src/*.ixx" "src/*.cpp" )
message("Find files: ${__file}")

add_executable(v_win_1 ${__file})

find_package(Vulkan REQUIRED)
message("Vulkan: ${Vulkan_INCLUDE_DIRS} ${Vulkan_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES})

find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)


find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)



message("${CMAKE_INCLUDE_PATH}")