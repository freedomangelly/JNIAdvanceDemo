package com.example.jniadvancedemo.JniUse;

/**
 * description:
 * author: freed on 2019/7/9
 * email: 674919909@qq.com
 * version: 1.0
 */
public class Struct {
    static {
        System.loadLibrary("struct-lib");
    }

    public native String StructToString();

    public native String StructToDefind();

    public native String StructToNest();

    public native String StructMemory();


    public native int StructSize();

    public native String unionToString();
}
