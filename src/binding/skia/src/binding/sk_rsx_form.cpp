//
// Created by dolphilia on 2024/01/10.
//

#include "sk_rsx_form.h"

extern "C" {

void SkRSXform_delete(SkRSXform *rsx_form) {
    delete rsx_form;
}

bool SkRSXform_rectStaysRect(SkRSXform *rsx_form) {
    return rsx_form->rectStaysRect();
}

void SkRSXform_setIdentity(SkRSXform *rsx_form) {
    rsx_form->setIdentity();
}

void SkRSXform_set(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) {
    rsx_form->set(scos, ssin, tx, ty);
}

void SkRSXform_toQuad(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4]) {
    rsx_form->toQuad(width, height, quad);
}

void SkRSXform_toQuad_2(SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4]) {
    rsx_form->toQuad(*size, quad);
}

void SkRSXform_toTriStrip(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4]) {
    rsx_form->toTriStrip(width, height, strip);
}

// static

sk_rsx_form_t SkRSXform_Make(SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) {
    return static_sk_rsx_form_make(SkRSXform::Make(scos, ssin, tx, ty));
}

sk_rsx_form_t SkRSXform_MakeFromRadians(SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) {
    return static_sk_rsx_form_make(SkRSXform::MakeFromRadians(scale, radians, tx, ty, ax, ay));
}

}