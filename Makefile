CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC = src/main.cpp src/Person.cpp
TARGET = build/students

all: $(TARGET)

$(TARGET): $(SRC) src/Person.h
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

clean:
	rm -rf build

.PHONY: all clean
