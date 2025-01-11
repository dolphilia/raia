//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RSX_FORM_H
#define RAIA_SKIA_SK_RSX_FORM_H

#include "include/core/SkRSXform.h"
#include "../static/static_sk_rsx_form.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkRSXform_delete(SkRSXform *rsx_form);
RAIA_API bool SkRSXform_rectStaysRect(SkRSXform *rsx_form);
RAIA_API void SkRSXform_setIdentity(SkRSXform *rsx_form);
RAIA_API void SkRSXform_set(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
RAIA_API void SkRSXform_toQuad(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4]);
RAIA_API void SkRSXform_toQuad_2(SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4]);
RAIA_API void SkRSXform_toTriStrip(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4]);
// static
RAIA_API sk_rsx_form_t SkRSXform_Make(SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty);
RAIA_API sk_rsx_form_t SkRSXform_MakeFromRadians(SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay);
}

#endif //RAIA_SKIA_SK_RSX_FORM_H
