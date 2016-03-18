#include <jni.h>
#include "Helper.h"
#include "../../cpp/public/Hellolib.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_sayHello__JLjava_lang_String_2(JNIEnv *env, jclass type,
                                                                           jlong holderPtr,
                                                                           jstring name_);

JNIEXPORT jlong JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_createNativeInstance(JNIEnv *env, jclass type,
                                                                 jobject helloLib);

JNIEXPORT void JNICALL
Java_nicolas_guillot_hellocpp_core_HelloLib_destroy(JNIEnv *env, jclass type,
                                                    jlong holderPtr);

#ifdef __cplusplus
}
#endif
