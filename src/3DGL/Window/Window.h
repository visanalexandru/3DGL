//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_WINDOW_H
#define INC_3DGL_WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include <glm/glm.hpp>

class Window {
private:
    void init_graphics() const ;


    GLFWwindow*window;


    void create_window(int width,int height,const std::string&title);


    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:

    Window(int width,int height,const std::string&title);

    bool needs_to_close() const;

    void set_window_should_close();

    void clear(glm::vec3 color=glm::vec3(0,0,0)) const;

    void display() const;

};


#endif //INC_3DGL_WINDOW_H
