//
// Created by gvisan on 30.08.2019.
//

#include "Renderer.h"

namespace gl3d {
    float Renderer::field_of_view = 90.f;
    glm::mat4 Renderer::projection = glm::mat4(1);
    glm::mat4 Renderer::view = glm::mat4(1);
    FrustumCull Renderer::culler;

    void Renderer::update_projection_matrix(int width, int height) {
        projection = glm::perspective(glm::radians(field_of_view), (float) width / height, 0.1f,
                                      1000.0f);//updates projection matrix
    }


    void Renderer::set_view(const gl3d::Transformable &view_transform) {
        glm::mat4 v = glm::inverse(view_transform.get_rotation_matrix());//we inverse the camera rotation
        v = glm::translate(v, -view_transform.get_position());//we translate back
        view = v;
        culler.update(projection * view);
    }

    void Renderer::set_field_of_view(float fov) {
        field_of_view = fov;

    }


    void Renderer::set_shader_uniforms(const gl3d::Drawable3D &to_draw, const gl3d::ShaderProgram &program) {
        program.setMat4("model", to_draw.get_model_matrix());
        program.setMat4("view", view);
        program.setMat4("projection", projection);
        to_draw.set_shader_uniforms();
    }


    void Renderer::draw(const Skybox &skybox) {

        glDepthFunc(
                GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        glDisable(GL_CULL_FACE);
        glm::mat4 view2 = glm::mat4(glm::mat3(view));
        skybox.bind_texture();


        skybox.get_program().bind_shader();
        skybox.get_program().setMat4("pv", projection * view2);


        skybox.bind_mesh();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glEnable(GL_CULL_FACE);
        glDepthFunc(GL_LESS); // set depth function back to default

    }


    void Renderer::draw(const gl3d::Drawable3D &to_draw) {
        if (culler.drawableInFrusum(to_draw)) {
            to_draw.bind_texture();
            const ShaderProgram &program = to_draw.get_program();

            program.bind_shader();
            set_shader_uniforms(to_draw, program);
            to_draw.bind_mesh();

            glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);
        }

    }

    void Renderer::draw(const gl3d::Framebuffer &framebuffer) {


        glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
        framebuffer.get_program().bind_shader();
        framebuffer.set_shader_uniforms();
        framebuffer.bind_framebuffer_mesh();
        framebuffer.bind_texture();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glEnable(GL_DEPTH_TEST);


    }


    void Renderer::draw(const gl3d::RenderList &list_to_draw) {
        const std::vector<Drawable3D *> &vec = list_to_draw.get_list();

        if (vec.empty())
            return;


        Drawable3D::attributes last(-1, -1);
        const ShaderProgram *last_program;


        for (unsigned i = 0; i < vec.size(); i++) {

            Drawable3D &to_draw = *vec[i];

            if (culler.drawableInFrusum(to_draw)) {

                Drawable3D::attributes now = to_draw.get_attributes();


                if (!(now == last)) {


                    if (last.texture_index != now.texture_index) {
                        to_draw.bind_texture();

                    }


                    if (last.shader_program_index != now.shader_program_index) {
                        last_program = &to_draw.get_program();

                        last_program->bind_shader();

                    }

                    last = now;

                }

                set_shader_uniforms(to_draw, *last_program);
                to_draw.bind_mesh();

                glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);

            }
        }
    }
}
