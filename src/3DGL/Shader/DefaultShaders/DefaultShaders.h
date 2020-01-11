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

        static const std::string gizmos_vertex_source;
        static const std::string gizmos_fragment_source;

        static const std::string skybox_vertex_source;
        static const std::string skybox_fragment_source;


        static const std::string framebuffer_vertex_source;
        static const std::string framebuffer_fragment_source;

        static const ShaderProgram *default_program;
        static const ShaderProgram *skybox_program;
        static const ShaderProgram *framebuffer_program;
        static const ShaderProgram *gizmos_program;

    public:

        static void init_shaders();

        static void delete_shaders();

        static const ShaderProgram &get_default_program();

        static const ShaderProgram &get_skybox_program();

        static const ShaderProgram &get_gizmo_program();

        static const ShaderProgram &get_framebuffer_program();

    };


}


#endif //INC_3DGL_DEFAULTSHADERS_H
