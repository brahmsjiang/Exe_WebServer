set(LIB_SRC
    Thread.cpp
)

add_library(lib_base ${LIB_SRC})
target_link_libraries(lib_base pthread rt)

set_target_properties(lib_base PROPERTIES OUTPUT_NAME "base")

