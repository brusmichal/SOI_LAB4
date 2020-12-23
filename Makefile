CXX = g++
CXXFLAGS = -std=c++17 -Wall  -g -pthread

all: main
	
main: main.cpp monitor.h bufferMonitor.h bufferMonitor.cpp
	${CXX} ${CXXFLAGS} $< -o $@

clean:
	rm -rf *.o