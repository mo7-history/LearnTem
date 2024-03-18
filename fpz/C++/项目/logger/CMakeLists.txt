cmake_minimum_required(VERSION 3.10)
project(logger)

set(CMAKE_CXX_STANDARD 14) # 或者您想要的C++版本

add_executable(logger main.cpp Logger.cpp)

# 如果有头文件，确保添加包含目录 (假设在include目录下)
include_directories(include)

# 若有库依赖，比如mylib，则添加类似以下语句
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(MyProject SomeLibrary)