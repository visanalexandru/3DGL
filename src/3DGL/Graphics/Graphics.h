//
// Created by gvisan on 30.08.2019.
//

#ifndef INC_3DGL_GRAPHICS_H
#define INC_3DGL_GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Shader/DefaultShaders/DefaultShaders.h"
#include "Renderer.h"

namespace gl3d {
    class Graphics {
    private:
        static int window_width;
        static int window_height;
        static GLFWwindow *main_context;

        static void set_window_hints();

        static void handle_new_window_size(int newwidth, int newheight);

        static void framebuffer_size_callback(GLFWwindow *window, int w, int h);


    public:
        static glm::vec2 get_cursor_position();

        static void initialize_graphics();

        static void clear_screen(glm::vec3 color);

        static void update_screen();//swap buffers

        static void initialize_window(int width, int height, const std::string &name);

        static void terminate_graphics();

        static bool is_pressed(int key);

        static void lock_cursor();

        static GLFWwindow *get_main_context();
    };
}

#endif //INC_3DGL_GRAPHICS_H
