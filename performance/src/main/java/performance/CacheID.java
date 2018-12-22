/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

package performance;

/**
 * Class to demonstrate performance issue by caching or not field ID, method ID
 * or class ID.
 *
 * @author Sebastien Vincent
 */
public class CacheID
{
    static
    {
        System.loadLibrary("jperformance");
    }

    private int val1 = 0;
    private int val2 = 1;
    private int val3 = 2;
    private int val4 = 3;
    private int val5 = 4;
    private int val6 = 5;

    /**
     * Prints value.
     * @param val value to print.
     */
    public static void printVal(int val)
    {
        int ret = val * val;
        //System.err.println(val);
    }

    /**
     * Prints static value.
     * @param val value to print.
     */
    public static native void callStaticMethod(int val);

    /**
     * Prints static value.
     * @param val value to print.
     */
    public static native void callStaticMethodWithCache(int val);

    /**
     * Makes the sum of the integer members.
     * @return sum.
     */
    public native int callSum();

    /**
     * Makes the sum of the integer members.
     * @return sum.
     */
    public native int callSumWithCache();
    
    /**
     * Makes the sum of the integer members.
     * @param val1 value 1.
     * @param val2 value 2.
     * @param val3 value 3.
     * @param val4 value 4.
     * @param val5 value 5.
     * @param val6 value 6.
     * @return sum.
     */
    public native int callSumPrimitive(int val1, int val2, int val3, int val4,
            int val5, int val6);
}

