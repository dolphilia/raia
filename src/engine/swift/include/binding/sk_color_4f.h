//
// Created by dolphilia on 25/01/30.
//

#ifndef SK_COLOR4F_H
#define SK_COLOR4F_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColor4f_delete(void *color);

// Public Attributes

float SkColor4f_fR(void *color); // (SkColor4f *color) -> float
float SkColor4f_fG(void *color); // (SkColor4f *color) -> float
float SkColor4f_fB(void *color); // (SkColor4f *color) -> float
float SkColor4f_fA(void *color); // (SkColor4f *color) -> float

// Public Member Functions

//bool operator== (const SkRGBA4f &other);
//bool operator!= (const SkRGBA4f &other);
//SkRGBA4f operator* (float scale);
//SkRGBA4f operator* (const SkRGBA4f &scale);
//float operator[] (SkColor4f *color, int index);
//float & operator[] (SkColor4f *color, int index);

const float * SkColor4f_vec(void *color); // (SkColor4f *color) -> const float *
float * SkColor4f_vec_2(void *color); // (SkColor4f *color) -> float *

// TODO
// std::array< float, 4 > SkColor4f_array (void *color);

bool SkColor4f_isOpaque (void *color); // (SkColor4f *color) -> bool
bool SkColor4f_fitsInBytes (void *color); // (SkColor4f *color) -> bool
unsigned int SkColor4f_toSkColor (void *color); // (SkColor4f *color) -> SkColor

// TODO
//SkRGBA4f< kPremul_SkAlphaType > premul (SkColor4f *color);
//SkRGBA4f< kUnpremul_SkAlphaType > unpremul (SkColor4f *color);

unsigned int SkColor4f_toBytes_RGBA (void *color); // (SkColor4f *color) -> uint32_t
int SkColor4f_makeOpaque(void *color); //  (SkColor4f *color) -> SkColor4f

// static

static int SkColor4f_FromColor (unsigned int color); // (SkColor color) -> SkColor4f
static int SkColor4f_FromPMColor (unsigned int color); // (SkPMColor color) -> SkColor4f
static int SkColor4f_FromBytes_RGBA (unsigned int color); // (uint32_t color) -> SkColor4f

#ifdef __cplusplus
}
#endif

#endif //SK_COLOR4F_H
