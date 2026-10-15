CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC = src/main.cpp src/Person.cpp src/Functions.cpp
HDR = src/Person.h src/Functions.h src/Timer.h
TARGET = build/students

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

clean:
	rm -rf build

.PHONY: all clean
