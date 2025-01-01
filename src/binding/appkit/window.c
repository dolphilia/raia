#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

typedef unsigned long NSUInteger;
typedef long NSInteger;

// MARK: ObjC

Class ObjC_getClass(const char * className) {
    return objc_getClass(className);
}

Class ObjC_allocateClassPair(Class superClass, const char * name, size_t extraBytes) {
    return objc_allocateClassPair(superClass, name, extraBytes);
}

void ObjC_registerClassPair(Class cls) {
    objc_registerClassPair(cls);
}

void ObjC_classAddMethod(Class cls, SEL sel, IMP imp, const char * types) {
    class_addMethod(cls, sel, imp, types);
}

SEL ObjC_selRegisterName(const char * selName) {
    return sel_registerName(selName);
}

// MARK: NSAutoreleasePool

id NSAutoreleasePool_new() {
    return ((id (*)(id, SEL))objc_msgSend)((id)objc_getClass("NSAutoreleasePool"), sel_registerName("new"));
}

void NSAutoreleasePool_drain(id pool) {
    ((void (*)(id, SEL))objc_msgSend)(pool, sel_registerName("drain"));
}

// MARK: NSAlert

id NSAlert_alloc() {
    id alertClass = (id)objc_getClass("NSAlert");
    return ((id (*)(id, SEL))objc_msgSend)(alertClass, sel_registerName("alloc"));
}

id NSAlert_init(id alert) {
    return ((id (*)(id, SEL))objc_msgSend)(alert, sel_registerName("init"));
}

void NSAlert_setAlertStyle(id alert, NSInteger style) {
    ((void (*)(id, SEL, NSInteger))objc_msgSend)(alert, sel_registerName("setAlertStyle:"), style);
}

void NSAlert_setMessageText(id alert, id text) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("setMessageText:"), text);
}

void NSAlert_setInformativeText(id alert, id text) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("setInformativeText:"), text);
}

void NSAlert_addButtonWithTitle(id alert, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("addButtonWithTitle:"), title);
}

void NSAlert_runModal(id alert) {
    ((void (*)(id, SEL))objc_msgSend)(alert, sel_registerName("runModal"));
}

id NSAlert_release(id alert) {
    return ((id (*)(id, SEL))objc_msgSend)(alert, sel_registerName("release"));
}

// MARK: NSAlertStyle

typedef enum {
    NSAlertStyleWarning       = 0, // 通常の警告
    NSAlertStyleInformational = 1, // 情報提供のスタイル
    NSAlertStyleCritical      = 2  // 重要な警告
} NSAlertStyle;

// MARK: NSWindow

id NSWindow_alloc() {
    id windowClass = (id)objc_getClass("NSWindow");
    return ((id (*)(id, SEL))objc_msgSend)(windowClass, sel_registerName("alloc"));
}

void NSWindow_setTitle(id window, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(window, sel_registerName("setTitle:"), title);
}

id NSWindow_initWithContentRect(id window, CGRect contentRect, NSUInteger styleMask, NSInteger backing, BOOL defer) {
    return ((id (*)(id, SEL, CGRect, NSUInteger, NSInteger, BOOL))objc_msgSend)(window, sel_registerName("initWithContentRect:styleMask:backing:defer:"), contentRect, styleMask, backing, defer);
}

void NSWindow_makeKeyAndOrderFront(id window, id sender) {
    ((void (*)(id, SEL, id))objc_msgSend)(window, sel_registerName("makeKeyAndOrderFront:"), sender);
}

id NSWindow_contentView(id window) {
    return ((id (*)(id, SEL))objc_msgSend)(window, sel_registerName("contentView"));
}

// MARK: NSWindowStyleMask

typedef enum {
    NSWindowStyleMaskBorderless          = 0,
    NSWindowStyleMaskTitled              = (1 << 0),
    NSWindowStyleMaskClosable            = (1 << 1),
    NSWindowStyleMaskMiniaturizable      = (1 << 2),
    NSWindowStyleMaskResizable           = (1 << 3),
    NSWindowStyleMaskTexturedBackground  = (1 << 8),
    NSWindowStyleMaskUnifiedTitleAndToolbar = (1 << 12),
    NSWindowStyleMaskFullScreen          = (1 << 14),
    NSWindowStyleMaskFullSizeContentView = (1 << 15),
    NSWindowStyleMaskUtilityWindow       = (1 << 4),
    NSWindowStyleMaskDocModalWindow      = (1 << 6),
    NSWindowStyleMaskHUDWindow           = (1 << 13)
} NSWindowStyleMask;

// MARK: NSView

void NSView_addSubview(id view, id subview) {
    ((void (*)(id, SEL, id))objc_msgSend)(view, sel_registerName("addSubview:"), subview);
}

// MARK: NSApplication

id NSApplication_sharedApplication() {
    return ((id (*)(id, SEL))objc_msgSend)((id)objc_getClass("NSApplication"), sel_registerName("sharedApplication"));
}

