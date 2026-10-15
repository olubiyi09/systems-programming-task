#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

int readInt(std::string prompt, int min, int max);
bool chooseMedian();
Person readPerson();
Person randomPerson(int number, int hwCount);
void readFile(std::string fileName, std::vector<Person>& students);
bool compareStudents(const Person& a, const Person& b);
void printSingle(const std::vector<Person>& students, bool median);
void printTable(const std::vector<Person>& students, std::ostream& out);
void writeTable(std::string fileName, const std::vector<Person>& students);
