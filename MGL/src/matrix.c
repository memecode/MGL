/*
 * Copyright (C) Matthew Allen on 26/4/2026
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
 * matrix.c
 * MGL
 *
 */

#include "matrix.h"
#include <stdio.h>
#include <stdint.h>

#include "glcorearb.h"
#include "mgl.h"

void mglMatrixMode(GLMContext ctx, GLenum mode)
{
    ctx->state.var.matrix_mode = mode;
}

static void matrix_identity(Matrix *m)
{
    GLdouble d[4][4] = {{ 1.0, 0.0, 0.0, 0.0 },
                        { 0.0, 1.0, 0.0, 0.0 },
                        { 0.0, 0.0, 1.0, 0.0 },
                        { 0.0, 0.0, 0.0, 1.0 }};
    m->type = MATRIX_DBL;
    m->dbl[0][0] = 1.0;
    m->dbl[1][0] = 0.0;
    m->dbl[2][0] = 0.0;
    m->dbl[3][0] = 0.0;

    m->dbl[0][1] = 0.0;
    m->dbl[1][1] = 1.0;
    m->dbl[2][1] = 0.0;
    m->dbl[3][1] = 0.0;

    m->dbl[0][2] = 0.0;
    m->dbl[1][2] = 0.0;
    m->dbl[2][2] = 1.0;
    m->dbl[3][2] = 0.0;

    m->dbl[0][3] = 0.0;
    m->dbl[1][3] = 0.0;
    m->dbl[2][3] = 0.0;
    m->dbl[3][3] = 1.0;
}

void mglLoadIdentity(GLMContext ctx)
{
    matrix_identity(&ctx->state.matrix);
}

void mglOrtho(GLMContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    Matrix *m = &ctx->state.matrix;
}




