project(Monitor)

# make monitor library
add_library(monitor STATIC MonitorOutput.cpp MonitorInput.cpp)
target_include_directories(monitor PUBLIC "${CMAKE_CURRENT_LIST_DIR}/includes")

# add commands
add_subdirectory(commands)
# add utilities
add_subdirectory(utils)

# link with our base commands
target_link_libraries(monitor PUBLIC commands_base)

# and utilities
target_link_libraries(monitor PUBLIC monitor_utils)

# add commons
add_subdirectory(CommonFunctions)
