project(commands)

# make library
add_library(commands_base STATIC BaseCommand.cpp Parser.cpp)
target_include_directories(commands_base PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(commands_base PUBLIC monitor_utils)
