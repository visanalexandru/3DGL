//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_SHADERPROGRAM_H
#define INC_3DGL_SHADERPROGRAM_H

#include "../VertexShader/VertexShader.h"
#include "../FragmentShader/FragmentShader.h"

class ShaderProgram {
private:
    unsigned shader_program_index;

    void check_for_succes() const;

    void attach_shader(const Shader &shader) const;

public:
    ~ShaderProgram();

    void bind_shader() const;

    void setFloat(const std::string &name, float value) const;

    void setInt(const std::string &name, int value) const;

    ShaderProgram(const VertexShader &v_shader, const FragmentShader &f_shader);

};


#endif //INC_3DGL_SHADERPROGRAM_H
