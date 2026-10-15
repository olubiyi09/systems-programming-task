#include "Test.h"

#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

#include "Functions.h"
#include "FunctionsDeque.h"
#include "FunctionsList.h"
#include "Person.h"
#include "Timer.h"

void printTimes(std::string container, size_t count, size_t passed, size_t failed,
                const double times[]) {
    std::string labels[] = {"Reading from file:", "Calculating final points:", "Sorting:",
                            "Splitting in two:", "Writing passed students:",
                            "Writing failed students:", "Total time:"};
    std::cout << "\nstd::" << container << ", " << count << " students: " << passed
              << " passed, " << failed << " failed\n";
    std::cout << std::fixed << std::setprecision(4) << std::left;
    for (int i = 0; i < 7; i++) std::cout << std::setw(28) << labels[i] << times[i] << " s\n";
}

void testVector(std::string fileName, bool median) {
    std::vector<Person> students, passed, failed;
    double times[7];
    Timer total;
    Timer t;

    readFile(fileName, students);
    times[0] = t.elapsed();
    t.reset();
    for (size_t i = 0; i < students.size(); i++) students[i].calculateFinal(median);
    times[1] = t.elapsed();
    t.reset();
    std::sort(students.begin(), students.end(), compareStudents);
    times[2] = t.elapsed();
    t.reset();
    splitStudents(students, passed, failed);
    times[3] = t.elapsed();
    t.reset();
    writeResults("passed_" + fileName, passed, median);
    times[4] = t.elapsed();
    t.reset();
    writeResults("failed_" + fileName, failed, median);
    times[5] = t.elapsed();
    times[6] = total.elapsed();

    printTimes("vector", students.size(), passed.size(), failed.size(), times);
}

void testList(std::string fileName, bool median) {
    std::list<Person> students, passed, failed;
    double times[7];
    Timer total;
    Timer t;

    readFile(fileName, students);
    times[0] = t.elapsed();
    t.reset();
    for (Person& p : students) p.calculateFinal(median);
    times[1] = t.elapsed();
    t.reset();
    students.sort(compareStudents);
    times[2] = t.elapsed();
    t.reset();
    splitStudents(students, passed, failed);
    times[3] = t.elapsed();
    t.reset();
    writeResults("passed_" + fileName, passed, median);
    times[4] = t.elapsed();
    t.reset();
    writeResults("failed_" + fileName, failed, median);
    times[5] = t.elapsed();
    times[6] = total.elapsed();

    printTimes("list", students.size(), passed.size(), failed.size(), times);
}

void testDeque(std::string fileName, bool median) {
    std::deque<Person> students, passed, failed;
    double times[7];
    Timer total;
    Timer t;

    readFile(fileName, students);
    times[0] = t.elapsed();
    t.reset();
    for (size_t i = 0; i < students.size(); i++) students[i].calculateFinal(median);
    times[1] = t.elapsed();
    t.reset();
    std::sort(students.begin(), students.end(), compareStudents);
    times[2] = t.elapsed();
    t.reset();
    splitStudents(students, passed, failed);
    times[3] = t.elapsed();
    t.reset();
    writeResults("passed_" + fileName, passed, median);
    times[4] = t.elapsed();
    t.reset();
    writeResults("failed_" + fileName, failed, median);
    times[5] = t.elapsed();
    times[6] = total.elapsed();

    printTimes("deque", students.size(), passed.size(), failed.size(), times);
}
