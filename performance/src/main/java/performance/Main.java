/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

package performance;

/**
 * Main class.
 *
 * @author Sebastien Vincent
 */
public class Main
{
    /**
     * Bench CacheID class.
     */
    private static void benchCacheID()
    {
        CacheID cacheID = new CacheID();
        long startTime = System.nanoTime();
        long endTime = 0;

        System.out.println("Bench cache ID");

        System.out.println("Field test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            cacheID.callSum();
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Field test with cache");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            cacheID.callSumWithCache();
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Field test primitive");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            cacheID.callSumPrimitive(0, 1, 2, 3, 4, 5);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Static method call test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            cacheID.callStaticMethod(i);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Static method call test with cache");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            cacheID.callStaticMethodWithCache(i);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");
        
        System.out.println("");
    }

    /**
     * Bench Array class.
     */
    private static void benchArray()
    {
        Array array  = new Array();
        long[] longs = new long[1024];
        long startTime = System.nanoTime();

        System.out.println("Bench array");

        System.out.println("Get element test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.getElement(longs, (int)i % 1024);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set element test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElement(longs, (int)i % 1024, i);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set elements test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElements(longs, 0, longs.length);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Get element region test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.getElementWithRegion(longs, (int)i % 1024);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set element region test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElementWithRegion(longs, (int)i % 1024, i);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set elements region test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElementsWithRegion(longs, 0, longs.length);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Get element critical test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.getElementWithCritical(longs, (int)i % 1024);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set element critical test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElementWithCritical(longs, (int)i % 1024, 0xCA);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("Set elements critical test");
        startTime = System.nanoTime();
        for(int i = 0 ; i < 1000000 ; i++)
        {
            array.setElementWithCritical(longs, 0, longs.length);
        }
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        String[] strings = new String[64];

        for(int i = 0 ; i < strings.length ; i++)
        {
            strings[i] = new String("Test " + i);
        }

        System.out.println("doWork test");
        startTime = System.nanoTime();
        array.doWork(strings);
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("doWorkWithDeleteLocalRefernce test");
        startTime = System.nanoTime();
        array.doWorkWithDeleteLocalReference(strings);
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("doWorkWithEnsureLocalCapacity test");
        startTime = System.nanoTime();
        array.doWorkWithEnsureLocalCapacity(strings);
        System.out.println("Finished in " +
                ((System.nanoTime() - startTime) / 1000000) + " ms");

        System.out.println("");
    }

    /**
     * Entry point of the program.
     * @param args program arguments.
     */
    public static void main(String[] args)
    {
        try
        {
            Print ep = new Print();
            ep.printHello();

            benchCacheID();

            benchArray();
        }
        catch(Throwable e)
        {
            System.out.println("Exception occured: " + e.toString());
            e.printStackTrace();
        }
    }
}

