# Sorting Algorithms Project - README

## Project Overview

**Project Name**: Sorting Algorithms & Big O

**Team Members**: Aishah Mabayoje, Ezejanu Dike

This project is a part of the ALX-Software Engineering Program and involved implementing various sorting algorithms in the C programming language. The project aims to deepen my understanding of sorting algorithms, data structures, and Big O notation.

## Background Context

In this project, I worked in teams of two to implement several sorting algorithms, including Bubble Sort, Insertion Sort, Selection Sort, Quick Sort, Shell Sort, Cocktail Shaker Sort, Counting Sort, Merge Sort, Heap Sort, Radix Sort, Bitonic Sort, and Quick Sort with the Hoare Partition scheme. The project provided me with a set of functions for printing arrays and linked lists, as well as a data structure for doubly linked lists.

## Project Files and Structure

The project consists of several tasks, each with its own set of files and requirements. Below is a brief overview of the tasks and their associated files:

1. **Bubble Sort (Task 0)**

   - Function: `void bubble_sort(int *array, size_t size)`
   - File: `0-bubble_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `0-O`

2. **Insertion Sort (Task 1)**

   - Function: `void insertion_sort_list(listint_t **list)`
   - File: `1-insertion_sort_list.c`
   - Big O Notations: Best case, Average case, Worst case in `1-O`

3. **Selection Sort (Task 2)**

   - Function: `void selection_sort(int *array, size_t size)`
   - File: `2-selection_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `2-O`

4. **Quick Sort (Task 3)**

   - Function: `void quick_sort(int *array, size_t size)`
   - File: `3-quick_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `3-O`

5. **Shell Sort - Knuth Sequence (Task 4)**

   - Function: `void shell_sort(int *array, size_t size)`
   - File: `100-shell_sort.c`

6. **Cocktail Shaker Sort (Task 5)**

   - Function: `void cocktail_sort_list(listint_t **list)`
   - File: `101-cocktail_sort_list.c`
   - Big O Notations: Best case, Average case, Worst case in `101-O`

7. **Counting Sort (Task 6)**

   - Function: `void counting_sort(int *array, size_t size)`
   - File: `102-counting_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `102-O`

8. **Merge Sort (Task 7)**

   - Function: `void merge_sort(int *array, size_t size)`
   - File: `103-merge_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `103-O`

9. **Heap Sort (Task 8)**

   - Function: `void heap_sort(int *array, size_t size)`
   - File: `104-heap_sort.c`
   - Big O Notations: Best case, Average case, Worst case in `104-O`

10. **Radix Sort (Task 9)**

    - Function: `void radix_sort(int *array, size_t size)`
    - File: `105-radix_sort.c`

11. **Bitonic Sort (Task 10)**

    - Function: `void bitonic_sort(int *array, size_t size)`
    - File: `106-bitonic_sort.c`
    - Big O Notations: Best case, Average case, Worst case in `106-O`

12. **Quick Sort - Hoare Partition scheme (Task 11)**

    - Function: `void quick_sort_hoare(int *array, size_t size)`
    - File: `107-quick_sort_hoare.c`
    - Big O Notations: Best case, Average case, Worst case in `107-O`

13. **Dealer (Task 12)**
    - Function: `void sort_deck(deck_node_t **deck)`
    - File: `1000-sort_deck.c`

## Prerequisites

Before running the code for any of the tasks, make sure you have the following prerequisites in place:

- C Compiler (e.g., GCC)
- Standard C Library
- The provided `sort.h` header file
- The provided data structures for the tasks

## Running the Code

Each task has its own file(s) containing the implementation. You can compile and run each task individually using a C compiler. For example:

```shell
gcc -Wall -Werror -Wextra -pedantic <task_file.c> -o <output_executable>
./<output_executable>
```

Make sure to replace `<task_file.c>` with the appropriate task file name and `<output_executable>` with your desired executable name.

## Big O Notation

Each task required me to analyze and document the Big O notations for the time complexity of the sorting algorithm in the best case, average case, and worst case scenarios. These notations are documented in the respective `*-O` files provided for each task.

## Conclusion

This project helped me to gain valuable experience in implementing and analyzing sorting algorithms and understanding their time complexity.

If you have any questions or need further assistance, please don't hesitate to reach out to me (maishah2540@gmail.com). Enjoy!
