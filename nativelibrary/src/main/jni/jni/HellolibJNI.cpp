#include <jni.h>
#include <memory>
#include "HellolibJNI.h"

JNIEXPORT jstring JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_sayHello__JLjava_lang_String_2(JNIEnv *env, jclass type,
                                                                           jlong nativeInstance,
                                                                           jstring name_) {
    auto *ptr = reinterpret_cast<Hellolib*>(static_cast<std::uintptr_t>(nativeInstance));
    if(ptr == nullptr) {
        std::u16string empty = u"";
        return helper->toJavaString(env, empty);
    }


    std::u16string result = ptr->sayHello(helper->fromJavaString(env, name_));
    jstring javaResult = helper->toJavaString(env, result);

    return javaResult;
}

JNIEXPORT jlong JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_createNativeInstance(JNIEnv *env, jclass type,
                                                                 jobject helloLib) {

    auto nativeHelloLib = std::unique_ptr<Hellolib>();

    jlong nativeInstanceHandle = reinterpret_cast<jlong>(nativeHelloLib.get());
    return nativeInstanceHandle;
}

JNIEXPORT void JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_destroy(JNIEnv *env, jclass type,
                                                    jlong nativeInstance) {

    auto *ptr = reinterpret_cast<Hellolib*>(static_cast<std::uintptr_t>(nativeInstance));
    if(ptr != nullptr)
        delete(ptr);
}
