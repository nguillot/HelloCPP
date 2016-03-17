//
// Created by Nicolas Guillot on 07/01/2016.
//

#ifndef CROSSPLATFORMMOBILEAPP_HELPER_H
#define CROSSPLATFORMMOBILEAPP_HELPER_H

#include <jni.h>

#include <string>

class Helper {
public:
    Helper(JavaVM *vm);

    ~Helper();

    /** Return a pointer to the current JNI environment, attach thread if required. */
    JNIEnv *getEnv() const;

    // --------------------------------------------------------------------------------
    // String object conversions

    /** Convert given Java string to the equivalent STL string. */
    std::u16string fromJavaString(JNIEnv *env, jstring in) const;

    /** Convert given STL string to the equivalent Java string. */
    jstring toJavaString(JNIEnv *env, const std::u16string &in) const;

private:
    JavaVM *vm;
};

/** Global helper class (created during JNI_OnLoad, destroyed during JNI_OnUnLoad). */
extern Helper *helper;

#endif //CROSSPLATFORMMOBILEAPP_HELPER_H
