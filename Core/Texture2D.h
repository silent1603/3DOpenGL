#pragma once
namespace Core
{
    class CORE_API Texture2D
    {
        public:
        // holds the ID of the texture object, used for all texture operations to reference to this particlar texture
        uint32_t ID;
        // texture image dimensions
        uint32_t Width, Height; // width and height of loaded image in pixels
        // texture Format
        uint32_t Internal_Format; // format of texture object
        uint32_t Image_Format;    // format of loaded image
        // texture configuration
        uint32_t Wrap_S;     // wrapping mode on S axis
        uint32_t Wrap_T;     // wrapping mode on T axis
        uint32_t Filter_Min; // filtering mode if texture pixels < screen pixels
        uint32_t Filter_Max; // filtering mode if texture pixels > screen pixels
        // constructor (sets default texture modes)
        Texture2D();
        // generates texture from image data
        void Generate(uint32_t width, uint32_t height, unsigned char *data);
        // binds the texture as the current active GL_TEXTURE_2D texture object
        void Bind() const;
    };
}