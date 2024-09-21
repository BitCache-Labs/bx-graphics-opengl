# GLAD lib
add_subdirectory (extern/glad)

add_library(bx-platform-opengl STATIC 
	"src/bx/platform/graphics_opengl.cpp"
	"src/bx/platform/imgui_opengl.cpp")
target_link_libraries(bx-platform-opengl PRIVATE glad)# imgui_opengl3)
target_include_directories (bx-platform-opengl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)