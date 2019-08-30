//
// Created by gvisan on 30.08.2019.
//

#include "Graphics.h"

namespace gl3d {
    int Graphics::window_width = 800;
    int Graphics::window_height = 800;
    GLFWwindow *Graphics::main_context = nullptr;


    //this function initialize the graphics calling glfwInit()
    void Graphics::initialize_graphics() {
        glfwInit();
        set_window_hints();

    }


    //terminate graphics by calling glfwTerminate() and deleting the default shaders
    void Graphics::terminate_graphics() {
        DefaultShaders::delete_shaders();
        glfwTerminate();
    }


    void Graphics::initialize_window(int width, int height, const std::string &name) {
        main_context = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);//we create a window

        handle_new_window_size(width, height);

        glfwMakeContextCurrent(main_context);//we set the created window the current context

        glfwSetFramebufferSizeCallback(main_context, framebuffer_size_callback);//we set the callback function

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);//we initialize glad

        DefaultShaders::init_shaders();

        glViewport(0, 0, width, height);//we set the viewport

        glEnable(GL_DEPTH_TEST);//we enable depth testing
    }


    //this function sets window hints
    void Graphics::set_window_hints() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }


    //this function gets called when the window gets resized
    void Graphics::framebuffer_size_callback(GLFWwindow *window, int w, int h) {

        glViewport(0, 0, w, h);//we set the viewport
        handle_new_window_size(w, h);
    }


    //call renderer static method for updating projection matrix
    void Graphics::handle_new_window_size(int newwidth, int newheight) {

        window_width = newwidth;
        window_height = newheight;
        Renderer::update_projection_matrix(newwidth, newheight);
    }


    void Graphics::clear_screen(glm::vec3 color) {
        color /= 255.f;
        glClearColor(color.x, color.y, color.z, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }


    void Graphics::update_screen() {
        glfwSwapBuffers(main_context);//we swap the buffers
        glfwPollEvents();//we poll events
    }


    glm::vec2 Graphics::get_cursor_position() {
        double x, y;
        glfwGetCursorPos(main_context, &x, &y);
        return glm::vec2(x, y);
    }

    bool Graphics::is_pressed(int key) {
        return glfwGetKey(main_context, key) == GLFW_PRESS;
    }

    void Graphics::lock_cursor() {
        glfwSetInputMode(main_context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

}