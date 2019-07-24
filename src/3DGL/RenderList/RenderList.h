//
// Created by gvisan on 24.07.2019.
//

#ifndef INC_3DGL_RENDERLIST_H
#define INC_3DGL_RENDERLIST_H

#include <iostream>
#include"../Drawable/Drawable3D.h"
#include<vector>


class RenderList {//this class is for organizing drawables into a list
private:
    std::vector<Drawable3D *> drawables;

public:
    void add_to_list(Drawable3D &to_add);


    void clear_list();

};


#endif //INC_3DGL_RENDERLIST_H
