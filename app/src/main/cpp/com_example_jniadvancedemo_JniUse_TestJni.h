/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_jniadvancedemo_JniUse_TestJni */

#ifndef _Included_com_example_jniadvancedemo_JniUse_TestJni
#define _Included_com_example_jniadvancedemo_JniUse_TestJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    stringFromJNI2
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_stringFromJNI2
  (JNIEnv *, jclass);

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    sum
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_sum
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    getEmployee
 * Signature: (Ljava/lang/String;D)Lcom/example/jniadvancedemo/JniUse/Employee;
 */
JNIEXPORT jobject JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_getEmployee
  (JNIEnv *, jobject, jstring, jdouble);

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    employeePrint
 * Signature: (Ljava/lang/String;D)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_employeePrint
  (JNIEnv *, jobject, jstring, jdouble);

#ifdef __cplusplus
}
#endif
#endif