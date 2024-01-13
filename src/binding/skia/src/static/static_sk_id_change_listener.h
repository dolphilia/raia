//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
#define RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H

#include <string>
#include <map>
#include "include/private/SkIDChangeListener.h"

void static_sk_id_change_listener_delete(const char *key);
SkIDChangeListener *static_sk_id_change_listener_get(const char *key);
void static_sk_id_change_listener_set(const char *key, sk_sp<SkIDChangeListener> value);
sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_ID_CHANGE_LISTENER_H
