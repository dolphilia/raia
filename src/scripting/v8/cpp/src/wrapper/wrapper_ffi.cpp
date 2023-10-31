//
// Created by dolphilia on 2023/10/29.
//

#include "wrapper_ffi.h"

void ffi_prep_cif_ext(ffi_cif *cif, ffi_abi abi, unsigned int nargs, ffi_type *rtype, ffi_type **atypes) {
    if (ffi_prep_cif(cif, abi, nargs, rtype, atypes) != FFI_OK) {
        fprintf(stderr, "ffi_prep_cif failed.\n");
        exit(1);
    }
}