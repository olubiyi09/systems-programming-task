#include "Functions.h"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

int readInt(std::string prompt, int min, int max) {
    std::string text;
    std::cout << prompt;
    while (true) {
        if (!(std::cin >> text)) throw std::runtime_error("Input ended");
        try {
            size_t pos;
            int value = std::stoi(text, &pos);
            if (pos != text.size()) throw std::invalid_argument(text);
            if (value < min || value > max) throw std::out_of_range(text);
            return value;
        } catch (const std::invalid_argument&) {
            std::cout << "This is not a number. ";
        } catch (const std::out_of_range&) {
            std::cout << "Number is out of range. ";
        }
        std::cout << "Enter a whole number from " << min << " to " << max << ": ";
    }
}

bool chooseMedian() {
    std::string answer;
    std::cout << "Final grade by (a)verage or (m)edian? ";
    if (!(std::cin >> answer)) throw std::runtime_error("Input ended");
    while (answer != "a" && answer != "m") {
        std::cout << "Type a or m: ";
        if (!(std::cin >> answer)) throw std::runtime_error("Input ended");
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

void readFile(std::string fileName, std::vector<Person>& students) {
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

void writeTable(std::string fileName, const std::vector<Person>& students) {
    std::ofstream out(fileName);
    if (!out) throw std::runtime_error("Cannot create file " + fileName);
    printTable(students, out);
    out.close();
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

void generateFile(std::string fileName, int count, int hwCount) {
    std::ofstream out(fileName);
    if (!out) throw std::runtime_error("Cannot create file " + fileName);
    std::ostringstream buffer;
    buffer << std::left << std::setw(16) << "Name" << std::setw(18) << "Surname" << std::right;
    for (int j = 1; j <= hwCount; j++) buffer << std::setw(5) << ("HW" + std::to_string(j));
    buffer << std::setw(6) << "Exam" << "\n";
    for (int i = 1; i <= count; i++) {
        buffer << std::left << std::setw(16) << ("Name" + std::to_string(i))
               << std::setw(18) << ("Surname" + std::to_string(i)) << std::right;
        for (int j = 0; j < hwCount; j++) buffer << std::setw(5) << rand() % 10 + 1;
        buffer << std::setw(6) << rand() % 10 + 1 << "\n";
        if (i % 100000 == 0) {
            out << buffer.str();
            buffer.str("");
        }
    }
    out << buffer.str();
    out.close();
}
