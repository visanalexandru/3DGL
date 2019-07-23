//
// Created by gvisan on 23.07.2019.
//

#ifndef INC_3DGL_TEXTURE_H
#define INC_3DGL_TEXTURE_H

#include "stb_image.h"
#include <string>
#include <GLFW/glfw3.h>


class Texture {
protected:
    unsigned texture_index;

    void delete_texture() const;

public:
    virtual void load_texture(const std::string &path) = 0;

    virtual void bind_texture() const = 0;

    Texture();

    virtual ~Texture();
};


#endif //INC_3DGL_TEXTURE_H
