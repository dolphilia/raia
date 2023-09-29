
//#include "jni.h"
//#include <cstdio>
//
//int main(int argc, char **argv) {
//    JavaVM *jvm;
//    JNIEnv *env;
//    JavaVMInitArgs vm_args;
//    JavaVMOption options[1];
//
//    options[0].optionString = "-Djava.class.path=."; // ここにクラスパスを設定
//    vm_args.version = JNI_VERSION_1_8;
//    vm_args.options = options;
//    vm_args.nOptions = 1;
//
//    jint res = JNI_CreateJavaVM(&jvm, (void **) &env, &vm_args);
//    if (res != JNI_OK) {
//        fprintf(stderr, "Failed to create JVM\n");
//        return 1;
//    }
//
//    jclass cls = (*env)->FindClass(env, "DialogCreator");
//    if (cls == NULL) {
//        fprintf(stderr, "Failed to find class\n");
//        return 1;
//    }
//
//    jmethodID mid = (*env)->GetStaticMethodID(env, cls, "showAlert", "()V");
//    if (mid == NULL) {
//        fprintf(stderr, "Failed to find method\n");
//        return 1;
//    }
//
//    (*env)->CallStaticVoidMethod(env, cls, mid);
//
//    (*jvm)->DestroyJavaVM(jvm);
//
//    return 0;
//}


//#include "jni.h"
//#include <iostream>
//
//int main() {
//    JavaVM *jvm;
//    JNIEnv *env;
//    JavaVMInitArgs vm_args;
//    JavaVMOption* options = new JavaVMOption[1];
//    options[0].optionString = "-Djava.class.path=.";
//
//    vm_args.version = JNI_VERSION_20;
//    vm_args.nOptions = 1;
//    vm_args.options = options;
//    vm_args.ignoreUnrecognized = JNI_TRUE;
//
//    jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
//    if (res != JNI_OK) {
//        std::cerr << "Failed to create JVM: " << res << "\n";
//        return 1;
//    }
//
//    jclass cls = env->FindClass("WindowCreator");
//    if (cls == nullptr) {
//        std::cerr << "Failed to find class\n";
//        return 1;
//    }
//
//    jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
//    if (mid == nullptr) {
//        std::cerr << "Failed to find method ID\n";
//        return 1;
//    }
//
//    jobjectArray args = env->NewObjectArray(0, env->FindClass("java/lang/String"), nullptr);
//    env->CallStaticVoidMethod(cls, mid, args);
//
//    if (env->ExceptionCheck()) {
//        std::cerr << "Java exception occurred\n";
//        env->ExceptionDescribe();
//        env->ExceptionClear();
//        return 1;
//    }
//
//    std::cin.get();
//
//    jvm->DestroyJavaVM();
//    return 0;
//}

//#include <iostream>
//#include "jni.h"
//#include <thread>
//#include <chrono>
//
//int main(int argc, char** argv) {
//    JavaVM* jvm;
//    JNIEnv* env;
//    JavaVMInitArgs vm_args;
//    JavaVMOption* options = new JavaVMOption[1];
//    options[0].optionString = "-Djava.class.path=.";
//    //options[1].optionString = "-Djava.home=/opt/homebrew/Cellar/openjdk/20.0.2/libexec/openjdk.jdk/Contents/Home";  // Replace with your JDK path
//
//    vm_args.version = JNI_VERSION_1_8;
//    vm_args.nOptions = 1;
//    vm_args.options = options;
//    vm_args.ignoreUnrecognized = false;
//
//    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
//    delete[] options;
//
//    jclass cls = env->FindClass("SwingWindow");
//    if(cls == nullptr) {
//        std::cerr << "ERROR: class not found !";
//    } else {
//        jmethodID mid = env->GetStaticMethodID(cls, "createWindow", "()V");
//        if(mid == nullptr) {
//            std::cerr << "ERROR: method not found !";
//        } else {
//            env->CallStaticVoidMethod(cls, mid);
//            if (env->ExceptionCheck()) {
//                env->ExceptionDescribe();
//                env->ExceptionClear();
//            }
//        }
//    }
//
//    std::this_thread::sleep_for(std::chrono::minutes(10));
//
//    jvm->DestroyJavaVM();
//
//    return 0;
//}

