cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 使用系统安装的 SFML
find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

# 链接到系统安装的 SFML 库
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)