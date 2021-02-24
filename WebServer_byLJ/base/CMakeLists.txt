set(LIB_SRC
    Thread.cpp
	Logging.cpp
	LogStream.cpp
)

set(LIB_HEAD
	Thread.h
	Logging.h
	LogStream.h
)

IF(CMAKE_PLATFORM STREQUAL "win64-vs14")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
ELSEIF(CMAKE_PLATFORM STREQUAL "linux-x86")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3" )
ENDIF()

add_library(libBase ${LIB_HEAD} ${LIB_SRC})

target_link_libraries(libBase)

set_target_properties(libBase PROPERTIES OUTPUT_NAME "Base")

