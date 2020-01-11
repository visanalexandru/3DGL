//
// Created by gvisan on 21.11.2019.
//

#include "Metrics.h"
#include "Renderer.h"

namespace gl3d {
    int Metrics::fps_index = 0;
    float Metrics::fps_log[frames_to_render];


    void Metrics::show_metrics() {
        ImGui::Begin("Metrics Window");

        float frame_time = ImGui::GetIO().Framerate;
        float frames_per_second = 1000.0f / frame_time;

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", frames_per_second, frame_time);


        if (fps_index == frames_to_render) {
            for (int i = 0; i < frames_to_render - 1; i++) {
                fps_log[i] = fps_log[i + 1];
            }
            fps_index--;
        }

        fps_log[fps_index] = frames_per_second;
        fps_index++;

        ImGui::PlotLines("Frame Times", fps_log, frames_to_render);
        ImGui::Text("Visible triangles: %.i ", Renderer::visible_triangles);
        ImGui::Text("Draw calls: %.i ", Renderer::draw_calls);

        ImGui::End();
    }
}