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
                                                            "uniform mat4 mvp;\n"
                                                            "out vec2 TexCoord;\n"
                                                            "out vec3 Normal;\n"
                                                            "\n"
                                                            "void main()\n"
                                                            "{\n"
                                                            "    TexCoord=tex_coord;\n"
                                                            "    Normal=aNormal;\n"
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
                                                             "    gl_Position = pv * vec4(aPos, 1.0);\n"
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


    const VertexShader DefaultShaders::basic_vertex_shader(basic_vertex_source);
    const FragmentShader DefaultShaders::basic_fragment_shader(basic_fragment_source);

    const VertexShader DefaultShaders::skybox_vertex_shader(skybox_vertex_source);
    const FragmentShader DefaultShaders::skybox_fragment_shader(skybox_fragment_source);


    const ShaderProgram DefaultShaders::default_program(basic_vertex_shader, basic_fragment_shader);
    const ShaderProgram DefaultShaders::skybox_program(skybox_vertex_shader, skybox_fragment_shader);

    const ShaderProgram &DefaultShaders::get_default_program() {
        return default_program;

    }

    const ShaderProgram &DefaultShaders::get_skybox_program() {
        return skybox_program;
    }


}