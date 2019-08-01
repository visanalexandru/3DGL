//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_DRAWABLE3D_H
#define INC_3DGL_DRAWABLE3D_H

#include "../Transformable/Transformable.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderProgram/ShaderProgram.h"
#include "../Texture/Texture.h"
#include "../Texture/Texture2D/Texture2D.h"
#include "../FrustumCulling/AABB.h"

class Drawable3D : public Transformable {


private:
    const Mesh *mesh;
    const Texture *texture;
    const ShaderProgram &shader_program;
public:

    struct attributes {
        unsigned texture_index, shader_program_index;

        attributes(unsigned tex, unsigned sh) : texture_index(tex), shader_program_index(sh) {};

        attributes() : texture_index(0), shader_program_index(0) {};

        bool operator==(const attributes &other) {
            return texture_index == other.texture_index && shader_program_index == other.shader_program_index;
        }

        bool operator<(const attributes &other) {
            if (texture_index < other.texture_index) {
                return true;
            } else if (texture_index > other.texture_index)
                return false;

            else {
                return shader_program_index < other.shader_program_index;
            }


        }


    };


    const Mesh &get_mesh() const;

    const ShaderProgram &get_program() const;

    const Texture &get_texture() const;

    std::pair<glm::vec3, glm::vec3> get_mesh_bounds() const;

    void set_texture(const Texture &new_texture);

    void set_mesh(const Mesh &new_mesh);

    void bind_texture() const;

    void bind_mesh() const;

    attributes get_attributes() const;

    AABB get_bounding_box() const;


    unsigned get_triangle_count() const;


    Drawable3D(const ShaderProgram &shader);

    Drawable3D(const ShaderProgram &shader, glm::vec3 position);


    ~Drawable3D();


};


#endif //INC_3DGL_DRAWABLE3D_H
