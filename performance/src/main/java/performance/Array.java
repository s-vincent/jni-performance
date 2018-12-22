/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

package performance;

/**
 * Class to demonstrate performance issue with array. 
 *
 * @author Sebastien Vincent
 */
public class Array
{
    static
    {
        System.loadLibrary("jperformance");
    }

    /**
     * Returns element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @return element at specified <tt>index</tt>.
     */
    public native long getElement(long[] array, int index);

    /**
     * Sets element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param val value to set.
     */
    public native void setElement(long[] array, int index, long val);

    /**
     * Sets elements in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param nb number of values to set.
     */
    public native void setElements(long[] array, int index, int nb);

    /**
     * Returns element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @return element at specified <tt>index</tt>.
     */
    public native long getElementWithRegion(long[] array, int index);

    /**
     * Sets element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param val value to set.
     */
    public native void setElementWithRegion(long[] array, int index, long val);
    
    /**
     * Sets elements in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param nb number of values to set.
     */
    public native void setElementsWithRegion(long[] array, int index, int nb);

    /**
     * Returns element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @return element at specified <tt>index</tt>.
     */
    public native long getElementWithCritical(long[] array, int index);

    /**
     * Sets element in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param val value to set.
     */
    public native void setElementWithCritical(long[] array, int index,
            long val);
    
    /**
     * Sets elements in specified index.
     * 
     * @param index index.
     * @param array array.
     * @param nb number of values to set.
     */
    public native void setElementsWithCritical(long[] array, int index, int nb);

    /**
     * Do some work on strings.
     *
     * @param strings array of <tt>String</tt>
     */
    public native void doWork(String[] strings);
    
    /**
     * Do some work on strings by deleting JNI local reference.
     *
     * @param strings array of <tt>String</tt>
     */
    public native void doWorkWithDeleteLocalReference(String[] strings);
    
    /**
     * Do some work on strings by using JNI EnsureLocalCapacity().
     *
     * @param strings array of <tt>String</tt>
     */
    public native void doWorkWithEnsureLocalCapacity(String[] strings);
}

