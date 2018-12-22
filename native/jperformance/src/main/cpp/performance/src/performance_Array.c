/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

#include <string.h>

#include "performance_Array.h"

inline static void checkArray(JNIEnv* env, jlongArray array, jint index)
{
  jsize size = (*env)->GetArrayLength(env, array);

  if(index >= size)
  {
    jclass oobe = (*env)->FindClass(env,
        "java/lang/ArrayIndexOutOfBoundsException");
    (*env)->ThrowNew(env, oobe, "Out of bounds!");
    return;
  }
}

JNIEXPORT jlong JNICALL Java_performance_Array_getElement
  (JNIEnv* env, jobject thiz, jlongArray array, jint index)
{
  jboolean is_copy = JNI_FALSE;
  jlong ret = 0;
  jlong* native_array = NULL;

  checkArray(env, array, index);
  if((*env)->ExceptionCheck(env))
  {
    return 0;
  }

  native_array = (*env)->GetLongArrayElements(env, array, &is_copy);
  if((*env)->ExceptionCheck(env))
  {
    return 0;
  }

  ret = native_array[index];
  (*env)->ReleaseLongArrayElements(env, array, native_array, 0);

  return ret;
}

JNIEXPORT void JNICALL Java_performance_Array_setElement
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jlong val)
{
  jboolean is_copy = JNI_FALSE;
  jlong ret = 0;
  jlong* native_array = NULL;

  checkArray(env, array, index);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  native_array = (*env)->GetLongArrayElements(env, array, &is_copy);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  native_array[index] = val;
  (*env)->ReleaseLongArrayElements(env, array, native_array, 0);
}

JNIEXPORT void JNICALL Java_performance_Array_setElements
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jint nb)
{
  jboolean is_copy = JNI_FALSE;
  jlong ret = 0;
  jlong* native_array = NULL;
  jlong tab[1024];

  checkArray(env, array, index);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  native_array = (*env)->GetLongArrayElements(env, array, &is_copy);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }

  memcpy(&native_array[index], tab, sizeof(jlong) * nb);
  (*env)->ReleaseLongArrayElements(env, array, native_array, 0);
}

JNIEXPORT jlong JNICALL Java_performance_Array_getElementWithRegion
  (JNIEnv* env, jobject thiz, jlongArray array, jint index)
{
  jlong ret = 0;

  (*env)->GetLongArrayRegion(env, array, index, 1, &ret);
  if((*env)->ExceptionCheck(env))
  {
    return 0;
  }

  return ret;
}

JNIEXPORT void JNICALL Java_performance_Array_setElementWithRegion
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jlong val)
{
  (*env)->SetLongArrayRegion(env, array, index, 1, &val);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }
}

JNIEXPORT void JNICALL Java_performance_Array_setElementsWithRegion
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jint nb)
{
  jlong tab[1024];

  (*env)->SetLongArrayRegion(env, array, index, nb, tab);
  if((*env)->ExceptionCheck(env))
  {
    return;
  }
}

JNIEXPORT jlong JNICALL Java_performance_Array_getElementWithCritical
  (JNIEnv* env, jobject thiz, jlongArray array, jint index)
{
  jlong ret = 0;
  jbyte* native_array = NULL;

  native_array = (*env)->GetPrimitiveArrayCritical(env, array, NULL);
  if(!native_array)
  {
    return 0;
  }

  memcpy(&ret, &native_array[index], sizeof(jlong));
  //ret = *(jlong*)&native_array[index];
  (*env)->ReleasePrimitiveArrayCritical(env, array, native_array, 0);

  return ret;
}

JNIEXPORT void JNICALL Java_performance_Array_setElementWithCritical
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jlong val)
{
  jbyte* native_array = NULL;

  native_array = (*env)->GetPrimitiveArrayCritical(env, array, NULL);
  if(!native_array)
  {
    return;
  }

  memcpy(&native_array[index], &val, sizeof(jlong));
  //*((jlong*)&native_array[index]) = val;
  (*env)->ReleasePrimitiveArrayCritical(env, array, native_array, 0);
}

JNIEXPORT void JNICALL Java_performance_Array_setElementsWithCritical
  (JNIEnv* env, jobject thiz, jlongArray array, jint index, jint nb)
{
  jbyte* native_array = NULL;
  jlong tab[1024] = {1, 2, 3, 4, 5, 6};

  native_array = (*env)->GetPrimitiveArrayCritical(env, array, NULL);
  if(!native_array)
  {
    return;
  }

  memcpy(&native_array[index], tab, sizeof(jlong) * nb);

  (*env)->ReleasePrimitiveArrayCritical(env, array, native_array, 0);
}

JNIEXPORT void JNICALL Java_performance_Array_doWork
  (JNIEnv* env, jobject thiz, jobjectArray array)
{
  jint size = (*env)->GetArrayLength(env, array);

  for(jint i = 0 ; i < size ; i++)
  {
    jobject s = (*env)->GetObjectArrayElement(env, array, i);
    const char* str;

    if((*env)->ExceptionCheck(env))
    {
      break;
    }

    str = (*env)->GetStringUTFChars(env, (jstring)s, NULL);
    printf("Index=%d value=%s\n", i, str);
    (*env)->ReleaseStringUTFChars(env, s, str);
  }
}

JNIEXPORT void JNICALL Java_performance_Array_doWorkWithDeleteLocalReference
  (JNIEnv* env, jobject thiz, jobjectArray array)
{
  jint size = (*env)->GetArrayLength(env, array);

  for(jint i = 0 ; i < size ; i++)
  {
    jobject s = (*env)->GetObjectArrayElement(env, array, i);
    const char* str;

    if((*env)->ExceptionCheck(env))
    {
      break;
    }

    str = (*env)->GetStringUTFChars(env, (jstring)s, NULL);
    printf("Index=%d value=%s\n", i, str);
    (*env)->ReleaseStringUTFChars(env, s, str);

    /* delete reference */
    (*env)->DeleteLocalRef(env, s);
  }
}

JNIEXPORT void JNICALL Java_performance_Array_doWorkWithEnsureLocalCapacity
  (JNIEnv* env, jobject thiz, jobjectArray array)
{
  jint size = (*env)->GetArrayLength(env, array);

  /* be sure to have at least 128 references per native */
  (*env)->EnsureLocalCapacity(env, 128);

  for(jint i = 0 ; i < size ; i++)
  {
    const char* str;
    jobject s = (*env)->GetObjectArrayElement(env, array, i);

    if((*env)->ExceptionCheck(env))
    {
      break;
    }

    str = (*env)->GetStringUTFChars(env, (jstring)s, NULL);
    printf("Index=%d value=%s\n", i, str);
    (*env)->ReleaseStringUTFChars(env, s, str);
  }
}

