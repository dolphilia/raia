//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_R_RECT_H
#define RAIA_SKIA_SK_R_RECT_H

#ifdef __cplusplus
extern "C" {
#endif

//SkRRect & operator=(const SkRRect &rrect)
void *SkRRect_new(); // () -> SkRRect *
void *SkRRect_new_2(const void *rrect); // (const SkRRect *rrect) -> SkRRect *
void SkRRect_delete(void *rrect); // (SkRRect *rrect)
int getType(void *rrect); // (SkRRect *rrect) -> SkRRect::Type
int type(void *rrect); // (SkRRect *rrect) -> SkRRect::Type
bool SkRRect_isEmpty(void *rrect); // (SkRRect *rrect) -> bool
bool SkRRect_isRect(void *rrect); // (SkRRect *rrect) -> bool
bool SkRRect_isOval(void *rrect); // (SkRRect *rrect) -> bool
bool SkRRect_isSimple(void *rrect); // (SkRRect *rrect) -> bool
bool SkRRect_isNinePatch(void *rrect); // (SkRRect *rrect) -> bool
bool SkRRect_isComplex(void *rrect); // (SkRRect *rrect) -> bool
float SkRRect_width(void *rrect); // (SkRRect *rrect) -> SkScalar
float SkRRect_height(void *rrect); // (SkRRect *rrect) -> SkScalar
int SkRRect_getSimpleRadii(void *rrect); // (SkRRect *rrect) -> sk_point_t
void SkRRect_setEmpty(void *rrect); // (SkRRect *rrect)
void SkRRect_setRect(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect)
void SkRRect_setOval(void *rrect, const void *oval); // (SkRRect *rrect, const SkRect *oval)
void SkRRect_setRectXY(void *rrect, const void *rect, float xRad, float yRad); // (SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad)
void SkRRect_setNinePatch(void *rrect, const void *rect, float leftRad, float topRad, float rightRad, float bottomRad); // (SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad)
void SkRRect_setRectRadii(void *rrect, const void *rect, const void * radii); // (SkRRect *rrect, const SkRect *rect, const SkVector radii[4])
const void *SkRRect_rect(void *rrect); // (SkRRect *rrect) -> const SkRect *
int SkRRect_radii(void *rrect, int corner); // (SkRRect *rrect, SkRRect::Corner corner) -> sk_point_t
const void *SkRRect_getBounds(void *rrect); // (SkRRect *rrect) -> const SkRect *
void SkRRect_inset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)
void SkRRect_inset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
void SkRRect_outset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)
void SkRRect_outset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
void SkRRect_offset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
int SkRRect_makeOffset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy) -> sk_r_rect_t
bool SkRRect_contains(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect) -> bool
bool SkRRect_isValid(void *rrect); // (SkRRect *rrect) -> bool
unsigned long SkRRect_writeToMemory(void *rrect, void *buffer); // (SkRRect *rrect, void *buffer) -> size_t
unsigned long SkRRect_readFromMemory(void *rrect, const void *buffer, unsigned long length); // (SkRRect *rrect, const void *buffer, size_t length) -> size_t
bool SkRRect_transform(void *rrect, const void *matrix, void *dst); // (SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst) -> bool
void SkRRect_dump(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex)
int SkRRect_dumpToString(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex) -> sk_string_t
void SkRRect_dump_2(void *rrect); // (SkRRect *rrect)
void SkRRect_dumpHex(void *rrect); // (SkRRect *rrect)

// static

int SkRRect_MakeEmpty(); // () -> sk_r_rect_t
int SkRRect_MakeRect(const void *r); // (const SkRect *r) -> sk_r_rect_t
int SkRRect_MakeOval(const void *oval); // (const SkRect *oval) -> sk_r_rect_t
int SkRRect_MakeRectXY(const void *rect, float xRad, float yRad); // (const SkRect *rect, SkScalar xRad, SkScalar yRad) -> sk_r_rect_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_R_RECT_H
