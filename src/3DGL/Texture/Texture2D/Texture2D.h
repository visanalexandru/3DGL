//
// Created by gvisan on 23.07.2019.
//

#ifndef INC_3DGL_TEXTURE2D_H
#define INC_3DGL_TEXTURE2D_H

#include "../Texture.h"
#include<iostream>
namespace gl3d {

    class Texture2D : public Texture {
    public:
        void load_texture(const std::string &path) override;

        void bind_texture() const override;
    };

}
#endif //INC_3DGL_TEXTURE2D_H
