//
//  raia_glfw.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "raia/raia_gl.h"

/// GLFWのテスト
void glfw_start(void) {
    glfw_init();
    raia_header_t header = get_raia_header();
    init_raia_window(header.window_width, header.window_height, header.window_title);
    GLFWwindow* glfw_window = get_raia_window();
    glfwMakeContextCurrent(glfw_window);
}

/// 再描画する
void glfw_redraw(void) {
    raia_header_t header = get_raia_header();
    int mag = header.magnification; // mag = magnification = 倍率

    GLFWwindow* glfw_window = get_raia_window();

#ifdef __MACOS__
    int now_width, now_height;
    glfwGetFramebufferSize(glfw_window, &now_width, &now_height);
    if (now_width > header.window_width) {
        mag = header.magnification * 2;
    }
#endif

    // ピクセルを描画
    int mag_width = mag * header.resolution_width;
    int mag_height = mag * header.resolution_height;;
    uint8_t* mag_pixel_data = calloc(mag_width * mag_height * header.samples_per_pixel * 4, sizeof(uint8_t));
    
    uint8_t* pixel_data = get_pixel_data();
    
    int i = 0;
    for (int y = 0; y < mag_height; y += mag) {
        for (int x = 0; x < mag_width * header.samples_per_pixel; x += mag * header.samples_per_pixel) {
            for (int m = 0; m < mag; m++) {
                for (int n = 0; n < mag; n++) {
                    for (int p = 0; p < header.samples_per_pixel; p++) {
                        mag_pixel_data[x + (y + m) * mag_width * header.samples_per_pixel + n * header.samples_per_pixel + p] = pixel_data[i + p];
                    }
                }
            }
            i += header.samples_per_pixel;
        }
    }

    // 描画の準備
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(-1, -1);
    glDrawPixels(mag_width, mag_height, GL_RGB, GL_UNSIGNED_BYTE, mag_pixel_data);
    free(mag_pixel_data);
    glfwSwapBuffers(glfw_window);
}
