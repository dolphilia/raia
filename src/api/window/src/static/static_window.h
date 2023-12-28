//
//  raia_windows.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef static_window_h
#define static_window_h

#include <stdio.h>
#include "../wrapper/wrapper_glfw.h"

void init_raia_window(int width, int height, const char* title);
GLFWwindow* get_raia_window(void);

#endif /* raia_windows_h */
