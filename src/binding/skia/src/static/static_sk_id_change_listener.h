//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
#define RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H

#include <string>
#include <map>
#include "include/private/SkIDChangeListener.h"

int static_sk_id_change_listener_make(sk_sp<SkIDChangeListener> value);
void static_sk_id_change_listener_delete(int key);
SkIDChangeListener *static_sk_id_change_listener_get(int key);
void static_sk_id_change_listener_set(int key, sk_sp<SkIDChangeListener> value);
sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(int key);

#endif //RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
