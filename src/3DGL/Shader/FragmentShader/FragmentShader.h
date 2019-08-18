//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_FRAGMENTSHADER_H
#define INC_3DGL_FRAGMENTSHADER_H

#include "../Shader.h"
namespace gl3d {

    class FragmentShader : public Shader {
    protected:
        void load_shader_from_memory(const std::string &source) override;
    public:
        FragmentShader(const std::string &path);
    };

}
#endif //INC_3DGL_FRAGMENTSHADER_H
