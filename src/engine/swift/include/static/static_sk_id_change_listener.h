//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
#define RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_id_change_listener_t;
void static_sk_id_change_listener_delete(int key);
void *static_sk_id_change_listener_get(int key); // -> SkIDChangeListener *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
