//
// Created by gvisan on 18.08.2019.
//

#include "DefaultShaders.h"

namespace gl3d {

    const std::string DefaultShaders::basic_vertex_source = "#version 330 core\n"
                                                            "layout (location = 0) in vec3 aPos;\n"
                                                            "layout (location = 1) in vec2 tex_coord;\n"
                                                            "layout (location = 2) in vec3 aNormal;\n"
                                                            "\n"
                                                            "uniform mat4 model;\n"
                                                            "uniform mat4 view;\n"
                                                            "uniform mat4 projection;\n"
                                                            "out vec2 TexCoord;\n"
                                                            "out vec3 Normal;\n"
                                                            "\n"
                                                            "void main()\n"
                                                            "{\n"
                                                            "    TexCoord=tex_coord;\n"
                                                            "    Normal=mat3(transpose(inverse(model))) * aNormal;\n"
                                                            "    mat4 mvp=projection*view*model;\n"
                                                            "    gl_Position = mvp*vec4(aPos, 1.0);\n"
                                                            "}";


    const std::string DefaultShaders::basic_fragment_source = "#version 330 core\n"
                                                              "out vec4 FragColor;\n"
                                                              "\n"
                                                              "in vec2 TexCoord;\n"
                                                              "\n"
                                                              "uniform sampler2D ourTexture;\n"
                                                              "in vec3 Normal;\n"
                                                              "\n"
                                                              "void main()\n"
                                                              "{\n"
                                                              "    vec3 norm = normalize(Normal);\n"
                                                              "    vec3 lightDir=vec3(0,1,0);\n"
                                                              "    float diff = max(dot(norm, lightDir), 0.4);\n"
                                                              "\n"
                                                              "\n"
                                                              "    FragColor = texture(ourTexture, TexCoord)*diff;\n"
                                                              "}";


    const std::string DefaultShaders::skybox_vertex_source = "#version 330 core\n"
                                                             "layout (location = 0) in vec3 aPos;\n"
                                                             "\n"
                                                             "out vec3 TexCoords;\n"
                                                             "\n"
                                                             "uniform mat4 pv;\n"
                                                             "\n"
                                                             "void main()\n"
                                                             "{\n"
                                                             "    TexCoords = aPos;\n"
                                                             "    vec4 pos=pv * vec4(aPos, 1.0);"
                                                             "    gl_Position =pos.xyww;\n"
                                                             "}";


    const std::string DefaultShaders::skybox_fragment_source = "#version 330 core\n"
                                                               "out vec4 FragColor;\n"
                                                               "\n"
                                                               "in vec3 TexCoords;\n"
                                                               "\n"
                                                               "uniform samplerCube skybox;\n"
                                                               "\n"
                                                               "void main()\n"
                                                               "{    \n"
                                                               "    FragColor = texture(skybox, TexCoords);\n"
                                                               "}";


    const std::string DefaultShaders::framebuffer_vertex_source = "#version 330 core\n"
                                                                  "layout (location = 0) in vec2 aPos;\n"
                                                                  "layout (location = 1) in vec2 aTexCoords;\n"
                                                                  "\n"
                                                                  "out vec2 TexCoords;\n"
                                                                  "\n"
                                                                  "void main()\n"
                                                                  "{\n"
                                                                  "    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); \n"
                                                                  "    TexCoords = aTexCoords;\n"
                                                                  "} ";


    const std::string DefaultShaders::framebuffer_fragment_source = "#version 330 core\n"
                                                                    "out vec4 FragColor;\n"
                                                                    "  \n"
                                                                    "in vec2 TexCoords;\n"
                                                                    "\n"
                                                                    "uniform sampler2D screenTexture;\n"
                                                                    "\n"
                                                                    "void main()\n"
                                                                    "{ \n"
                                                                    "    FragColor = texture(screenTexture, TexCoords);\n"
                                                                    "}";


    const std::string DefaultShaders::gizmos_vertex_source = "#version 330 core\n"
                                                             "layout (location = 0) in vec3 aPos;\n"
                                                             "uniform mat4 mvp;\n"
                                                             "uniform vec3 gizmoColor;\n"
                                                             "out vec3 color;\n"

                                                             "void main()\n"
                                                             "{\n"
                                                             "color=gizmoColor;\n"
                                                             "gl_Position = mvp*vec4(aPos, 1.0);\n"
                                                             "};";

