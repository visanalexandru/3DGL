//
// Created by gvisan on 23.07.2019.
//

#include "Texture2D.h"


void Texture2D::bind_texture() const {

    glBindTexture(GL_TEXTURE_2D, texture_index);

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
        texture_index = texture;

    } else {
        std::cout << "Failed to load texture: " << path << std::endl;
        texture_index = 0;
    }


    stbi_image_free(data);

}