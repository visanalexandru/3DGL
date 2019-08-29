//
// Created by gvisan on 21.07.2019.
//

#include "Mesh.h"

namespace gl3d {


    Mesh::Mesh() : triangle_count(0) {


    }

    void Mesh::delete_mesh() const {

        glDeleteVertexArrays(1, &resource_index);//clean vertex array index
    }

    Mesh::~Mesh() {


        delete_mesh();

    }

    std::pair<glm::vec3, glm::vec3> Mesh::get_dimensions() const {

        return dimensions;

    }


    void Mesh::bind_empty_mesh() {

        glBindVertexArray(0);

    }

    unsigned Mesh::get_triangle_count() const {

        return triangle_count;

    }

    void Mesh::bind_mesh() const {

        glBindVertexArray(resource_index);//bind the vertex array index

    }
}