//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_SKIA_H
#define RAIA_GUI_RAIA_SKIA_H

#include "static/static_sk_rect.h"
#include "static/static_sk_i_rect.h"
#include "static/static_sk_image_info.h"
#include "static/static_sk_data.h"
#include "static/static_sk_stream.h"
#include "static/static_sk_image.h"
#include "static/static_sk_shader.h"
#include "static/static_sk_blender.h"
#include "static/static_sk_color_filter.h"
#include "static/static_sk_color_space.h"
#include "static/static_sk_color_table.h"
#include "static/static_sk_image_filter.h"
#include "static/static_sk_picture.h"
#include "static/static_sk_pixel_ref.h"
#include "static/static_sk_text_blob.h"
#include "static/static_sk_typeface.h"
#include "static/static_sk_vertices.h"
#include "static/static_sk_capabilities.h"
#include "static/static_sk_contour_measure.h"
#include "static/static_sk_data_table.h"
#include "static/static_sk_drawable.h"
#include "static/static_sk_flattenable.h"
#include "static/static_sk_font_mgr.h"
#include "static/static_sk_font_style_set.h"
#include "static/static_sk_mask_filter.h"
#include "static/static_sk_path_effect.h"
#include "static/static_sk_surface.h"
#include "static/static_sk_canvas.h"
#include "static/static_sk_drawable_gpu_draw_handler.h"
#include "static/static_sk_executor.h"
#include "static/static_sk_file_stream.h"
#include "static/static_sk_memory_stream.h"
#include "static/static_sk_stream_asset.h"

extern "C" {
#include <time.h>
#include "../../../common/c/utility/export_api.h"
#include "../../../common/c/utility/platform.h"
#include "../../../common/c/wrapper/wrapper_yyjson.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../third_party/c/nothings/stb/stb_image.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#include "EGL/egl.h"
#include "GLES3/gl32.h"

#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif
}

#endif //RAIA_GUI_RAIA_SKIA_H
