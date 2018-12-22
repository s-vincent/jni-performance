# jni-performance

Samples with Java Native Interface good/bad practices

## Pre-requisites

You need a JDK (either from Oracle or OpenJDK) and maven.

On GNU/Linux Debian like distributions you can use:

`apt-get install default-jdk mvn`

## Build

To build the project:

`mvn package`

To build the javadoc:

`mvn javadoc:javadoc`

## Usage

Once build, the compiled jar as well as dependencies jars are in
performance/target/.

To run from project directory:

`java -Djava.library.path=performance/target/lib -jar performance/target/performance-1.0-SNAPSHOT.jar`

You can also run it via maven:

`mvn exec:exec`

## Eclipse

Eclipse can be used to build, debug and run this project as well.

To do so, use import option, select "Existing Maven projects" and finally set
the project directory as "Root Directory".

## License

All codes are under BSD-3 license.

## Links

 * https://www.ibm.com/developerworks/library/j-jni/index.html 

