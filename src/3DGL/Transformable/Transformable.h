//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_TRANSFORMABLE_H
#define INC_3DGL_TRANSFORMABLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtx/euler_angles.hpp>

class Transformable {
private:
    glm::vec3 position;
    glm::vec3 rotation;
public:
    Transformable();

    Transformable(glm::vec3 pos);

    glm::vec3 get_position() const;

    glm::vec3 get_rotation() const;

    glm::mat4 get_rotation_matrix() const;

    glm::mat4 get_model_matrix() const;

    void rotate(glm::vec3 rotate);

    void move(glm::vec3 offset);

    void set_rotation(glm::vec3 rot);

    void set_position(glm::vec3 pos);


};


#endif //INC_3DGL_TRANSFORMABLE_H
