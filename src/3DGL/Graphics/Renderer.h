//
// Created by gvisan on 30.08.2019.
//

#ifndef INC_3DGL_RENDERER_H
#define INC_3DGL_RENDERER_H

#include "../Drawable/Drawable3D.h"
#include "../Drawable/Skybox/Skybox.h"
#include "../RenderList/RenderList.h"
#include "../FrustumCulling/FrustumCull.h"
#include "../Framebuffer/Framebuffer.h"
#include "../Camera/Camera.h"

namespace gl3d {
    class Renderer {
    private:
        static void set_shader_uniforms(const Drawable3D &to_draw, const ShaderProgram &program,const Camera&camera);

    public:

        static void draw(const Skybox &skybox, const Camera &camera);

        static void draw(const Drawable3D &to_draw, const Camera &camera);

        static void draw(const Framebuffer &framebuffer);

        static void draw(const RenderList &list_to_draw, const Camera &camera);


    };
}


#endif //INC_3DGL_RENDERER_H
