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

class Drawable3D : public Transformable {


private:
    Mesh mesh;
    Texture *texture;
    bool has_default_texture;
    const ShaderProgram &shader_program;
public:
    void bind_mesh() const;

    void set_texture(Texture&new_texture);

    void bind_texture() const;

    unsigned get_vertex_count() const;

    const ShaderProgram &get_program() const;

    Drawable3D(const ShaderProgram &shader);

    Drawable3D(const ShaderProgram &shader, glm::vec3 position);


    ~Drawable3D();

    template<class datatype>
    void set_mesh_data(MeshBuffer<datatype> &vertex_data);

};


template<class datatype>
void Drawable3D::set_mesh_data(MeshBuffer<datatype> &vertex_data) {

    mesh.set_data(vertex_data);

}

#endif //INC_3DGL_DRAWABLE3D_H