void NSApplication_run(id app) {
    ((void (*)(id, SEL))objc_msgSend)(app, sel_registerName("run"));
}

// MARK: NSButton

id NSButton_alloc() {
    id buttonClass = (id)objc_getClass("NSButton");
    return ((id (*)(id, SEL))objc_msgSend)(buttonClass, sel_registerName("alloc"));
}

id NSButton_initWithFrame(id button, CGRect frame) {
    return ((id (*)(id, SEL, CGRect))objc_msgSend)(button, sel_registerName("initWithFrame:"), frame);
}

void NSButton_setTitle(id button, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(button, sel_registerName("setTitle:"), title);
}

void NSButton_setBezelStyle(id button, NSInteger style) {
    ((void (*)(id, SEL, NSInteger))objc_msgSend)(button, sel_registerName("setBezelStyle:"), style);
}

void NSButton_setTarget(id button, id target) {
    ((void (*)(id, SEL, id))objc_msgSend)(button, sel_registerName("setTarget:"), target);
}

void NSButton_setAction(id button, SEL action) {
    ((void (*)(id, SEL, SEL))objc_msgSend)(button, sel_registerName("setAction:"), action);
}

// MARK: NSString

id NSString_stringWithUTF8String(const char * str) {
    return ((id (*)(id, SEL, const char *))objc_msgSend)((id)objc_getClass("NSString"), sel_registerName("stringWithUTF8String:"), str);
}

// MARK: NSBackingStoreType

typedef enum {
    NSBackingStoreRetained    = 0, // 描画内容を保持
    NSBackingStoreNonretained = 1, // 描画内容を保持せず再描画
    NSBackingStoreBuffered    = 2  // 描画内容をバッファリング（推奨）
} NSBackingStoreType;

// MARK: NSBezelStyle

typedef enum {
    NSBezelStyleRounded          = 1,
    NSBezelStyleRegularSquare    = 2,
    NSBezelStyleDisclosure       = 5,
    NSBezelStyleShadowlessSquare = 6,
    NSBezelStyleCircular         = 7,
    NSBezelStyleTexturedSquare   = 8,
    NSBezelStyleHelpButton       = 9,
    NSBezelStyleSmallSquare      = 10,
    NSBezelStyleTexturedRounded  = 11,
    NSBezelStyleRoundRect        = 12,
    NSBezelStyleRecessed         = 13,
    NSBezelStyleRoundedDisclosure= 14
} NSBezelStyle;

//--

void buttonClicked(id self, SEL _cmd, id sender) {
    id pool = NSAutoreleasePool_new();

    id alert = NSAlert_init(NSAlert_alloc());
    NSAlert_setAlertStyle(alert, NSAlertStyleWarning);
    id messageText = NSString_stringWithUTF8String("Confirmation");
    id informativeText = NSString_stringWithUTF8String("Button was clicked!");
    id okButtonTitle = NSString_stringWithUTF8String("OK");
    NSAlert_setMessageText(alert, messageText);
    NSAlert_setInformativeText(alert, informativeText);
    NSAlert_addButtonWithTitle(alert, okButtonTitle);
    NSAlert_runModal(alert);
    NSAlert_release(alert);

    NSAutoreleasePool_drain(pool);
}

int main() {
    id pool = NSAutoreleasePool_new();

    id app = NSApplication_sharedApplication();

    CGRect rect = CGRectMake(300, 300, 400, 200);

    id window = NSWindow_alloc();
    window = NSWindow_initWithContentRect(window, rect, NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, NSBackingStoreBuffered, NO);

    id titleString = NSString_stringWithUTF8String("C Language Window");
    NSWindow_setTitle(window, titleString);

    NSWindow_makeKeyAndOrderFront(window, nil);

    CGRect buttonRect = CGRectMake(150, 80, 100, 40);

    id button = NSButton_initWithFrame(NSButton_alloc(), buttonRect);

    id buttonTitle = NSString_stringWithUTF8String("Click Me");
    NSButton_setTitle(button, buttonTitle);
    NSButton_setBezelStyle(button, NSBezelStyleRounded);

    Class NSObject = ObjC_getClass("NSObject");
    Class MyButtonHandler = ObjC_allocateClassPair(NSObject, "MyButtonHandler", 0);
    ObjC_classAddMethod(MyButtonHandler, ObjC_selRegisterName("buttonClicked:"), (IMP)buttonClicked, "v@:@");
    ObjC_registerClassPair(MyButtonHandler);
    id delegate = ((id (*)(id, SEL)) objc_msgSend)((id)MyButtonHandler, ObjC_selRegisterName("new"));
    NSButton_setTarget(button, delegate);
    NSButton_setAction(button, ObjC_selRegisterName("buttonClicked:"));

    id contentView = NSWindow_contentView(window);
    NSView_addSubview(contentView, button);

    NSApplication_run(app);

    NSAutoreleasePool_drain(pool);
    return 0;
}
