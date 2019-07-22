//
// Created by gvisan on 21.07.2019.
//

#include "Window.h"


Window::Window(int w, int h, const std::string &title) : projection(1) {

    set_window_size(w, h);
    init_graphics();
    create_window(width, height, title);
}

void Window::update_projection_matrix() {

    projection = glm::perspective(glm::radians(45.0f), (float) width / height, 0.1f, 100.0f);//updates projection matrix
}


void Window::set_window_size(int newwidth, int newheight) {//this function handles screen size update

    width = newwidth;
    height = newheight;

    update_projection_matrix();
}

void Window::framebuffer_size_callback(GLFWwindow *window, int w,
                                       int h) {//function to update the viewport when window size is modified

    glViewport(0, 0, w, h);//we set the viewport

    void *ptr = glfwGetWindowUserPointer(window);//we take the window pointer
    Window *this_window = reinterpret_cast<Window *>(ptr);//casting to window type
    this_window->set_window_size(w, h);//update window size
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

    glfwSetWindowUserPointer(window,
                             this);//this function sets the pointer to this window to the glfw window so it can be handled in the callbacks

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
