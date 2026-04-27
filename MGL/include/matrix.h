#pragma once

#include <GL/glcorearb.h>

typedef enum {
    MATRIX_FLT,
    MATRIX_DBL
}   mgl_matrix_t;

typedef struct Matrix_t {
    mgl_matrix_t type;
    union {
        GLfloat  flt[4][4]; // type == MATRIX_FLT
        GLdouble dbl[4][4]; // type == MATRIX_DBL
    };
}   Matrix;