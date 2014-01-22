include_directories ("${PROJECT_SOURCE_DIR}/test")
include_directories ("${PROJECT_SOURCE_DIR}/src")

aux_source_directory(. SRC_LIST)

add_executable(CmdOptionTest ${SRC_LIST})

target_link_libraries(CmdOptionTest cmdoption)

# 安装目标
install(
    TARGETS CmdOptionTest
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib${ARCH_SUFFIX}
    ARCHIVE DESTINATION lib${ARCH_SUFFIX}
)
