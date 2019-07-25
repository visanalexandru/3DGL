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
    unsigned vertex_index, texture_coord_index;

    vertex() : vertex_index(0), texture_coord_index(0) {};

    vertex(unsigned a, unsigned b) : vertex_index(a), texture_coord_index(b) {};

    bool operator==(const vertex &other) const {

        return other.vertex_index == vertex_index && other.texture_coord_index == texture_coord_index;

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
            return seed;
        }
    };


}


class ModelLoader {

private:


    std::unordered_map<vertex, unsigned> vertices;


    std::vector<glm::vec3> parsed_positions;
    std::vector<glm::vec2> parsed_texture_coords;

    std::vector<vertex> parsed_vertices;

    void parse(const std::string &path);

    bool exists(vertex to_check);

    unsigned get_index_of(vertex to_get);

    vertex get_vertex(const std::string &to_parse) const;


public:

    void load_model(const std::string &path, MeshBuffer<textured_vertex> &buffer);

};


#endif //INC_3DGL_MODELLOADER_H