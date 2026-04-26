#include <stdio.h>

#include "GL/glcorearb.h"
#include "GL/bar_glue.h"

int GLAD_GL_VERSION_1_0 = 0;
int GLAD_GL_VERSION_1_1 = 0;
int GLAD_GL_VERSION_1_2 = 0;
int GLAD_GL_VERSION_1_3 = 0;
int GLAD_GL_VERSION_1_4 = 0;
int GLAD_GL_VERSION_1_5 = 0;
int GLAD_GL_VERSION_2_0 = 0;
int GLAD_GL_VERSION_2_1 = 0;
int GLAD_GL_VERSION_3_0 = 0;
int GLAD_GL_VERSION_3_1 = 0;
int GLAD_GL_VERSION_3_2 = 0;
int GLAD_GL_VERSION_3_3 = 1;
int GLAD_GL_VERSION_4_0 = 1;
int GLAD_GL_VERSION_4_1 = 1;
int GLAD_GL_VERSION_4_2 = 1;
int GLAD_GL_VERSION_4_3 = 1;
int GLAD_GL_VERSION_4_4 = 1;
int GLAD_GL_VERSION_4_5 = 1;
int GLAD_GL_VERSION_4_6 = 1;

#define NO_IMPL printf("%s:%i - %s not impl\n", __FILE__, __LINE__, __func__);

void glBindFramebufferEXT(GLenum target, GLuint framebuffer)
{
    NO_IMPL
}

void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value)
{
    NO_IMPL
}

void glGenerateMipmapEXT(GLenum target)
{
    NO_IMPL
}

void glGenFramebuffersEXT(GLsizei n, GLuint *framebuffers)
{
    NO_IMPL
}

void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers)
{
    NO_IMPL
}

void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    NO_IMPL
}

void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    NO_IMPL
}

void glDeleteRenderbuffersEXT(GLsizei n, const GLuint *renderbuffers)
{
    NO_IMPL
}

void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer)
{
    NO_IMPL
}

void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
    NO_IMPL
}

void glActiveTextureARB(GLenum texture)
{
    NO_IMPL
}

void glBindProgramARB(GLenum target, GLuint program)
{
    NO_IMPL
}

void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NO_IMPL
}

void glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat *params)
{
    NO_IMPL
}

void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    NO_IMPL
}

void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
    NO_IMPL
}

void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void *string)
{
    NO_IMPL
}

void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data)
{
    NO_IMPL
}

void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)
{
    NO_IMPL
}

void glDeleteFramebuffersEXT(GLsizei n, const GLuint *framebuffers)
{
    NO_IMPL
}

void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    NO_IMPL
}

void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    NO_IMPL
}

void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    NO_IMPL
}

void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
    NO_IMPL
}

void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
    NO_IMPL
}

void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
    NO_IMPL
}

GLboolean glIsRenderbufferEXT(GLuint renderbuffer)
{
    NO_IMPL
    return GL_FALSE;
}
