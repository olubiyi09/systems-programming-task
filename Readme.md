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

Option 3 asks for a container (`1 - vector, 2 - list, 3 - deque`), reads a file, sorts the students and divides them:

- final points `< 5.0` go to `failed_<file name>`
- final points `>= 5.0` go to `passed_<file name>`

## Project files

```
src/main.cpp       menu and time measuring
src/Person.h/.cpp  Person class
src/Functions.h/.cpp  reading, writing, sorting, splitting, generating (std::vector)
src/FunctionsList.h/.cpp   the same functions for std::list
src/FunctionsDeque.h/.cpp  the same functions for std::deque
src/Test.h/.cpp    time measuring for every container
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

## Speed analysis (v0.25, std::vector vs std::list vs std::deque)

Same computer and the same five files. Times are in seconds.

### Reading from file

| Records | vector | list | deque |
|---|---|---|---|
| 1 000 | 0.0019 | 0.0018 | 0.0030 |
| 10 000 | 0.0163 | 0.0145 | 0.0163 |
| 100 000 | 0.1749 | 0.1401 | 0.1749 |
| 1 000 000 | 1.4910 | 1.4338 | 1.3745 |
| 10 000 000 | 15.6136 | 14.0770 | 14.4025 |

### Sorting

| Records | vector | list | deque |
|---|---|---|---|
| 1 000 | 0.0004 | 0.0001 | 0.0007 |
| 10 000 | 0.0047 | 0.0011 | 0.0055 |
| 100 000 | 0.0537 | 0.0113 | 0.0586 |
| 1 000 000 | 0.6316 | 0.1298 | 0.6525 |
| 10 000 000 | 7.8596 | 1.6825 | 7.7003 |

### Splitting in two

| Records | vector | list | deque |
|---|---|---|---|
| 1 000 | 0.0002 | 0.0001 | 0.0001 |
| 10 000 | 0.0015 | 0.0007 | 0.0007 |
| 100 000 | 0.0138 | 0.0074 | 0.0060 |
| 1 000 000 | 0.1774 | 0.0732 | 0.0612 |
| 10 000 000 | 2.4185 | 0.7981 | 0.6445 |

### Writing passed + failed students

| Records | vector | list | deque |
|---|---|---|---|
| 1 000 | 0.0015 | 0.0013 | 0.0013 |
| 10 000 | 0.0051 | 0.0047 | 0.0047 |
| 100 000 | 0.0375 | 0.0384 | 0.0379 |
| 1 000 000 | 0.3849 | 0.3767 | 0.3763 |
| 10 000 000 | 4.1069 | 4.7564 | 4.1199 |

### Total time

| Records | vector | list | deque |
|---|---|---|---|
| 1 000 | 0.0040 | 0.0032 | 0.0051 |
| 10 000 | 0.0276 | 0.0211 | 0.0273 |
| 100 000 | 0.2807 | 0.1978 | 0.2790 |
| 1 000 000 | 2.6975 | 2.0187 | 2.4714 |
| 10 000 000 | 30.3060 | 21.9741 | 27.4601 |

### Conclusions

- Reading and writing take almost the same time with all containers, the file itself is the slow part.
- `std::list` sorts about 4-5 times faster. `list.sort()` only changes links between nodes, while `std::sort` on vector and deque copies whole `Person` objects (with their homework vector).
- Splitting is slowest with `std::vector`, because `push_back` sometimes has to move all elements to a bigger memory block. `std::list` and `std::deque` do not do that.
- For this program `std::list` was the fastest in total, `std::deque` second and `std::vector` third.
