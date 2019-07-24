//
// Created by gvisan on 21.07.2019.
//

#include "ShaderProgram.h"

void ShaderProgram::attach_shader(const Shader &shader) const {

    glAttachShader(shader_program_index, shader.get_shader_index());

}

void ShaderProgram::check_for_succes() const {//this function logs errors when compiling the shader
    int success;
    char infoLog[512];
    glGetProgramiv(shader_program_index, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shader_program_index, 512, nullptr, infoLog);
        std::cout << "Shader program compilation failed :" << std::endl;
        std::cout << infoLog << std::endl;

    } else
        std::cout << "Shader program compilation success" << std::endl;


}

const unsigned ShaderProgram::get_shader_index() const {

    return shader_program_index;

}

void ShaderProgram::setMat4(const std::string &name, glm::mat4 value) const {

    int mat_location = glGetUniformLocation(shader_program_index, name.c_str());
    glUniformMatrix4fv(mat_location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setFloat(const std::string &name, float value) const {

    glUniform1f(glGetUniformLocation(shader_program_index, name.c_str()), value);
}

void ShaderProgram::setInt(const std::string &name, int value) const {

    glUniform1i(glGetUniformLocation(shader_program_index, name.c_str()), value);
}


ShaderProgram::ShaderProgram(const VertexShader &v_shader, const FragmentShader &f_shader) {
    shader_program_index = glCreateProgram();//we create a new program
    //we attach vertex and fragment shaders
    attach_shader(f_shader);
    attach_shader(v_shader);

    glLinkProgram(shader_program_index);
    check_for_succes();

}

void ShaderProgram::bind_shader() const {//this function activates the shader


    glUseProgram(shader_program_index);
}

ShaderProgram::~ShaderProgram() {

    glUseProgram(0);
    glDeleteProgram(shader_program_index);
}