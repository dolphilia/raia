//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PICTURE_RECORDER_H
#define RAIA_SKIA_SK_PICTURE_RECORDER_H

#include "include/core/SkPictureRecorder.h"
#include "include/core/SkBBHFactory.h"
#include "../static/static_sk_picture.h"
#include "../static/static_sk_drawable.h"
#include "../static/static_sk_b_box_hierarchy.h"

extern "C" {
SkPictureRecorder *SkPictureRecorder_new();
void SkPictureRecorder_delete(SkPictureRecorder *picture_recorder);
SkCanvas *SkPictureRecorder_beginRecording(SkPictureRecorder *picture_recorder, const SkRect *bounds, sk_b_box_hierarchy_t b_box_hierarchy);
SkCanvas * SkPictureRecorder_beginRecording_2(SkPictureRecorder *picture_recorder, const SkRect *bounds, SkBBHFactory *bbhFactory);
SkCanvas * SkPictureRecorder_beginRecording_3(SkPictureRecorder *picture_recorder, SkScalar width, SkScalar height, SkBBHFactory *bbhFactory);
SkCanvas * SkPictureRecorder_getRecordingCanvas(SkPictureRecorder *picture_recorder);
sk_picture_t SkPictureRecorder_finishRecordingAsPicture(SkPictureRecorder *picture_recorder);
sk_picture_t SkPictureRecorder_finishRecordingAsPictureWithCull(SkPictureRecorder *picture_recorder, const SkRect *cullRect);
sk_picture_t SkPictureRecorder_finishRecordingAsDrawable(SkPictureRecorder *picture_recorder);
}

#endif //RAIA_SKIA_SK_PICTURE_RECORDER_H
