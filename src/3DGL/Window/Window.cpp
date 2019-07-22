//
// Created by gvisan on 21.07.2019.
//

#include "Window.h"


Window::Window(int width, int height, const std::string &title) {

    init_graphics();
    create_window(width, height, title);
}


void Window::framebuffer_size_callback(GLFWwindow *window, int width,
                                       int height) {//function to update the viewport when window size is modified

    glViewport(0, 0, width, height);//we set the viewport
}


void Window::init_graphics() const {//function to initialize glfw graphics


    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}


bool Window::needs_to_close() const {

    return glfwWindowShouldClose(window);

}

void Window::set_window_should_close() {

    glfwSetWindowShouldClose(window, true);
}

void Window::create_window(int width, int height, const std::string &title) {//for creating the window

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);//we create a window

    glfwMakeContextCurrent(window);//we set the created window the current context

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//we set the callback function

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);//we initialize glad

    glViewport(0, 0, width, height);//we set the viewport

}


void Window::clear(glm::vec3 color) const {//clear the screen

    color /= 255.f;
    glClearColor(color.x, color.y, color.z, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

}

void Window::display() const {//display what we had rendered

    glfwSwapBuffers(window);//we swap the buffers

    glfwPollEvents();//we poll events
}
