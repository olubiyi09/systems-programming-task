#include "FunctionsList.h"

#include <fstream>
#include <iomanip>
#include <stdexcept>

void readFile(std::string fileName, std::list<Person>& students) {
    std::ifstream file(fileName);
    if (!file) throw std::runtime_error("Cannot open file " + fileName);
    std::string header;
    std::getline(file, header);
    Person p;
    while (file >> p) students.push_back(p);
    if (!file.eof())
        throw std::runtime_error("Wrong data in " + fileName + " at student line " +
                                 std::to_string(students.size() + 1));
    file.close();
    if (students.empty()) throw std::runtime_error("No students in file " + fileName);
}

void printSingle(const std::list<Person>& students, bool median, std::ostream& out) {
    out << std::left << std::setw(18) << "Name" << std::setw(20) << "Surname";
    if (median) out << "Final_Point(Med.)\n";
    else out << "Final_Point(Aver.)\n";
    out << std::string(56, '-') << "\n";
    for (const Person& p : students) {
        out << std::left << std::setw(18) << p.name()
            << std::setw(20) << p.surname() << std::right << std::fixed
            << std::setprecision(2) << std::setw(14) << p.finalGrade() << "\n";
    }
}

void writeResults(std::string fileName, const std::list<Person>& students, bool median) {
    std::ofstream out(fileName);
    if (!out) throw std::runtime_error("Cannot create file " + fileName);
    printSingle(students, median, out);
    out.close();
}

void splitStudents(const std::list<Person>& students, std::list<Person>& passed,
                   std::list<Person>& failed) {
    for (const Person& p : students) {
        if (p.finalGrade() < 5.0) failed.push_back(p);
        else passed.push_back(p);
    }
}
