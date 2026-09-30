# Student Points Calculator

Author: Okediya Meshach Olubiyi
Course: Systems Programming, 2026 Autumn, Vilniaus verslo kolegija

## About

A C++ console application that calculates the final points of students from their
homework and exam results. Each student is stored as a `Person` object (first name,
surname, homework results, exam result, final grade) that follows the rule of three.

Planned features:

- manual data entry, with an unknown number of homework results
- random generation of homework and exam scores
- reading students from a text file
- final points calculated by either the average or the median of the homework results
- output sorted by surname and formatted in aligned columns

## Final points formula

```
Final points = 0.4 * (Average of HW | Median of HW) + 0.6 * Exam
```

## Build and run

```
make
./build/students
```

Requires a C++17 compiler (g++ or clang++).

## Modes

1. Enter data manually. Homework results are entered until 0 is typed, then the exam result.
2. Generate random homework and exam results (1-10) for a chosen number of students.
3. Read students from a file (`Students.txt` sample included). The first line is a header,
   then each line is `Name Surname HW1 ... HWn Exam`. The last number on a line is the exam.
   The number of homework columns may differ between files. Results are sorted by surname
   and written as `Final (Avg.) | Final (Med.)` to the console or to a chosen file.

The large data files (`students10000.txt`, `students100000.txt`, `students1000000.txt`)
are not stored in the repository.
