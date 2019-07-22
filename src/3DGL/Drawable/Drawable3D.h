//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_DRAWABLE3D_H
#define INC_3DGL_DRAWABLE3D_H

#include "../Transformable/Transformable.h"
#include "../Mesh/Mesh.h"

class Drawable3D : public Transformable {


private:
    Mesh mesh;
public:
    void bind_mesh() const;

    Drawable3D();

    Drawable3D(glm::vec3 position);

    template<class datatype>
    void set_mesh_data(MeshBuffer<datatype> &vertex_data);

};


template<class datatype>
void Drawable3D::set_mesh_data(MeshBuffer<datatype> &vertex_data) {

    mesh.set_data(vertex_data);

}

#endif //INC_3DGL_DRAWABLE3D_H
