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
void printSingle(const std::vector<Person>& students, bool median, std::ostream& out);
void writeResults(std::string fileName, const std::vector<Person>& students, bool median);
void splitStudents(const std::vector<Person>& students, std::vector<Person>& passed,
                   std::vector<Person>& failed);
void generateFile(std::string fileName, int count, int hwCount);
