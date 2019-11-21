//
// Created by gvisan on 21.11.2019.
//

#ifndef INC_3DGL_METRICS_H
#define INC_3DGL_METRICS_H

#include "../imgui/imgui.h"

namespace gl3d {
    class Metrics {
    public:
        static void show_metrics();

    private:
        static const int frames_to_render=10000;
        static float fps_log[frames_to_render];
        static int fps_index;
    };
}


#endif //INC_3DGL_METRICS_H
