project(Core VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_library(CoreStatic STATIC ${srcs})
target_include_directories(CoreStatic PUBLIC include)


add_library(CoreShard SHARED ${srcs})
target_include_directories(CoreShard PUBLIC include)


add_custom_command(TARGET CoreShard POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CoreShard> ${CMAKE_CURRENT_BINARY_DIR}/../Viewer/Core.dll
)

#add_custom_target(CopyCoreShard ALL DEPENDS CoreShard)


