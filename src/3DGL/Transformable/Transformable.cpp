//
// Created by gvisan on 22.07.2019.
//

#include "Transformable.h"

Transformable::Transformable() : position(0, 0, 0), rotation(1) {


}


Transformable::Transformable(glm::vec3 pos) : position(pos), rotation(1) {


}

glm::vec3 Transformable::get_position() const {

    return position;
}

glm::mat4 Transformable::get_rotation_matrix() const {
    glm::mat4 rot = glm::eulerAngleYXZ(glm::radians(rotation.y), glm::radians(rotation.x), glm::radians(rotation.z));

    return rot;

}

glm::vec3 Transformable::get_rotation() const {

    return rotation;

}

glm::mat4 Transformable::get_model_matrix() const {
    glm::mat4 pos(1);

    pos = glm::translate(pos, position);

    return pos * get_rotation_matrix();

}

void Transformable::rotate(glm::vec3 direction) {

    rotation += direction;

}

void Transformable::move(glm::vec3 offset) {

    position += offset;

}

void Transformable::set_position(glm::vec3 pos) {

    position = pos;

}

void Transformable::set_rotation(glm::vec3 rot) {

    rotation = rot;

}