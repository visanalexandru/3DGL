//
// Created by gvisan on 25.07.2019.
//

#include "ModelLoader.h"


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


    return vertex(formed[0], formed[1]);


}


std::string ModelLoader::get_next_element(const std::string &source, unsigned &cursor) {
    std::string result;

    if (cursor < source.length()) {

        do {
            result += source[cursor];
            cursor++;
        } while (cursor < source.length() && source[cursor] != 'v' && source[cursor] != 'f');
    }

    return result;


}

bool ModelLoader::is_prefix(const std::string &to_check, const std::string &prefix) const {


    if (to_check.length() < prefix.length())
        return false;

    for (int i = 0; i < prefix.length(); i++) {
        if (to_check[i] != prefix[i])
            return false;
    }
    return true;

}

void ModelLoader::parse_element(const std::string &to_parse) {

    std::string type;
    std::stringstream str(to_parse);

    str >> type;

    if (is_prefix(to_parse, "v ")) {
        glm::vec3 parsed;

        str >> parsed.x >> parsed.y >> parsed.z;


        parsed_positions.push_back(parsed);

    } else if (is_prefix(to_parse, "vt ")) {
        glm::vec2 parsed;


        str >> parsed.x >> parsed.y;

        parsed_texture_coords.push_back(parsed);


    } else if (is_prefix(to_parse, "f ")) {


        std::string a, b, c;
        vertex v1, v2, v3;

        str >> a >> b >> c;

        v1 = get_vertex(a);
        v2 = get_vertex(b);
        v3 = get_vertex(c);

        parsed_vertices.push_back(v1);
        parsed_vertices.push_back(v2);
        parsed_vertices.push_back(v3);


    }
}


void ModelLoader::parse(const std::string &path) {

    std::ifstream in(path);

    parsed_vertices.clear();
    parsed_positions.clear();
    parsed_texture_coords.clear();

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string content = buffer.str();
    unsigned cursor = 0;

    while (cursor < content.length()) {
        parse_element(get_next_element(content, cursor));

    }


}


unsigned ModelLoader::get_index_of(vertex to_get) {

    return vertices[to_get];

}


bool ModelLoader::exists(vertex to_check) {


    return vertices.find(to_check) != vertices.end();

}


void ModelLoader::load_model(const std::string &path, MeshBuffer<textured_vertex> &buffer) {

    parse(path);

    unsigned added = 0;


    for (int i = 0; i < parsed_vertices.size(); i++) {

        vertex h = parsed_vertices[i];

        if (!exists(h)) {
            int a = h.vertex_index - 1;
            int b = h.texture_coord_index - 1;

            glm::vec3 position = parsed_positions[a];
            glm::vec2 texture_coord(0, 0);


            if (b >= 0) {//this variable is -1 when no texture coordinates are given


                texture_coord = parsed_texture_coords[b];

            }

            textured_vertex to_add(position, texture_coord);


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