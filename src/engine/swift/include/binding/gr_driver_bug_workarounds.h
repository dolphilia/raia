//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_GR_DRIVER_BUG_WORKAROUNDS_H
#define RAIA_SKIA_GR_DRIVER_BUG_WORKAROUNDS_H

#include "include/gpu/GrDriverBugWorkarounds.h"

extern "C" {
// GrDriverBugWorkarounds & operator= (const GrDriverBugWorkarounds &)=default
GrDriverBugWorkarounds *GrDriverBugWorkarounds_new();
GrDriverBugWorkarounds *GrDriverBugWorkarounds_new_2(const GrDriverBugWorkarounds *driverBugWorkarounds);
GrDriverBugWorkarounds *GrDriverBugWorkarounds_new_3(const std::vector<int32_t> *workarounds);
void GrDriverBugWorkarounds_delete(GrDriverBugWorkarounds *driverBugWorkarounds);
void applyOverrides(GrDriverBugWorkarounds *driverBugWorkarounds, const GrDriverBugWorkarounds *workarounds);
}

#endif //RAIA_SKIA_GR_DRIVER_BUG_WORKAROUNDS_H
