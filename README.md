# Project goal

Attempt to use the Android Studio CPP debug support with two kind of project:
 
* A standalone application (branch without_library)
* An application using an Android library (branch use_android_library)

## Attempts

* Declare an ndk section into the library's *build.gradle* file, put the CPP files into the library's JNI folder and the Java files into the library's java folder (commit 1931a50)
    * The application run without the debug support
* Use an external build system and move the libraries on the *app/src/main/jniLibs** directory (commit 75f1e98) 
    * The application run without the debug support: we can see the CPP stack trace but not the CPP variables
* Compile the CPP library with Gradle and move them on the *app/src/main/jniLibs** directory 
    * The application run without the debug support: we can see the CPP stack trace but not the CPP variables        
* move the ndk section of the library to the app module (commit 7e27e64)
    * The application run and the debug support is available. But it can be cumbersome on a large project with multiple library, we will have duplicate JNI_onLoad methods.
