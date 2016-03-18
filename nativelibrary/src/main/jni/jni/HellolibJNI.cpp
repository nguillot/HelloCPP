#include <jni.h>
#include <memory>
#include "HellolibJNI.h"
#include "NativeHolder.h"

JNIEXPORT jstring JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_sayHello__JLjava_lang_String_2(JNIEnv *env, jclass type,
                                                                           jlong holderPtr,
                                                                           jstring name_) {
    auto holder = (NativeHolder *) holderPtr;
    if(holder == nullptr) {
        std::u16string empty = u"";
        return helper->toJavaString(env, empty);
    }
    auto nativeHelloLib = std::static_pointer_cast<Hellolib>(holder->helloLib);

    std::u16string result = nativeHelloLib->sayHello(helper->fromJavaString(env, name_));
    jstring javaResult = helper->toJavaString(env, result);

    return javaResult;
}

JNIEXPORT jlong JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_createNativeInstance(JNIEnv *env, jclass type,
                                                                 jobject helloLib) {

    auto nativeHelloLib = std::make_shared<Hellolib>();

    auto holder = new NativeHolder;
    holder->helloLib = nativeHelloLib;

    return (jlong) holder;
}

JNIEXPORT void JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_destroy(JNIEnv *env, jclass type,
                                                    jlong holderPtr) {
    auto holder = (NativeHolder *) holderPtr;
    if(holder != nullptr)
        delete(holder);
}
