//
// Created by gvisan on 29.08.2019.
//

#ifndef INC_3DGL_FRAMEBUFFER_H
#define INC_3DGL_FRAMEBUFFER_H

#include "../Resource/NonCopyable.h"
#include "../Mesh/Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gl3d {
    class Framebuffer : public NonCopyable {
    private:
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

        void unbind_framebuffer() const;

        Framebuffer(int width, int height);

    };
}


#endif //INC_3DGL_FRAMEBUFFER_H
