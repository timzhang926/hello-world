
all:
	javac HelloWorld.java
	javah HelloWorld
	gcc -shared -fPIC -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux libHelloWorld.c -o libHelloWorld.so
	java HelloWorld

clean:
	rm -fr *.so *.class
