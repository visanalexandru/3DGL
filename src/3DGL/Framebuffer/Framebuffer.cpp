//
// Created by gvisan on 29.08.2019.
//

#include <stdexcept>
#include "Framebuffer.h"
#include "../Shader/DefaultShaders/DefaultShaders.h"

namespace gl3d {


    void Framebuffer::create_framebuffer(int width, int height) {
        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        glGenTextures(1, &textureColorbuffer);
        glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);
        // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)


        glGenRenderbuffers(1, &renderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width,
                              height); // use a single renderbuffer object for both a depth AND stencil buffer.
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER,
                                  renderbuffer); // now actually attach it
        // now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            throw std::runtime_error("Could not create framebuffer");
        glBindFramebuffer(GL_FRAMEBUFFER, 0);


    }


    void Framebuffer::delete_framebuffer() const {

        glDeleteFramebuffers(1, &framebuffer);
        glDeleteTextures(1, &textureColorbuffer);
        glDeleteRenderbuffers(1, &renderbuffer);


    }


    void Framebuffer::unbind_framebuffer() const {

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

    }


    void Framebuffer::bind_framebuffer() const {

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    }


    Framebuffer::~Framebuffer() {
        delete_framebuffer();
    }


    Framebuffer::Framebuffer(int width, int height) {
        MeshBuffer<sprite_vertex> data;


        sprite_vertex d(glm::vec2(-1, 1), glm::vec2(0, 1));
        sprite_vertex a(glm::vec2(-1, -1), glm::vec2(0, 0));
        sprite_vertex b(glm::vec2(1, -1), glm::vec2(1, 0));
        sprite_vertex c(glm::vec2(1, 1), glm::vec2(1, 1));

        data.add_triangle(d, a, b);
        data.add_triangle(d, b, c);


        quad.set_data(data);
        create_framebuffer(width, height);

        screen_program = &DefaultShaders::get_framebuffer_program();
    }

    void Framebuffer::set_shader_program(const gl3d::ShaderProgram &prog) {
        screen_program = &prog;
    }

    const ShaderProgram &Framebuffer::get_program() const {
        return *screen_program;
    }


    void Framebuffer::bind_framebuffer_texture() const {

        glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    }

    void Framebuffer::bind_framebuffer_mesh() const {
        quad.bind_resource();
    }

}