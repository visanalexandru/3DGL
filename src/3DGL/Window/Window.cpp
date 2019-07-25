//
// Created by gvisan on 21.07.2019.
//

#include "Window.h"


Window::Window(int w, int h, const std::string &title) : projection(1), view(1), field_of_view(45.f) {

    handle_new_window_size(w, h);
    init_graphics();
    create_window(width, height, title);
}


void Window::update_projection_matrix() {

    projection = glm::perspective(glm::radians(field_of_view), (float) width / height, 0.1f,
                                  100.0f);//updates projection matrix
}


void Window::handle_new_window_size(int newwidth, int newheight) {//this function handles screen size update

    width = newwidth;
    height = newheight;

    update_projection_matrix();
}

bool Window::is_pressed(int key) const {

    return glfwGetKey(window, key) == GLFW_PRESS;

}

void Window::set_field_of_view(float fov) {

    field_of_view = fov;
    update_projection_matrix();//we update the projection matrix

}

void Window::set_view(const Transformable &new_view) {//sets the camera transform

    glm::mat4 v = glm::inverse(new_view.get_rotation_matrix());//we inverse the camera rotation
    v = glm::translate(v, -new_view.get_position());//we translate back
    view = v;

}

void Window::framebuffer_size_callback(GLFWwindow *window, int w,
                                       int h) {//function to update the viewport when window size is modified

    glViewport(0, 0, w, h);//we set the viewport

    void *ptr = glfwGetWindowUserPointer(window);//we take the window pointer
    Window *this_window = reinterpret_cast<Window *>(ptr);//casting to window type
    this_window->handle_new_window_size(w, h);//update window size
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


void Window::draw(const RenderList &list_to_draw) const {

    const std::vector<Drawable3D *> &vec = list_to_draw.get_list();


    if (vec.empty())
        return;


    Drawable3D::attributes last = vec[0]->get_attributes();
    const ShaderProgram *last_program = &vec[0]->get_program();


    last_program->bind_shader();
    vec[0]->get_texture().bind_texture();


    for (unsigned i = 0; i < vec.size(); i++) {

        Drawable3D &to_draw = *vec[i];

        glm::mat4 model = to_draw.get_model_matrix();

        Drawable3D::attributes now = to_draw.get_attributes();


        if (!(now == last)) {


            if (last.texture_index != now.texture_index) {
                to_draw.get_texture().bind_texture();

            }


            if (last.shader_program_index != now.shader_program_index) {
                last_program = &to_draw.get_program();

                last_program->bind_shader();

            }

            last = now;

        }

        last_program->setMat4("mvp", projection * view * model);
        to_draw.get_mesh().bind_mesh();

        glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);

    }


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

    glEnable(GL_DEPTH_TEST);//we enable depth testing

}

void Window::draw(const Drawable3D &to_draw) const {

    glm::mat4 model = to_draw.get_model_matrix();
    to_draw.get_texture().bind_texture();
    const ShaderProgram &program = to_draw.get_program();

    program.bind_shader();
    program.setMat4("mvp", projection * view * model);
    to_draw.get_mesh().bind_mesh();

    glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);

}

glm::vec2 Window::get_cursor_position() const {

    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return glm::vec2(x, y);

}

void Window::lock_cursor() const {

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::clear(glm::vec3 color) const {//clear the screen

    color /= 255.f;
    glClearColor(color.x, color.y, color.z, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}


void Window::display() const {//display what we had rendered

    glfwSwapBuffers(window);//we swap the buffers

    glfwPollEvents();//we poll events
}
