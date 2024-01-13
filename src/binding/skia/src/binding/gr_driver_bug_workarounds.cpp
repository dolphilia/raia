//
// Created by dolphilia on 2024/01/13.
//

#include "gr_driver_bug_workarounds.h"

extern "C" {

// GrDriverBugWorkarounds & operator= (const GrDriverBugWorkarounds &)=default

GrDriverBugWorkarounds *GrDriverBugWorkarounds_new() {
    return new GrDriverBugWorkarounds();
}

GrDriverBugWorkarounds *GrDriverBugWorkarounds_new_2(const GrDriverBugWorkarounds *driverBugWorkarounds) {
    return new GrDriverBugWorkarounds(*driverBugWorkarounds);
}

GrDriverBugWorkarounds *GrDriverBugWorkarounds_new_3(const std::vector<int32_t> *workarounds) {
    return new GrDriverBugWorkarounds(*workarounds);
}

void GrDriverBugWorkarounds_delete(GrDriverBugWorkarounds *driverBugWorkarounds) {
    delete driverBugWorkarounds;
}

void applyOverrides(GrDriverBugWorkarounds *driverBugWorkarounds, const GrDriverBugWorkarounds *workarounds) {
    driverBugWorkarounds->applyOverrides(*workarounds);
}

}