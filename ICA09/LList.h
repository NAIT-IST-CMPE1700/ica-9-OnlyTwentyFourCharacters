#ifndef LLIST
#pragma once
#define LLIST

static char* names[] = { "Joey", "Bob", "Harry", "Junior", "Ethan", "Frank", "Dylan", "George", "Henry", "Matthew" };
static int IDs[] = { 101, 204, 92, 555, 230, 80, 981, 710, 003, 222 };
static int marks[] = { 10, 70, 15, 99, 82, 100, 50, 0, 91, 50 };

//node struct of a student
typedef struct Student{
	char* name;
	int mark;
	int ID;
	struct Student* next;
} Student;

//declare methods
void BuildListOrderedID(Student* head);
void BuildListOrderedMarks(Student* head);

void AddMarksItem(Student* head, int index);
void AddIDItem(Student* head, int index);

void PrintList(Student* head);
void PrintStudent(Student* head, int ID);
void PrintListMarkThreshold(Student* head, int value);

void FreeListMemory(Student* head);

#endif // !LLIST
