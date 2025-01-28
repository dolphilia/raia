//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PICTURE_RECORDER_H
#define RAIA_SKIA_SK_PICTURE_RECORDER_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkPictureRecorder_new(); // () -> SkPictureRecorder *
void SkPictureRecorder_delete(void *picture_recorder); // (SkPictureRecorder *picture_recorder)
void *SkPictureRecorder_beginRecording(void *picture_recorder, const void *bounds, int b_box_hierarchy); // (SkPictureRecorder *picture_recorder, const SkRect *bounds, sk_b_box_hierarchy_t b_box_hierarchy) -> SkCanvas *
void *SkPictureRecorder_beginRecording_2(void *picture_recorder, const void *bounds, void *bbhFactory); // (SkPictureRecorder *picture_recorder, const SkRect *bounds, SkBBHFactory *bbhFactory) -> SkCanvas *
void *SkPictureRecorder_beginRecording_3(void *picture_recorder, float width, float height, void *bbhFactory); // (SkPictureRecorder *picture_recorder, SkScalar width, SkScalar height, SkBBHFactory *bbhFactory) -> SkCanvas *
void *SkPictureRecorder_getRecordingCanvas(void *picture_recorder); // (SkPictureRecorder *picture_recorder) -> SkCanvas *
int SkPictureRecorder_finishRecordingAsPicture(void *picture_recorder); // (SkPictureRecorder *picture_recorder) -> sk_picture_t
int SkPictureRecorder_finishRecordingAsPictureWithCull(void *picture_recorder, const void *cullRect); // (SkPictureRecorder *picture_recorder, const SkRect *cullRect) -> sk_picture_t
int SkPictureRecorder_finishRecordingAsDrawable(void *picture_recorder); // (SkPictureRecorder *picture_recorder) -> sk_picture_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PICTURE_RECORDER_H
