//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RSX_FORM_H
#define RAIA_SKIA_SK_RSX_FORM_H

#include "include/core/SkRSXform.h"

extern "C" {
bool SkRSXform_rectStaysRect(SkRSXform *rsx_form);
void SkRSXform_setIdentity(SkRSXform *rsx_form);
void SkRSXform_set(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
void SkRSXform_toQuad(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4]);
void SkRSXform_toQuad_2(SkRSXform *rsx_form, const SkSize &size, SkPoint quad[4]);
void SkRSXform_toTriStrip(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4]);
// static
SkRSXform SkRSXform_Make(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
SkRSXform SkRSXform_MakeFromRadians(SkRSXform *rsx_form, SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay);
}

#endif //RAIA_SKIA_SK_RSX_FORM_H
