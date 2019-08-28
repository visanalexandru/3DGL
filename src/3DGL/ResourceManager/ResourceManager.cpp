//
// Created by gvisan on 08.08.2019.
//

#include "ResourceManager.h"


namespace gl3d {

    void ResourceManager::load_shader(const std::string &name, const std::string &v_path, const std::string &f_path) {


        if (contains(resources, name))
            throw std::runtime_error("shader already exists: " + name);

        FragmentShader f;
        f.load_shader_from_path(f_path);
        VertexShader v;
        v.load_shader_from_path(v_path);

        ShaderProgram *new_shader = new ShaderProgram(v, f);

        resources[name] = new_shader;


    }


    void ResourceManager::load_texture(const std::string &name, const std::string &path) {

        if (contains(resources, name))
            throw std::runtime_error("texture already exists: " + name);


        Texture2D *new_texture = new Texture2D();
        new_texture->load_texture(path);

        resources[name] = new_texture;

    }


    void ResourceManager::load_cubemap(const std::string &name, const std::string &path,
                                       const std::vector<std::string> &paths) {

        if (contains(resources, name))
            throw std::runtime_error("cubemap already exists: " + name);

        Cubemap *new_cubemap = new Cubemap();

        new_cubemap->load_texture(path, paths);

        resources[name] = new_cubemap;


    }


    const ShaderProgram &ResourceManager::get_shader(const std::string &name) {

        if (contains(resources, name)) {

            Resource *res = resources[name];

            ShaderProgram *derived_cast = dynamic_cast<ShaderProgram *>(res);

            if (derived_cast == nullptr) {
                throw std::runtime_error("resource is not a shader: " + name);

            }

            return *derived_cast;

        } else throw std::runtime_error("resource does not exist: " + name);

    }

    const Texture2D &ResourceManager::get_texture(const std::string &name) {

        if (contains(resources, name)) {

            Resource *res = resources[name];

            Texture2D *derived_cast = dynamic_cast<Texture2D *>(res);

            if (derived_cast == nullptr) {
                throw std::runtime_error("resource is not a texture: " + name);

            }

            return *derived_cast;

        } else throw std::runtime_error("resource does not exist: " + name);

    }

    const Cubemap &ResourceManager::get_cubemap(const std::string &name) {
        if (contains(resources, name)) {

            Resource *res = resources[name];

            Cubemap *derived_cast = dynamic_cast<Cubemap *>(res);

            if (derived_cast == nullptr) {
                throw std::runtime_error("resource is not a cubemap: " + name);

            }

            return *derived_cast;

        } else throw std::runtime_error("resource does not exist: " + name);

    }

    void ResourceManager::delete_resources() {
        for (auto &resource:resources) {
            delete resource.second;
        }

    }

    ResourceManager::~ResourceManager() {
        delete_resources();

    }


}