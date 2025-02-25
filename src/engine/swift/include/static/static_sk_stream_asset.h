//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
#define RAIA_SKIA_STATIC_SK_STREAM_ASSET_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stream_asset_t;
void static_sk_stream_asset_delete(int key);
void *static_sk_stream_asset_get_ptr(int key); // -> SkStreamAsset *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
