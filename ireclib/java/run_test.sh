
mkdir build
cd build
cmake ..
cmake --build . --config Release --target install
cd ..


export LD_LIBRARY_PATH=.
export DYLD_LIBRARY_PATH=.
export CLASSPATH=myproject.jar:. 

javac swig_test.java
java swig_test
