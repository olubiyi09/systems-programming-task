#pragma once
#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person();
    Person(const std::string& name, const std::string& surname,
           const std::vector<int>& hw, int exam);

    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    const std::string& name() const { return name_; }
    const std::string& surname() const { return surname_; }
    const std::vector<int>& homework() const { return hw_; }
    int exam() const { return exam_; }
    double finalGrade() const { return final_; }

    void setName(const std::string& n) { name_ = n; }
    void setSurname(const std::string& s) { surname_ = s; }
    void addHomework(int g) { hw_.push_back(g); }
    void setExam(int e) { exam_ = e; }

    double average() const;
    double median() const;
    double calculateFinal(bool useMedian);

    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);

private:
    std::string name_;
    std::string surname_;
    std::vector<int> hw_;
    int exam_;
    double final_;
};
