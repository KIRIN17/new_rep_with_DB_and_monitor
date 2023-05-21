project(monitorTests)

# fetch tests libs
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# windows settings from installation guide
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# enable tests itself
enable_testing()

# configure executable
add_executable(monitorTests utilityTest.cpp parserTest.cpp commandFactoryTest.cpp)

# link with gtest lib
target_link_libraries(monitorTests PUBLIC GTest::gtest_main)
# make gtests available and find tests sources
include(GoogleTest)
gtest_discover_tests(monitorTests)

# include monitor libs
target_include_directories(monitorTests PUBLIC "${Project_root}/monitor")
target_link_libraries(monitorTests PUBLIC monitor)

# add test command classes
add_subdirectory(testCommands)
target_link_libraries(monitorTests PUBLIC testcommands)
