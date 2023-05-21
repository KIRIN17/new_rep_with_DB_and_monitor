project(CommonFunction)

# common functions library
add_library(monitor_common STATIC CommonFunctions.cpp)
target_include_directories(monitor_common PUBLIC ${CMAKE_CURRENT_LIST_DIR})
