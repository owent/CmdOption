cmake_minimum_required(VERSION 2.8)

# set(CMAKE_BUILD_TYPE "Debug") 
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
include_directories (${PROJECT_SOURCE_DIR}/src)

aux_source_directory(. SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

add_library(cmdoption ${SRC_LIST})

# 必须支持POSIX命令集（Windows下请安装MinGW和msys，并把相应bin目录都加到path下）
exec_program (rm ${PROJECT_SOURCE_DIR}/src ARGS -rf ${PROJECT_SOURCE_DIR}/include/*.h)
exec_program (cp ${PROJECT_SOURCE_DIR}/src ARGS ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/include/)
