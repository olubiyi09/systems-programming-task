# Student Points Calculator

Author: Okediya Meshach Olubiyi  
Course: Systems Programming, 2026 Autumn

A C++ program that calculates the final points of students from their homework and exam results.
The data can be entered by hand, generated randomly or read from a file.

## Final points formula

```
Final points = 0.4 * (Average of HW | Median of HW) + 0.6 * Exam
```

## Run

```
make
./build/students
```

## Data file

The first line is a header. Each next line is one student:

```
Name  Surname  HW1 HW2 HW3 ... Exam
```

The last number on the line is the exam result.
