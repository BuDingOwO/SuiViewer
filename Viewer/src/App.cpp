#include <Viewer/App.h>
#include <Core/Core.h>
#include <imgui.h>
#include <Viewer/Config.h>
#include <imgui_internal.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <Viewer/GraphicsSystem.h>

Graphics::imgObj img_a;

namespace App {
    static int currentFrame = 0;
    const char* frames[] = {"frame_1", "frame_2"};

    void Setup(){
        if (Config::Debug) {
            LoadTextureFromFile("../../../Viewer/res/icon.png", &img_a);
        } else {
            LoadTextureFromFile("res/icon.png", &img_a);
        }
    }

    void ProcessBefore(){

    }

    void ProcessAfter(){

    }

    void frame_1(){
        ImGuiWindow* window = ImGui::GetCurrentWindow();
//        window -> DrawList ->AddLine(ImVec2(32, 32), ImVec2(static_cast<float>(Config::WindowAttr.x - 32), static_cast<float>(Config::WindowAttr.y - 32)), ImColor::HSV(10, 0, 20));
//        window -> DrawList ->AddLine(ImVec2(32, static_cast<float>(Config::WindowAttr.y - 32)), ImVec2(static_cast<float>(Config::WindowAttr.x - 32), 32), ImColor::HSV(10, 0, 20));
        window -> DrawList ->AddRect(ImVec2(32, 32), ImVec2(static_cast<float>(Config::WindowAttr.x - 32), static_cast<float>(Config::WindowAttr.y - 32)), ImColor::HSV(10, 0, 20));
    }

    void frame_2(){
        ImGuiWindow* window = ImGui::GetCurrentWindow();

        Graphics::AddImage(&img_a.texture, ImVec2(128, 128), ImVec2((float)img_a.width, (float)img_a.height), DebugConfig::TmpPicCenter, DebugConfig::TmpPicScale);

        window -> DrawList ->AddLine(ImVec2(128 - 64, 128), ImVec2(128 + 64, 128), ImColor(255, 256, 256, 100));
        window -> DrawList ->AddLine(ImVec2(128, 128 - 64), ImVec2(128, 128 + 64), ImColor(255, 256, 256, 100));

        window -> DrawList ->AddRect(ImVec2(32, 32), ImVec2(static_cast<float>(Config::WindowAttr.x - 32), static_cast<float>(Config::WindowAttr.y - 32)), ImColor::HSV(10, 0, 20));
    }

    void SetupBaseWindow(){
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowBorderSize = 0;
        ImGuiWindowFlags flags = 0;
        flags |= ImGuiWindowFlags_NoTitleBar;
        flags |= ImGuiWindowFlags_NoCollapse;
        flags |= ImGuiWindowFlags_NoMove;
        flags |= ImGuiWindowFlags_NoResize;
        flags |= ImGuiWindowFlags_NoScrollbar;
        flags |= ImGuiWindowFlags_NoBackground;
        flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;


        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowPos(viewport->Pos);
        bool p_open = true;

        ImGui::Begin("App", &p_open, flags);

        switch (currentFrame) {
            case 0:
                frame_1();
                break;
            case 1:
                frame_2();
                break;
            default:
                frame_1();
        }

        ImGui::End();
    }

    void ConfigBox(){
        {
            ImGuiStyle& style = ImGui::GetStyle();
            style.WindowBorderSize = 0;
            ImGuiWindowFlags flags = 0;
            flags |= ImGuiWindowFlags_NoMove;
            flags |= ImGuiWindowFlags_NoResize;


            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowSize(ImVec2(256, viewport->Size.y));
            ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x + viewport->Size.x - 256, viewport->Pos.y));
            ImGuiIO& io = ImGui::GetIO(); (void)io;

            static int counter = 0;

            ImGui::Begin("Debug", nullptr, flags);

            ImGui::Checkbox("Demo", &Config::ShowDemoWindow);ImGui::SameLine();
//            ImGui::Checkbox("Debug", &Config::Debug);
            ImGui::Checkbox("Debug_Border", &Config::Debug_Border);


            ImGui::Text("frameList");
            if (ImGui::BeginListBox("frame_list", ImVec2(-FLT_MIN, 5 * ImGui::GetTextLineHeightWithSpacing())))
            {
                for (int n = 0; n < IM_ARRAYSIZE(frames); n++)
                {
                    const bool is_selected = (currentFrame == n);
                    if (ImGui::Selectable(frames[n], is_selected))
                        currentFrame = n;

                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndListBox();
            }

            ImGui::SliderFloat("Scale", &DebugConfig::TmpPicScale, 0.0f, 5.0f);ImGui::SameLine();
            ImGui::Checkbox("Center", &DebugConfig::TmpPicCenter);
            ImGui::ColorEdit3("clear color", (float*)&Config::ClearColor); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }
    }
}



