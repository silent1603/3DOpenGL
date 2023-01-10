#pragma once
#include "pch.h"
#include <glad/glad.h>
#include "Texture2D.h"
#include "Shader.h"

namespace Core
{
    class CORE_API ResourceManager
    {
    public:
        // resource storage
    //    static eastl::map<eastl::string, Shader> Shaders;
    //    static eastl::map<eastl::string, Texture2D> Textures;
    //    // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    //    static Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, eastl::string name);
    //    // retrieves a stored sader
    //    static Shader GetShader(eastl::string name);
    //    // loads (and generates) a texture from file
    //    static Texture2D LoadTexture(const char *file, bool alpha, eastl::string name);
    //    // retrieves a stored texture
    //    static Texture2D GetTexture(eastl::string name);
    //    // properly de-allocates all loaded resources
    //    static void Clear();

    //private:
    //    // private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    //    ResourceManager() {}
    //    // loads and generates a shader from file
    //    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    //    // loads a single texture from file
    //    static Texture2D loadTextureFromFile(const char *file, bool alpha);
    };

}