//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_CUBEMAP_H
#define INC_3DGL_CUBEMAP_H

#include "../../Resource/Resource.h"
#include "../stb_image.h"
#include <iostream>
#include <vector>

namespace gl3d {

    class Cubemap : public Resource {
        void delete_cubemap() const;

    public:

        void load_texture(const std::string &path, const std::vector<std::string> &paths);

        void bind_cubemap() const;


    };
}

#endif //INC_3DGL_CUBEMAP_H
