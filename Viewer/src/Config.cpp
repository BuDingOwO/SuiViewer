#include <string>
#include <vector>
#include <functional>

#include "Viewer/Config.h"

namespace Config {
    std::string WindowTitle = "Viewer";
    bool Debug = true;
    bool Debug_Border = true;

    bool ShowDemoWindow = false;
//    ImVec4 ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//    ImVec4 ClearColor = ImVec4(1, 1, 1, 1);
    ImVec4 ClearColor = ImVec4(0.90, 0.75, 0.75, 1);

    iVec2 WindowAttr = {1280, 720};

}

namespace DebugConfig {
    float TmpPicScale = 1.f;
    bool TmpPicCenter = false;
}