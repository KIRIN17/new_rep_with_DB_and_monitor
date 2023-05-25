add_library(Nodes STATIC condition_parser.cpp token.cpp node.cpp)
target_include_directories(Nodes PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Nodes PUBLIC Dates)