//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_VERTEX_H
#define INC_3DGL_VERTEX_H
#include <glm/glm.hpp>
#include <glad/glad.h>

struct simple_vertex
{
    glm::vec3 position;

    simple_vertex(glm::vec3 pos)
    {
        position=pos;
    }

    simple_vertex()
    {
        position=glm::vec3(0,0,0);
    }


    static void enable_attributes()
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(simple_vertex), (const GLvoid*)offsetof(simple_vertex, position));
        glEnableVertexAttribArray(0);
    }


    glm::vec3 get_position()
    {
        return position;
    }
};



#endif //INC_3DGL_VERTEX_H
