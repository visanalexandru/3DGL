//
// Created by gvisan on 01.02.2020.
//

#ifndef INC_3DGL_ACTOR_H
#define INC_3DGL_ACTOR_H

#include "../Drawable/Drawable3D.h"
#include "ActorData.h"

namespace gl3d {

    class Actor : public Drawable3D {
    private:
        glm::mat4 bones[100];
        NodeStructure node_structure;
        Mesh mesh;
        Animation animation;

        void update_bones(const Node *here, glm::mat4 transform);

    public:
        void update_animation(float time);

        Actor(const ActorData &data);

        virtual void set_shader_uniforms() const override;

    };
}


#endif //INC_3DGL_ACTOR_H
