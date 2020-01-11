//
// Created by gvisan on 30.08.2019.
//

#include "Renderer.h"

namespace gl3d {

    int Renderer::visible_triangles = 0;

    void Renderer::set_shader_uniforms(const gl3d::Drawable3D &to_draw, const gl3d::ShaderProgram &program,
                                       const Camera &camera) {
        program.setMat4("model", to_draw.get_model_matrix());
        program.setMat4("view", camera.get_view_matrix());
        program.setMat4("projection", camera.get_projection_matrix());
        to_draw.set_shader_uniforms();
    }


    void Renderer::draw(const Skybox &skybox, const Camera &camera) {

        glDepthFunc(
                GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        glDisable(GL_CULL_FACE);
        glm::mat4 view2 = glm::mat4(glm::mat3(camera.get_view_matrix()));
        skybox.bind_texture();


        DefaultShaders::get_skybox_program().bind_shader();
        DefaultShaders::get_skybox_program().setMat4("pv", camera.get_projection_matrix() * view2);


        visible_triangles += 12;
        skybox.bind_mesh();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glEnable(GL_CULL_FACE);
        glDepthFunc(GL_LESS); // set depth function back to default

    }


    void Renderer::draw(const gl3d::Drawable3D &to_draw, const Camera &camera) {
        if (camera.get_frustum_culler().drawableInFrusum(to_draw)) {
            to_draw.bind_texture();
            const ShaderProgram &program = to_draw.get_program();

            program.bind_shader();
            set_shader_uniforms(to_draw, program, camera);
            to_draw.bind_mesh();

            visible_triangles += to_draw.get_triangle_count()/3;

            glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);
        }

    }

    void Renderer::draw(const gl3d::Framebuffer &framebuffer) {


        glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
        framebuffer.get_program().bind_shader();
        framebuffer.set_shader_uniforms();
        framebuffer.bind_framebuffer_mesh();
        framebuffer.bind_texture();
        visible_triangles += 2;
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glEnable(GL_DEPTH_TEST);


    }


    void Renderer::draw(const gl3d::RenderList &list_to_draw, const Camera &camera) {
        const std::vector<Drawable3D *> &vec = list_to_draw.get_list();

        if (vec.empty())
            return;


        Drawable3D::attributes last = vec[0]->get_attributes();
        const ShaderProgram *last_program = &vec[0]->get_program();


        for (unsigned i = 1; i < vec.size(); i++) {

            Drawable3D &to_draw = *vec[i];

            if (camera.get_frustum_culler().drawableInFrusum(to_draw)) {

                Drawable3D::attributes now = to_draw.get_attributes();


                if (now != last) {


                    if (last.texture_index != now.texture_index) {
                        to_draw.bind_texture();

                    }


                    if (last.shader_program_index != now.shader_program_index) {
                        last_program = &to_draw.get_program();

                        last_program->bind_shader();

                    }

                    last = now;

                }

                set_shader_uniforms(to_draw, *last_program, camera);
                to_draw.bind_mesh();

                visible_triangles += to_draw.get_triangle_count()/3;
                glDrawElements(GL_TRIANGLES, to_draw.get_triangle_count(), GL_UNSIGNED_INT, 0);

            }
        }
    }

    void Renderer::draw_gui() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        Metrics::show_metrics();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Renderer::clear_screen(glm::vec3 color) {
        color /= 255.f;
        glClearColor(color.x, color.y, color.z, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        visible_triangles = 0;
    }

    void Renderer::update_screen() {
        glfwSwapBuffers(Core::get_main_context());//we swap the buffers
        glfwPollEvents();//we poll events
    }
}
