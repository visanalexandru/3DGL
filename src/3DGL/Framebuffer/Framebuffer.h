//
// Created by gvisan on 29.08.2019.
//

#ifndef INC_3DGL_FRAMEBUFFER_H
#define INC_3DGL_FRAMEBUFFER_H

#include "../Resource/NonCopyable.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderProgram/ShaderProgram.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gl3d {
    class Framebuffer : public NonCopyable {
    private:
        const ShaderProgram *screen_program;
        Mesh quad;
        unsigned textureColorbuffer;
        unsigned renderbuffer;
        unsigned framebuffer;

        void create_framebuffer(int width, int height);

        void delete_framebuffer() const;

    public:

        ~Framebuffer();

        void bind_framebuffer() const;

        void bind_framebuffer_texture() const;

        void bind_framebuffer_mesh() const;

        void set_shader_program(const ShaderProgram &prog);

        const ShaderProgram &get_program() const;

        void unbind_framebuffer() const;

        Framebuffer(int width, int height);

    };
}


#endif //INC_3DGL_FRAMEBUFFER_H
