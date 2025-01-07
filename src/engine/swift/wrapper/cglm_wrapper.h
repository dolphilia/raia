#ifndef cglm_wrapper_h
#define cglm_wrapper_h

#ifdef __cplusplus
extern "C" {
#endif

/// Swift 側から float[16] を渡したい場合のラッパー群

/// mat4_identity
void swift_glm_mat4_identity(float *dest);

/// lookat
void swift_glm_lookat(const float *eye, const float *center, const float *up, float *dest);

/// perspective
void swift_glm_perspective(float fovy, float aspect, float nearVal, float farVal, float *dest);

/// rotate
void swift_glm_rotate(float *mat /* inout */, float angle, const float *axis);

/// mat4_mul
/// result = m1 * m2
void swift_glm_mat4_mul(const float *m1, const float *m2, float *dest);

#ifdef __cplusplus
}
#endif

#endif /* cglm_wrapper_h */
