//
// Created by gvisan on 22.07.2019.
//

#include "Drawable3D.h"


void Drawable3D::bind_mesh() const {

    mesh.bind_mesh();

}

Drawable3D::Drawable3D() {


}

Drawable3D::Drawable3D(glm::vec3 position) : Transformable(position) {


}
