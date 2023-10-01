//
// Created by dolphilia on 2023/09/12.
//

#include <objc/objc-runtime.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, const char * argv[]) {
    Class class = objc_getClass("NSAutoreleasePool");
    id pool = objc_msgSend(class, sel_getUid("new"));

    id app = objc_msgSend(objc_getClass("NSApplication"), sel_getUid("sharedApplication"));
    objc_msgSend(app, sel_getUid("setActivationPolicy:"), 0);

    id alert = objc_msgSend(objc_msgSend(objc_getClass("NSAlert"), sel_getUid("alloc")), sel_getUid("init"));

    objc_msgSend(alert, sel_getUid("setMessageText:"), CFSTR("Caption text"));
    objc_msgSend(alert, sel_getUid("setInformativeText:"), CFSTR("Detailed text"));

    objc_msgSend(alert, sel_getUid("addButtonWithTitle:"), CFSTR("OK"));
    objc_msgSend(alert, sel_getUid("setAlertStyle:"), 0);

    objc_msgSend(app, sel_getUid("activateIgnoringOtherApps:"), (id)1);
    objc_msgSend(alert, sel_getUid("runModal"));
    objc_msgSend(app, sel_getUid("terminate:"), nil);

    objc_msgSend(pool, sel_getUid("drain"));

    return 0;
}