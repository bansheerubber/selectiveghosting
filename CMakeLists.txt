cmake_minimum_required(VERSION 3.0)
project(SelectiveGhosting)
set(CMAKE_CXX_FLAGS "-static -static-libgcc -static-libstdc++ -Wall -Werror")
set(CMAKE_TOOLCHAIN_FILE "./toolchain-mingw32-i686.cmake")
add_library(SelectiveGhosting SHARED
	src/SelectiveGhosting.cpp
	src/RedoBlHooks.cpp
)
set_target_properties(SelectiveGhosting PROPERTIES PREFIX "")
target_link_libraries(
	SelectiveGhosting
	psapi
)