# Student Management System

This is a simple student management system written in C. It allows you to add, find, update, delete, and display student details. The student data is stored in a text file (`students.txt`).

## Features

- Add a new student
- Find a student by ID
- Update student details
- Delete a student by ID
- Show all students

## How to Use

1. **Compile the program**:
    ```sh
    gcc student_management.c -o student_management
    ```

2. **Run the program**:
    ```sh
    ./student_management
    ```

3. **Follow the menu**:
    ```
    1. For add student
    2. Find the Student details
    3. Update the student details
    4. Delete the students details
    5. Show all Students details
    6. Exit
    Enter your choice:
    ```

## File Structure

- `student_management.c`: The main C source file containing all functions and logic.
- `students.txt`: The text file used for storing student data. This file is created automatically if it doesn't exist.

## Functions

### `void load_data()`
Loads student data from `students.txt` into the program.

### `void save_data()`
Saves the current student data from the program into `students.txt`.

### `void add()`
Adds a new student to the system.

### `void find()`
Finds and displays a student's details by ID.

### `void update()`
Updates the details of an existing student.

### `void deletek()`
Deletes a student by ID.

### `void show()`
Displays all students' details.

## Notes

- Make sure `students.txt` is in the same directory as the executable when running the program.
- The maximum number of students is set to 100. You can change this by modifying the `MAX_STUDENTS` macro.
- The program automatically saves data when exiting.

## Example

```sh
gcc student_management.c -o student_management
./student_management
