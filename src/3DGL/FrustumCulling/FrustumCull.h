//
// Created by gvisan on 31.07.2019.
//

#ifndef INC_3DGL_FRUSTUMCULL_H
#define INC_3DGL_FRUSTUMCULL_H


#include "AABB.h"

#include "../Transformable/Transformable.h"

#include "../Drawable/Drawable3D.h"

class FrustumCull {
private:
    struct Plane {
        float distanceToPoint(const glm::vec3 &point) const;

        float distanceToOrigin;
        glm::vec3 normal;

    };

    Plane m_planes[6];

public:
    void update(const glm::mat4 &projViewMatrix);

    bool pointInFrustum(glm::vec3 &p) const;

    bool boxInFrustum(const AABB &box) const;

    bool drawableInFrusum(const Drawable3D &drawable) const;

};


#endif //INC_3DGL_FRUSTUMCULL_H
