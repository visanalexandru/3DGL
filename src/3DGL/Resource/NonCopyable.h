//
// Created by gvisan on 18.08.2019.
//

#ifndef INC_3DGL_NONCOPYABLE_H
#define INC_3DGL_NONCOPYABLE_H


class NonCopyable {
public:
    NonCopyable() = default;

    NonCopyable operator=(const NonCopyable &other) = delete;
    NonCopyable(const NonCopyable&other)= delete;

};


#endif //INC_3DGL_NONCOPYABLE_H
