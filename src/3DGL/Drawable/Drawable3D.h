//
// Created by gvisan on 22.07.2019.
//

#ifndef INC_3DGL_DRAWABLE3D_H
#define INC_3DGL_DRAWABLE3D_H

#include "../Transformable/Transformable.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderProgram/ShaderProgram.h"
#include "../Texture/Texture2D/Texture2D.h"
#include "../FrustumCulling/AABB.h"
#include "../Shader/DefaultShaders/DefaultShaders.h"

namespace gl3d {


    class Drawable3D : public Transformable {


    private:
        const Mesh *mesh;
        const Texture2D *texture;
        const ShaderProgram *shader_program;
        AABB local_bounding_box;
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

        virtual void set_shader_uniforms() const {};

        const ShaderProgram &get_program() const;

        const Texture2D &get_texture() const;

        std::pair<glm::vec3, glm::vec3> get_mesh_bounds() const;

        void set_texture(const Texture2D &new_texture);

        void set_mesh(const Mesh &new_mesh);

        void set_shader_program(const ShaderProgram &program);

        void bind_texture() const;

        void bind_mesh() const;

        void set_rotation(glm::vec3 new_rotation) override;

        void set_scale(glm::vec3 new_scale) override;

        void update_local_bounds();

        attributes get_attributes() const;

        AABB get_bounding_box() const;


        unsigned get_triangle_count() const;


        Drawable3D();

        Drawable3D(glm::vec3 position);


        ~Drawable3D() = default;


    };

}
#endif //INC_3DGL_DRAWABLE3D_H
