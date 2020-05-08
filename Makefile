CXX=clang++
# CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=lab05Test01 lab05Test02 lab05Test03

all: ${BINARIES}

tests: ${BINARIES}
	.lab05Test01
	.lab05Test02
	.lab05Test03

lab05Test01: lab05Test01.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab05Test02: lab05Test02.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab05Test03: lab05Test03.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
