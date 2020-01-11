//
// Created by gvisan on 11.01.2020.
//

#ifndef INC_3DGL_GIZMO_H
#define INC_3DGL_GIZMO_H

#include "../Transformable/Transformable.h"
#include "../Mesh/Mesh.h"

namespace gl3d {

    class Gizmo : public Transformable {
    protected:
        glm::vec3 gizmo_color;
        Mesh gizmo_mesh;
    public:
        Gizmo(glm::vec3 col);

        glm::vec3 get_color() const;

        void set_color(glm::vec3 newcolor);

        const Mesh& get_mesh() const;
    };
}


#endif //INC_3DGL_GIZMO_H
