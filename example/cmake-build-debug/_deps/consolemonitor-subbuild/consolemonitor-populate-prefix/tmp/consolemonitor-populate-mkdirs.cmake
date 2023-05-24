# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-src"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-build"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/tmp"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/src/consolemonitor-populate-stamp"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/src"
  "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/src/consolemonitor-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/src/consolemonitor-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Prog/1Students/ConsoleMonitor-main (1)/ConsoleMonitor/example/cmake-build-debug/_deps/consolemonitor-subbuild/consolemonitor-populate-prefix/src/consolemonitor-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
