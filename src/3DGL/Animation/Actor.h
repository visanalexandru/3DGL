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
        Node *root_bone;
        Mesh mesh;

        void update_bones(Node *here, glm::mat4 transform);

    public:
        Actor(const ActorData &data);

        virtual void set_shader_uniforms() const override;

    };
}


#endif //INC_3DGL_ACTOR_H
