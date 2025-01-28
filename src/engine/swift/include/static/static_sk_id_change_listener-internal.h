#ifndef STATIC_SK_ID_CHANGE_LISTENER_INTERNAL_H
#define STATIC_SK_ID_CHANGE_LISTENER_INTERNAL_H
#include <set>
#include <map>
#include "include/private/SkIDChangeListener.h"
int static_sk_id_change_listener_make(sk_sp<SkIDChangeListener> value);
void static_sk_id_change_listener_set(int key, sk_sp<SkIDChangeListener> value);
sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(int key);
#endif // STATIC_SK_ID_CHANGE_LISTENER_INTERNAL_H
