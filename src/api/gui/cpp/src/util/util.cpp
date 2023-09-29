//
// Created by dolphilia on 2023/08/16.
//

#include "util.h"
//#include "GLFW/glfw3.h" // Will drag system OpenGL headers
//#include "../imgui/imgui_impl_opengl3.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "../stb/stb_image.h"
//
//GLuint load_texture(const char* filename) {
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
//    if (!data) {
//        //std::err << "Failed to load image\n";
//        return 0;
//    }
//    GLuint texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//    glGenerateMipmap(GL_TEXTURE_2D);
//    stbi_image_free(data);
//    return texture;
//}