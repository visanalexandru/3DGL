//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_WINDOW_H
#define INC_3DGL_WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include "../Drawable/Drawable3D.h"
#include "../Drawable/Skybox/Skybox.h"
#include "../RenderList/RenderList.h"

class Window {
private:
    glm::mat4 projection;
    glm::mat4 view;
    int width, height;
    float field_of_view;
    GLFWwindow *window;
    const Skybox *skybox;


    void update_projection_matrix();

    void init_graphics() const;


    void create_window(int w, int h, const std::string &title);

    void draw_skybox() const;


    static void framebuffer_size_callback(GLFWwindow *window, int w, int h);

public:

    Window(int width, int height, const std::string &title);

    bool needs_to_close() const;

    glm::vec2 get_cursor_position() const;

    void set_field_of_view(float fov);

    void handle_new_window_size(int newwidth, int newheight);

    void lock_cursor() const;

    void set_view(const Transformable &new_view);

    void draw(const Drawable3D &to_draw) const;

    void set_skybox(const Skybox&new_skybox);

    void draw(const RenderList &to_draw) const;

    void set_window_should_close();

    void clear(glm::vec3 color = glm::vec3(0, 0, 0)) const;

    bool is_pressed(int key) const;

    void display() const;

};


#endif //INC_3DGL_WINDOW_H
