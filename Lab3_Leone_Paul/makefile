
#Program Name: makefile
#Author: Paul Leone
#Date: 7/13/2019
#Description: This is the makefile for Lab 3

CXX = g++
CXXFLAGS = -std=c++11

OBJS = main.o Game.o Die.o LoadedDie.o

SRCS = main.cpp Game.cpp Die.cpp LoadedDie.cpp

HEADERS = Game.hpp Die.hpp LoadedDie.hpp

die: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o die

clean:
	rm *.o main
