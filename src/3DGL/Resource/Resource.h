//
// Created by gvisan on 08.08.2019.
//

#ifndef INC_3DGL_RESOURCE_H
#define INC_3DGL_RESOURCE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Resource {

protected:
    unsigned resource_index;

    virtual void bind_resource() const = 0;

    virtual void unload_resource() const = 0;



public:
    Resource();

    virtual ~Resource();

    unsigned get_resource_index() const;

};


#endif //INC_3DGL_RESOURCE_H
