set(LIB_SRC
    Thread.cpp
)

set(LIB_HEAD
	Thread.h
)

IF(CMAKE_PLATFORM STREQUAL "win64-vs14")
    set(TARGET_NAME "libBase")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
ELSEIF(CMAKE_PLATFORM STREQUAL "linux-x86")
    set(TARGET_NAME "Base")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3" )
ENDIF()

add_library(${TARGET_NAME} ${LIB_HEAD} ${LIB_SRC})

target_link_libraries(${TARGET_NAME} pthread rt)

set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME "Base")

