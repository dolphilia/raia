//
//  raia_glfw.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "raia/raia_gl.h"

/// GLFWの開始
void glfw_start(void) {
    glfw_init();
    raia_header_t header = get_raia_header();
    init_raia_window(header.window_width, header.window_height, header.window_title);
    GLFWwindow* glfw_window = get_raia_window();
    glfwMakeContextCurrent(glfw_window);
    glfwSwapInterval(1);
    
    // HiDPI判定
    int now_width, now_height;
    glfwGetFramebufferSize(glfw_window, &now_width, &now_height);
    if (now_width > header.window_width) {
        set_resolution_size(header.window_width * 2, header.window_height * 2);
    } else {
        set_resolution_size(header.window_width, header.window_height);
    }
}

/// 再描画する
void glfw_redraw(void) {
    raia_header_t header = get_raia_header();
    raia_shader_t shader = get_raia_shader();
    GLFWwindow* glfw_window = get_raia_window();
    uint8_t* pixel_data = get_pixel_data();

    // 描画の準備
    glViewport(0, 0, header.resolution_width, header.resolution_height); // Set the viewport
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glUseProgram(shader.program); // Use the program object
    glVertexAttribPointer(shader.pos_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), shader.vertices); // Load the vertex position
    glVertexAttribPointer(shader.tex_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), shader.vertices + 3); // Load the texture coordinate
    glEnableVertexAttribArray(shader.pos_location);
    glEnableVertexAttribArray(shader.tex_location);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, header.window_width, header.window_height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);
    glActiveTexture(GL_TEXTURE0); // Bind the texture
    glBindTexture(GL_TEXTURE_2D, shader.texture);
    glUniform1i(shader.sampler_location, 0); // Set the texture sampler to texture unit to 0
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, shader.indices);
    
    glfwSwapBuffers(glfw_window);
}
