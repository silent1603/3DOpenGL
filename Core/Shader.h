#pragma once
#include <glad/glad.h>
#include <EASTL/string.h>
#include <EASTL/shared_ptr.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core
{
    enum class ShaderType : int{
        VERTEX = 0,
        FRAGMENT = 1,
        GEOMETRY = 2,
        PROGRAM = 3
    };

    class CORE_API Shader : public eastl::enable_shared_from_this<Shader>
    {
    public:
        uint32_t ID = 0;
        Shader()  =default;
        //explicit Shader(Shader& s) noexcept;
        //explicit Shader(const Shader& s) noexcept;
        //explicit Shader(Shader&& s) noexcept;
        //explicit Shader(const Shader&& s) noexcept;
        ~Shader();

        eastl::shared_ptr<Shader> Bind();
        void Compile(const char *vertexSource, const char *fragmnetSource, const char *geometrySource = nullptr);

        void SetFloat(const char *name, float value, bool userShader = false);
        void SetInteger(const char *name, int value, bool userShader = false);
        void SetVector2f(const char *name, float x, float y, bool userShader = false);
        void SetVector2f(const char *name, const glm::vec2 &value, bool useShader = false);
        void SetVector3f(const char *name, float x, float y, float z, bool useShader = false);
        void SetVector3f(const char *name, const glm::vec3 &value, bool useShader = false);
        void SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);
        void SetVector4f(const char *name, const glm::vec4 &value, bool userShader = false);
        void SetMatrix4(const char *name, const glm::mat4 &matrix, bool useShader = false);

    private:
        void checkCompileErrors(uint32_t ID, ShaderType type);
    };
}