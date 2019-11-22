//
// Created by gvisan on 08.08.2019.
//

#ifndef INC_3DGL_RESOURCEMANAGER_H
#define INC_3DGL_RESOURCEMANAGER_H

#include "../Shader/ShaderProgram/ShaderProgram.h"
#include "../Texture/Texture2D/Texture2D.h"
#include "../Texture/Cubemap/Cubemap.h"
#include <unordered_map>
#include <string>

namespace gl3d {

    class ResourceManager {
    private:
        static std::unordered_map<std::string, Resource *> resources;

        static bool contains(const std::string &to_check);

    public:
        static void load_shader(const std::string &name, const std::string &v_path, const std::string &f_path);

        static void
        load_cubemap(const std::string &name, const std::string &path, const std::vector<std::string> &paths);

        static void load_texture(const std::string &name, const std::string &path);


        static const ShaderProgram &get_shader(const std::string &name);

        static const Texture2D &get_texture(const std::string &name);

        static const Cubemap &get_cubemap(const std::string &name);

        static void unload_all_resources();

        static void unload_resource(const std::string &name);
    };

}


#endif //INC_3DGL_RESOURCEMANAGER_H
