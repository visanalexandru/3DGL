//
// Created by gvisan on 10.01.2020.
//

#ifndef INC_3DGL_CAMERA_H
#define INC_3DGL_CAMERA_H

#include "../Transformable/Transformable.h"
#include "../Graphics/Core.h"
#include "../FrustumCulling/FrustumCull.h"

namespace gl3d {

    class Camera {

    private:
        glm::vec3 position;
        glm::vec3 rotation;


        float field_of_view;
        glm::mat4 projection;

        FrustumCull frustum_culler;

        void update_culler();

    public:

        Camera(glm::vec3 pos, glm::vec3 rot);

        Camera(glm::vec3 pos);

        Camera();

        void set_fov(float new_fov);

        void set_position(glm::vec3 pos);

        void set_rotation(glm::vec3 rot);

        glm::vec3 get_position() const;

        glm::vec3 get_rotation() const;

        glm::vec3 get_forward_vector() const;

        glm::mat4 get_projection_matrix() const;

        glm::mat4 get_view_matrix() const;

        glm::mat4 get_rotation_matrix() const;

        void update_projection_matrix();


        const FrustumCull &get_frustum_culler() const;

    };


}


#endif //INC_3DGL_CAMERA_H
