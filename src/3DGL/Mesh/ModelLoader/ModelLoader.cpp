//
// Created by gvisan on 25.07.2019.
//

#include "ModelLoader.h"
namespace gl3d {


    vertex ModelLoader::get_vertex(const std::string &to_parse) const {

        int formed[3]{0, 0, 0};

        unsigned last = 0;
        unsigned index = 0;

        unsigned digit;

        for (int i = 0; i < to_parse.length(); i++) {
            if (to_parse[i] != '/') {

                digit = to_parse[i] - '0';

                formed[index] = formed[index] * 10 + digit;

            } else {
                index++;
            }
        }

        return vertex(formed[0], formed[1], formed[2]);


    }


    void ModelLoader::triangulate(const std::vector<vertex> &triangle_strip) {

        for (int i = 1; i < triangle_strip.size() - 1; i++) {

            parsed_vertices.push_back(triangle_strip[0]);
            parsed_vertices.push_back(triangle_strip[i]);
            parsed_vertices.push_back(triangle_strip[i + 1]);

        }
    }

    void ModelLoader::parse_new_vertex_position() {
        glm::vec3 parsed;

        stream >> parsed.x >> parsed.y >> parsed.z;
        parsed_positions.push_back(parsed);

    }


    void ModelLoader::parse_new_texture_coordinates() {

        glm::vec2 parsed;

        stream >> parsed.x >> parsed.y;

        parsed_texture_coords.push_back(parsed);


    }

    void ModelLoader::parse_new_normal() {

        glm::vec3 parsed;

        stream >> parsed.x >> parsed.y >> parsed.z;

        parsed_normals.push_back(parsed);

    }


    void ModelLoader::parse_new_triangles() {


        std::string aux;

        std::vector<vertex> extracted;


        std::stringstream::pos_type pos = stream.tellg();


        bool bool_has_next = false;

        while (stream >> aux) {

            if (std::isdigit(aux[0])) {

                vertex v = get_vertex(aux);

                extracted.push_back(v);


            } else {

                bool_has_next = true;

                break;
            }

            pos = stream.tellg();


        }

        if (bool_has_next)
            stream.seekg(pos);
        triangulate(extracted);


    }

    void ModelLoader::parse(const std::string &path) {

        std::ifstream in(path);
        stream << in.rdbuf();

        std::string aux;

        while (stream >> aux) {
            if (aux == "v") {
                parse_new_vertex_position();

            } else if (aux == "vt") {
                parse_new_texture_coordinates();

            } else if (aux == "f") {
                parse_new_triangles();
            } else if (aux == "vn") {
                parse_new_normal();
            }

        }


    }


    unsigned ModelLoader::get_index_of(vertex to_get) {

        return vertices[to_get];

    }


    bool ModelLoader::exists(vertex to_check) {


        return vertices.find(to_check) != vertices.end();

    }


    void ModelLoader::load_model(const std::string &path, MeshBuffer<normal_textured_vertex> &buffer) {

        stream.str("");
        stream.clear();
        parsed_vertices.clear();
        parsed_positions.clear();
        parsed_normals.clear();
        parsed_texture_coords.clear();
        vertices.clear();


        parse(path);

        unsigned added = 0;

        for (int i = 0; i < parsed_vertices.size(); i++) {

            vertex h = parsed_vertices[i];

            if (!exists(h)) {
                int a = h.vertex_index - 1;
                int b = h.texture_coord_index - 1;
                int c = h.normal_index - 1;

                glm::vec3 position = parsed_positions[a];
                glm::vec2 texture_coord(0, 0);
                glm::vec3 normal(0, 0, 0);


                if (b >= 0) {//this variable is -1 when no texture coordinates are given


                    texture_coord = parsed_texture_coords[b];

                }

                if (c >= 0) {
                    normal = parsed_normals[c];

                }

                normal_textured_vertex to_add(position, texture_coord, normal);


                buffer.add_vertex(to_add);
                buffer.add_triangle_index(added);
                vertices[h] = added;

                added++;


            } else {
                unsigned index = get_index_of(h);

                buffer.add_triangle_index(index);

            }

        }

    }
}