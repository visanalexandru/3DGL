//
// Created by gvisan on 18.08.2019.
//

#ifndef INC_3DGL_DEFAULTSHADERS_H
#define INC_3DGL_DEFAULTSHADERS_H

#include <string>
#include "../ShaderProgram/ShaderProgram.h"

namespace gl3d {

    class DefaultShaders {
    private:
        static const std::string basic_vertex_source;
        static const std::string basic_fragment_source;

        static const std::string skybox_vertex_source;
        static const std::string skybox_fragment_source;

        static const VertexShader basic_vertex_shader;
        static const FragmentShader basic_fragment_shader;

        static const VertexShader skybox_vertex_shader;
        static const FragmentShader skybox_fragment_shader;


        static const ShaderProgram default_program;
        static const ShaderProgram skybox_program;

    public:

        static const ShaderProgram &get_default_program();

        static const ShaderProgram &get_skybox_program();

    };


}


#endif //INC_3DGL_DEFAULTSHADERS_H
