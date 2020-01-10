//
// Created by gvisan on 10.01.2020.
//

#include "Camera.h"

namespace gl3d {
    Camera::Camera() : position(0, 0, 0), rotation(0, 0, 0) {
        set_fov(90.f);
    }

    Camera::Camera(glm::vec3 pos) : position(pos) {
        set_fov(90.f);
    }


    Camera::Camera(glm::vec3 pos, glm::vec3 rot) : position(pos), rotation(rot) {
        set_fov(90.f);
    }

    void Camera::update_culler() {
        frustum_culler.update(projection * get_view_matrix());
    }

    glm::vec3 Camera::get_forward_vector() const {
        const glm::vec3 direction = -normalize(glm::vec3(get_rotation_matrix()[2]));
        return direction;
    }

    void Camera::set_position(glm::vec3 pos) {
        position = pos;
        update_culler();
    }

    void Camera::set_rotation(glm::vec3 rot) {
        rotation = rot;
        update_culler();
    }

    glm::vec3 Camera::get_rotation() const {
        return rotation;
    }

    glm::vec3 Camera::get_position() const {
        return position;
    }

    void Camera::set_fov(float new_fov) {
        field_of_view = new_fov;
        update_projection_matrix();
    }

    void Camera::update_projection_matrix() {
        int width = Core::get_window_width();
        int height = Core::get_window_height();

        projection = glm::perspective(glm::radians(field_of_view), (float) width / height, 0.1f,
                                      1000.0f);//updates projection matrix
        update_culler();
    }

    glm::mat4 Camera::get_projection_matrix() const {
        return projection;
    }

    glm::mat4 Camera::get_rotation_matrix() const {
        glm::mat4 rot = glm::eulerAngleYXZ(glm::radians(rotation.y), glm::radians(rotation.x),
                                           glm::radians(rotation.z));

        return rot;
    }


    glm::mat4 Camera::get_view_matrix() const {
        glm::mat4 pos = glm::inverse(get_rotation_matrix());

        pos = glm::translate(pos, -position);

        return pos;

    }

    const FrustumCull &Camera::get_frustum_culler() const {
        return frustum_culler;
    }


}