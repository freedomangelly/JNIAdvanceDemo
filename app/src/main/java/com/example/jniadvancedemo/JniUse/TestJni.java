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
}
