//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_MESHBUFFER_H
#define INC_3DGL_MESHBUFFER_H

#include "../Vertex/Vertex.h"
#include<vector>


template<class datatype>
class MeshBuffer {//container for different type of vertices

private:
    std::vector<datatype> vertices;
    std::vector<unsigned> indices;
public:

    const void *get_vertices() const;

    const void *get_indices() const;

    unsigned get_indices_count() const;

    unsigned get_vertices_count() const;

    void set_attributes() const;


    void add_triangle(datatype t1, datatype t2, datatype t3);

    MeshBuffer();


};

template<class datatype>
const void *MeshBuffer<datatype>::get_vertices() const {

    return &vertices[0];//pointer to the first element

}


template<class datatype>
const void *MeshBuffer<datatype>::get_indices() const {

    return &indices[0];//pointer to the first element

}


template<class datatype>
unsigned MeshBuffer<datatype>::get_indices_count() const {

    return indices.size();

}


template<class datatype>
unsigned MeshBuffer<datatype>::get_vertices_count() const {

    return vertices.size();

}


template<class datatype>
void MeshBuffer<datatype>::set_attributes() const {

    datatype::enable_attributes();//we set the attributes(the vertex attribute pointers)

}


template<class datatype>
void MeshBuffer<datatype>::add_triangle(datatype t1, datatype t2, datatype t3) {
    unsigned size_now = vertices.size();


    vertices.push_back(t1);
    vertices.push_back(t2);
    vertices.push_back(t3);


    indices.push_back(size_now);
    indices.push_back(size_now + 1);
    indices.push_back(size_now + 2);

}



template<class datatype>
MeshBuffer<datatype>::MeshBuffer() {


}

#endif //INC_3DGL_MESHBUFFER_H
