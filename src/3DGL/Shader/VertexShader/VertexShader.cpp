//
// Created by gvisan on 21.07.2019.
//

#include "VertexShader.h"
namespace gl3d {

    void VertexShader::load_shader(const std::string &path) {

        std::string shader_data = get_shader_data(path);

        const char *shader_to_compile = shader_data.c_str();

        shader_index = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(shader_index, 1, &shader_to_compile, nullptr);

        glCompileShader(shader_index);


        int success;
        glGetShaderiv(shader_index, GL_COMPILE_STATUS, &success);

        if (!success) {

            throw std::runtime_error("Vertex Shader compilation failed: " +path+" "+get_compile_error_code());

        } else {
            std::cout << "Vertex Shader compilation successful: " << path << std::endl;

        }
    }


    VertexShader::VertexShader(const std::string &path) {


        load_shader(path);

    }
}