#include <jni.h>
#include <string>
#include<android/log.h>
#include "com_example_jniadvancedemo_JniUse_Struct.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
    struct  Worker{  // 定义一个结构体，相当于 java 的 class
        char name[10];
        int age;
        double salary;
    };
// 第二种方式，可以直接取名字
    struct  Worker2{
        char name[10];
        int age;
        double salary;
    } liuy={"liuy",100,1000};// 这种方式会有一个默认初始值
/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    StructToString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_StructToString
  (JNIEnv *env, jobject jobject){
    struct Worker worker;// 初始化 , 没有初始化的情况下，那么里面所有的属性都是没有初始值的
    //赋值
    worker.age=20;
    worker.salary=1000;
    char* t="jackkkk";
    strcpy(worker.name,"jack");

    char temp[1024]= {0};
    sprintf(temp,"worker age=%d,salary=%lf,name=%s",worker.age,worker.salary,worker.name);
    LOGI("%s",temp);
    return env->NewStringUTF(temp);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    StructToDefind
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_StructToDefind
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    StructToNest
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_StructToNest
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    StructMemory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_StructMemory
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    StructSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_StructSize
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jniadvancedemo_JniUse_Struct
 * Method:    unionToString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_Struct_unionToString
  (JNIEnv *, jobject){

}

