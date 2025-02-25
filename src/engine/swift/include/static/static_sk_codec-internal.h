#ifndef STATIC_SK_CODEC_INTERNAL_H
#define STATIC_SK_CODEC_INTERNAL_H

#include <set>
#include <map>
#include "include/codec/SkCodec.h"

int static_sk_codec_make(std::unique_ptr<SkCodec> value);
void static_sk_codec_set(int key, std::unique_ptr<SkCodec> value);
std::unique_ptr<SkCodec> static_sk_codec_get_entity(int key);

#endif // STATIC_SK_CODEC_INTERNAL_H
