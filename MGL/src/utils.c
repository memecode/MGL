/*
 * Copyright (C) Michael Larson on 1/6/2022
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * utils.c
 * MGL
 *
 */

#include <math.h>
#include <stdbool.h>

#include "utils.h"

#include "glcorearb.h"
#include "glm_context.h"
#include "mgl.h"

GLuint ilog2(GLuint val)
{
    if (val == 0)
        return 0;
    
    return (GLuint)floor(log2(val));
}

GLfloat clamp(GLfloat a, GLfloat min, GLfloat max)
{
    a = MAX(a, min);
    a = MIN(a, max);

    return a;
}

GLuint maxLevels(GLuint width, GLuint height, GLuint depth)
{
    return (ilog2(MAX(width, MAX(height, depth))) + 1);
}

GLboolean checkMaxLevels(GLuint levels, GLuint width, GLuint height, GLuint depth)
{
    return levels <= maxLevels(width, height, depth);
}

#define CAP_OP(_var_) \
    if (store) state->caps._var_ = ctx->state.caps._var_; \
    else       ctx->state.caps._var_ = state->caps._var_;

#define VAR_OP(_var_) \
    if (store) state->var._var_ = ctx->state.var._var_; \
    else       ctx->state.var._var_ = state->var._var_;

void mglStackOp(GLMContext ctx, GLbitfield mask, GLboolean store)
{
    if (ctx->cur_stack < 0 || ctx->cur_stack >= STATE_STACK_SIZE)
        ERROR_RETURN(GL_INVALID_INDEX);
    GLMState *state = ctx->stack + ctx->cur_stack;
    const char *op_name = store ? "saving" : "loading";

    if (mask & GL_ACCUM_BUFFER_BIT)
    {
        // Accumulation buffer clear value
        printf("%s:%i - %s impl: GL_ACCUM_BUFFER_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_COLOR_BUFFER_BIT)
    {
        /*
        GL_ALPHA_TEST enable bit
        Alpha test function and reference value
        GL_BLEND enable bit
        Blending source and destination functions
        Constant blend color
        Blending equation
        GL_DITHER enable bit
        GL_DRAW_BUFFER setting
        GL_COLOR_LOGIC_OP enable bit
        GL_INDEX_LOGIC_OP enable bit
        Logic op function
        Color mode and index mode clear values
        Color mode and index mode writemasks 
        */
        printf("%s:%i - %s impl: GL_COLOR_BUFFER_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_CURRENT_BIT)
    {
        /*
        Current RGBA color
        Current color index
        Current normal vector
        Current texture coordinates
        Current raster position
        GL_CURRENT_RASTER_POSITION_VALID flag
        RGBA color associated with current raster position
        Color index associated with current raster position
        Texture coordinates associated with current raster position
        GL_EDGE_FLAG flag 
        */
        printf("%s:%i - %s impl: GL_CURRENT_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_DEPTH_BUFFER_BIT)
    {
        /*
        GL_DEPTH_TEST enable bit
        Depth buffer test function
        Depth buffer clear value
        GL_DEPTH_WRITEMASK enable bit
        */
        printf("%s:%i - %s impl: GL_DEPTH_BUFFER_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_ENABLE_BIT)
    {
            
        // caps:
        CAP_OP(alpha_test); // GL_ALPHA_TEST flag
        CAP_OP(auto_normal); // GL_AUTO_NORMAL flag
        CAP_OP(color_material); // GL_COLOR_MATERIAL
        CAP_OP(cull_face); // GL_CULL_FACE flag
        CAP_OP(depth_test); // GL_DEPTH_TEST flag
        CAP_OP(dither); // GL_DITHER flag
        CAP_OP(fog); // GL_FOG flag
        CAP_OP(lighting); // GL_LIGHTING flag
        CAP_OP(line_smooth); // GL_LINE_SMOOTH flag
        CAP_OP(line_stipple); // GL_LINE_STIPPLE flag
        CAP_OP(color_logic_op); // GL_COLOR_LOGIC_OP flag
        CAP_OP(index_logic_op); // GL_INDEX_LOGIC_OP flag
        CAP_OP(multisample); // GL_MULTISAMPLE flag
        CAP_OP(normalize); // GL_NORMALIZE flag
        CAP_OP(point_smooth); // GL_POINT_SMOOTH flag
        CAP_OP(polygon_offset_line); // GL_POLYGON_OFFSET_LINE flag
        CAP_OP(polygon_offset_fill); // GL_POLYGON_OFFSET_FILL flag
        CAP_OP(polygon_offset_point); // GL_POLYGON_OFFSET_POINT flag
        CAP_OP(polygon_smooth); // GL_POLYGON_SMOOTH flag
        CAP_OP(polygon_stipple); // GL_POLYGON_STIPPLE flag
        CAP_OP(sample_alpha_to_coverage); // GL_SAMPLE_ALPHA_TO_COVERAGE flag
        CAP_OP(sample_alpha_to_one); // GL_SAMPLE_ALPHA_TO_ONE flag
        CAP_OP(sample_coverage); // GL_SAMPLE_COVERAGE flag
        CAP_OP(scissor_test); // GL_SCISSOR_TEST flag
        CAP_OP(stencil_test); // GL_STENCIL_TEST flag
        
        // vars:
        for (int i=0; i<MAX_COLOR_ATTACHMENTS; i++) // GL_BLEND flag
        {
            VAR_OP(blend_src_rgb[i]);
            VAR_OP(blend_src_alpha[i]);
            VAR_OP(blend_dst_rgb[i]);
            VAR_OP(blend_dst_alpha[i]);
        }

        VAR_OP(map1_grid_domain); // GL_MAP1_x where x is a map type
        VAR_OP(map1_grid_segments);
        VAR_OP(map2_grid_domain); // GL_MAP2_x where x is a map type
        VAR_OP(map2_grid_segments);
        VAR_OP(texture_binding_1d); // GL_TEXTURE_1D flag
        VAR_OP(texture_binding_2d); // GL_TEXTURE_2D flag
        VAR_OP(texture_binding_3d); // GL_TEXTURE_3D flag
        
        /* Things with no mapping?
            - Enable bits for the user-definable clipping planes        
            - GL_LIGHTi where 0 <= i < GL_MAX_LIGHTS        
            - Flags GL_TEXTURE_GEN_x where x is S, T, R, or Q */

        printf("%s:%i - %s %s GL_ENABLE_BIT fields\n", __FILE__, __LINE__, __func__, op_name);
    }

    if (mask & GL_EVAL_BIT)
    {
        /*
        GL_MAP1_x enable bits, where x is a map type
        GL_MAP2_x enable bits, where x is a map type
        1D grid endpoints and divisions
        2D grid endpoints and divisions
        GL_AUTO_NORMAL enable bit 
        */
        printf("%s:%i - %s impl: GL_EVAL_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_FOG_BIT)
    {
        /*
        GL_FOG enable bit
        Fog color
        Fog density
        Linear fog start
        Linear fog end
        Fog index
        GL_FOG_MODE value
        */
        printf("%s:%i - %s impl: GL_FOG_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_HINT_BIT)
    {
        /*
        GL_PERSPECTIVE_CORRECTION_HINT setting
        GL_POINT_SMOOTH_HINT setting
        GL_LINE_SMOOTH_HINT setting
        GL_POLYGON_SMOOTH_HINT setting
        GL_FOG_HINT setting
        GL_GENERATE_MIPMAP_HINT setting
        GL_TEXTURE_COMPRESSION_HINT setting
        */
        printf("%s:%i - %s impl: GL_HINT_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_LIGHTING_BIT)
    {
        /*
        GL_COLOR_MATERIAL enable bit
        GL_COLOR_MATERIAL_FACE value
        Color material parameters that are tracking the current color
        Ambient scene color
        GL_LIGHT_MODEL_LOCAL_VIEWER value
        GL_LIGHT_MODEL_TWO_SIDE setting
        GL_LIGHTING enable bit
        Enable bit for each light
        Ambient, diffuse, and specular intensity for each light
        Direction, position, exponent, and cutoff angle for each light
        Constant, linear, and quadratic attenuation factors for each light
        Ambient, diffuse, specular, and emissive color for each material
        Ambient, diffuse, and specular color indices for each material
        Specular exponent for each material
        GL_SHADE_MODEL setting 
        */
        printf("%s:%i - %s impl: GL_LIGHTING_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_LINE_BIT)
    {
        /*
        GL_LINE_SMOOTH flag
        GL_LINE_STIPPLE enable bit
        Line stipple pattern and repeat counter
        Line width 
        */
        printf("%s:%i - %s impl: GL_LINE_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_LIST_BIT)
    {
        /*
        GL_LIST_BASE setting
        */
        printf("%s:%i - %s impl: GL_LIST_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_MULTISAMPLE_BIT)
    {
        /*
        GL_MULTISAMPLE flag
        GL_SAMPLE_ALPHA_TO_COVERAGE flag
        GL_SAMPLE_ALPHA_TO_ONE flag
        GL_SAMPLE_COVERAGE flag
        GL_SAMPLE_COVERAGE_VALUE value
        GL_SAMPLE_COVERAGE_INVERT value 
        */
        printf("%s:%i - %s impl: GL_MULTISAMPLE_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_PIXEL_MODE_BIT)
    {
        /*
        GL_RED_BIAS and GL_RED_SCALE settings
        GL_GREEN_BIAS and GL_GREEN_SCALE values
        GL_BLUE_BIAS and GL_BLUE_SCALE
        GL_ALPHA_BIAS and GL_ALPHA_SCALE
        GL_DEPTH_BIAS and GL_DEPTH_SCALE
        GL_INDEX_OFFSET and GL_INDEX_SHIFT values
        GL_MAP_COLOR and GL_MAP_STENCIL flags
        GL_ZOOM_X and GL_ZOOM_Y factors
        GL_READ_BUFFER setting
        */
        printf("%s:%i - %s impl: GL_PIXEL_MODE_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_POINT_BIT)
    {
        /*
        GL_POINT_SMOOTH flag
	    Point size
        */
        printf("%s:%i - %s impl: GL_POINT_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_POLYGON_BIT)
    {
        /*
        GL_CULL_FACE enable bit
        GL_CULL_FACE_MODE value
        GL_FRONT_FACE indicator
        GL_POLYGON_MODE setting
        GL_POLYGON_SMOOTH flag
        GL_POLYGON_STIPPLE enable bit
        GL_POLYGON_OFFSET_FILL flag
        GL_POLYGON_OFFSET_LINE flag
        GL_POLYGON_OFFSET_POINT flag
        GL_POLYGON_OFFSET_FACTOR
        GL_POLYGON_OFFSET_UNITS
        */
         printf("%s:%i - %s impl: GL_POLYGON_BIT\n", __FILE__, __LINE__, __func__);
   }

    if (mask & GL_POLYGON_STIPPLE_BIT)
    {
        // Polygon stipple image
        printf("%s:%i - %s impl: GL_POLYGON_STIPPLE_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_SCISSOR_BIT)
    {
        /*
        GL_SCISSOR_TEST flag
	    Scissor box
        */
        printf("%s:%i - %s impl: GL_SCISSOR_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_STENCIL_BUFFER_BIT)
    {
        /*
        GL_STENCIL_TEST enable bit
        Stencil function and reference value
        Stencil value mask
        Stencil fail, pass, and depth buffer pass actions
        Stencil buffer clear value
        Stencil buffer writemask
        */
         printf("%s:%i - %s impl: GL_STENCIL_BUFFER_BIT\n", __FILE__, __LINE__, __func__);
   }

    if (mask & GL_TEXTURE_BIT)
    {
        /*
        Enable bits for the four texture coordinates
        Border color for each texture image
        Minification function for each texture image
        Magnification function for each texture image
        Texture coordinates and wrap mode for each texture image
        Color and mode for each texture environment
        Enable bits GL_TEXTURE_GEN_x, x is S, T, R, and Q
        GL_TEXTURE_GEN_MODE setting for S, T, R, and Q
        glTexGen plane equations for S, T, R, and Q
        Current texture bindings (for example, GL_TEXTURE_BINDING_2D)
        */
        printf("%s:%i - %s impl: GL_TEXTURE_BIT\n", __FILE__, __LINE__, __func__);
   }

    if (mask & GL_TRANSFORM_BIT)
    {
        /*
        Coefficients of the six clipping planes
        Enable bits for the user-definable clipping planes
        GL_MATRIX_MODE value
        GL_NORMALIZE flag
        GL_RESCALE_NORMAL flag
        */
        printf("%s:%i - %s impl: GL_TRANSFORM_BIT\n", __FILE__, __LINE__, __func__);
    }

    if (mask & GL_VIEWPORT_BIT)
    {
        /*
        Depth range (near and far)
	    Viewport origin and extent
        */
        printf("%s:%i - %s impl: GL_VIEWPORT_BIT\n", __FILE__, __LINE__, __func__);
    }
}

void mglPushAttrib(GLMContext ctx, GLbitfield mask)
{
    if (ctx->cur_stack < -1 || ctx->cur_stack >= STATE_STACK_SIZE - 1)
        ERROR_RETURN(GL_INVALID_INDEX);

    ctx->cur_stack++;
    mglStackOp(ctx, mask, true);
}

void mglPopAttrib(GLMContext ctx)
{
    if (ctx->cur_stack < 0 || ctx->cur_stack >= STATE_STACK_SIZE)
    {
        printf("%s:%i:%i - invalid cur stack: %i\n", _FL, __func__, ctx->cur_stack);
        ERROR_RETURN(GL_INVALID_INDEX);
    }

    mglStackOp(ctx, ctx->stack[ctx->cur_stack].stack_bits, false);
    ctx->cur_stack--;
}

