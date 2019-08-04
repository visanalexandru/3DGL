//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_AABB_H
#define INC_3DGL_AABB_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace gl3d {

    class AABB {
    public:
        AABB(glm::vec3 positionin, glm::vec3 dimensionin);

        glm::vec3 getVN(const glm::vec3 &normal) const;

        glm::vec3 getVP(const glm::vec3 &normal) const;


    private:
        glm::vec3 AABB_position;
        glm::vec3 AABB_dimension;
    };

}
#endif //INC_3DGL_AABB_H
