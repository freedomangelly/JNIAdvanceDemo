package com.example.jniadvancedemo.JniUse;

/**
 * description:
 * author: freed on 2019/6/22
 * email: 674919909@qq.com
 * version: 1.0
 */
public class Employee {
    private String name;
    private double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }
    public String print(){
        StringBuffer sb=new StringBuffer();
        sb.append(name);
        sb.append(" ");
        sb.append(salary);
        return sb.toString();
    }

}
