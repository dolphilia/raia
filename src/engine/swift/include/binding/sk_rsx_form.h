//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RSX_FORM_H
#define RAIA_SKIA_SK_RSX_FORM_H

#include "include/core/SkRSXform.h"
#include "../static/static_sk_rsx_form.h"

extern "C" {
void SkRSXform_delete(SkRSXform *rsx_form);
bool SkRSXform_rectStaysRect(SkRSXform *rsx_form);
void SkRSXform_setIdentity(SkRSXform *rsx_form);
void SkRSXform_set(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
void SkRSXform_toQuad(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4]);
void SkRSXform_toQuad_2(SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4]);
void SkRSXform_toTriStrip(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4]);
// static
sk_rsx_form_t SkRSXform_Make(SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
sk_rsx_form_t SkRSXform_MakeFromRadians(SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay);
}

#endif //RAIA_SKIA_SK_RSX_FORM_H
