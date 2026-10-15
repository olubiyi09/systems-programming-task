# Student Points Calculator

Author: Okediya Meshach Olubiyi  
Course: Systems Programming, 2026 Autumn

A C++ program that calculates the final points of students from their homework and exam results.
The data can be entered by hand, generated randomly or read from a file.
Students from a file are sorted and divided into two files: passed and failed.

## Final points formula

```
Final points = 0.4 * (Average of HW | Median of HW) + 0.6 * Exam
```

## Run

```
make
./build/students
```

Menu:

```
1 - enter data manually
2 - generate random data
3 - read data from file
4 - generate student files
```

Option 4 creates five files with random marks:
`students1000.txt`, `students10000.txt`, `students100000.txt`, `students1000000.txt`, `students10000000.txt`.

Option 3 reads a file, sorts the students and divides them:

- final points `< 5.0` go to `failed_<file name>`
- final points `>= 5.0` go to `passed_<file name>`

## Project files

```
src/main.cpp       menu and time measuring
src/Person.h/.cpp  Person class
src/Functions.h/.cpp  reading, writing, sorting, splitting, generating
src/Timer.h        Timer class with std::chrono
```

Errors like a missing file, wrong data in a file or wrong input are handled with exceptions.

## Data file

The first line is a header. Each next line is one student:

```
Name  Surname  HW1 HW2 HW3 ... Exam
```

The last number on the line is the exam result.

## Speed analysis (v0.2, std::vector)

Computer: Apple M1, 16 GB RAM, SSD, macOS 26.5, Apple clang 21, `-O2`.
Students have 5 homework marks. Times are in seconds.

| Records | Reading | Final points | Sorting | Splitting | Writing passed | Writing failed | Total |
|---|---|---|---|---|---|---|---|
| 1 000 | 0.0031 | 0.0000 | 0.0005 | 0.0002 | 0.0007 | 0.0003 | 0.0049 |
| 10 000 | 0.0157 | 0.0001 | 0.0049 | 0.0014 | 0.0027 | 0.0019 | 0.0266 |
| 100 000 | 0.1499 | 0.0011 | 0.0524 | 0.0137 | 0.0259 | 0.0183 | 0.2613 |
| 1 000 000 | 1.4677 | 0.0117 | 0.6208 | 0.1718 | 0.2554 | 0.1806 | 2.7081 |
| 10 000 000 | 16.1605 | 0.3052 | 7.6537 | 2.5393 | 2.4300 | 1.8453 | 30.9341 |

Reading from file takes the most time, then sorting.
The time grows about 10 times when the number of records grows 10 times.
