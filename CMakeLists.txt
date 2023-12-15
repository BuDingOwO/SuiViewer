cmake_minimum_required(VERSION 3.24)

IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF ()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_COMPILER "D:\\Program Files\\w64devkit\\bin\\g++.exe")
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(SuiViewer VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(Viewer)
add_subdirectory(Core)

set(CMAKE_TOOLCHAIN_FILE "D://vcpkg")


#add_library(glfw STATIC IMPORTED)
#set_property(TARGET glfw PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Extern/glfw/lib-mingw-w64/libglfw3.a)
#target_include_directories(glfw INTERFACE ${CMAKE_SOURCE_DIR}/Extern/glfw/include/ )

#target_link_libraries(Core PUBLIC glfw)
#target_link_libraries(Viewer PUBLIC glfw)






