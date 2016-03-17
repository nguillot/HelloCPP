//
// Created by Nicolas Guillot on 07/01/2016.
//

#include "../public/Helper.h"

// Global native helper instance
Helper* helper = nullptr;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    helper = new Helper(vm);

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
    delete helper;
    helper = nullptr;
}

Helper::Helper(JavaVM* vm) : vm(vm) {}

JNIEnv *Helper::getEnv() const {
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) == JNI_EDETACHED) {
        vm->AttachCurrentThread(&env, nullptr);
    }
    return env;
}

std::u16string Helper::fromJavaString(JNIEnv* env, jstring in) const {
    auto length = env->GetStringLength(in);
    auto chars = env->GetStringChars(in, nullptr);
    auto out = std::u16string((const char16_t *) chars, length);
    env->ReleaseStringChars(in, chars);
    return out;
}

jstring Helper::toJavaString(JNIEnv* env, const std::u16string& in) const {
    return env->NewString((const jchar *) in.data(), in.length());
}

Helper::~Helper() {

}
