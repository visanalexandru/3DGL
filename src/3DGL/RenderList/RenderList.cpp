//
// Created by gvisan on 24.07.2019.
//

#include "RenderList.h"


void RenderList::clear_list() {
    drawables.clear();

}

void RenderList::add_to_list(Drawable3D &to_add) {

    for (unsigned i = 0; i < drawables.size(); i++) {


        if (to_add.get_attributes() < drawables[i]->get_attributes()) {


            drawables.insert(drawables.begin() + i, &to_add);

            return;

        }

    }
    drawables.push_back(&to_add);

}