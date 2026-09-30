#include "Person.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

Person::Person() {
    exam_ = 0;
    final_ = 0;
}

Person::Person(const std::string& name, const std::string& surname,
               const std::vector<int>& hw, int exam) {
    name_ = name;
    surname_ = surname;
    hw_ = hw;
    exam_ = exam;
    final_ = 0;
}

Person::Person(const Person& other) {
    name_ = other.name_;
    surname_ = other.surname_;
    hw_ = other.hw_;
    exam_ = other.exam_;
    final_ = other.final_;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name_ = other.name_;
        surname_ = other.surname_;
        hw_ = other.hw_;
        exam_ = other.exam_;
        final_ = other.final_;
    }
    return *this;
}

Person::~Person() {}

double Person::average() const {
    if (hw_.empty()) return 0;
    double sum = 0;
    for (size_t i = 0; i < hw_.size(); i++) sum += hw_[i];
    return sum / hw_.size();
}

double Person::median() const {
    if (hw_.empty()) return 0;
    std::vector<int> sorted = hw_;
    std::sort(sorted.begin(), sorted.end());
    int n = sorted.size();
    if (n % 2 == 1) return sorted[n / 2];
    return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
}

double Person::calculateFinal(bool useMedian) {
    if (useMedian) final_ = 0.4 * median() + 0.6 * exam_;
    else final_ = 0.4 * average() + 0.6 * exam_;
    return final_;
}

std::istream& operator>>(std::istream& in, Person& p) {
    std::string line;
    if (!std::getline(in, line)) return in;

    std::istringstream ss(line);
    std::string name, surname;
    std::vector<int> numbers;
    int x;
    ss >> name >> surname;
    while (ss >> x) numbers.push_back(x);

    if (name == "" || surname == "" || numbers.empty()) {
        in.setstate(std::ios::failbit);
        return in;
    }

    p.name_ = name;
    p.surname_ = surname;
    p.exam_ = numbers.back();
    numbers.pop_back();
    p.hw_ = numbers;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    double avg = 0.4 * p.average() + 0.6 * p.exam_;
    double med = 0.4 * p.median() + 0.6 * p.exam_;
    out << std::left << std::setw(18) << p.name_ << std::setw(20) << p.surname_
        << std::right << std::fixed << std::setprecision(2)
        << std::setw(14) << avg << " | " << std::setw(14) << med;
    return out;
}
