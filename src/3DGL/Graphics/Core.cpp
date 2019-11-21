//
// Created by gvisan on 30.08.2019.
//

#include "Core.h"

namespace gl3d {
    int Core::window_width = 800;
    int Core::window_height = 800;
    const char *Core::glsl_version = "#version 130";
    GLFWwindow *Core::main_context = nullptr;
    bool Core::draw_gui = false;


    //this function initialize the graphics calling glfwInit()
    void Core::initialize_graphics() {
        glfwInit();
        set_window_hints();

    }


    //terminate graphics by calling glfwTerminate() and deleting the default shaders
    void Core::terminate_graphics() {
        DefaultShaders::delete_shaders();
        glfwTerminate();
    }

    void Core::init_imgui() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(main_context, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void Core::draw_imgui() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        Metrics::show_metrics();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Core::initialize_window(int width, int height, const std::string &name) {
        main_context = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);//we create a window

        handle_new_window_size(width, height);

        glfwMakeContextCurrent(main_context);//we set the created window the current context

        glfwSetFramebufferSizeCallback(main_context, framebuffer_size_callback);//we set the callback function

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);//we initialize glad

        DefaultShaders::init_shaders();

        glViewport(0, 0, width, height);//we set the viewport

        glEnable(GL_DEPTH_TEST);//we enable depth testing

        init_imgui();


    }

    int Core::get_window_width() {
        return window_width;
    }

    int Core::get_window_height() {
        return window_height;
    }

    GLFWwindow *Core::get_main_context() {
        return main_context;
    }


    //this function sets window hints
    void Core::set_window_hints() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }


    //this function gets called when the window gets resized
    void Core::framebuffer_size_callback(GLFWwindow *window, int w, int h) {

        glViewport(0, 0, w, h);//we set the viewport
        handle_new_window_size(w, h);
    }


    //call renderer static method for updating projection matrix
    void Core::handle_new_window_size(int newwidth, int newheight) {

        window_width = newwidth;
        window_height = newheight;
        Renderer::update_projection_matrix(newwidth, newheight);
    }


    void Core::clear_screen(glm::vec3 color) {
        color /= 255.f;
        glClearColor(color.x, color.y, color.z, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }


    void Core::update_screen() {
        if (draw_gui)
            draw_imgui();
        glfwSwapBuffers(main_context);//we swap the buffers
        glfwPollEvents();//we poll events
    }


    glm::vec2 Core::get_cursor_position() {
        double x, y;
        glfwGetCursorPos(main_context, &x, &y);
        return glm::vec2(x, y);
    }

    bool Core::is_pressed(int key) {
        return glfwGetKey(main_context, key) == GLFW_PRESS;
    }

    void Core::lock_cursor() {
        glfwSetInputMode(main_context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    void Core::unlock_cursor() {
        glfwSetInputMode(main_context, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    bool Core::window_needs_to_close() {
        return glfwWindowShouldClose(main_context);
    }

    void Core::set_window_should_close(bool close) {
        glfwSetWindowShouldClose(main_context, close);
    }

    void Core::set_key_callback(void (*function)(GLFWwindow *, int, int, int, int)) {
        glfwSetKeyCallback(main_context,function);

    }

    void Core::set_should_draw_gui(bool draw) {
        draw_gui = draw;
    }

}