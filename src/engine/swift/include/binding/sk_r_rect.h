//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_R_RECT_H
#define RAIA_SKIA_SK_R_RECT_H

#include "include/core/SkRRect.h"
#include "../static/static_sk_string.h"
#include "../static/static_sk_r_rect.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
//SkRRect & operator=(const SkRRect &rrect)
RAIA_API SkRRect *SkRRect_new();
RAIA_API SkRRect *SkRRect_new_2(const SkRRect *rrect);
RAIA_API void SkRRect_delete(SkRRect *rrect);
RAIA_API SkRRect::Type getType(SkRRect *rrect);
RAIA_API SkRRect::Type type(SkRRect *rrect);
RAIA_API bool SkRRect_isEmpty(SkRRect *rrect);
RAIA_API bool SkRRect_isRect(SkRRect *rrect);
RAIA_API bool SkRRect_isOval(SkRRect *rrect);
RAIA_API bool SkRRect_isSimple(SkRRect *rrect);
RAIA_API bool SkRRect_isNinePatch(SkRRect *rrect);
RAIA_API bool SkRRect_isComplex(SkRRect *rrect);
RAIA_API SkScalar SkRRect_width(SkRRect *rrect);
RAIA_API SkScalar SkRRect_height(SkRRect *rrect);
RAIA_API sk_point_t SkRRect_getSimpleRadii(SkRRect *rrect);
RAIA_API void SkRRect_setEmpty(SkRRect *rrect);
RAIA_API void SkRRect_setRect(SkRRect *rrect, const SkRect *rect);
RAIA_API void SkRRect_setOval(SkRRect *rrect, const SkRect *oval);
RAIA_API void SkRRect_setRectXY(SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad);
RAIA_API void SkRRect_setNinePatch(SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad);
RAIA_API void SkRRect_setRectRadii(SkRRect *rrect, const SkRect *rect, const SkVector radii[4]);
RAIA_API const SkRect * SkRRect_rect(SkRRect *rrect);
RAIA_API sk_point_t SkRRect_radii(SkRRect *rrect, SkRRect::Corner corner);
RAIA_API const SkRect * SkRRect_getBounds(SkRRect *rrect);
RAIA_API void SkRRect_inset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst);
RAIA_API void SkRRect_inset_2(SkRRect *rrect, SkScalar dx, SkScalar dy);
RAIA_API void SkRRect_outset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst);
RAIA_API void SkRRect_outset_2(SkRRect *rrect, SkScalar dx, SkScalar dy);
RAIA_API void SkRRect_offset(SkRRect *rrect, SkScalar dx, SkScalar dy);
RAIA_API sk_r_rect_t SkRRect_makeOffset(SkRRect *rrect, SkScalar dx, SkScalar dy);
RAIA_API bool SkRRect_contains(SkRRect *rrect, const SkRect *rect);
RAIA_API bool SkRRect_isValid(SkRRect *rrect);
RAIA_API size_t SkRRect_writeToMemory(SkRRect *rrect, void *buffer);
RAIA_API size_t SkRRect_readFromMemory(SkRRect *rrect, const void *buffer, size_t length);
RAIA_API bool SkRRect_transform(SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst);
RAIA_API void SkRRect_dump(SkRRect *rrect, bool asHex);
RAIA_API sk_string_t SkRRect_dumpToString(SkRRect *rrect, bool asHex);
RAIA_API void SkRRect_dump_2(SkRRect *rrect);
RAIA_API void SkRRect_dumpHex(SkRRect *rrect);
// static
RAIA_API sk_r_rect_t SkRRect_MakeEmpty();
RAIA_API sk_r_rect_t SkRRect_MakeRect(const SkRect *r);
RAIA_API sk_r_rect_t SkRRect_MakeOval(const SkRect *oval);
RAIA_API sk_r_rect_t SkRRect_MakeRectXY(const SkRect *rect, SkScalar xRad, SkScalar yRad);
}

#endif //RAIA_SKIA_SK_R_RECT_H
