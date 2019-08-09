//
// Created by gvisan on 23.07.2019.
//

#ifndef INC_3DGL_TEXTURE2D_H
#define INC_3DGL_TEXTURE2D_H

#include "../../Resource/Resource.h"
#include "../stb_image.h"
#include<iostream>
namespace gl3d {

    class Texture2D : public Resource{
        void unload_resource() const override ;

    public:
        void load_texture(const std::string &path);

        void bind_resource() const override;

        static void bind_empty_texture();


        ~Texture2D();
    };

}
#endif //INC_3DGL_TEXTURE2D_H
