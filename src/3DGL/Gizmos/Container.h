//
// Created by gvisan on 11.01.2020.
//

#ifndef INC_3DGL_CONTAINER_H
#define INC_3DGL_CONTAINER_H

#include "Gizmo.h"
#include "../FrustumCulling/AABB.h"
#include "../Mesh/MeshBuilder/MeshBuilder.h"

namespace gl3d {

    class Container : public Gizmo {

    private:

        void create_cube_mesh();

    public:

        Container(AABB bounding_box, glm::vec3 color);

    };
}


#endif //INC_3DGL_CONTAINER_H
