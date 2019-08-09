//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_CUBEMAP_H
#define INC_3DGL_CUBEMAP_H

#include "../../Resource/Resource.h"
#include "../stb_image.h"
#include <iostream>

namespace gl3d {

    class Cubemap : public Resource {
        void unload_resource() const override;

    public:

        void load_texture(const std::string &path);

        void bind_resource() const override;


        static std::string cubemap_names[6];
    };
}

#endif //INC_3DGL_CUBEMAP_H
