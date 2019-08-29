//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_SHADERPROGRAM_H
#define INC_3DGL_SHADERPROGRAM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../VertexShader/VertexShader.h"
#include "../FragmentShader/FragmentShader.h"
#include "../../Resource/Resource.h"

namespace gl3d {

    class ShaderProgram : public Resource {
    private:

        void check_for_succes() const;

        void attach_shader(const Shader &shader) const;

        void delete_shader() const;


    public:
        ~ShaderProgram();


        void bind_shader() const;


        void setFloat(const std::string &name, float value) const;

        void setInt(const std::string &name, int value) const;

        void setMat4(const std::string &name, glm::mat4 value) const;


        ShaderProgram(const VertexShader &v_shader, const FragmentShader &f_shader);

    };
}


#endif //INC_3DGL_SHADERPROGRAM_H
