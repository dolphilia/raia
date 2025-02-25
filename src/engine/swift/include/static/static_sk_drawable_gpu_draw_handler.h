//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_drawable_gpu_draw_handler_t;
void static_sk_drawable_gpu_draw_handler_delete(int key);
void *static_sk_drawable_gpu_draw_handler_get_ptr(int key); // -> SkDrawable::GpuDrawHandler *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
