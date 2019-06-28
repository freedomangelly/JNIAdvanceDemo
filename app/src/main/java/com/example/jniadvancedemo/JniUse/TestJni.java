package com.example.jniadvancedemo.JniUse;

/**
 * description:
 * author: freed on 2019/6/22
 * email: 674919909@qq.com
 * version: 1.0
 */
public class TestJni {
    static {
        System.loadLibrary("native-lib");
    }
    public native String stringFromJNI();
    public static native String stringFromJNI2();
    public  native int sum(int i,int j);

    public native Employee getEmployee(String name,double salary);
    public native String employeePrint(String name,double salary);

    public native void bastTypeLog();

    public native void random();

    /***/
    public native void clloc(int number ,int[] numbers);

    public native void cllocSize(int num1,int num2);

    public native void compress(String filePath);
    public native void charTest();
    public native void charLength();
    public native void charChange();
    public native boolean charEquals(String text1,String text2);
}
