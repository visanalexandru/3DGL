//
// Created by gvisan on 25.07.2019.
//

#ifndef INC_3DGL_MODELLOADER_H
#define INC_3DGL_MODELLOADER_H

#include "../MeshBuffer.h"
#include <unordered_map>
#include <sstream>
#include<vector>
#include <fstream>
#include <iostream>


struct vertex {
    unsigned vertex_index, texture_coord_index, normal_index;

    vertex() : vertex_index(0), texture_coord_index(0), normal_index(0) {};

    vertex(unsigned a, unsigned b, unsigned c) : vertex_index(a), texture_coord_index(b), normal_index(c) {};

    bool operator==(const vertex &other) const {

        return other.vertex_index == vertex_index && other.texture_coord_index == texture_coord_index &&
               other.normal_index == normal_index;

    }
};


template<class T>
inline void hash_combine(std::size_t &seed, const T &v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}


namespace std {

    template<>
    struct hash<vertex> {

        std::size_t operator()(const vertex &k) const {
            std::size_t seed = 0;
            hash_combine(seed, k.vertex_index);
            hash_combine(seed, k.texture_coord_index);
            hash_combine(seed, k.normal_index);

            return seed;
        }
    };


}
namespace gl3d {


    class ModelLoader {

    private:


        std::unordered_map<vertex, unsigned> vertices;


        std::vector<glm::vec3> parsed_positions;
        std::vector<glm::vec2> parsed_texture_coords;
        std::vector<glm::vec3> parsed_normals;

        std::vector<vertex> parsed_vertices;

        std::stringstream stream;

        void parse(const std::string &path);

        bool exists(vertex to_check);

        unsigned get_index_of(vertex to_get);

        vertex get_vertex(const std::string &to_parse) const;

        void parse_new_vertex_position();

        void parse_new_texture_coordinates();

        void parse_new_triangles();

        void parse_new_normal();


        void triangulate(const std::vector<vertex> &triangle_strip);


    public:

        void load_model(const std::string &path, MeshBuffer<normal_textured_vertex> &buffer);

    };
}

#endif //INC_3DGL_MODELLOADER_H
