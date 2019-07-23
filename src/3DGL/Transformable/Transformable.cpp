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
    glm::mat4 matRoll(1);
    glm::mat4 matPitch(1);
    glm::mat4 matYaw(1);


    matRoll = glm::rotate(matRoll,glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    matPitch = glm::rotate(matPitch, glm::radians(rotation.x), glm::vec3(0.0f, 1.0f, 0.0f));
    matYaw = glm::rotate(matYaw, glm::radians(rotation.y), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 rotation = matRoll * matPitch * matYaw;

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