//
// Created by gvisan on 21.07.2019.
//

#include "Mesh.h"


Mesh::Mesh() : vertex_array_index(0), triangle_count(0) {


}

void Mesh::delete_vertex_array_index() const {

    glDeleteVertexArrays(1, &vertex_array_index);//clean vertex array index
}

Mesh::~Mesh() {

    delete_vertex_array_index();

}

unsigned Mesh::get_triangle_count() const {

    return triangle_count;

}

void Mesh::bind_mesh() const {

    glBindVertexArray(vertex_array_index);//bind the vertex array index

}