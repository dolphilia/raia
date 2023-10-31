//
// Created by dolphilia on 2023/10/29.
//

#ifndef RAIA_V8_STATIC_ARGS_HASH_H
#define RAIA_V8_STATIC_ARGS_HASH_H

#include <stdio.h>
#include <stdint.h>
//#include <complex.h>
#include "../../../third_party/c/troydhanson/uthash/uthash.h"

typedef enum {
    TYPE_UINT8,
    TYPE_SINT8,
    TYPE_UINT16,
    TYPE_SINT16,
    TYPE_UINT32,
    TYPE_SINT32,
    TYPE_UINT64,
    TYPE_SINT64,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_UCHAR,
    TYPE_SCHAR,
    TYPE_USHORT,
    TYPE_SSHORT,
    TYPE_UINT,
    TYPE_SINT,
    TYPE_ULONG,
    TYPE_SLONG,
    TYPE_LONGDOUBLE,
    TYPE_STRING,
    TYPE_POINTER,
    TYPE_COMPLEX_FLOAT,
    TYPE_COMPLEX_DOUBLE,
    TYPE_COMPLEX_LONGDOUBLE
} args_type_t;

typedef struct {
    args_type_t type;
    union {
        uint8_t value_uint8;
        int8_t value_sint8;
        uint16_t value_uint16;
        int16_t value_sint16;
        uint32_t value_uint32;
        int32_t value_sint32;
        uint64_t value_uint64;
        int64_t value_sint64;
        float value_float;
        double value_double;
        unsigned char value_uchar;
        char value_schar;
        unsigned short value_ushort;
        short value_sshort;
        unsigned int value_uint;
        int value_sint;
        unsigned long value_ulong;
        long value_slong;
        long double value_longdouble;
        const char *value_string;
        void *value_pointer;
//        _Complex float value_complex_float;
//        _Complex double value_complex_double;
//        _Complex long double value_complex_longdouble;
    } data;
} args_key_t;

typedef struct {
    char name[50];
    args_key_t key;
    UT_hash_handle hh;
} args_hash_t;

typedef struct {
    char name[50];
    args_key_t key;
    UT_hash_handle hh;
} args_name_hash_t;

void add_args_hash(args_key_t key, const char *name);
args_hash_t *find_args_hash(args_key_t key);
void delete_args_hash(args_hash_t *item);
void delete_all_args_hash();
void add_args_name_hash(args_key_t key, const char *name);
args_name_hash_t *find_args_name_hash(const char *name);
void delete_args_name_hash(args_key_t key, const char *name);
void delete_all_args_name_hash();

void *add_args_hash_to_uint8(const char *name, uint8_t value);
void *add_args_hash_to_sint8(const char *name, int8_t value);
void *add_args_hash_to_uint16(const char *name, uint16_t value);
void *add_args_hash_to_sint16(const char *name, int16_t value);
void *add_args_hash_to_uint32(const char *name, uint32_t value);
void *add_args_hash_to_sint32(const char *name, int32_t value);
void *add_args_hash_to_uint64(const char *name, uint64_t value);
void *add_args_hash_to_sint64(const char *name, int64_t value);
void *add_args_hash_to_float(const char *name, float value);
void *add_args_hash_to_double(const char *name, double value);
void *add_args_hash_to_uchar(const char *name, unsigned char value);
void *add_args_hash_to_schar(const char *name, char value);
void *add_args_hash_to_ushort(const char *name, unsigned short value);
void *add_args_hash_to_sshort(const char *name, short value);
void *add_args_hash_to_uint(const char *name, unsigned int value);
void *add_args_hash_to_sint(const char *name, int value);
void *add_args_hash_to_ulong(const char *name, unsigned long value);
void *add_args_hash_to_slong(const char *name, long value);
void *add_args_hash_to_longdouble(const char *name, long double value);
void *add_args_hash_to_string(const char *name, const char * value);
void *add_args_hash_to_pointer(const char *name, void *value);
//void *add_args_hash_to_complex_float(const char *name, _Complex float value);
//void *add_args_hash_to_complex_double(const char *name, _Complex double value);
//void *add_args_hash_to_complex_longdouble(const char *name, _Complex long double value);


#endif //RAIA_V8_STATIC_ARGS_HASH_H
