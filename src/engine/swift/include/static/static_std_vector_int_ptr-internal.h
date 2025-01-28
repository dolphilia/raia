//
// Created by dolphilia on 25/01/12.
//

#ifndef STATIC_STD_VECTOR_INT_PTR_INTERNAL_H
#define STATIC_STD_VECTOR_INT_PTR_INTERNAL_H
#include <set>
#include <map>
#include <vector>
int static_int_vector_ptr_make(std::vector<int>* value);
void static_int_vector_ptr_set(int key, std::vector<int>* value);
std::vector<int>* static_int_vector_ptr_move(int key);
#endif //STATIC_STD_VECTOR_INT_PTR_INTERNAL_H
