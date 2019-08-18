//
// Created by gvisan on 21.07.2019.
//

#include "FragmentShader.h"

namespace gl3d {

    void FragmentShader::load_shader_from_memory(const std::string &source) {

        const char *shader_to_compile = source.c_str();

        shader_index = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(shader_index, 1, &shader_to_compile, nullptr);

        glCompileShader(shader_index);


        int success;
        glGetShaderiv(shader_index, GL_COMPILE_STATUS, &success);

        if (!success) {
            throw std::runtime_error("Fragment Shader compilation failed: " + get_compile_error_code());
        }
    }

    FragmentShader::FragmentShader(const std::string &path) {

        load_shader_from_path(path);
    }
}