//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_SKYBOX_H
#define INC_3DGL_SKYBOX_H

#include "../Drawable3D.h"
#include "../../Mesh/MeshBuilder/MeshBuilder.h"

class Skybox : public Drawable3D {
private:
    Mesh cube_mesh;
public:
    Skybox(const ShaderProgram &program);

};


#endif //INC_3DGL_SKYBOX_H
