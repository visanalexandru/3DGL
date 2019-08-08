//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_MESH_H
#define INC_3DGL_MESH_H

#include "MeshBuffer.h"
#include "../Resource/Resource.h"
#include <iostream>

namespace gl3d {

    class Mesh : public Resource {

    private:
        unsigned triangle_count;

        std::pair<glm::vec3, glm::vec3> dimensions;

        void unload_resource() const override;

        template<class datatype>
        void create_vertex_array_index(const MeshBuffer<datatype> &vertex_data);


    public:
        Mesh();

        ~Mesh();

        void bind_resource() const override;

        unsigned get_triangle_count() const;

        static void bind_empty_mesh();

        std::pair<glm::vec3, glm::vec3> get_dimensions() const;

        Mesh &operator=(const Mesh &other) = delete;

        Mesh(const Mesh &other) = delete;

        template<class datatype>
        void set_data(const MeshBuffer<datatype> &vertex_data);

    };


    template<class datatype>
    void Mesh::create_vertex_array_index(const MeshBuffer<datatype> &vertex_data) {

        unsigned VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);//we create a VAO
        glGenBuffers(1, &VBO);//generating VBO and EBO buffers
        glGenBuffers(1, &EBO);//VBO is used for vertex data and EBO is used for index data


        glBindVertexArray(VAO);//we bind the vertex array index


        const void *vertices = vertex_data.get_vertices();//pointer to the first element of the vertex data vector
        const void *indices = vertex_data.get_indices();//pointer to the first element of the index data vector

        unsigned vertices_count = vertex_data.get_vertices_count();
        unsigned indices_count = vertex_data.get_indices_count();


        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices_count * sizeof(datatype), vertices,
                     GL_STATIC_DRAW);//we set the vertex data to the VBO buffer

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_count * sizeof(unsigned), indices,
                     GL_STATIC_DRAW);//we set the indices to the EBO buffer

        vertex_data.set_attributes();


        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);//this unbinds the vertex array index

        glDeleteBuffers(1, &VBO);//we delete this buffers as we don't need them anymore
        glDeleteBuffers(1, &EBO);//it's safe because we unbound the created vertex array

        resource_index = VAO;
        triangle_count = indices_count;
        dimensions = vertex_data.get_min_and_max_position();

    }


    template<class datatype>
    void Mesh::set_data(const MeshBuffer<datatype> &vertex_data) {

        unload_resource();//we delete the last mesh data

        create_vertex_array_index(vertex_data);//we create vao based on the vertex data

    }
}

#endif //INC_3DGL_MESH_H
