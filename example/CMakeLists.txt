cmake_minimum_required(VERSION 3.22)
project(Monitor_example)

# will load with fetchcontent
include(FetchContent)

# load monitor libs from github
FetchContent_Declare(ConsoleMonitor
        GIT_REPOSITORY https://github.com/kooooootb/ConsoleMonitor.git
        GIT_TAG main
        )
# make em available
FetchContent_MakeAvailable(ConsoleMonitor)

# configure executable
add_executable(example example.cpp date.cpp database.cpp)
# make it compile to output folder
set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/output")

# link with monitor
target_link_libraries(example PUBLIC monitor)

# add our commands
add_subdirectory(myCommands)
# link it with our custom commands
target_link_libraries(example PUBLIC mycommands)
