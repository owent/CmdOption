cmake_minimum_required(VERSION 2.8)

project(CmdOptionTest)

# 编译选项
#####################################################################
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

#add_definitions(-D_POSIX_MT_)
#remove_definitions(-D_POSIX_MT_)
# 库文件的附加参数 -fPIC, 多线程附加参数 -pthread
set(ALL_FLAGS_IN_ONE_COMMON "-Wall -Werror -Wno-invalid-offsetof") 
set(ALL_FLAGS_IN_ONE_DEBUG "-g -ggdb -O0 ${ALL_FLAGS_IN_ONE_COMMON}")
set(ALL_FLAGS_IN_ONE_RELEASE "-O2 ${ALL_FLAGS_IN_ONE_COMMON} -DNDEBUG")
set(ALL_FLAGS_IN_ONE_RELWITHDEBINFO "-O2 -g -ggdb ${ALL_FLAGS_IN_ONE_COMMON}")
set(ALL_FLAGS_IN_ONE_MINSIZEREL "-Os ${ALL_FLAGS_IN_ONE_COMMON} -DNDEBUG")

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} ${ALL_FLAGS_IN_ONE_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} ${ALL_FLAGS_IN_ONE_RELEASE}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "$ENV{CXXFLAGS} ${ALL_FLAGS_IN_ONE_RELWITHDEBINFO}")
set(CMAKE_CXX_FLAGS_MINSIZEREL "$ENV{CXXFLAGS} ${ALL_FLAGS_IN_ONE_MINSIZEREL}")

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} ${ALL_FLAGS_IN_ONE_DEBUG}")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} ${ALL_FLAGS_IN_ONE_RELEASE}")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "$ENV{CFLAGS} ${ALL_FLAGS_IN_ONE_RELWITHDEBINFO}")
set(CMAKE_C_FLAGS_MINSIZEREL "$ENV{CFLAGS} ${ALL_FLAGS_IN_ONE_MINSIZEREL}")

# 生成库文件
add_subdirectory (src)

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_SOURCE_DIR}/include)

link_directories (${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(. SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

add_executable(CmdOptionTest ${SRC_LIST})

target_link_libraries(CmdOptionTest cmdoption)
