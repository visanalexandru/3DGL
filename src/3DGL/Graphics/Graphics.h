//
// Created by gvisan on 30.08.2019.
//

#ifndef INC_3DGL_GRAPHICS_H
#define INC_3DGL_GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Shader/DefaultShaders/DefaultShaders.h"
#include "Renderer.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"


namespace gl3d {
    class Graphics {
    private:
        static int window_width;
        static int window_height;

        static bool draw_gui;

        static GLFWwindow *main_context;

        static const char *glsl_version;

        static void set_window_hints();

        static void handle_new_window_size(int newwidth, int newheight);

        static void framebuffer_size_callback(GLFWwindow *window, int w, int h);

        static void init_imgui();

        static void draw_imgui();

    public:
        static glm::vec2 get_cursor_position();

        static void initialize_graphics();

        static void clear_screen(glm::vec3 color);

        static void update_screen();//swap buffers

        static void initialize_window(int width, int height, const std::string &name);

        static void terminate_graphics();

        static bool is_pressed(int key);

        static int get_window_width();

        static int get_window_height();

        static void lock_cursor();

        static void unlock_cursor();


        static GLFWwindow *get_main_context();

        static bool window_needs_to_close();

        static void set_window_should_close(bool close);

        static void set_should_draw_gui(bool draw);
    };
}

#endif //INC_3DGL_GRAPHICS_H
