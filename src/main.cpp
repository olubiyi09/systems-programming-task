#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

int main() {
    int studentCount, hwCount;
    std::cout << "Number of students: ";
    std::cin >> studentCount;
    std::cout << "Number of homework assignments: ";
    std::cin >> hwCount;

    std::vector<Person> students;
    for (int i = 0; i < studentCount; i++) {
        Person p;
        std::string text;
        int grade;
        std::cout << "Student " << i + 1 << " name: ";
        std::cin >> text;
        p.setName(text);
        std::cout << "Student " << i + 1 << " surname: ";
        std::cin >> text;
        p.setSurname(text);
        for (int j = 0; j < hwCount; j++) {
            std::cout << "  HW" << j + 1 << ": ";
            std::cin >> grade;
            p.addHomework(grade);
        }
        std::cout << "  Exam: ";
        std::cin >> grade;
        p.setExam(grade);
        p.calculateFinal(false);
        students.push_back(p);
    }

    std::cout << "\n" << std::left << std::setw(18) << "Name" << std::setw(20) << "Surname"
              << "Final_Point(Aver.)\n";
    std::cout << std::string(56, '-') << "\n";
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << std::left << std::setw(18) << students[i].name()
                  << std::setw(20) << students[i].surname() << std::right << std::fixed
                  << std::setprecision(2) << std::setw(14) << students[i].finalGrade() << "\n";
    }
    return 0;
}
