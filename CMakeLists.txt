cmake_minimum_required(VERSION 3.14)
project(3DGL)

set(CMAKE_CXX_STANDARD 14)

add_library(3DGL src/3DGL/glad.c src/3DGL/Window/Window.cpp src/3DGL/Window/Window.h src/3DGL/Shader/Shader.cpp src/3DGL/Shader/Shader.h src/3DGL/Shader/VertexShader/VertexShader.cpp src/3DGL/Shader/VertexShader/VertexShader.h src/3DGL/Shader/FragmentShader/FragmentShader.cpp src/3DGL/Shader/FragmentShader/FragmentShader.h src/3DGL/Shader/ShaderProgram/ShaderProgram.cpp src/3DGL/Shader/ShaderProgram/ShaderProgram.h src/3DGL/Vertex/Vertex.h src/3DGL/Mesh/MeshBuffer.h src/3DGL/Mesh/Mesh.cpp src/3DGL/Mesh/Mesh.h src/3DGL/Transformable/Transformable.cpp src/3DGL/Transformable/Transformable.h src/3DGL/Drawable/Drawable3D.cpp src/3DGL/Drawable/Drawable3D.h src/3DGL/Texture/Texture.cpp src/3DGL/Texture/Texture.h src/3DGL/Texture/stb_image.h src/3DGL/Texture/stb_image.cpp src/3DGL/Texture/Texture2D/Texture2D.cpp src/3DGL/Texture/Texture2D/Texture2D.h src/3DGL/RenderList/RenderList.cpp src/3DGL/RenderList/RenderList.h src/3DGL/Mesh/MeshBuilder/MeshBuilder.cpp src/3DGL/Mesh/MeshBuilder/MeshBuilder.h)
