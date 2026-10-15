#include "Functions.h"

#include <cstdlib>
#include <fstream>
#include <iomanip>

int readInt(std::string prompt, int min, int max) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < min || value > max) {
        if (std::cin.eof()) exit(1);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Enter a whole number from " << min << " to " << max << ": ";
    }
    return value;
}

bool chooseMedian() {
    std::string answer;
    std::cout << "Final grade by (a)verage or (m)edian? ";
    std::cin >> answer;
    while (answer != "a" && answer != "m") {
        std::cout << "Type a or m: ";
        std::cin >> answer;
    }
    return answer == "m";
}

Person readPerson() {
    Person p;
    std::string text;
    std::cout << "Name: ";
    std::cin >> text;
    p.setName(text);
    std::cout << "Surname: ";
    std::cin >> text;
    p.setSurname(text);

    std::cout << "Enter homework results (1-10), 0 to finish:\n";
    int grade = readInt("  HW: ", 0, 10);
    while (grade != 0) {
        p.addHomework(grade);
        grade = readInt("  HW: ", 0, 10);
    }
    p.setExam(readInt("Exam (1-10): ", 1, 10));
    return p;
}

Person randomPerson(int number, int hwCount) {
    Person p;
    p.setName("Name" + std::to_string(number));
    p.setSurname("Surname" + std::to_string(number));
    for (int i = 0; i < hwCount; i++) p.addHomework(rand() % 10 + 1);
    p.setExam(rand() % 10 + 1);
    return p;
}

bool readFile(std::string fileName, std::vector<Person>& students) {
    std::ifstream file(fileName);
    if (!file) return false;
    std::string header;
    std::getline(file, header);
    Person p;
    while (file >> p) students.push_back(p);
    file.close();
    return true;
}

bool compareStudents(const Person& a, const Person& b) {
    if (a.surname() != b.surname()) return a.surname() < b.surname();
    return a.name() < b.name();
}

void printSingle(const std::vector<Person>& students, bool median) {
    std::cout << "\n" << std::left << std::setw(18) << "Name" << std::setw(20) << "Surname";
    if (median) std::cout << "Final_Point(Med.)\n";
    else std::cout << "Final_Point(Aver.)\n";
    std::cout << std::string(56, '-') << "\n";
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << std::left << std::setw(18) << students[i].name()
                  << std::setw(20) << students[i].surname() << std::right << std::fixed
                  << std::setprecision(2) << std::setw(14) << students[i].finalGrade() << "\n";
    }
}

void printTable(const std::vector<Person>& students, std::ostream& out) {
    out << std::left << std::setw(18) << "Name" << std::setw(20) << "Surname" << std::right
        << std::setw(14) << "Final (Avg.)" << " | " << std::setw(14) << "Final (Med.)" << "\n";
    out << std::string(68, '-') << "\n";
    for (size_t i = 0; i < students.size(); i++) out << students[i] << "\n";
}
