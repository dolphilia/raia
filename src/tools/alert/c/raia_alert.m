// Windows
// gcc -O2 -o raia_alert -mwindows raia_alert.c
//
// Linux
// gcc -O2 -o raia_alert `pkg-config --cflags --libs gtk+-3.0` raia_alert.c

#include <unistd.h>
#include <getopt.h>
#import <Cocoa/Cocoa.h>

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

// 次のエラーが発生しました
//
// - タイプ: ファイルが見つからない
//   - 問題の箇所: ファイル名
// - スタックトレース: (なし)
// - ソースファイル名: raia_xxx
// - 関数: xxx()
// - 行: 000
// - 時刻: 00:00:00
// - ライブラリ: raia_xxx
// - リポジトリ: https://github.com/raia-engine/

typedef enum {
    ERROR_FILE_NOT_FOUND,
    ERROR_INVALID_INPUT,
    // ... other error codes
} ERROR_CODE;

typedef enum {
    JA,
    EN,
} USER_LANG;

#include <time.h>
void report_error(const char *msg, const char *file, int line, const char *func) {
    time_t t = time(NULL);
    char *time_str = ctime(&t);
    if (time_str) {
        time_str[strlen(time_str) - 1] = '\0'; // Remove newline character
    } else {
        time_str = "unknown time";
    }

    fprintf(stderr, "[%s] Error in function '%s' at %s:%d: %s\n", time_str, func, file, line, msg);
    if (errno != 0) {
        fprintf(stderr, "System error message: %s\n", strerror(errno));
    }
}

#define REPORT_ERROR(msg)                                  \
do {                                                       \
    report_error(msg, __FILE__, __LINE__, __func__);       \
} while(0) \
;

RAIA_EXPORT void raia_alert_show(const char *caption, const char *text) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setMessageText:[NSString stringWithUTF8String:caption]];
        [alert setInformativeText:[NSString stringWithUTF8String:text]];
        [alert addButtonWithTitle:@"OK"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [app activateIgnoringOtherApps:YES];
        [alert runModal];
        [app terminate:nil];
    }
}

int main(int argc, const char * argv[]) {
    int c;
    char *caption = "Unset caption";
    char *text = "Error with no clarification specified.";
    struct option longopts[] = {
            {"caption", required_argument, 0, 'c'},
            {"text", required_argument, 0, 't'},
            {0, 0, 0, 0}
    };
    while((c = getopt_long(argc, argv, "c:t:", longopts, NULL)) != -1) {
        switch(c) {
            case 'c':
                caption = optarg;
                break;
            case 't':
                text = optarg;
                break;
            default:
                caption = "unknown args";
                text = "Unknown command line argument specified.";
                break;
        }
    }
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setMessageText:[NSString stringWithUTF8String:caption]];
        [alert setInformativeText:[NSString stringWithUTF8String:text]];
        [alert addButtonWithTitle:@"OK"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [app activateIgnoringOtherApps:YES];
        [alert runModal];
        [app terminate:nil];
    }
    return 1;
}

// Windows
// gcc -O2 -o raia_alert -mwindows raia_alert.c
//
// Linux
// gcc -O2 -o raia_alert `pkg-config --cflags --libs gtk+-3.0` raia_alert.c
//
//#ifdef _WIN32
//#include <windows.h>
//#else
//#include <gtk/gtk.h>
//#endif
//int main(int argc, char *argv[]) {
//    int c;
//    char *caption = "Unset caption";
//    char *text = "Error with no clarification specified.";
//    struct option longopts[] = {
//        {"caption", required_argument, 0, 'c'},
//        {"text", required_argument, 0, 't'},
//        {0, 0, 0, 0}
//    };
//
//    while((c = getopt_long(argc, argv, "c:t:", longopts, NULL)) != -1) {
//        switch(c) {
//            case 'c':
//                caption = optarg;
//                break;
//            case 't':
//                text = optarg;
//                break;
//            default:
//                caption = "unknown args";
//                text = "Unknown command line argument specified.";
//                break;
//        }
//    }
//
//#ifdef _WIN32
//    MessageBox(NULL, text, caption, MB_OK);
//#elif __APPLE__
//    NSAlert *alert = [[NSAlert alloc] init];
//    [alert addButtonWithTitle:@"OK"];
//    [alert setMessageText:[NSString stringWithUTF8String:caption]];
//    [alert setInformativeText:[NSString stringWithUTF8String:text]];
//    [alert setAlertStyle:NSWarningAlertStyle];
//    [alert runModal];
//#else
//    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", text);
//    gtk_window_set_title(GTK_WINDOW(dialog), caption);
//    gtk_dialog_run(GTK_DIALOG(dialog));
//    gtk_widget_destroy(dialog);
//#endif
//
//    return EXIT_SUCCESS;
//}