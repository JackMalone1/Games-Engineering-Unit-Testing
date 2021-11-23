.DEFAULT_GOAL:= build
fileName := sampleapp
files := "./src/*.cpp"
CC = g++
include	:= "C:/msys64/mingw64/include/cppunit"
include1 := "C:/msys64/mingw64/include/cppunit/ui/text"
lib	:= "C:/msys64/mingw64/lib"
LINKER_FLAGS  = -std=c++17 -Wall -Wextra -Werror -g -I
BUILD_DIR := ./bin
SRC := ./src/*.cpp ../Mainline/src/LotteryProduction.cpp
CXXFLAGS 	:= -std=c++11 -Wall -Wextra -Werror -g -I.

build:
	@echo "Build started"
	${CC} -o TestFile ${SRC} -I${include} -I${include1} -I. -I./include -L${lib} -lmingw32 -llibcppunit
	@echo "Build completed"

clean:
	@echo "Cleaning up"
	rm -rf ${BUILD_DIR} || true
