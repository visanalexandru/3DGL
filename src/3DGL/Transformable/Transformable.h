//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_TRANSFORMABLE_H
#define INC_3DGL_TRANSFORMABLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtx/euler_angles.hpp>
namespace gl3d {

    class Transformable {
    protected:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
    public:
        Transformable();

        Transformable(glm::vec3 pos);

        glm::vec3 get_position() const;

        glm::vec3 get_rotation() const;

        glm::vec3 get_scale() const;

        glm::mat4 get_rotation_matrix() const;

        glm::mat4 get_model_matrix() const;

        void rotate(glm::vec3 rotate);

        glm::vec3 get_forward_vector() const;

        void move(glm::vec3 offset);

        virtual void set_rotation(glm::vec3 rot);

        virtual void set_scale(glm::vec3 sc);

        virtual void set_position(glm::vec3 pos);


    };

}
#endif //INC_3DGL_TRANSFORMABLE_H
