//
// Created by gvisan on 11.01.2020.
//

#ifndef INC_3DGL_CONTAINER_H
#define INC_3DGL_CONTAINER_H

#include "Gizmo.h"
#include "../Mesh/MeshBuilder/MeshBuilder.h"

namespace gl3d {

    class Container : public Gizmo {

    private:

        void create_cube_mesh();

    public:

        Container(glm::vec3 position, glm::vec3 size, glm::vec3 color);

        Container(AABB aabb, glm::vec3 color);

        AABB get_bounding_box() const override;
    };
}


#endif //INC_3DGL_CONTAINER_H
