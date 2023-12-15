#include <Viewer/GraphicsSystem.h>

#include <GL/glut.h>
#include <imgui.h>
#include <imgui_internal.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <Viewer/Config.h>

namespace Graphics{
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height){
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, nullptr, 4);
    if (image_data == nullptr)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Same

    // Upload pixels into texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}
    bool LoadTextureFromFile(const char* filename, Graphics::imgObj* img){
        // Load from file
        int image_width = 0;
        int image_height = 0;
        unsigned char* image_data = stbi_load(filename, &image_width, &image_height, nullptr, 4);
        if (image_data == nullptr)
            return false;

        // Create a OpenGL texture identifier
        GLuint image_texture;
        glGenTextures(1, &image_texture);
        glBindTexture(GL_TEXTURE_2D, image_texture);

        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // This is required on WebGL for non power-of-two textures
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Same

        // Upload pixels into texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
        stbi_image_free(image_data);

        img->texture = image_texture;
        img->width = image_width;
        img->height = image_height;

        return true;
    }
    bool AddImage(const GLuint* img, const ImVec2& pos, const ImVec2& attr, bool center = false, float Scale = 1.f){
        ImGuiWindow* window = ImGui::GetCurrentWindow();

        ImVec2 Pos1, Pos2, ScaledAttr;
        ScaledAttr = ImVec2(attr.x * Scale, attr.y * Scale);

        if (center) {
            Pos1.x = pos.x - ScaledAttr.x / 2;
            Pos1.y = pos.y - ScaledAttr.y / 2;

            Pos2.x = pos.x + ScaledAttr.x - ScaledAttr.x / 2;
            Pos2.y = pos.y + ScaledAttr.y - ScaledAttr.y / 2;
        }else{
            Pos1 = pos;
            Pos2.x = (pos.x + ScaledAttr.x);
            Pos2.y = (pos.y + ScaledAttr.y);
        }

        window -> DrawList ->AddImage((void*)img, Pos1, Pos2);
        if (Config::Debug_Border) window -> DrawList ->AddRect(Pos1, Pos2, ImColor(255, 0, 0, 100));
        return TRUE;
    }
}