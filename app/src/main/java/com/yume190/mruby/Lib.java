package com.yume190.mruby;

public class Lib {
//    public native int add(int a, int b);
    public static native Byte[] compile(String code, boolean remove_lv) throws Exception;
    static {
        System.loadLibrary("mruby");
    }
}
