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

SkCanvas *SkPictureRecorder_beginRecording(SkPictureRecorder *picture_recorder, const SkRect *bounds, sk_b_box_hierarchy_t b_box_hierarchy) {
    return picture_recorder->beginRecording(*bounds, static_sk_b_box_hierarchy_move(b_box_hierarchy));
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

sk_picture_t SkPictureRecorder_finishRecordingAsPicture(SkPictureRecorder *picture_recorder) {
    return static_sk_picture_make(picture_recorder->finishRecordingAsPicture());
}

sk_picture_t SkPictureRecorder_finishRecordingAsPictureWithCull(SkPictureRecorder *picture_recorder, const SkRect *cullRect) {
    return static_sk_picture_make(picture_recorder->finishRecordingAsPictureWithCull(*cullRect));
}

sk_drawable_t SkPictureRecorder_finishRecordingAsDrawable(SkPictureRecorder *picture_recorder) {
    return static_sk_drawable_make(picture_recorder->finishRecordingAsDrawable());
}

}