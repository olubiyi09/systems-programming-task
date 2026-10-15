#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Functions.h"
#include "Person.h"

int main() {
    srand(time(0));
    std::vector<Person> students;

    std::cout << "1 - enter data manually\n2 - generate random data\n3 - read data from file\n";
    int mode = readInt("Choice: ", 1, 3);

    if (mode == 3) {
        std::string fileName;
        std::cout << "File name: ";
        std::cin >> fileName;
        if (!readFile(fileName, students)) {
            std::cout << "Cannot open file " << fileName << "\n";
            return 1;
        }
        std::sort(students.begin(), students.end(), compareStudents);
        std::cout << "Loaded " << students.size() << " students.\n";

        std::string outName;
        std::cout << "Output file name (0 for console): ";
        std::cin >> outName;
        if (outName == "0") {
            printTable(students, std::cout);
        } else {
            std::ofstream out(outName);
            printTable(students, out);
            out.close();
            std::cout << "Results written to " << outName << "\n";
        }
        return 0;
    }

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
