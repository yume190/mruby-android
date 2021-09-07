//#include <mruby/mruby.h>

#ifdef MRB_NO_STDIO
# error mruby-bin-mrbc conflicts 'MRB_NO_STDIO' in your build configuration
#endif

#include <stdlib.h>
#include <string.h>
#include <mruby/compile.h>
#include <mruby/dump.h>
#include <mruby/proc.h>

void
mrb_init_mrblib(mrb_state *mrb)
{
}

#ifndef MRB_NO_GEMS
void
mrb_init_mrbgems(mrb_state *mrb)
{
}

void
mrb_final_mrbgems(mrb_state *mrb)
{
}
#endif

#include <jni.h>
#include <Android/Log.h>

#define LOGI(text) __android_log_write(ANDROID_LOG_INFO, "MRUBY", text)

//JNIEXPORT jint
//JNICALL
//Java_com_yume190_mruby_Lib_add(JNIEnv *env, jobject thiz, jint a, jint b) {
//    LOGI("123");
//    return a+b;
//}

JNIEXPORT jbyteArray JNICALL
Java_com_yume190_mruby_MRuby_compile(JNIEnv *env, jclass clazz, jstring code, jboolean remove_lv) {
    mrb_state *mrb = mrb_open();
    if (mrb == NULL) {
        LOGI("mrb_open fail");
        (*env)->ThrowNew(env, "java/lang/Exception", "mrb_open fail");
        return (*env)->NewByteArray(env, 0);
    }
    int n, result;

    mrbc_context *c = mrbc_context_new(mrb);
    c->no_exec = TRUE;

    jboolean isCopy = FALSE;
    char *_code = (*env)->GetStringUTFChars(env, code, &isCopy);
    LOGI(_code);
    mrb_value load = mrb_load_string_cxt(mrb, _code, c);
    if (mrb_nil_p(load)) {
        LOGI("load string fail");
        (*env)->ThrowNew(env, "java/lang/Exception", "load string fail");
        return (*env)->NewByteArray(env, 0);
    }

    uint8_t *bin = NULL;
    size_t bin_size = 0;
    struct RProc *proc = mrb_proc_ptr(load);
    if (proc == NULL) {
        LOGI("mrb_proc_ptr fail");
        (*env)->ThrowNew(env, "java/lang/Exception", "mrb_proc_ptr fail");
        return (*env)->NewByteArray(env, 0);
    }
    mrb_irep *irep = proc->body.irep;
    uint8_t flags = 0;

    if (remove_lv) {
        mrb_irep_remove_lv(mrb, irep);
    }
    result = mrb_dump_irep(mrb, irep, flags, &bin, &bin_size);
//    if (result == MRB_DUMP_OK) {
//    }

    jobjectArray array = (*env)->NewByteArray(env, bin_size);
    (*env)->SetByteArrayRegion(env, array, 0, bin_size, bin);

    mrb_free(mrb, bin);
    mrb_close(mrb);

    return array;
}
