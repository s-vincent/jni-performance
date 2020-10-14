/*
 * jni-performance - Java Native Interface performance.
 * Copyright (c) 2018, Sebastien Vincent
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

package performance;

import junit.framework.*;

public class PerformanceTest extends TestCase
{
    public void testPrint()
    {
        Print ep = new Print();

        ep.printHello();
    }
}

