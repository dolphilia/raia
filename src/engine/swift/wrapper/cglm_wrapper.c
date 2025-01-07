#include "cglm_wrapper.h"
#include <cglm/cglm.h>

void swift_glm_mat4_identity(float *dest) {
    // mat4は float[4][4] なので、(mat4*) でキャスト
    glm_mat4_identity(*(mat4*)dest);
}

void swift_glm_lookat(const float *eye, const float *center, const float *up, float *dest) {
    glm_lookat((vec3*)eye, (vec3*)center, (vec3*)up, *(mat4*)dest);
}

void swift_glm_perspective(float fovy, float aspect, float nearVal, float farVal, float *dest) {
    glm_perspective(fovy, aspect, nearVal, farVal, *(mat4*)dest);
}

void swift_glm_rotate(float *mat, float angle, const float *axis) {
    glm_rotate(*(mat4*)mat, angle, *(vec3*)axis);
}

void swift_glm_mat4_mul(const float *m1, const float *m2, float *dest) {
    glm_mat4_mul(*(mat4*)m1, *(mat4*)m2, *(mat4*)dest);
}
