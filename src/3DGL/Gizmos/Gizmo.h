//
// Created by gvisan on 11.01.2020.
//

#ifndef INC_3DGL_GIZMO_H
#define INC_3DGL_GIZMO_H

#include "../Transformable/Transformable.h"
#include "../Mesh/Mesh.h"
#include "../FrustumCulling/AABB.h"


namespace gl3d {

    class Gizmo {
    protected:
        glm::vec3 gizmo_color;
        Mesh gizmo_mesh;
        glm::vec3 position;
        glm::vec3 scale;

    public:
        Gizmo(glm::vec3 col);

        glm::vec3 get_color() const;

        glm::mat4 get_model_matrix() const;

        void set_position(glm::vec3 newpos);

        virtual AABB get_bounding_box() const = 0;

        void set_scale(glm::vec3 newscale);

        void set_color(glm::vec3 newcolor);

        const Mesh &get_mesh() const;
    };
}


#endif //INC_3DGL_GIZMO_H
