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

