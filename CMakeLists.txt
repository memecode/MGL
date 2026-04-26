cmake_minimum_required(VERSION 3.20)
project(openglonmetal)

# brew install glslang
# brew install SPIRV-Cross

message("CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

set(SPIRV_CROSS "${CMAKE_BINARY_DIR}/SPIRV-Cross")
if(NOT EXISTS "${SPIRV_CROSS}")
    message("SPIRV_CROSS=${SPIRV_CROSS} not found...")
    set(SCRIPT "${CMAKE_CURRENT_LIST_DIR}/external/xcbuild-SPIRV-Cross.sh")
    message("SCRIPT=${SCRIPT}")
    execute_process(
        COMMAND bash ${SCRIPT}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        RESULT_VARIABLE result
        OUTPUT_VARIABLE out
        ERROR_VARIABLE err)
    # message("execute_process: ${result} ${out} ${err}")
    if(${result})
        message(FATAL_ERROR "execute_process failed: ${out} ${err}")
    endif()
endif()

option(MGL_USE_ES_API "Use the OpenGL ES Api" FALSE)

set(SOURCES
    MGL/src/buffers.c
    MGL/src/buffers.h
    MGL/src/compute.c
    MGL/src/draw_buffers.c
    MGL/src/error.c
    MGL/src/fence.c
    MGL/src/framebuffers.c
    MGL/src/get.c
    MGL/src/glm_context.c
    MGL/src/glm_dispatch.c
    MGL/src/glm_params.c
    MGL/src/hash_table.m
    MGL/src/mgl_funcs_to_be_implemented.c
    MGL/src/mgl_safety.h
    MGL/src/mgl_toolchain.c
    MGL/src/MGLRenderer.m
    MGL/src/MGLTextures.m
    MGL/src/non_core_unimplemented.c
    MGL/src/pixel_utils.c
    MGL/src/program.c
    MGL/src/programs.h
    MGL/src/rendering.c
    MGL/src/samplers.c
    MGL/src/shaders.c
    MGL/src/shaders.h
    MGL/src/state.c
    MGL/src/tex_param.c
    MGL/src/textures.c
    MGL/src/textures.c.with_debug
    MGL/src/textures.c.with_lots_of_debug
    MGL/src/uniforms.c
    MGL/src/utils.c
    MGL/src/matrix.c
    MGL/src/vertex_arrays.c
    MGL/src/vertex_arrays.h
    MGL/src/vertex_buffers.c
    MGL/src/bar_glue.c)

if(MGL_USE_ES_API)
    list(APPEND SOURCES MGL/src/gl_es.c)
else()
    list(APPEND SOURCES MGL/src/gl_core.c)
endif()

add_library(openglonmetal SHARED
    ${SOURCES})

target_include_directories(openglonmetal
    PUBLIC
        MGL/include
        MGL/include/GL
        external/glfw/deps
        external/glfw/include
    PRIVATE
        /opt/homebrew/Cellar/glslang/16.2.0/include/glslang/Include
        /opt/homebrew/Cellar/spirv-tools/1.4.341.0/include
        ${CMAKE_BINARY_DIR}/SPIRV-Cross)

if(MGL_USE_ES_API)
    target_compile_definitions(openglonmetal
        PRIVATE
            MGL_GL_ES)
else()
    target_compile_definitions(openglonmetal
        PRIVATE
            MGL_GL_CORE)
endif()

target_link_directories(openglonmetal PRIVATE
    "/opt/homebrew/lib")
target_link_libraries(openglonmetal PRIVATE
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework Metal"
    "-framework QuartzCore"
    glslang
    glslang-default-resource-limits
    spirv-cross-c
    spirv-cross-core
    spirv-cross-msl
    spirv-cross-cpp
    spirv-cross-glsl
    spirv-cross-hlsl
    spirv-cross-reflect
    c++)

# turn off symbol exports, except ones explicitly marked:
target_compile_options(openglonmetal PRIVATE "-fvisibility=hidden")
if(1)
    # don't demangle things for debugging:
    target_link_options(openglonmetal PRIVATE "-Wl,--no-demangle")
endif()