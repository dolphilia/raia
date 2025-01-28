#ifndef STATIC_SK_ENCODER_INTERNAL_H
#define STATIC_SK_ENCODER_INTERNAL_H
#include <set>
#include <map>
#include "include/encode/SkEncoder.h"
int static_sk_encoder_make(std::unique_ptr<SkEncoder> value);
void static_sk_encoder_set(int key, std::unique_ptr<SkEncoder> value);
std::unique_ptr<SkEncoder> static_sk_encoder_move(int key);
#endif // STATIC_SK_ENCODER_INTERNAL_H
