cmake_minimum_required(VERSION 3.20)
project(openglonmetal)

# brew install glslang
# brew install SPIRV-Cross

#     MGL/src/gl_core.c

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

add_library(openglonmetal
    MGL/src/buffers.c
    MGL/src/buffers.h
    MGL/src/compute.c
    MGL/src/draw_buffers.c
    MGL/src/error.c
    MGL/src/fence.c
    MGL/src/framebuffers.c
    MGL/src/get.c
    MGL/src/gl_es.c
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
    MGL/src/vertex_arrays.c
    MGL/src/vertex_arrays.h
    MGL/src/vertex_buffers.c)

target_include_directories(openglonmetal
    PRIVATE
        MGL/include
        MGL/include/GL
        /opt/homebrew/Cellar/glslang/16.2.0/include/glslang/Include
        /opt/homebrew/Cellar/spirv-tools/1.4.341.0/include
        ${CMAKE_BINARY_DIR}/SPIRV-Cross)

target_compile_definitions(openglonmetal
    PRIVATE
        MGL_GL_ES)