    const std::string DefaultShaders::gizmos_fragment_source = "#version 330 core\n"
                                                               "out vec4 FragColor;\n"
                                                               "  \n"
                                                               "in vec3 color;\n"
                                                               "void main()\n"
                                                               "{ \n"
                                                               "    FragColor = vec4(color,1);\n"
                                                               "}";

    const std::string DefaultShaders::skinned_mesh_vertex_source = "#version 330 core\n"
                                                                   "layout (location = 0) in vec3 aPos;\n"
                                                                   "layout (location = 1) in vec2 tex_coord;\n"
                                                                   "layout (location = 2) in vec3 aNormal;\n"
                                                                   "layout (location = 3) in ivec4 BoneIDs;\n"
                                                                   "layout (location = 4) in vec4 Weights;\n"
                                                                   "uniform mat4 model;\n"
                                                                   "uniform mat4 view;\n"
                                                                   "uniform mat4 projection;\n"
                                                                   "out vec2 TexCoord;\n"
                                                                   "out vec3 Normal;\n"
                                                                   "\n"
                                                                   "const int MAX_BONES=100;\n"
                                                                   "uniform mat4 gBones[MAX_BONES];\n"
                                                                   "\n"
                                                                   "void main()\n"
                                                                   "{\n"
                                                                   " mat4 BoneTransform = gBones[BoneIDs[0]] * (Weights[0]);\n"
                                                                   "    BoneTransform += gBones[BoneIDs[1]] *  (Weights[1]);\n"
                                                                   "    BoneTransform += gBones[BoneIDs[2]] *  (Weights[2]);\n"
                                                                   "    BoneTransform += gBones[BoneIDs[3]] *  (Weights[3]);\n"
                                                                   "\n"
                                                                   "vec4 PosL=BoneTransform*vec4(aPos,1.0);\n"
                                                                   "vec4 NormalL=BoneTransform*vec4(aNormal,0);\n"
                                                                   "\n"
                                                                   "TexCoord=tex_coord;\n"
                                                                   "Normal=mat3(transpose(inverse(model))) * NormalL.xyz;\n"
                                                                   "mat4 mvp=projection*view*model;\n"
                                                                   "gl_Position = mvp*PosL;\n"
                                                                   "\n"
                                                                   "\n"
                                                                   "\n"
                                                                   "};";


    const ShaderProgram *DefaultShaders::default_program;
    const ShaderProgram *DefaultShaders::skybox_program;
    const ShaderProgram *DefaultShaders::framebuffer_program;
    const ShaderProgram *DefaultShaders::gizmos_program;
    const ShaderProgram *DefaultShaders::skinned_program;

    const ShaderProgram &DefaultShaders::get_default_program() {
        return *default_program;

    }

    const ShaderProgram &DefaultShaders::get_skybox_program() {
        return *skybox_program;
    }


    const ShaderProgram &DefaultShaders::get_framebuffer_program() {
        return *framebuffer_program;
    }

    const ShaderProgram &DefaultShaders::get_gizmo_program() {
        return *gizmos_program;
    }

    const ShaderProgram &DefaultShaders::get_skinned_program() {
        return *skinned_program;
    }

    void DefaultShaders::init_shaders() {
        VertexShader basic_vertex_shader(basic_vertex_source);
        FragmentShader basic_fragment_shader(basic_fragment_source);

        VertexShader skybox_vertex_shader(skybox_vertex_source);
        FragmentShader skybox_fragment_shader(skybox_fragment_source);


        VertexShader framebuffer_vertex_shader(framebuffer_vertex_source);
        FragmentShader framebuffer_fragment_shader(framebuffer_fragment_source);

        VertexShader gizmos_vertex_shader(gizmos_vertex_source);
        FragmentShader gizmos_fragment_shader(gizmos_fragment_source);

        VertexShader skinned_vertex_shader(skinned_mesh_vertex_source);

        default_program = new ShaderProgram(basic_vertex_shader, basic_fragment_shader);
        skybox_program = new ShaderProgram(skybox_vertex_shader, skybox_fragment_shader);
        framebuffer_program = new ShaderProgram(framebuffer_vertex_shader, framebuffer_fragment_shader);
        gizmos_program = new ShaderProgram(gizmos_vertex_shader, gizmos_fragment_shader);
        skinned_program = new ShaderProgram(skinned_vertex_shader, basic_fragment_shader);
    }

    void DefaultShaders::delete_shaders() {
        delete default_program;
        delete skybox_program;
        delete framebuffer_program;
    }


}