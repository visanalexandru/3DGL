//
// Created by gvisan on 21.07.2019.
//

#include "ShaderProgram.h"

namespace gl3d {

    void ShaderProgram::attach_shader(const Shader &shader) const {

        glAttachShader(resource_index, shader.get_shader_index());

    }

    void ShaderProgram::check_for_succes() const {//this function logs errors when compiling the shader
        int success;
        char infoLog[512];
        glGetProgramiv(resource_index, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(resource_index, 512, nullptr, infoLog);
            std::string to_log = infoLog;
            throw std::runtime_error("Shader program compilation failed: " + to_log);

        } else
            std::cout << "Shader program compilation success" << std::endl;


    }


    void ShaderProgram::setMat4(const std::string &name, glm::mat4 value) const {

        int mat_location = glGetUniformLocation(resource_index, name.c_str());
        glUniformMatrix4fv(mat_location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void ShaderProgram::setFloat(const std::string &name, float value) const {

        glUniform1f(glGetUniformLocation(resource_index, name.c_str()), value);
    }

    void ShaderProgram::setInt(const std::string &name, int value) const {

        glUniform1i(glGetUniformLocation(resource_index, name.c_str()), value);
    }


    ShaderProgram::ShaderProgram(const VertexShader &v_shader, const FragmentShader &f_shader) {
        resource_index = glCreateProgram();//we create a new program
        //we attach vertex and fragment shaders
        attach_shader(f_shader);
        attach_shader(v_shader);

        glLinkProgram(resource_index);
        check_for_succes();

    }

    void ShaderProgram::delete_shader() const {

        glUseProgram(0);
        glDeleteProgram(resource_index);

    }

    void ShaderProgram::bind_shader() const {//this function activates the shader


        glUseProgram(resource_index);
    }

    ShaderProgram::~ShaderProgram() {
        delete_shader();

    }
}