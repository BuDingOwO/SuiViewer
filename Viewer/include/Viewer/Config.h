#ifndef SUIVIEWER_CONFIG_H
#define SUIVIEWER_CONFIG_H

#include <imgui.h>
#include <string>
#include <GLFW/glfw3.h>

struct iVec2{
    int x, y;
};

namespace Config{
    extern std::string WindowTitle;
    extern bool Debug;
    extern bool Debug_Border;

    extern bool ShowDemoWindow;
    extern ImVec4 ClearColor;
    extern iVec2 WindowAttr;
    extern iVec2 ScreenAttr;
}

namespace DebugConfig {
    extern float TmpPicScale;
    extern bool TmpPicCenter;

}

#endif //SUIVIEWER_CONFIG_H
