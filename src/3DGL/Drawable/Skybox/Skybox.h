//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_SKYBOX_H
#define INC_3DGL_SKYBOX_H


#include "../../Texture/Cubemap/Cubemap.h"
#include "../../Mesh/Mesh.h"
#include "../../Shader/DefaultShaders/DefaultShaders.h"
#include "../../Mesh/MeshBuilder/MeshBuilder.h"

namespace gl3d {

    class Skybox {
    private:
        Mesh cube_mesh;
        const Cubemap &text_cubemap;
    public:
        void bind_texture() const;
        void bind_mesh() const;
        Skybox(const Cubemap &cubemap);

    };

}
#endif //INC_3DGL_SKYBOX_H
