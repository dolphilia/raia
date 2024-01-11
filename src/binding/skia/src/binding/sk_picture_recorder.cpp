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

SkCanvas * SkPictureRecorder_beginRecording(SkPictureRecorder *picture_recorder, const SkRect &bounds, sk_sp<SkBBoxHierarchy> bbh) {
    return picture_recorder->beginRecording(bounds, std::move(bbh));
}

SkCanvas * SkPictureRecorder_beginRecording_2(SkPictureRecorder *picture_recorder, const SkRect &bounds, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(bounds, bbhFactory);
}

SkCanvas * SkPictureRecorder_beginRecording_3(SkPictureRecorder *picture_recorder, SkScalar width, SkScalar height, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(width, height, bbhFactory);
}

SkCanvas * SkPictureRecorder_getRecordingCanvas(SkPictureRecorder *picture_recorder) {
    return picture_recorder->getRecordingCanvas();
}

void SkPictureRecorder_finishRecordingAsPicture(const char *sk_picture_key_out, SkPictureRecorder *picture_recorder) {
    static_sk_picture_set(sk_picture_key_out, picture_recorder->finishRecordingAsPicture());
}

void SkPictureRecorder_finishRecordingAsPictureWithCull(const char *sk_picture_key_out, SkPictureRecorder *picture_recorder, const SkRect &cullRect) {
    static_sk_picture_set(sk_picture_key_out, picture_recorder->finishRecordingAsPictureWithCull(cullRect));
}

void SkPictureRecorder_finishRecordingAsDrawable(const char *sk_drawable_key_out, SkPictureRecorder *picture_recorder) {
    static_sk_drawable_set(sk_drawable_key_out, picture_recorder->finishRecordingAsDrawable());
}

}