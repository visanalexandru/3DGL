//
// Created by gvisan on 22.07.2019.
//

#include "Transformable.h"
namespace gl3d {

    Transformable::Transformable() : position(0, 0, 0), rotation(0,0,0), scale(1, 1, 1) {


    }


    Transformable::Transformable(glm::vec3 pos) : position(pos), rotation(0,0,0), scale(1, 1, 1) {


    }

    glm::vec3 Transformable::get_position() const {

        return position;
    }

    glm::mat4 Transformable::get_rotation_matrix() const {//we convert from euler angles to rotation matrix
        glm::mat4 rot = glm::eulerAngleYXZ(glm::radians(rotation.y), glm::radians(rotation.x),
                                           glm::radians(rotation.z));

        return rot;

    }


    void Transformable::set_scale(glm::vec3 sc) {

        scale = sc;

    }

    glm::vec3 Transformable::get_scale() const {

        return scale;

    }

    glm::vec3 Transformable::get_rotation() const {

        return rotation;

    }

    glm::mat4 Transformable::get_model_matrix() const {
        glm::mat4 pos(1);

        pos = glm::translate(pos, position);

        pos = pos * get_rotation_matrix();

        pos = glm::scale(pos, scale);

        return pos;

    }

    void Transformable::rotate(glm::vec3 rotate) {

        set_rotation(rotation + rotate);

    }

    glm::vec3 Transformable::get_forward_vector() const {

        const glm::vec3 direction = -normalize(glm::vec3(get_rotation_matrix()[2]));
        return direction;
    }

    void Transformable::move(glm::vec3 offset) {

        set_position(position + offset);

    }

    void Transformable::set_position(glm::vec3 pos) {

        position = pos;

    }

    void Transformable::set_rotation(glm::vec3 rot) {

        rotation = rot;

    }
}