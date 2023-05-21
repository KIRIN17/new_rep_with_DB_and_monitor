project(Monitor_utils)

add_library(monitor_utils STATIC utilFunctions.cpp)
target_include_directories(monitor_utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})
