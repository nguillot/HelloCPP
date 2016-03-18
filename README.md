# Project goal

Attempt to use the Android Studio CPP debug support with two kind of project:
 
* A standalone application (branch without_library)
* An application using an Android library (branch use_android_library)

## Attempts

1. Declare an ndk section into the library's *build.gradle* file, put the CPP files into the library's JNI folder and the Java files into the library's java folder (commit 1931a50)
    * The application run without the debug support
2. Use an external build system and move the libraries on the *app/src/main/jniLibs** directory (commit 75f1e98) 
    * The application run without the debug support: we can see the CPP stack trace but not the CPP variables      
3. Move the ndk section of the library to the app module (commit 7e27e64)
    * The application run and the debug support is available. But it can be cumbersome on a large project with multiple library, we will have duplicate JNI_onLoad methods.
5. On the library side, provide the headers. And on the application side link the native dependencies through *source.main.jni.dependencies* as explain the the [NDK Dependencies](http://tools.android.com/tech-docs/new-build-system/gradle-experimental#TOC-NDK-Dependencies) section (commit c517f95)
    * The application run and the debug support is available.
