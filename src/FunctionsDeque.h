#pragma once
#include <deque>
#include <iostream>
#include <string>

#include "Person.h"

void readFile(std::string fileName, std::deque<Person>& students);
void printSingle(const std::deque<Person>& students, bool median, std::ostream& out);
void writeResults(std::string fileName, const std::deque<Person>& students, bool median);
void splitStudents(const std::deque<Person>& students, std::deque<Person>& passed,
                   std::deque<Person>& failed);
