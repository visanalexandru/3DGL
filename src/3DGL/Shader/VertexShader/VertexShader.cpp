//
// Created by gvisan on 21.07.2019.
//

#include "VertexShader.h"

namespace gl3d {

    void VertexShader::load_shader_from_memory(const std::string &source) {
        delete_shader();
        const char *shader_to_compile = source.c_str();

        shader_index = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(shader_index, 1, &shader_to_compile, nullptr);

        glCompileShader(shader_index);


        int success;
        glGetShaderiv(shader_index, GL_COMPILE_STATUS, &success);

        if (!success) {

            throw std::runtime_error("Vertex Shader compilation failed: " + get_compile_error_code());

        }

    }


    VertexShader::VertexShader(const std::string &source) {


        load_shader_from_memory(source);

    }
}