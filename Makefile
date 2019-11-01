all: test/test.o

package: build/homlib.so

test/test.o: test/test.cc src/hom.hh src/graph.hh src/treedec.hh
	g++ -O3 -std=c++17 -I./src -o test/test.o test/test.cc 

test/speedtest.o: test/speedtest.cc src/hom.hh src/graph.hh src/treedec.hh
	g++ -O3 -std=c++17 -I./src -o test/speedtest.o test/speedtest.cc 

build/homlib.so: src/homlib.cc src/hom.hh src/graph.hh src/treedec.hh
	g++ -O3 -std=c++17 -I`python3 -c 'from distutils.sysconfig import *; print(get_python_inc())'` -DPIC -shared -fPIC -o build/homlib.so src/homlib.cc -lboost_python3


.PHONY: test
test: test/test.o test/speedtest.o
	./test/test.o
	./test/speedtest.o
