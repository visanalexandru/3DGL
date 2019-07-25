//
// Created by gvisan on 25.07.2019.
//

#include "MeshBuilder.h"


glm::vec3 MeshBuilder::cube_positions[8]{

        glm::vec3(-0.5f, -0.5f, -0.5f),//0
        glm::vec3(0.5f, -0.5f, -0.5f),//1
        glm::vec3(0.5f, -0.5f, 0.5f),//2
        glm::vec3(-0.5f, -0.5f, 0.5f),//3

        glm::vec3(-0.5f, 0.5f, -0.5f),//4
        glm::vec3(0.5f, 0.5f, -0.5f),//5
        glm::vec3(0.5f, 0.5f, 0.5f),//6
        glm::vec3(-0.5f, 0.5f, 0.5f),//7
};


glm::vec3 MeshBuilder::cube_faces[6][4]{
        {cube_positions[0], cube_positions[1], cube_positions[2], cube_positions[3]},//bottom

        {cube_positions[7], cube_positions[6], cube_positions[5], cube_positions[4]},//top



        {cube_positions[3], cube_positions[2], cube_positions[6], cube_positions[7]},//front

        {cube_positions[1], cube_positions[0], cube_positions[4], cube_positions[5]},//back




        {cube_positions[0], cube_positions[3], cube_positions[7], cube_positions[4]},//left

        {cube_positions[2], cube_positions[1], cube_positions[5], cube_positions[6]},//right



};


void MeshBuilder::add_cube_face(MeshBuffer<simple_vertex> &data, glm::vec3 position, unsigned face_index) {
    glm::vec3 a = cube_faces[face_index][0];
    glm::vec3 b = cube_faces[face_index][1];
    glm::vec3 c = cube_faces[face_index][2];
    glm::vec3 d = cube_faces[face_index][3];

    data.add_triangle(a, b, c);
    data.add_triangle(c, d, a);

}
void MeshBuilder::add_cube_face(MeshBuffer<textured_vertex> &data, glm::vec3 position, unsigned face_index) {
    glm::vec3 a = cube_faces[face_index][0];
    glm::vec3 b = cube_faces[face_index][1];
    glm::vec3 c = cube_faces[face_index][2];
    glm::vec3 d = cube_faces[face_index][3];


    textured_vertex v1(a,glm::vec2(0,0));
    textured_vertex v2(b,glm::vec2(1,0));
    textured_vertex v3(c,glm::vec2(1,1));
    textured_vertex v4(d,glm::vec2(0,1));


    data.add_triangle(v1, v2, v3);
    data.add_triangle(v3, v4, v1);
}