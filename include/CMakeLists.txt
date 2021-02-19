aux_source_directory(. CODE)
set(CMAKE_BUILD_TYPE Debug)
add_library(code ${CODE})

message(STATUS "code library: " ${CODE})