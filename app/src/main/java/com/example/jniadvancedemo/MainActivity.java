package com.example.jniadvancedemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.example.jniadvancedemo.JniUse.TestJni;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        TestJni jni=new TestJni();
//        tv.setText(TestJni.stringFromJNI2());
//        tv.setText(String.valueOf(jni.sum(100,99)));
//        tv.setText(jni.getEmployee("hhh",1000.00).print());
        tv.setText(jni.employeePrint("hhh",1000.00));
//        jni.bastTypeLog();
//        jni.random();
//        int[] ints=new int[]{1,2,3,4,5,6,7,8,9,0};
//        jni.clloc(ints.length,ints);
//        jni.cllocSize(10,20);
//        jni.charEquals("ba","ba");
        jni.spiteFileWrite("/mnt/sdcard/1.jpg",1);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

}
