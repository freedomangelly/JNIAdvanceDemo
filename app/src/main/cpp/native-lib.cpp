#include <jni.h>
#include <string>
#include "com_example_jniadvancedemo_JniUse_TestJni.h"
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_jniadvancedemo_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI
        (JNIEnv *env, jobject objece){
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    stringFromJNI2
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI2
        (JNIEnv *env, jclass clazz){
    std::string hello = "Hello static from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jint JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_sum
        (JNIEnv *env, jobject object, jint i, jint j){
    return i+j;
}

//
jobject getContruceEntity(JNIEnv *env, jstring name, jdouble salary){
    jclass clazz=env->FindClass("com/example/jniadvancedemo/JniUse/Employee");
    jmethodID  contruct=env->GetMethodID(clazz,"<init>","(Ljava/lang/String;D)V");
    jobject emp =env->NewObject(clazz,contruct,name,salary);
    return emp;
}

JNIEXPORT jobject JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_getEmployee
        (JNIEnv *env, jobject object, jstring name, jdouble salary){
    jobject emp =getContruceEntity(env,name,salary);
    return emp;
}

JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_employeePrint
        (JNIEnv *env, jobject object, jstring name, jdouble salary){
    jclass clazz=env->FindClass("com/example/jniadvancedemo/JniUse/Employee");
    jobject emp =getContruceEntity(env,name,salary);
    jmethodID  print=env->GetMethodID(clazz,"print", "()Ljava/lang/String;");
    jstring hello = (jstring)env->CallObjectMethod(emp,print);
    return hello;
}
