//
// Created by dolphilia on 2023/10/29.
//

#ifndef RAIA_V8_WRAPPER_FFI_H
#define RAIA_V8_WRAPPER_FFI_H

//extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "ffi.h"

#define ffi_call_ext(fn, nargs, rtype, atypes, rvalue, avalue)     \
do {                                                               \
    ffi_cif cif;                                                   \
    ffi_prep_cif_ext(&cif, FFI_DEFAULT_ABI, nargs, rtype, atypes); \
    ffi_call(&cif, FFI_FN(fn), rvalue, avalue);                    \
} while(0)

void ffi_prep_cif_ext(ffi_cif *cif, ffi_abi abi, unsigned int nargs, ffi_type *rtype, ffi_type **atypes);
//}

#endif //RAIA_V8_WRAPPER_FFI_H
