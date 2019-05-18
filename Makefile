CXX=g++
SRC_FILES=src/main.cpp src/common/*.cpp
BIN_DIR=bin
EXEC=main.exe
FLAGS=-std=c++11
INCLUDE=-Iinclude -Isrc/common
LIB=-Llib -lglew32 -lglfw3 -lopengl32

all: main

main:
	$(CXX) $(FLAGS) $(SRC_FILES) -o $(BIN_DIR)/$(EXEC) $(INCLUDE) $(LIB)