//#include <iostream>
//#include "jni.h"
//
//int main(int argc, char** argv) {
//    JavaVM* jvm;       // Pointer to the JVM (Java Virtual Machine)
//    JNIEnv* env;       // Pointer to native method interface
//    JavaVMInitArgs vm_args; // JVM launch parameters
//    JavaVMOption* options = new JavaVMOption[2]; // JVM options
//    options[0].optionString = "-Djava.class.path=."; // where to find java .class
//    options[1].optionString = "-Djava.home=/opt/homebrew/Cellar/openjdk/20.0.2/libexec/openjdk.jdk/Contents/Home";
//    vm_args.version = JNI_VERSION_20; // JDK version. This indicates version 1.6
//    vm_args.nOptions = 2;
//    vm_args.options = options;
//    vm_args.ignoreUnrecognized = false;
//
//    // Load and initialize a Java VM, return a JNI interface pointer in env
//    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
//    delete[] options;
//
//    // Find the class that contains the method you want to call
//    jclass cls = env->FindClass("HelloWorld");
//    if(cls == nullptr) {
//        std::cerr << "ERROR: class not found !";
//    } else {
//        // Obtain the method ID for that method
//        jmethodID mid = env->GetStaticMethodID(cls, "sayHello", "(Ljava/lang/String;)V");
//        if(mid == nullptr) {
//            std::cerr << "ERROR: method not found !";
//        } else {
//            // Create a string with the passed String
//            jstring jstr = env->NewStringUTF(" from C++");
//
//            // Call the static void sayHello(String) method
//            env->CallStaticVoidMethod(cls, mid, jstr);
//            if (env->ExceptionCheck()) {
//                env->ExceptionDescribe();
//                env->ExceptionClear();
//            }
//        }
//    }
//
//    // Destroy the Java VM and free the resources
//    jvm->DestroyJavaVM();
//
//    return 0;
//}


#include <iostream>
#include "jni.h"
#include <thread>
#include <chrono>

int main(int argc, char** argv) {
    JavaVM* jvm;       // Pointer to the JVM (Java Virtual Machine)
    JNIEnv* env;       // Pointer to native method interface
    JavaVMInitArgs vm_args; // JVM launch parameters
    JavaVMOption* options = new JavaVMOption[2]; // JVM options
    options[0].optionString = "-Djava.class.path=."; // where to find java .class
    options[1].optionString = "-Djava.home=/opt/homebrew/Cellar/openjdk/20.0.2/libexec/openjdk.jdk/Contents/Home";
    vm_args.version = JNI_VERSION_1_8; // JDK version. This indicates version 1.6
    vm_args.nOptions = 2;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;

    // Load and initialize a Java VM, return a JNI interface pointer in env
    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    delete[] options;

    // Find the class that contains the method you want to call
    jclass cls = env->FindClass("DialogCreator");
    if(cls == nullptr) {
        std::cerr << "ERROR: class not found !";
    } else {
        // Obtain the method ID for that method
        jmethodID mid = env->GetStaticMethodID(cls, "showAlert", "()V");
        if(mid == nullptr) {
            std::cerr << "ERROR: method not found !";
        } else {
            // Create a string with the passed String
            //jstring jstr = env->NewStringUTF(" from C++");

            // Call the static void sayHello(String) method
            env->CallStaticVoidMethod(cls, mid);
            if (env->ExceptionCheck()) {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds (10));
    std::cout << "End" << std::endl;

    // Destroy the Java VM and free the resources
    jvm->DestroyJavaVM();

    return 0;
}