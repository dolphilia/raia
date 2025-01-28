//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RSX_FORM_H
#define RAIA_SKIA_SK_RSX_FORM_H

#ifdef __cplusplus
extern "C" {
#endif

void SkRSXform_delete(void *rsx_form); // (SkRSXform *rsx_form)
bool SkRSXform_rectStaysRect(void *rsx_form); // (SkRSXform *rsx_form) -> bool
void SkRSXform_setIdentity(void *rsx_form); // (SkRSXform *rsx_form)
void SkRSXform_set(void *rsx_form, float scos, float ssin, float tx, float ty); // (SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
void SkRSXform_toQuad(void *rsx_form, float width, float height, void * quad); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4])
void SkRSXform_toQuad_2(void *rsx_form, const void *size, void * quad); // (SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4])
void SkRSXform_toTriStrip(void *rsx_form, float width, float height, void * strip); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4])

// static

int SkRSXform_Make(float scos, float ssin, float tx, float ty); // (SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) -> sk_rsx_form_t
int SkRSXform_MakeFromRadians(float scale, float radians, float tx, float ty, float ax, float ay); // (SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) -> sk_rsx_form_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RSX_FORM_H
