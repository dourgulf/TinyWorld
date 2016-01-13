#pragma once
#include <GL/glew.h>

class Texture
{

public:

    ~Texture();

    void load(const char *filename);
    void bind(GLuint textureUnit);

private:

    void destroy();

    bool loaded = false;

    GLuint id;
};