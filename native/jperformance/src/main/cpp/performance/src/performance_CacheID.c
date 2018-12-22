/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

#include "performance_CacheID.h"

/**
 * \brief JNI version needed.
 */
static const jint JNI_VERSION = JNI_VERSION_1_8;

static jclass CacheID = NULL;
static jmethodID CacheID_callStaticMethod = 0;
static jfieldID CacheID_val1 = 0;
static jfieldID CacheID_val2 = 0;
static jfieldID CacheID_val3 = 0;
static jfieldID CacheID_val4 = 0;
static jfieldID CacheID_val5 = 0;
static jfieldID CacheID_val6 = 0;

JNIEXPORT void JNICALL Java_performance_CacheID_callStaticMethod
  (JNIEnv* env, jclass clazz, jint val)
{
  jclass cls = (*env)->FindClass(env, "performance/CacheID");
  jmethodID method = 0;

  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  method = (*env)->GetStaticMethodID(env, cls, "printVal", "(I)V");

  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  (*env)->CallStaticVoidMethod(env, clazz, method, val);

  if((*env)->ExceptionCheck(env))
  {
    return;
  }
}

JNIEXPORT void JNICALL Java_performance_CacheID_callStaticMethodWithCache
  (JNIEnv* env, jclass clazz, jint val)
{
  (*env)->CallStaticVoidMethod(env, clazz, CacheID_callStaticMethod, val);

  if((*env)->ExceptionCheck(env))
  {
    return;
  }
}

JNIEXPORT jint JNICALL Java_performance_CacheID_callSum
  (JNIEnv* env, jobject thiz)
{
  jclass clazz = (*env)->GetObjectClass(env, thiz);
  jfieldID val1 = (*env)->GetFieldID(env, clazz, "val1", "I");
  jfieldID val2 = (*env)->GetFieldID(env, clazz, "val2", "I");
  jfieldID val3 = (*env)->GetFieldID(env, clazz, "val3", "I");
  jfieldID val4 = (*env)->GetFieldID(env, clazz, "val4", "I");
  jfieldID val5 = (*env)->GetFieldID(env, clazz, "val5", "I");
  jfieldID val6 = (*env)->GetFieldID(env, clazz, "val6", "I");
  jint ret = 0;

  ret += (*env)->GetIntField(env, thiz, val1);
  ret += (*env)->GetIntField(env, thiz, val1);
  ret += (*env)->GetIntField(env, thiz, val2);
  ret += (*env)->GetIntField(env, thiz, val3);
  ret += (*env)->GetIntField(env, thiz, val4);
  ret += (*env)->GetIntField(env, thiz, val5);
  ret += (*env)->GetIntField(env, thiz, val6);

  return ret;
}

JNIEXPORT jint JNICALL Java_performance_CacheID_callSumWithCache
  (JNIEnv* env, jobject thiz)
{
  jint ret = 0;

  ret += (*env)->GetIntField(env, thiz, CacheID_val1);
  ret += (*env)->GetIntField(env, thiz, CacheID_val2);
  ret += (*env)->GetIntField(env, thiz, CacheID_val3);
  ret += (*env)->GetIntField(env, thiz, CacheID_val4);
  ret += (*env)->GetIntField(env, thiz, CacheID_val5);
  ret += (*env)->GetIntField(env, thiz, CacheID_val6);

  return ret;
}

JNIEXPORT jint JNICALL Java_performance_CacheID_callSumPrimitive
  (JNIEnv* env, jobject thiz, jint val1, jint val2, jint val3, jint val4,
   jint val5, jint val6)
{
  return val1 + val2 + val3 + val4 + val5 + val6;
}

jint JNI_OnLoad(JavaVM* jvm, void* reserved)
{
  JNIEnv* env = NULL;

  (void)reserved;

  if((*jvm)->GetEnv(jvm, (void**)&env, JNI_VERSION) != JNI_OK)
  {
    return JNI_ERR;
  }

  /* assign class cache */
  jclass tmpLocalClass = (*env)->FindClass(env, "performance/CacheID");
  CacheID = (*env)->NewGlobalRef(env, tmpLocalClass);
  (*env)->DeleteLocalRef(env, tmpLocalClass);

  CacheID_callStaticMethod = (*env)->GetStaticMethodID(env, CacheID, "printVal",
      "(I)V");

  CacheID_val1 = (*env)->GetFieldID(env, CacheID, "val1", "I");
  CacheID_val2 = (*env)->GetFieldID(env, CacheID, "val2", "I");
  CacheID_val3 = (*env)->GetFieldID(env, CacheID, "val3", "I");
  CacheID_val4 = (*env)->GetFieldID(env, CacheID, "val4", "I");
  CacheID_val5 = (*env)->GetFieldID(env, CacheID, "val5", "I");
  CacheID_val6 = (*env)->GetFieldID(env, CacheID, "val6", "I");

  return JNI_VERSION;
}

void JNI_OnUnload(JavaVM* jvm, void* reserved)
{
  JNIEnv* env = NULL;

  (void)reserved;

  (*jvm)->GetEnv(jvm, (void**)env, JNI_VERSION);

  /* removes global ref */
  (*env)->DeleteGlobalRef(env, CacheID);
}

