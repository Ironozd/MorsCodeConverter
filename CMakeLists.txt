cmake_minimum_required(VERSION 3.7.0)
project(Mors VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMDEBUG")

file(GLOB mors
"src/*/*.h"
"src/*/*.cpp"
)

add_executable(mors_file src/mors_file.cpp ${mors})

add_executable(mors_convert src/mors_converter.cpp ${mors})
set(CMAKE_EXE_LINKER_FLAGS " -static")
target_link_libraries(mors_file -static-libgcc -static-libstdc++)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
