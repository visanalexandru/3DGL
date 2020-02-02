//
// Created by gvisan on 02.02.2020.
//

#ifndef INC_3DGL_ANIMATION_H
#define INC_3DGL_ANIMATION_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include<glm/gtx/quaternion.hpp>

class Animation {
public:
    struct PositionFrame {
        glm::vec3 position;
        float time;

        PositionFrame() : position(0, 0, 0), time(0) {

        }
    };

    struct RotationFrame {
        glm::quat rotation;
        float time;

        RotationFrame() : rotation(0, 0, 0, 0), time(0) {

        }
    };

    struct AnimationNode {
        std::string name;
        std::vector<PositionFrame> position_frames;
        std::vector<RotationFrame> rotation_frames;

        glm::vec3 FindPosition(float time) {
            for (int i = 0; i < position_frames.size() - 1; i++) {
                if (time < position_frames[i + 1].time) {
                    return position_frames[i].position;
                }
            }
        }

        glm::quat FindRotation(float time) {
            for (int i = 0; i < rotation_frames.size() - 1; i++) {
                if (time < rotation_frames[i + 1].time) {
                    return rotation_frames[i].rotation;
                }
            }
        }
    };

    std::vector<AnimationNode> animation_nodes;
    double duration;
    double ticks_per_second;


};


#endif //INC_3DGL_ANIMATION_H
