//
// Created by gvisan on 02.02.2020.
//

#ifndef INC_3DGL_ANIMATION_H
#define INC_3DGL_ANIMATION_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include<glm/gtx/quaternion.hpp>
#include <iostream>

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

            int l = 0, r = position_frames.size() - 1, middle;
            float middle_time;

            while (l < r) {
                middle = (l + r) / 2;
                middle_time = position_frames[middle].time;
                if (time <= middle_time) {
                    r = middle;
                } else {
                    l = middle + 1;
                }
            }

            float before = position_frames[l - 1].time;
            float after = position_frames[l].time;


            float distance = after - before;
            float coef = (time - before) / distance;

            return glm::mix(position_frames[l-1].position, position_frames[l].position, coef);
        }

        glm::quat FindRotation(float time) {
            int l = 0, r = rotation_frames.size() - 1, middle;
            float middle_time;

            while (l < r) {
                middle = (l + r) / 2;
                middle_time = rotation_frames[middle].time;
                if (time <= middle_time) {
                    r = middle;
                } else {
                    l = middle + 1;
                }
            }

            float before = rotation_frames[l - 1].time;
            float after = rotation_frames[l].time;


            float distance = after - before;
            float coef = (time - before) / distance;

            return glm::mix(rotation_frames[l-1].rotation, rotation_frames[l].rotation, coef);
        }
    };

    std::vector<AnimationNode> animation_nodes;
    double duration;
    double ticks_per_second;


};


#endif //INC_3DGL_ANIMATION_H
