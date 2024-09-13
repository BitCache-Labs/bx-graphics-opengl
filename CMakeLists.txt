# GLAD lib
add_subdirectory (extern/glad)

## ImGui OpenGL3
#add_library (imgui_opengl3 STATIC "imgui/backends/imgui_impl_opengl3.cpp")
#target_include_directories (imgui_opengl3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

add_library(bx-platform-opengl STATIC 
    "src/bx/platform/graphics_opengl.cpp"
 "src/bx/platform/imgui_opengl.cpp")
target_link_libraries(bx-platform-opengl PRIVATE glad)# imgui_opengl3)
target_include_directories (bx-platform-opengl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)