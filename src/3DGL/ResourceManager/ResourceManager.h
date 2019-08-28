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
        std::unordered_map<std::string, Resource *> resources;

        template<class type>
        bool contains(std::unordered_map<std::string, type> &map, const std::string &to_check);

        void delete_resources();


    public:
        void load_shader(const std::string &name, const std::string &v_path, const std::string &f_path);

        void load_cubemap(const std::string &name, const std::string &path, const std::vector<std::string> &paths);

        void load_texture(const std::string &name, const std::string &path);


        const ShaderProgram &get_shader(const std::string &name);

        const Texture2D &get_texture(const std::string &name);

        const Cubemap &get_cubemap(const std::string &name);

        ~ResourceManager();


    };


    template<class type>
    bool ResourceManager::contains(std::unordered_map<std::string, type> &map, const std::string &to_check) {

        return map.find(to_check) != map.end();
    }


}


#endif //INC_3DGL_RESOURCEMANAGER_H
