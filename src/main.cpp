#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Functions.h"
#include "Person.h"
#include "Test.h"
#include "Timer.h"

int main() {
    srand(time(0));
    std::vector<Person> students;

    try {
        std::cout << "1 - enter data manually\n2 - generate random data\n3 - read data from file\n4 - generate student files\n";
        int mode = readInt("Choice: ", 1, 4);

        if (mode == 4) {
            int sizes[] = {1000, 10000, 100000, 1000000, 10000000};
            int hwCount = readInt("Number of homework assignments: ", 1, 20);
            for (int i = 0; i < 5; i++) {
                std::string fileName = "students" + std::to_string(sizes[i]) + ".txt";
                Timer t;
                generateFile(fileName, sizes[i], hwCount);
                std::cout << fileName << " created in " << t.elapsed() << " s\n";
            }
            return 0;
        }

        if (mode == 3) {
            std::string fileName;
            std::cout << "File name: ";
            std::cin >> fileName;
            bool median = chooseMedian();
            int container = readInt("Container (1 - vector, 2 - list): ", 1, 2);
            if (container == 1) testVector(fileName, median);
            else testList(fileName, median);
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
        std::cout << "\n";
        printSingle(students, median, std::cout);
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
