//
// Created by gvisan on 31.07.2019.
//

#include "Cubemap.h"


std::string Cubemap::cubemap_names[6]{
        "right.jpg",
        "left,jpg",
        "top.jpg",
        "botom.jpg",
        "front.jpg",
        "back.jpg"
};


void Cubemap::load_texture(const std::string &path) {


    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);



// set the texture wrapping/filtering options (on the currently bound texture object)
// load and generate the texture



    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(false);


    for (int i = 0; i < 6; i++) {


        std::string newpath = path + "/" + cubemap_names[i];


        unsigned char *data = stbi_load(newpath.c_str(), &width, &height, &nrChannels, 0);


        if (data) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                         data);


            std::cout << "Texture loaded: " << newpath << std::endl;


        } else {

            std::cout << "Failed to load texture :" << newpath << std::endl;


        }
        stbi_image_free(data);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    texture_index = texture;


}


void Cubemap::bind_texture() const {

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture_index);

}