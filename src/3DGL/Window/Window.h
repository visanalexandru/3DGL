//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_WINDOW_H
#define INC_3DGL_WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include "../Drawable/Drawable3D.h"

class Window {
private:
    glm::mat4 projection;
    int width, height;
    float field_of_view;
    GLFWwindow *window;




    void update_projection_matrix();

    void init_graphics() const;




    void create_window(int w, int h, const std::string &title);


    static void framebuffer_size_callback(GLFWwindow *window, int w, int h);

public:

    Window(int width, int height, const std::string &title);

    bool needs_to_close() const;

    void set_field_of_view(float fov);

    void set_window_size(int newwidth, int newheight);

    void draw(const Drawable3D&to_draw) const;

    void set_window_should_close();

    void clear(glm::vec3 color = glm::vec3(0, 0, 0)) const;

    void display() const;

};


#endif //INC_3DGL_WINDOW_H
