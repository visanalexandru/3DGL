//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_TRANSFORMABLE_H
#define INC_3DGL_TRANSFORMABLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Transformable {
private:
    glm::vec3 position;
    glm::mat4 rotation;
public:
    Transformable();

    Transformable(glm::vec3 pos);

    glm::vec3 get_position() const;

    glm::mat4 get_rotation() const;

    glm::mat4 get_model_matrix() const;

    void rotate(glm::vec3 direction, float radians);

    void move(glm::vec3 offset);

    void set_rotation(glm::mat4 rot);

    void set_position(glm::vec3 pos);



};


#endif //INC_3DGL_TRANSFORMABLE_H
