#include <jni.h>
#include <string>
#include<android/log.h>
#include "com_example_jniadvancedemo_JniUse_TestJni.h"
#include <time.h>
#include <stdlib.h>

#define TAG "myDemo-jni" // 这个是自定义的LOG的标识

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_jniadvancedemo_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI
        (JNIEnv *env, jobject objece) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    stringFromJNI2
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI2
        (JNIEnv *env, jclass clazz) {
    std::string hello = "Hello static from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jint JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_sum
        (JNIEnv *env, jobject object, jint i, jint j) {
    return i + j;
}

//
jobject getContruceEntity(JNIEnv *env, jstring name, jdouble salary) {
    jclass clazz = env->FindClass("com/example/jniadvancedemo/JniUse/Employee");
    jmethodID contruct = env->GetMethodID(clazz, "<init>", "(Ljava/lang/String;D)V");
    jobject emp = env->NewObject(clazz, contruct, name, salary);
    return emp;
}

JNIEXPORT jobject JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_getEmployee
        (JNIEnv *env, jobject object, jstring name, jdouble salary) {
    jobject emp = getContruceEntity(env, name, salary);
    return emp;
}

JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_employeePrint
        (JNIEnv *env, jobject object, jstring name, jdouble salary) {
    jclass clazz = env->FindClass("com/example/jniadvancedemo/JniUse/Employee");
    jobject emp = getContruceEntity(env, name, salary);
    jmethodID print = env->GetMethodID(clazz, "print", "()Ljava/lang/String;");
    jstring hello = (jstring) env->CallObjectMethod(emp, print);
    return hello;
}

// 函数指针（回调）
void add(int num1, int num2) {
    LOGI("fun add mothod num1 + num2 = %d\n", (num1 + num2));
}

void mins(int num1, int num2) {
    LOGI("fun mins mothod num1 - num2 = %d\n", (num1 - num2));
}

// 方法指针，传两个数
void opreate(void(method)(int, int), int num1, int num2) {
    method(num1, num2);
}

JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_bastTypeLog
        (JNIEnv *env, jobject) {
    int i = 100;
    double d = 200;
    float f = 200;
    long l = 100;
    short s = 100;
    char c = 'D';
    // 字符串 char*

    // 输出打印 ,要用占位符
    LOGI("int i的值是：%d ,  int大小是：%d\n", i, sizeof(int));
    LOGI("double d的值是：%lf, double大小是：%d\n", d, sizeof(double));
    LOGI("float f的值是：%f, float大小是：%d\n", f, sizeof(float));
    LOGI("long l的值是：%ld, long大小是：%d\n", l, sizeof(long));
    LOGI("short s的值是：%d, short大小是：%d\n", s, sizeof(short));
    LOGI("char c的值是：%c , char大小是：%d\n", c, sizeof(char));

    opreate(add, 1, 2);
    opreate(mins, 1, 2);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    random
 * Signature: ()V
 * 在谭大神的指导下编写
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_random
        (JNIEnv *env, jobject){
    srand((unsigned)time(NULL));
    int i;
    int size=10;
    int arr[10];//静态开辟
    char str[10+1+100]={0};
//    char str[size];//最好不要用size开辟内存，这样不符合标准，初始化char右值最好{0}
    char tmp[10]={0};
    for (i = 0; i<size; i++){
        arr[i]=rand() % 1000;
        int randoms=arr[i];
        if(i==size-1){
            sprintf(tmp, "%d", randoms);
        } else{
            sprintf(tmp, "%d,", randoms);
        }
        LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_random %d\n", randoms);
        strcat(str, tmp);
        LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_random 11 %s==%s\n", str,tmp);
    }


    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_random!!! %s\n", str);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    clloc
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_clloc
        (JNIEnv *, jobject){

}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    cllocSize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_cllocSize
        (JNIEnv *, jobject){

}
