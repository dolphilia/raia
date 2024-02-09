//
// Created by dolphilia on 2024/02/09.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_CLIP_PATH_H
#define RAIA_SKIA_STATIC_SK_SVG_CLIP_PATH_H

#include <set>
#include <string>
#include <map>
#include "modules/svg/include/SkSVGClipPath.h"

typedef int sk_svg_clip_path_t;

extern "C" {
void static_sk_svg_clip_path_delete(int key);
SkSVGClipPath *static_sk_svg_clip_path_get(int key);
}

int static_sk_svg_clip_path_make(sk_sp<SkSVGClipPath> value);
void static_sk_svg_clip_path_set(int key, sk_sp<SkSVGClipPath> value);
sk_sp<SkSVGClipPath> static_sk_svg_clip_path_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_CLIP_PATH_H
