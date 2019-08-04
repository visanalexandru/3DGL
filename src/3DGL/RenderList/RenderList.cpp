//
// Created by gvisan on 24.07.2019.
//

#include "RenderList.h"
namespace gl3d {


    void RenderList::clear_list() {
        drawables.clear();

    }


    bool RenderList::compare(const Drawable3D *a, const Drawable3D *b) {

        return a->get_attributes() < b->get_attributes();
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


    const std::vector<Drawable3D *> &RenderList::get_list() const {

        return drawables;
    }

    void RenderList::update_list() {

        std::sort(drawables.begin(), drawables.end(), compare);

    }
}