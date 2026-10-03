Student Record Management System:

This project is a Student Record Management System written in C using a Singly Linked List (SLL).

The program is menu-driven and allows the user to add, display, delete, modify, save, load, sort, delete all, and reverse student records.

Student records are dynamically allocated using malloc() and released using free().

The project was developed as Mini Project – II: Student Record Management System.

 Student Record Structure
Each student is represented using the following structure:
typedef struct student
{
    int rollno;
    char name[50];
    float marks;
    struct student *next;
} SLL;
//when deleting then which one we need to delete i up that selection of data i provided 
Delete Record
Menu option:
d/D : Delete a record
The program provides two methods:
R/r : Enter roll number to delete
N/n : Enter name to delete

 Modify Record
Menu option:
m/M : Modify a record

The program provides:
R/r : Search by roll number
N/n : Search by name
P/p : Search by marks

Modify by Roll Number
The current record is displayed and the user can enter:
New name
New marks
Modify by Marks

The program searches for a matching marks value and allows the user to update:
Name
Marks
Marks are validated between 0 and 100.

Save Records
Menu option:
v/V : Save records
The program saves the linked-list records to:
student.dat
The file stores:
roll_number name marks
example:
1 mahi 99.0000
2 babu 88.0000
Load Records

When the program starts, it attempts to open:
filename: student.dat
If the file exists, the saved student records are loaded into the linked list.
If the file does not exist, the program starts with an empty list.

Exit
Menu option:

e/E : Exit
The program asks:
S/s : Save and exit
E/e : Exit without saving

Save and Exit
The records are saved to student.dat, then all dynamically allocated nodes are freed.

Exit Without Saving
The current in-memory changes are discarded and all allocated nodes are freed.

Sort Records
Menu option:
t/T : Sort the list
The program provides:

N/n : Sort by name
P/p : Sort by marks
Sort by Name
The linked list is sorted alphabetically by student name.

Sort by Marks
Records are sorted in descending order of marks.
Delete All Records

Menu option:
l/L : Delete all the records
Example:

3 record(s) deleted
Deleting records from memory does not automatically delete student.dat.
Reverse Linked List

Menu option:

r/R : Reverse the list

The program reverses the linked list by changing the next pointers.

Example:
// Before:
1 -> 2 -> 3 -> 4 -> NULL

//After:
4 -> 3 -> 2 -> 1 -> NULL

No additional set of nodes is created for the reversal.

Linked List Reversal
The reversal uses three pointers:

SLL *prev;
SLL *curr;
SLL *next;

The links are changed as follows:
prev <- curr <- next
until the complete list is reversed.
