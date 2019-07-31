//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_CUBEMAP_H
#define INC_3DGL_CUBEMAP_H

#include "../Texture.h"
#include <iostream>

class Cubemap : public Texture {
public:

    void load_texture(const std::string &path) override;

    void bind_texture() const override;

    static std::string cubemap_names[6];
};


#endif //INC_3DGL_CUBEMAP_H
