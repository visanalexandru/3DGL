//
// Created by gvisan on 21.07.2019.
//

#ifndef INC_3DGL_FRAGMENTSHADER_H
#define INC_3DGL_FRAGMENTSHADER_H

#include "../Shader.h"
namespace gl3d {

    class FragmentShader : public Shader {
    protected:
        void load_shader(const std::string &path) override;
    public:
        FragmentShader(const std::string &path);
    };

}
#endif //INC_3DGL_FRAGMENTSHADER_H
