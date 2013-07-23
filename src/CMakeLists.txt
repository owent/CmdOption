include_directories ("${PROJECT_SOURCE_DIR}/src")
aux_source_directory(. SRC_LIST)

add_library(cmdoption ${SRC_LIST})

# 必须支持POSIX命令集（Windows下请安装MinGW和msys，并把相应bin目录都加到path下）
file(REMOVE "${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB ALL_LIB_HEADERS  "${PROJECT_SOURCE_DIR}/src/*.h")
file(COPY ${ALL_LIB_HEADERS} DESTINATION "${PROJECT_SOURCE_DIR}/include" USE_SOURCE_PERMISSIONS )

