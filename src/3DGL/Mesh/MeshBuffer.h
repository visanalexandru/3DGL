//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_MESHBUFFER_H
#define INC_3DGL_MESHBUFFER_H

#include "../Vertex/Vertex.h"
#include<vector>

namespace gl3d {

    template<class datatype>
    class MeshBuffer {//container for different type of vertices
    public:
        std::vector<datatype> vertices;
        std::vector<unsigned> indices;

        const void *get_vertices() const;

        const void *get_indices() const;


        void set_attributes() const;

        std::pair<glm::vec3, glm::vec3> get_min_and_max_position() const;

        void add_triangle(datatype t1, datatype t2, datatype t3);

        void add_vertex(datatype t);

        void add_triangle_index(unsigned index);

        MeshBuffer() = default;


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
    void MeshBuffer<datatype>::set_attributes() const {

        datatype::enable_attributes();//we set the attributes(the vertex attribute pointers)

    }

    template<class datatype>
    void MeshBuffer<datatype>::add_vertex(datatype t) {

        vertices.push_back(t);

    }

    template<class datatype>
    void MeshBuffer<datatype>::add_triangle_index(unsigned index) {
        indices.push_back(index);

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
    std::pair<glm::vec3, glm::vec3> MeshBuffer<datatype>::get_min_and_max_position() const {
        glm::vec3 min(0, 0, 0), max(0, 0, 0);

        if (vertices.size()) {
            min = vertices[0].get_position();
            max = vertices[0].get_position();

            for (unsigned i = 1; i < vertices.size(); i++) {

                glm::vec3 here = vertices[i].get_position();

                min.x = std::min(min.x, here.x);
                min.y = std::min(min.y, here.y);
                min.z = std::min(min.z, here.z);

                max.x = std::max(max.x, here.x);
                max.y = std::max(max.y, here.y);
                max.z = std::max(max.z, here.z);


            }


        }

        return {min, max};

    }

}
#endif //INC_3DGL_MESHBUFFER_H
