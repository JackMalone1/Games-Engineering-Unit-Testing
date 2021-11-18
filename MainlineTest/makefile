.DEFAULT_GOAL:= build
fileName := sampleapp
files := "./src/*.cpp"
CC = g++

LINKER_FLAGS  = -std=c++17 -Wall -Wextra -Werror -g -I
BUILD_DIR := ./bin
SRC := ./src/*.cpp ../Mainline/src/*.cpp

build:
	@echo "Build started"
	${CC} -o TestFile ${SRC} -I. -I./include -lmingw32 -llibcppunit
	@echo "Build completed"

clean:
	@echo "Cleaning up"
	rm -rf ${BUILD_DIR} || true
