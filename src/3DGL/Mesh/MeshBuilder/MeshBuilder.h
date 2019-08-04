//
// Created by gvisan on 25.07.2019.
//

#ifndef INC_3DGL_MESHBUILDER_H
#define INC_3DGL_MESHBUILDER_H

#include "../MeshBuffer.h"
namespace gl3d {

    class MeshBuilder {
    private:
        static glm::vec3 cube_positions[8];
        static glm::vec3 cube_faces[6][4];

    public:
        static void add_cube_face(MeshBuffer<simple_vertex> &data, glm::vec3 position, unsigned face_index);

        static void add_cube_face(MeshBuffer<textured_vertex> &data, glm::vec3 position, unsigned face_index);

    };

}
#endif //INC_3DGL_MESHBUILDER_H
