package com.yume190.mruby

open class MRuby {

    companion object {
        @JvmStatic open external fun compile(code: String, remove_lv: Boolean): ByteArray

        init {
            System.loadLibrary("mruby")
        }
    }
}