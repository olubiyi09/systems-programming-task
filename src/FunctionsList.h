#pragma once
#include <iostream>
#include <list>
#include <string>

#include "Person.h"

void readFile(std::string fileName, std::list<Person>& students);
void printSingle(const std::list<Person>& students, bool median, std::ostream& out);
void writeResults(std::string fileName, const std::list<Person>& students, bool median);
void splitStudents(const std::list<Person>& students, std::list<Person>& passed,
                   std::list<Person>& failed);
