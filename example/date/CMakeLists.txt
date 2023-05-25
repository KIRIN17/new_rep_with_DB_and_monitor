add_library(Dates STATIC date.cpp)
target_include_directories(Dates PUBLIC ${CMAKE_CURRENT_LIST_DIR})