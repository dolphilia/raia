//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_R_RECT_H
#define RAIA_SKIA_SK_R_RECT_H

#include "include/core/SkRRect.h"
#include "../static/static_sk_string.h"
#include "../static/static_sk_r_rect.h"
#include "../static/static_sk_point.h"

extern "C" {
//SkRRect & operator=(const SkRRect &rrect)
SkRRect *SkRRect_new();
SkRRect *SkRRect_new_2(const SkRRect *rrect);
void SkRRect_delete(SkRRect *rrect);
SkRRect::Type getType(SkRRect *rrect);
SkRRect::Type type(SkRRect *rrect);
bool SkRRect_isEmpty(SkRRect *rrect);
bool SkRRect_isRect(SkRRect *rrect);
bool SkRRect_isOval(SkRRect *rrect);
bool SkRRect_isSimple(SkRRect *rrect);
bool SkRRect_isNinePatch(SkRRect *rrect);
bool SkRRect_isComplex(SkRRect *rrect);
SkScalar SkRRect_width(SkRRect *rrect);
SkScalar SkRRect_height(SkRRect *rrect);
sk_point_t SkRRect_getSimpleRadii(SkRRect *rrect);
void SkRRect_setEmpty(SkRRect *rrect);
void SkRRect_setRect(SkRRect *rrect, const SkRect *rect);
void SkRRect_setOval(SkRRect *rrect, const SkRect *oval);
void SkRRect_setRectXY(SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad);
void SkRRect_setNinePatch(SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad);
void SkRRect_setRectRadii(SkRRect *rrect, const SkRect *rect, const SkVector radii[4]);
const SkRect * SkRRect_rect(SkRRect *rrect);
sk_point_t SkRRect_radii(SkRRect *rrect, SkRRect::Corner corner);
const SkRect * SkRRect_getBounds(SkRRect *rrect);
void SkRRect_inset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst);
void SkRRect_inset_2(SkRRect *rrect, SkScalar dx, SkScalar dy);
void SkRRect_outset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst);
void SkRRect_outset_2(SkRRect *rrect, SkScalar dx, SkScalar dy);
void SkRRect_offset(SkRRect *rrect, SkScalar dx, SkScalar dy);
sk_r_rect_t SkRRect_makeOffset(SkRRect *rrect, SkScalar dx, SkScalar dy);
bool SkRRect_contains(SkRRect *rrect, const SkRect *rect);
bool SkRRect_isValid(SkRRect *rrect);
size_t SkRRect_writeToMemory(SkRRect *rrect, void *buffer);
size_t SkRRect_readFromMemory(SkRRect *rrect, const void *buffer, size_t length);
bool SkRRect_transform(SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst);
void SkRRect_dump(SkRRect *rrect, bool asHex);
sk_string_t SkRRect_dumpToString(SkRRect *rrect, bool asHex);
void SkRRect_dump_2(SkRRect *rrect);
void SkRRect_dumpHex(SkRRect *rrect);
// static
sk_r_rect_t SkRRect_MakeEmpty();
sk_r_rect_t SkRRect_MakeRect(const SkRect *r);
sk_r_rect_t SkRRect_MakeOval(const SkRect *oval);
sk_r_rect_t SkRRect_MakeRectXY(const SkRect *rect, SkScalar xRad, SkScalar yRad);
}

#endif //RAIA_SKIA_SK_R_RECT_H
