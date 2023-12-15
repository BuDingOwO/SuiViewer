project(Viewer VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE lib_imgui_cpp CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/Extern/imgui/*.cpp)
#file(GLOB_RECURSE lib_imgui_h CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/Extern/imgui/*.h)
#file(GLOB_RECURSE lib_stb_h CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/Extern/stb/*.h)

add_executable(Viewer WIN32
        ${srcs}
        ${lib_imgui_cpp}
)

target_include_directories(Viewer PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/Extern/imgui/
        ${CMAKE_SOURCE_DIR}/Extern/stb/
)

target_link_libraries(Viewer PRIVATE CoreShard)

find_package(FreeGLUT CONFIG REQUIRED)
target_link_libraries(Viewer PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)

target_link_libraries(Viewer PRIVATE opengl32)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Viewer PRIVATE glfw)

target_link_libraries(Viewer PRIVATE
        -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
)

#add_custom_command(TARGET Viewer POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/View/res ${CMAKE_CURRENT_BINARY_DIR}/res
#)
