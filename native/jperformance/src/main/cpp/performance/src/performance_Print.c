/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

#include <stdio.h>

#include "performance_Print.h"

JNIEXPORT void JNICALL Java_performance_Print_printHello
  (JNIEnv* env, jobject thiz)
{
  (void)env;
  (void)thiz;

  fprintf(stdout, "Hello world\n");
  fflush(stdout);
}

