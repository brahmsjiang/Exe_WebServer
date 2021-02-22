set(SRCS
    Main.cpp
    Server.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/base)


add_executable(server ${SRCS})
target_link_libraries(server libBase)
