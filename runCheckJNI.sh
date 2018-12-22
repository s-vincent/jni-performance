#!/bin/sh

TARGETPATH=$(dirname $0)/performance/target

java -Xcheck:jni -verbose:jni -Djava.library.path=$TARGETPATH/lib -jar $TARGETPATH/performance-1.0-SNAPSHOT.jar

