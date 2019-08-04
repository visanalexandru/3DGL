//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_VERTEX_H
#define INC_3DGL_VERTEX_H

#include <glm/glm.hpp>
#include <glad/glad.h>
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
}

#endif //INC_3DGL_VERTEX_H
