//
// Created by gvisan on 23.07.2019.
//

#ifndef INC_3DGL_TEXTURE_H
#define INC_3DGL_TEXTURE_H

#include "stb_image.h"
#include <string>
#include <glad/glad.h>


class Texture {
protected:
    unsigned texture_index;

    void delete_texture() const;

public:
    virtual void load_texture(const std::string &path) = 0;

    const unsigned get_texture_index() const;

    Texture &operator=(const Texture &other) = delete;

    Texture(const Texture &other) = delete;

    virtual void bind_texture() const = 0;

    Texture();

    virtual ~Texture();
};


#endif //INC_3DGL_TEXTURE_H
