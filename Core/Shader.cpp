#include "Shader.h"

namespace Core
{
    void Shader::Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource )
    {
        uint32_t sVertex, sFragment, sGeometry;

        sVertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(sVertex, 1, &vertexSource, NULL);
        glCompileShader(sVertex);
        checkCompileErrors(sVertex, ShaderType::VERTEX);

        sFragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(sFragment, 1, &fragmentSource, NULL);
        glCompileShader(sFragment);
        checkCompileErrors(sFragment, ShaderType::FRAGMENT);

        if (geometrySource != nullptr)
        {
            sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(sGeometry, 1, &geometrySource, NULL);
            glCompileShader(sGeometry);
            checkCompileErrors(sGeometry, ShaderType::GEOMETRY);
        }

        ID = glCreateProgram();
        glAttachShader(ID, sVertex);
        glAttachShader(ID, sFragment);
        if (geometrySource != nullptr)
        {
            glAttachShader(ID, sGeometry);
        }

        glLinkProgram(ID);
        checkCompileErrors(ID, ShaderType::PROGRAM);
        glDeleteShader(sVertex);
        glDeleteShader(sFragment);
        if (geometrySource != nullptr)
        {
            glDeleteShader(sGeometry);
        }
    }

    eastl::shared_ptr<Shader> Shader::Bind()
    {
        glUseProgram(ID);
        return shared_from_this();
    }

    void Shader::SetFloat(const char *name, float value, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform1f(glGetUniformLocation(ID, name), value);
    }

    void Shader::SetInteger(const char *name, int value, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }

        glUniform1i(glGetUniformLocation(ID, name), value);
    }
    void Shader::SetVector2f(const char *name, float x, float y, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform2f(glGetUniformLocation(this->ID, name), x, y);
    }
    void Shader::SetVector2f(const char *name, const glm::vec2 &value, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
    }
    void Shader::SetVector3f(const char *name, float x, float y, float z, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
    }
    void Shader::SetVector3f(const char *name, const glm::vec3 &value, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
    }
    void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
    }
    void Shader::SetVector4f(const char *name, const glm::vec4 &value, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
    }
    void Shader::SetMatrix4(const char *name, const glm::mat4 &matrix, bool useShader)
    {
        if (useShader)
        {
            glUseProgram(ID);
        }
        glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, false, glm::value_ptr(matrix));
    }

    void Shader::checkCompileErrors(uint32_t ID,ShaderType type)
    {
        int success;
        char infoLog[1024];
        switch (type)
        {
        case ShaderType::PROGRAM:
            glGetShaderiv(ID,GL_COMPILE_STATUS,&success);
            if(!success)
            {
                glGetShaderInfoLog(ID,1024,nullptr,infoLog);
                //Log

            }
            break;
        case ShaderType::VERTEX:
        case ShaderType::FRAGMENT:
        case ShaderType::GEOMETRY:
            glGetProgramiv(ID,GL_LINK_STATUS,&success);
            if(!success)
            {
                glGetProgramInfoLog(ID,1024,nullptr,infoLog);
                //Log
            }
        default:
            break;
        }
    }

    Shader::~Shader()
    {

    }
}