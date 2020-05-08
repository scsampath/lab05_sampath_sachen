CXX=clang++
# CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=test1 test2 test3

all: ${BINARIES}

tests: ${BINARIES}
	./test1
	./test2
	./test3

test1: test1.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

test2: test2.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

test3: test3.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
