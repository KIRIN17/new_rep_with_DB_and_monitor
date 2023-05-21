project(testcommands)

# make library
add_library(testcommands STATIC Init.cpp Help.cpp)
target_include_directories(testcommands PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# link it with commands bases
target_link_libraries(testcommands commands_base)
