//
// Created by dolphilia on 2024/01/10.
//

#include "sk_raster_handle_allocator.h"

extern "C" {

void SkRasterHandleAllocator_delete(SkRasterHandleAllocator *raster_handle_allocator) {
    delete raster_handle_allocator;
}

bool SkRasterHandleAllocator_allocHandle(SkRasterHandleAllocator *raster_handle_allocator, const SkImageInfo *info, SkRasterHandleAllocator::Rec *rec) {
    return raster_handle_allocator->allocHandle(*info, rec);
}

void SkRasterHandleAllocator_updateHandle(SkRasterHandleAllocator *raster_handle_allocator, SkRasterHandleAllocator::Handle handle, const SkMatrix *matrix, const SkIRect *irect) {
    raster_handle_allocator->updateHandle(handle, *matrix, *irect);
}

// static

// @TODO
//std::unique_ptr<SkCanvas> SkRasterHandleAllocator_MakeCanvas(std::unique_ptr<SkRasterHandleAllocator> allocator, const SkImageInfo &info, const SkRasterHandleAllocator::Rec *rec, const SkSurfaceProps *props) {
//    return SkRasterHandleAllocator::MakeCanvas(allocator, info, rec, props);
//}

}