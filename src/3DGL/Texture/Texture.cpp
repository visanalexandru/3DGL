//
// Created by gvisan on 23.07.2019.
//

#include "Texture.h"


void Texture::delete_texture() const {

    glDeleteTextures(1, &texture_index);

}

Texture::~Texture() {
    delete_texture();
}

Texture::Texture() : texture_index(0) {


}

const unsigned Texture::get_texture_index() const {

    return texture_index;

}