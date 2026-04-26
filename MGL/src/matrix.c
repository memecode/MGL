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

#include <stdio.h>
#include <stdint.h>

#include "mgl.h"

void mglMatrixMode(GLMContext ctx, GLenum mode)
{
    ctx->state.var.matrix_mode = mode;
}

void mglLoadIdentity(GLMContext ctx)
{
    NO_IMPL
}

void mglOrtho(GLMContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    NO_IMPL
}




