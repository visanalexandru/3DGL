//
// Created by gvisan on 24.07.2019.
//

#ifndef INC_3DGL_RENDERLIST_H
#define INC_3DGL_RENDERLIST_H

#include <iostream>
#include"../Drawable/Drawable3D.h"
#include<vector>
#include <algorithm>
namespace gl3d {


    class RenderList {//this class is for organizing drawables into a list
    private:
        std::vector<Drawable3D *> drawables;

        static bool compare(const Drawable3D *a, const Drawable3D *b);

    public:
        void add_to_list(Drawable3D &to_add);

        const std::vector<Drawable3D *> &get_list() const;

        void clear_list();

        void update_list();

    };

}

#endif //INC_3DGL_RENDERLIST_H
