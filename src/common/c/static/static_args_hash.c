//
// Created by dolphilia on 2023/10/29.
//

#include "static_args_hash.h"

args_hash_t *args_hash = NULL;
args_name_hash_t *args_name_hash = NULL;

void add_args_hash(args_key_t key, const char *name) {
    args_hash_t *s;
    s = (args_hash_t *)malloc(sizeof(args_hash_t));
    if (s == NULL) {
        exit(-1); // エラー処理
    }
    s->key = key;
    strncpy(s->name, name, 50);
    HASH_ADD(hh, args_hash, key, sizeof(args_key_t), s);
}

args_hash_t *find_args_hash(args_key_t key) {
    args_hash_t *s;
    HASH_FIND(hh, args_hash, &key, sizeof(args_key_t), s);
    return s;
}

void delete_args_hash(args_hash_t *item) {
    HASH_DEL(args_hash, item);
    free(item);
}

void delete_all_args_hash() {
    args_hash_t *current, *tmp;
    HASH_ITER(hh, args_hash, current, tmp) {
        HASH_DEL(args_hash, current);
        free(current);
    }
}

void add_args_name_hash(args_key_t key, const char *name) {
    // 既存の add_item 関数を使ってキーに基づくハッシュテーブルに追加
    add_args_hash(key, name);

    // 名前に基づくハッシュテーブルに追加
    args_name_hash_t *s = (args_name_hash_t *)malloc(sizeof(args_name_hash_t));
    if (s == NULL) {
        exit(-1); // エラー処理
    }
    strncpy(s->name, name, sizeof(s->name));
    s->key = key;
    HASH_ADD_STR(args_name_hash, name, s);
}

args_name_hash_t *find_args_name_hash(const char *name) {
    args_name_hash_t *s;
    HASH_FIND_STR(args_name_hash, name, s);
    return s;
}

void delete_args_name_hash(args_key_t key, const char *name) {
    // キーに基づくハッシュテーブルから削除
    args_hash_t *found = find_args_hash(key);
    if (found) {
        delete_args_hash(found);
    }

    // 名前に基づくハッシュテーブルから削除
    args_name_hash_t *s;
    HASH_FIND_STR(args_name_hash, name, s);
    if (s) {
        if(s->key.type == TYPE_STRING) {
            free((void *)s->key.data.value_string);
        }
        HASH_DEL(args_name_hash, s);
        free(s);
    }
}

void delete_all_args_name_hash() {
    args_name_hash_t *current, *tmp;
    HASH_ITER(hh, args_name_hash, current, tmp) {
        if(current->key.type == TYPE_STRING) {
            free((void *)current->key.data.value_string);
        }
        HASH_DEL(args_name_hash, current);
        free(current);
    }
}

void *add_args_hash_to_uint8(const char *name, uint8_t value) {
    args_key_t key = {.type = TYPE_UINT8, .data = {.value_uint8 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uint8;
}

void *add_args_hash_to_sint8(const char *name, int8_t value) {
    args_key_t key = {.type = TYPE_SINT8, .data = {.value_sint8 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sint8;
}

void *add_args_hash_to_uint16(const char *name, uint16_t value) {
    args_key_t key = {.type = TYPE_UINT16, .data = {.value_uint16 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uint16;
}

void *add_args_hash_to_sint16(const char *name, int16_t value) {
    args_key_t key = {.type = TYPE_SINT16, .data = {.value_sint16 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sint16;
}

void *add_args_hash_to_uint32(const char *name, uint32_t value) {
    args_key_t key = {.type = TYPE_UINT32, .data = {.value_uint32 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uint32;
}

void *add_args_hash_to_sint32(const char *name, int32_t value) {
    args_key_t key = {.type = TYPE_SINT32, .data = {.value_sint32 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sint32;
}

void *add_args_hash_to_uint64(const char *name, uint64_t value) {
    args_key_t key = {.type = TYPE_UINT64, .data = {.value_uint64 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uint64;
}

void *add_args_hash_to_sint64(const char *name, int64_t value) {
    args_key_t key = {.type = TYPE_SINT64, .data = {.value_sint64 = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sint64;
}

void *add_args_hash_to_float(const char *name, float value) {
    args_key_t key = {.type = TYPE_FLOAT, .data = {.value_float = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_float;
}

void *add_args_hash_to_double(const char *name, double value) {
    args_key_t key = {.type = TYPE_DOUBLE, .data = {.value_double = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_double;
}

void *add_args_hash_to_uchar(const char *name, unsigned char value) {
    args_key_t key = {.type = TYPE_UCHAR, .data = {.value_uchar = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uchar;
}

void *add_args_hash_to_schar(const char *name, char value) {
    args_key_t key = {.type = TYPE_SCHAR, .data = {.value_schar = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_schar;
}

void *add_args_hash_to_ushort(const char *name, unsigned short value) {
    args_key_t key = {.type = TYPE_USHORT, .data = {.value_ushort = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_ushort;
}

void *add_args_hash_to_sshort(const char *name, short value) {
    args_key_t key = {.type = TYPE_SSHORT, .data = {.value_sshort = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sshort;
}

void *add_args_hash_to_uint(const char *name, unsigned int value) {
    args_key_t key = {.type = TYPE_UINT, .data = {.value_uint = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_uint;
}

void *add_args_hash_to_sint(const char *name, int value) {
    args_key_t key = {.type = TYPE_SINT, .data = {.value_sint = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_sint;
}

void *add_args_hash_to_ulong(const char *name, unsigned long value) {
    args_key_t key = {.type = TYPE_ULONG, .data = {.value_ulong = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_ulong;
}

void *add_args_hash_to_slong(const char *name, long value) {
    args_key_t key = {.type = TYPE_SLONG, .data = {.value_slong = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_slong;
}

void *add_args_hash_to_longdouble(const char *name, long double value) {
    args_key_t key = {.type = TYPE_LONGDOUBLE, .data = {.value_longdouble = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_longdouble;
}

void *add_args_hash_to_string(const char *name, const char * value) {
    args_key_t key = {.type = TYPE_STRING, .data = {.value_string = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return &hash->key.data.value_string;
}

void *add_args_hash_to_pointer(const char *name, void * value) {
    args_key_t key = {.type = TYPE_POINTER, .data = {.value_pointer = value}};
    add_args_name_hash(key, name);
    args_name_hash_t *hash = find_args_name_hash(name);
    return hash->key.data.value_pointer;
}

//void *add_args_hash_to_complex_float(const char *name, _Complex float value) {
//    args_key_t key = {.type = TYPE_COMPLEX_FLOAT, .data = {.value_complex_float = value}};
//    add_args_name_hash(key, name);
//    args_name_hash_t *hash = find_args_name_hash(name);
//    return &hash->key.data.value_complex_float;
//}
//
//void *add_args_hash_to_complex_double(const char *name, _Complex double value) {
//    args_key_t key = {.type = TYPE_COMPLEX_DOUBLE, .data = {.value_complex_double = value}};
//    add_args_name_hash(key, name);
//    args_name_hash_t *hash = find_args_name_hash(name);
//    return &hash->key.data.value_complex_double;
//}
//
//void *add_args_hash_to_complex_longdouble(const char *name, _Complex long double value) {
//    args_key_t key = {.type = TYPE_COMPLEX_LONGDOUBLE, .data = {.value_complex_longdouble = value}};
//    add_args_name_hash(key, name);
//    args_name_hash_t *hash = find_args_name_hash(name);
//    return &hash->key.data.value_complex_longdouble;
//}