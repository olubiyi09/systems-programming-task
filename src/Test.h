#pragma once
#include <string>

void printTimes(std::string container, size_t count, size_t passed, size_t failed,
                const double times[]);
void testVector(std::string fileName, bool median);
void testList(std::string fileName, bool median);
void testDeque(std::string fileName, bool median);
