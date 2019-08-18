//
// Created by gvisan on 21.07.2019.
//

#include "Shader.h"

namespace gl3d {

    std::string Shader::get_shader_data(const std::string &path) const {

        std::ifstream input(path);

        if (input.fail())
            throw std::runtime_error("cannot open file: " + path);

        std::stringstream buffer;

        buffer << input.rdbuf();

        return buffer.str();

    }

    std::string Shader::get_compile_error_code() const {
        char err[512];

        glGetShaderInfoLog(shader_index, 512, nullptr, err);

        return err;
    }


    void Shader::load_shader_from_path(const std::string &path) {

        load_shader_from_memory(get_shader_data(path));
    }


    void Shader::delete_shader() {

        glDeleteShader(shader_index);
    }

    Shader::~Shader() {


        delete_shader();


    }

    unsigned Shader::get_shader_index() const {


        return shader_index;
    }


    Shader::Shader() : shader_index(0) {


    }
}