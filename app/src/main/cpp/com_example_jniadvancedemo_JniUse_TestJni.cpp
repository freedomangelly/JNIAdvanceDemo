#include <jni.h>
#include <string>
#include<android/log.h>
#include "com_example_jniadvancedemo_JniUse_TestJni.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

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

//动态开辟内存
void dynamiclloc(){
    int* arr = (int*)malloc(1 * 1024 * 1024 * sizeof(int)); // 40M

    // 第二个重要的方法，手动释放 free , 释放arr这一块内存
    free(arr);
}
/*
 * 动态开辟内存
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    clloc
 * Signature: ()V
 */

JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_clloc
        (JNIEnv *env, jobject object,jint nums, jintArray arrays){

    jint *body=env->GetIntArrayElements(arrays, NULL);
    // int arr[10 * 1024 * 1024];

    // 假设我们现在需要接收用户所输入的数，然后进行排序
    int num;
    // 获取用户输入的值
    num=nums;
    LOGI("请输入数的个数：%d",num);
    // 定义一个数组来存放用户的数据
    // int arr[num]; 静态开辟，内存大小不能改变
    int* arr = (int*)malloc(sizeof(int)*num);

    // for 循环接收
    int i = 0;
    int print_num;
    for (; i < num;i++){
        print_num = body[i];
        arr[i] = print_num;// arr[i] = *(arr+i)
        LOGI("请输入第%d个的值：%d",i,arr[i]);
        printf("%d, %p\n", *(arr + i), arr + i);
    }

    // 排序 堆排序（4个小时），快排序
    free(arr);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    cllocSize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_cllocSize
        (JNIEnv * env, jobject object, jint num1, jint num2){
        int num;
        num=num1;
        int* arr = (int*)(malloc(sizeof(int) * num));
        int i=0;
        int print_num;
        for (;i<num;i++){
            arr[i]=i;
        }
        LOGI("开辟内存的指针：%p\n",arr);
        LOGI("请输入新增的个数");
        int new_num;
        new_num=num2;
        int* new_arr = (int*)realloc(arr, sizeof(int)*(num+new_num));
        if(new_arr){
            i=new_num;

        for(;i<(num+new_num);i++){
            arr[i]=i;
        }
        LOGI("新开辟内存的指针：%p\n",new_arr);
        i=0;
        for(;i<num+new_num;i++){
            LOGI("%d,%p\n",*(arr +i),arr+i);
        }
        }
        if(new_arr){
            free(new_arr);
            new_arr = NULL;
        }else{
            free(arr);
        }

}

// 监听数据压缩回调
void call_back(int current,int total){
    printf("压缩的进度是：%d/%d",current,total);
}

// 这个方法 3 ，他是一个额外的文件了
void compress(char* file_name,void(*callback)(int,int)){
    callback(12,24);
}

JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_compress
        (JNIEnv *env, jobject object,jstring str){
    void(*call)(int, int);// 声明了一个函数
    call = call_back;// 给函数指针赋值

    // call(1,2);// 通过函数指针间接的调用call_back
    compress("str", call);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    charTest
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_charTest
        (JNIEnv *env, jobject object){
    char str[] = {'D','a','r','r','e','n','\0'};
    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_charTest str=%c",str);
    str[2]='y';
    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_charTest str=%c",str);
    char *str1 = "Darren";
    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_charTest str=%c",str1);
    str1[2]='y';
    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_charTest str=%c",str1);
}

int strlen_(char *str){
    // 怎么获取字符串的长度？ 不断读取字符，判断末尾 '\0'

    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    charLength
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_charLength
        (JNIEnv *env, jobject object){
    char *name = "Darren is";

    char str[] = { 'D', 'a', 'r', 'r', 'e', 'n', '\0','i','s' };
    LOGI("name length is %d\n", strlen(str));
    LOGI("name length is %d", strlen_(str));
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    charChange
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_charChange
        (JNIEnv *, jobject){
     char * num = "1"; //-> int float double
     char *num_str = "12.0xxx";

     int number = atoi(num_str);// 如果不能转换就是 0 ，后面如果有其他不是数字的就会被剔除 12xxx -> 12

     char *num_str2 = "12.5f";
     float number2 = atof(num_str2);// 如果不能转换返回的是默认值 0.000000

    char *num_str3 = "12.5xx";
    double number3 = strtod(num_str3, NULL);

    LOGI("number is %c",number);
    LOGI("number2 is %f",number2);
    LOGI("number3 is %lf",number3);
}
char * substr(char * str,int start,int end){

    // 开辟一个字符串去存储我们的数据，开辟多大计算
    // char sub[end-start];
    int len = end - start;
    char* sub = (char*)malloc(len*sizeof(char)+1);// 记得加上1 ，在 NDK 一般会采用静态的数组存储 char sub[len]
    // malloc 一定要 free

    // 遍历赋值
    str += start;
    for (int i = 0; i < len; i++)
    {
        sub[i] = *str;
        str++;// 指针往后逻一位
    }
    // 标记字符串结尾，否则 print 无法判断结尾
    sub[len] = '\0';

    printf("%p\n",sub);

    // free(sub);

    return sub;
}
/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    charEquals
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT jboolean JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_charEquals
        (JNIEnv *env, jobject object, jstring str1, jstring str2){
    char* char1=(char*)env->GetStringUTFChars(str1, NULL);
    char* char2=(char*)env->GetStringUTFChars(str2,NULL);

     int rc = strcmp(char1, char2);// 比较方法 区分大小写比较
    char* rc2 = strstr(char1,char2);//包含方法
    if(rc2){
        //包含
    } else{
        //不包含
    }
    int i=strlen(char1);//长度
    char cpy[20];
    strcpy(cpy, char1);//拷贝
    strcat(cpy,char1);//拼接
    tolower(*char1);//大写转小写
    toupper(*char1);//小写转大写
//     int rc = _strcmpi(str1, str2);// c strcmpi c++ _strcmpi , andrroid ndk strcasecmp
    LOGI("Java_com_example_jniadvancedemo_JniUse_TestJni_charEquals %s,%s,isEquals=%d",char1,char2,rc);
    return rc==0;
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    copyFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_copyFile
        (JNIEnv *env, jobject object, jstring src, jstring dest){
    char* srcFile = const_cast<char *>(env->GetStringUTFChars(src, NULL));
    char* destFile = const_cast<char *>(env->GetStringUTFChars(dest, NULL));

    FILE *file=fopen(srcFile,"rb");
    FILE *file_copy=fopen(destFile,"wb");

    if(!file || !file_copy){
        //文件打开失败
        return false;
    }
    int buffer[1024];
    int len;
    LOGI("buffer size=%d", sizeof(buffer));
    while ((len=fread(buffer, sizeof(int),len,file_copy))){
        fwrite(buffer, sizeof(int),len,file_copy);
    }
    //加密解密用的语法
//    while ((c = fgetc(file)) != EOF){
//        fputc(c ^ 5, file_decrpy);
//    }
    fclose(file);
    fclose(file_copy);
    return true;

}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    getFileSize
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jlong JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_getFileSize
        (JNIEnv *env, jobject object, jstring filePath){
    char* filename= const_cast<char *>(env->GetStringUTFChars(filePath, NULL));
    FILE *file = fopen(filename,"rb");

    if(!file){
        return 0;
    }
    // 没有一个函数是可以直接拿文件大小
    // 思路：将文件的指针移动到最后，然后再去计算偏移量
    // 三个参数  SEEK_SET（开头）, SEEK_CUR（当前）, SEEK_END（移动到最后）
    fseek(file,0,SEEK_END);
    // 计算偏移的位置,ftell 从 0 开始统计到当前（SEEK_END）
    long file_size = ftell(file);
    LOGI("%s文件大小%d",filename,file_size);
    fclose(file);
    return file_size;
}

int getFileSize(char* fileName){
    FILE* file = fopen(fileName,"rb");

    if (!file){
        return 0;
    }

    fseek(file,0,SEEK_END);
    int file_size = ftell(file);

    fclose(file);

    return file_size;
}

char* addCharToPath(char* filename,int addchar){
    LOGI("filename1=%s",filename);
    char* c=strrchr(filename,'.');//.jpg
    LOGI("filename2=%s",c);
    char* d=substr(filename,0,strlen_(filename)-strlen_(c));
    LOGI("filename3=%s",d);
//    strcat(d,addchar);
////    strcat(d,c);
//    sprintf(d,"%d",addchar);
//    sprintf(d,"%s",c);
    LOGI("filename4=%s",d);
}

/*
 * Class:     com_example_jniadvancedemo_JniUse_TestJni
 * Method:    spiteFileWrite
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_example_jniadvancedemo_JniUse_TestJni_spiteFileWrite
        (JNIEnv *env, jobject object, jstring str, jint spilt){
    char* filename = (char*)(env->GetStringUTFChars(str, NULL));
    FILE* file = fopen(filename,"rb");
    int file_size=getFileSize(filename);
    int file_number=spilt;
    char** file_names = (char**)malloc(sizeof(char*)*file_number);
    int preFileSize = file_size / file_number;
    // 进行复制
    int i = 0;
    for (; i < 3; i++)
    {
        file_names[i] = (char*)malloc(sizeof(char)*100);// '\0'
//        sprintf(file_names[i], addCharToPath(*file_names,i));

        printf("%s\n", file_names[i]);
    }

    i = 0;
    for (; i < file_number; i++)
    {
        // 从源文件中往切割文件写入数据
        FILE* cur_file = fopen(file_names[i],"wb");

        // 写多少？
        int start = i*preFileSize;
        int end = (i + 1)*preFileSize;
        if (i == file_number - 1){
            end = file_size;
        }

        // 第一个循环 file 读，第二个循环还是从 file 里面
        for (int j = start; j < end; j++)
        {
            // 从file 里面读，写如到 cur_file
            fputc(fgetc(file),cur_file);
        }

        fclose(cur_file);
        free(file_names[i]);
    }

    fclose(file);
    free(file_names);
}

