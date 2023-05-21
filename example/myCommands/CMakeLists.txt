project(mycommands)

# make library
add_library(mycommands STATIC Init.cpp Help.cpp Print.cpp Add.cpp Find.cpp Del.cpp Last.cpp condition_parser.cpp node.cpp token.cpp)
target_include_directories(mycommands PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# link it with commands bases
target_link_libraries(mycommands commands_base)
