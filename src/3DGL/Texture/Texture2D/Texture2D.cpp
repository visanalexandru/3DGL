//
// Created by gvisan on 23.07.2019.
//

#include "Texture2D.h"

namespace gl3d {


    void Texture2D::bind_texture() const {

        glBindTexture(GL_TEXTURE_2D, resource_index);

    }

    void Texture2D::load_texture(const std::string &path) {

        delete_texture();
        unsigned int texture;
        glGenTextures(1, &texture);//create empty texture
        glBindTexture(GL_TEXTURE_2D, texture);



        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



        // load and generate the texture
        int width, height, nrChannels;

        GLuint type = GL_RGB;

        stbi_set_flip_vertically_on_load(true);

        unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);//load texture data

        if (nrChannels == 4)//png images
            type = GL_RGBA;


        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);

            glGenerateMipmap(GL_TEXTURE_2D);

            std::cout << "Texture loaded: " << path << std::endl;
            resource_index = texture;

        } else {
            throw std::runtime_error("Failed to load texture: " + path);
        }


        stbi_image_free(data);

    }

    void Texture2D::delete_texture() const {
        glDeleteTextures(1, &resource_index);
    }

    Texture2D::~Texture2D() {
        delete_texture();
    }

    void Texture2D::bind_empty_texture() {

        glBindTexture(GL_TEXTURE_2D, 0);
    }
}


