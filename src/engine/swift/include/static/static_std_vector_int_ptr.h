//
// Created by dolphilia on 25/01/12.
//

#ifndef STATIC_STD_VECTOR_INT_PTR_H
#define STATIC_STD_VECTOR_INT_PTR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int vector_int_ptr_t;
void static_int_vector_ptr_delete(int key);
void* static_int_vector_ptr_get_ptr(int key);

#ifdef __cplusplus
}
#endif

#endif //STATIC_STD_VECTOR_INT_PTR_H
