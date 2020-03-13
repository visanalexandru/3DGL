//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_VERTEX_H
#define INC_3DGL_VERTEX_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <stdexcept>
#include <iostream>

namespace gl3d {

    struct simple_vertex//basic vertex , only holds position data
    {
        glm::vec3 position;

        simple_vertex(glm::vec3 pos) {
            position = pos;
        }

        simple_vertex() {
            position = glm::vec3(0, 0, 0);
        }


        static void enable_attributes() {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(simple_vertex),
                                  (const GLvoid *) offsetof(simple_vertex, position));
            glEnableVertexAttribArray(0);
        }


        glm::vec3 get_position() const {
            return position;
        }
    };

    struct colored_vertex {//vertex that holds position and color data

        glm::vec3 position;
        glm::vec3 color;

        colored_vertex(glm::vec3 pos, glm::vec3 c) {
            color = c;
            position = pos;
        }

        colored_vertex() {
            color = glm::vec3(0, 0, 0);
            position = glm::vec3(0, 0, 0);
        }

        static void enable_attributes() {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(colored_vertex),
                                  (const GLvoid *) offsetof(colored_vertex, position));
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(colored_vertex),
                                  (const GLvoid *) offsetof(colored_vertex, color));
            glEnableVertexAttribArray(1);

        }

        glm::vec3 get_position() const {
            return position;
        }


    };


    struct textured_vertex {//vertex that holds position and texture coordinates

        glm::vec3 position;
        glm::vec2 texture_coords;

        textured_vertex(glm::vec3 pos, glm::vec2 text_coords) {
            texture_coords = text_coords;
            position = pos;
        }

        textured_vertex() {
            texture_coords = glm::vec2(0, 0);
            position = glm::vec3(0, 0, 0);
        }

        static void enable_attributes() {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(textured_vertex),
                                  (const GLvoid *) offsetof(textured_vertex, position));
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(textured_vertex),
                                  (const GLvoid *) offsetof(textured_vertex, texture_coords));
            glEnableVertexAttribArray(1);

        }

        glm::vec3 get_position() const {
            return position;
        }


    };


    struct normal_textured_vertex {//vertex that holds position normal and texture coordinates

        glm::vec3 position;
        glm::vec2 texture_coords;
        glm::vec3 normal;

        normal_textured_vertex(glm::vec3 pos, glm::vec2 text_coords, glm::vec3 n) {
            texture_coords = text_coords;
            position = pos;
            normal = n;
        }

        normal_textured_vertex() {
            texture_coords = glm::vec2(0, 0);
            position = glm::vec3(0, 0, 0);
            normal = glm::vec3(0, 0, 0);

        }

        static void enable_attributes() {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(normal_textured_vertex),
                                  (const GLvoid *) offsetof(normal_textured_vertex, position));
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(normal_textured_vertex),
                                  (const GLvoid *) offsetof(normal_textured_vertex, texture_coords));
            glEnableVertexAttribArray(1);

            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(normal_textured_vertex),
                                  (const GLvoid *) offsetof(normal_textured_vertex, normal));
            glEnableVertexAttribArray(2);

        }

        glm::vec3 get_position() const {
            return position;
        }


    };


    struct sprite_vertex {


        glm::vec2 position;
        glm::vec2 texture_coords;

        sprite_vertex(glm::vec2 pos, glm::vec2 uv) {
            position = pos;
            texture_coords = uv;
        }

        sprite_vertex() {
            position = glm::vec2(0, 0);
            texture_coords = glm::vec2(0, 0);
        }

        static void enable_attributes() {
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(sprite_vertex),
                                  (const GLvoid *) offsetof(sprite_vertex, position));
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(sprite_vertex),
                                  (const GLvoid *) offsetof(sprite_vertex, texture_coords));
            glEnableVertexAttribArray(1);

        }

        glm::vec3 get_position() const {
            return glm::vec3(position.x, position.y, 0);
        }


    };

    struct skeletal_vertex {

        glm::vec3 position;
        glm::vec2 texture_coords;
        glm::vec3 normal;
        int bone_ids[4];
        float weights[4];
        int set_bones;

        void add_bone(int boneid, float weight) {
            if(set_bones<4){
                bone_ids[set_bones] = boneid;
                weights[set_bones] = weight;
                set_bones++;
            }
            else std::cout<<"MORE THAN 4 BONES PER VERTEX \n";

        }

        skeletal_vertex(glm::vec3 pos, glm::vec2 text_coords, glm::vec3 n) {
            set_bones = 0;
            texture_coords = text_coords;
            position = pos;
            normal = n;
            for (int i = 0; i < 4; i++) {
                bone_ids[i] = 0;
                weights[i] = 0.f;
            }
        }

        skeletal_vertex() {
            set_bones = 0;
            texture_coords = glm::vec2(0, 0);
            position = glm::vec3(0, 0, 0);
            normal = glm::vec3(0, 0, 0);

            for (int i = 0; i < 4; i++) {
                bone_ids[i] = 0;
                weights[i] = 0.f;
            }

        }

        static void enable_attributes() {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(skeletal_vertex),
                                  (const GLvoid *) offsetof(skeletal_vertex, position));
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(skeletal_vertex),
                                  (const GLvoid *) offsetof(skeletal_vertex, texture_coords));
            glEnableVertexAttribArray(1);

            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(skeletal_vertex),
                                  (const GLvoid *) offsetof(skeletal_vertex, normal));
            glEnableVertexAttribArray(2);

            glVertexAttribIPointer(3, 4, GL_INT, sizeof(skeletal_vertex),
                                  (const GLvoid *) offsetof(skeletal_vertex, bone_ids));
            glEnableVertexAttribArray(3);

            glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(skeletal_vertex),
                                  (const GLvoid *) offsetof(skeletal_vertex, weights));
            glEnableVertexAttribArray(4);

        }

        glm::vec3 get_position() const {
            return position;
        }


    };
}

#endif //INC_3DGL_VERTEX_H
