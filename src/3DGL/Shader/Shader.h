//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_SHADER_H
#define INC_3DGL_SHADER_H


#include<iostream>
#include<fstream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
protected:

    std::string get_shader_data(const std::string &path) const;

    std::string get_compile_error_code() const;

    virtual void load_shader(const std::string &path) = 0;

    unsigned shader_index;

private:

    void delete_shader();

public:
    unsigned get_shader_index() const;
    
    Shader();

    virtual ~Shader();
};


#endif //INC_3DGL_SHADER_H
