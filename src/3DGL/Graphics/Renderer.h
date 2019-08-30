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


namespace gl3d {
    class Renderer {
    private:
        static float field_of_view;
        static glm::mat4 projection;
        static glm::mat4 view;
        static FrustumCull culler;
        static int last_width;
        static int last_height;

        static void set_shader_uniforms(const Drawable3D &to_draw, const ShaderProgram &program);

    public:
        static void update_projection_matrix(int width, int height);

        static void set_view(const Transformable &view_transform);

        static void set_field_of_view(float fov);

        static void draw(const Skybox &skybox);

        static void draw(const Drawable3D &to_draw);

        static void draw(const Framebuffer &framebuffer);

        static void draw(const RenderList &list_to_draw);


    };
}


#endif //INC_3DGL_RENDERER_H
