/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

package performance;

/**
 * Class that performs JNI calls to print stuff.
 *
 * @author Sebastien Vincent
 */
public class Print
{
    static
    {
        System.loadLibrary("jperformance");
    }

    /**
     * Print hello using JNI.
     */
    public native void printHello();
}

