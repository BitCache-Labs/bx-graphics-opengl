#include "bx/platform/imgui_opengl.hpp"

#include <bx/core/macros.hpp>
#include <backends/imgui_impl_opengl3.h>

bool ImGuiImpl::Initialize_Graphics()
{
#if defined BX_GRAPHICS_OPENGL_BACKEND
    if (!ImGui_ImplOpenGL3_Init("#version 460 core\n"))
#elif defined BX_GRAPHICS_OPENGLES_BACKEND
    if (!ImGui_ImplOpenGL3_Init("#version 300 es\n"))
#endif
    {
        BX_LOGE("Failed to initialize ImGui OpenGL backend!");
        return false;
    }

    return true;
}

void ImGuiImpl::Shutdown_Graphics()
{
    ImGui_ImplOpenGL3_Shutdown();
}

void ImGuiImpl::NewFrame_Graphics()
{
    ImGui_ImplOpenGL3_NewFrame();
}

void ImGuiImpl::EndFrame_Graphics()
{
    GraphicsHandle renderTarget = Graphics::GetCurrentBackBufferRT();
    GraphicsHandle depthStencil = Graphics::GetDepthBuffer();
    Graphics::SetRenderTarget(renderTarget, depthStencil);

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}