# Student Record Management System Using BST

## Problem Statement
To develop a Student Record Management System using a Binary Search Tree (BST) with roll numbers as keys. The system supports insertion, searching, sorted display, and node counting.

## Objectives
- Implement a Binary Search Tree in C++.
- Store student roll numbers and names.
- Search for student records by roll number.
- Display records in ascending order of roll number.
- Count the total number of student records.

## Data Structure Used
- **Binary Search Tree (BST):** Each node stores a roll number, student name, and pointers to its left and right children.

## Operations
1. Insert Student Record
2. Search Student Record
3. Display Records in Sorted Order
4. Count Total Nodes
5. Exit

## Concepts Used
- C++
- Binary Search Tree
- Classes and Objects
- Structures
- Pointers
- Recursion
- Dynamic Memory Allocation
- Inorder Traversal

## Algorithm
1. Start the program.
2. Create an empty Binary Search Tree.
3. Display the menu of operations.
4. For insertion, read the roll number and name, then insert the record according to the BST property. Duplicate roll numbers are rejected.
5. For searching, compare the requested roll number with each node and move left or right accordingly.
6. For display, use inorder traversal to show records in ascending roll-number order.
7. For counting, recursively count the current node and its left and right subtrees.
8. Repeat until the user selects Exit.
9. Stop the program.

## Sample Input
```text
1
103
Aarav Sharma
1
101
Priya Patil
1
105
Rahul Deshmukh
3
4
2
101
5
```

## Sample Output
```text
Student record inserted successfully!
Student record inserted successfully!
Student record inserted successfully!

Student Records in Sorted Order
--------------------------------
Roll Number: 101 | Name: Priya Patil
Roll Number: 103 | Name: Aarav Sharma
Roll Number: 105 | Name: Rahul Deshmukh

Total Student Records: 3

Student Record Found
Roll Number: 101
Name: Priya Patil

Program ended successfully.
```

*Note: The menu and prompts are omitted from this sample output for readability.*

## How to Compile and Run

### Using g++
```bash
g++ StudentRecord.cpp -o StudentRecord
./StudentRecord
```

On Windows, run:
```bash
g++ StudentRecord.cpp -o StudentRecord.exe
StudentRecord.exe
```

You can also open `StudentRecord.cpp` in Code::Blocks, Visual Studio Code, or another C++ IDE and compile it.

## Advantages
- Student records are organized by roll number.
- Searching is efficient on average for a reasonably balanced tree.
- Records are displayed in ascending roll-number order.
- New records can be added dynamically.
- The total number of records can be counted easily.

## Limitations
- Records are stored in memory and are not saved after the program closes.
- A basic BST can become unbalanced, making some operations slower in the worst case.

## Conclusion
The Student Record Management System demonstrates the implementation of a Binary Search Tree in C++. It performs insertion, searching, sorted display, and node counting using roll numbers as keys. The project helps demonstrate BST operations, inorder traversal, pointers, recursion, and dynamic memory allocation.
