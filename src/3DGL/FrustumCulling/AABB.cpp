//
// Created by gvisan on 31.07.2019.
//

#include "AABB.h"


AABB::AABB(glm::vec3 positionin, glm::vec3 dimensionin) : AABB_position(positionin), AABB_dimension(dimensionin) {


}


glm::vec3 AABB::getVN(const glm::vec3 &normal) const {
    glm::vec3 res = AABB_position;


    if (normal.x < 0) {

        res.x += AABB_dimension.x;

    }
    if (normal.y < 0) {

        res.y += AABB_dimension.y;

    }

    if (normal.z < 0) {

        res.z += AABB_dimension.z;

    }


    return res;
}


glm::vec3 AABB::getVP(const glm::vec3 &normal) const {
    glm::vec3 res = AABB_position;
    if (normal.x > 0) {
        res.x += AABB_dimension.x;
    }


    if (normal.y > 0) {


        res.y += AABB_dimension.y;

    }

    if (normal.z > 0) {

        res.z += AABB_dimension.z;

    }

    return res;

}