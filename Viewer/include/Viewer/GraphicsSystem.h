#ifndef SUIVIEWER_GRAPHICSSYSTEM_H
#define SUIVIEWER_GRAPHICSSYSTEM_H
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Graphics{
    struct imgObj {
        int width;
        int height;
        GLuint texture;
    };
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
    bool LoadTextureFromFile(const char* filename, Graphics::imgObj* img);
    bool AddImage(const GLuint* img, const ImVec2& pos, const ImVec2& attr, bool center, float Scale);
}

#endif //SUIVIEWER_GRAPHICSSYSTEM_H
