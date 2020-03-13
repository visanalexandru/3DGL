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
#include <algorithm>

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

        glm::vec3 FindPosition(float time) const {


            int l = std::lower_bound(position_frames.begin(), position_frames.end(), time, Comparator()) -
                    position_frames.begin();

            if (l == 0)
                return position_frames[0].position;

            float before = position_frames[l - 1].time;
            float after = position_frames[l].time;
            float distance = after - before;
            float coef = (time - before) / distance;
            return glm::mix(position_frames[l - 1].position, position_frames[l].position, coef);


        }

        glm::quat FindRotation(float time) const {
            int l = std::lower_bound(rotation_frames.begin(), rotation_frames.end(), time, Comparator()) -
                    rotation_frames.begin();

            if (l == 0)
                return rotation_frames[0].rotation;

            float before = rotation_frames[l - 1].time;
            float after = rotation_frames[l].time;
            float distance = after - before;
            float coef = (time - before) / distance;


            return glm::slerp(rotation_frames[l - 1].rotation, rotation_frames[l].rotation, coef);
        }
    };

    std::vector<AnimationNode> animation_nodes;
    double duration;
    double ticks_per_second;


private:
    struct Comparator {

        float asTime(const PositionFrame &a) const{
            return a.time;
        }

        float asTime(const RotationFrame &a) const{
            return a.time;
        }

        float asTime(float a) const {
            return a;
        }

        template<typename T1, typename T2>
        bool operator()(T1 const &t1, T2 const &t2) const {
            return asTime(t1) < asTime(t2);
        }
    };


};


#endif //INC_3DGL_ANIMATION_H
