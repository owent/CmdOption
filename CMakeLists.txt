cmake_minimum_required(VERSION 2.8.6)

project(CmdOptionTest)

include ("${PROJECT_SOURCE_DIR}/CompilerOption.cmake")
include ("${PROJECT_SOURCE_DIR}/TargetOption.cmake")

# 生成库文件
add_subdirectory (src)

include_directories ("${PROJECT_SOURCE_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/include")

link_directories ("${PROJECT_SOURCE_DIR}/lib")

aux_source_directory(. SRC_LIST)

add_executable(CmdOptionTest ${SRC_LIST})

target_link_libraries(CmdOptionTest cmdoption)
