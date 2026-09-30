#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

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

int main() {
    srand(time(0));
    std::vector<Person> students;

    std::cout << "1 - enter data manually\n2 - generate random data\n";
    int mode = readInt("Choice: ", 1, 2);

    if (mode == 1) {
        int more = 1;
        while (more == 1) {
            students.push_back(readPerson());
            more = readInt("Add another student? (1 - yes, 0 - no): ", 0, 1);
        }
    } else {
        int count = readInt("Number of students: ", 1, 1000000);
        int hwCount = readInt("Number of homework assignments: ", 0, 100);
        for (int i = 1; i <= count; i++) students.push_back(randomPerson(i, hwCount));
    }

    bool median = chooseMedian();
    for (size_t i = 0; i < students.size(); i++) students[i].calculateFinal(median);
    printSingle(students, median);
    return 0;
}
