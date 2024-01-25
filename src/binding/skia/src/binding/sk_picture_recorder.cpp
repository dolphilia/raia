//
// Created by dolphilia on 2024/01/10.
//

#include "sk_picture_recorder.h"

extern "C" {

SkPictureRecorder *SkPictureRecorder_new() {
    return new SkPictureRecorder();
}

void SkPictureRecorder_delete(SkPictureRecorder *picture_recorder) {
    delete picture_recorder;
}

SkCanvas *SkPictureRecorder_beginRecording(int sk_b_box_hierarchy_key_in, SkPictureRecorder *picture_recorder,
                                           const SkRect *bounds) {
    return picture_recorder->beginRecording(*bounds, static_sk_b_box_hierarchy_move(sk_b_box_hierarchy_key_in));
}

SkCanvas * SkPictureRecorder_beginRecording_2(SkPictureRecorder *picture_recorder, const SkRect *bounds, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(*bounds, bbhFactory);
}

SkCanvas * SkPictureRecorder_beginRecording_3(SkPictureRecorder *picture_recorder, SkScalar width, SkScalar height, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(width, height, bbhFactory);
}

SkCanvas * SkPictureRecorder_getRecordingCanvas(SkPictureRecorder *picture_recorder) {
    return picture_recorder->getRecordingCanvas();
}

int SkPictureRecorder_finishRecordingAsPicture(SkPictureRecorder *picture_recorder) {
    return static_sk_picture_make(picture_recorder->finishRecordingAsPicture());
}

int SkPictureRecorder_finishRecordingAsPictureWithCull(SkPictureRecorder *picture_recorder, const SkRect *cullRect) {
    return static_sk_picture_make(picture_recorder->finishRecordingAsPictureWithCull(*cullRect));
}

int SkPictureRecorder_finishRecordingAsDrawable(SkPictureRecorder *picture_recorder) {
    return static_sk_drawable_make(picture_recorder->finishRecordingAsDrawable());
}

}