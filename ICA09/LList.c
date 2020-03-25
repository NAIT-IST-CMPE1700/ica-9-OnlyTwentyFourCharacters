#include "LList.h"
#include <stdlib.h>
#include <stdio.h>


//***************************************
//Build an ascending order ID list
//***************************************
void BuildListOrderedID(Student* head)
{
	//loop through arrays
	for (int i = 0; i < 2; i++)
	{
		AddIDItem(head, i);
	}
}

//***************************************
//Build a descending order marks list
//***************************************
void BuildListOrderedMarks(Student* head)
{
	//loop through arrays
	for (int i = 0; i < 10; i++)
	{
		AddMarksItem(head, i);
	}
}

//***************************************
//Add a node to the ordered ID list
//***************************************
void AddIDItem(Student* head, int index)
{
	//create new node
	Student* temp = (Student*)malloc(sizeof(Student));
	
	//memory error
	if (!temp)
	{
		exit(EXIT_FAILURE);
	}

	temp->name = names[index];
	temp->ID = IDs[index];
	temp->mark = marks[index];
	temp->next = NULL;

	//placeholder value for shuffling
	Student* current;
	
	//first value
	if (head == NULL)
	{
		head = temp;	
	}
	//belongs as first item
	else if (temp->ID < head->ID)
	{
		//save state
		current = head;

		head = temp;
		head->next = current;

	}
	//belongs later in list
	else if (temp->ID > head->ID)
	{
		current = head;

		//loop until ordered position
		while (temp->ID > current->ID && current->next != NULL)
		{
			current = current->next;
		}

		//end of the list
		if (current->next == NULL)
		{
			current->next = temp;
		}
		//in between nodes
		else
		{
			temp->next = current->next;
			current->next = temp;
		}
		
	}

}
//***************************************
//Add a node to the ordered marks list
//***************************************
void AddMarksItem(Student* head, int index)
{
	//create new node
	Student* temp = (Student*)malloc(sizeof(Student));

	//memory error
	if (!temp)
	{
		exit(EXIT_FAILURE);
	}

	temp->name = names[index];
	temp->ID = IDs[index];
	temp->mark = marks[index];
	temp->next = NULL;

	//placeholder value for shuffling
	Student* current;

	//first value
	if (head == NULL)
	{
		head = temp;
	}
	//belongs as first item
	else if (temp->mark > head->mark)
	{
		//save state
		current = head;

		head = temp;
		head->next = current;

	}
	//belongs later in list
	else if (temp->mark < head->mark)
	{
		current = head;

		//loop until ordered position
		while (temp->mark < current->mark && current->next != NULL)
		{
			current = current->next;
		}

		//end of the list
		if (current->next == NULL)
		{
			current->next = temp;
		}
		//in between nodes
		else
		{
			temp->next = current->next;
			current->next = temp;
		}

	}
}

//***************************************
//Print all values in list
//***************************************
void PrintList(Student* head)
{
	Student* temp = head;

	printf("\nListing all values:\n");
	while (temp != NULL)
	{
		printf("Name: %s, ID: %d, Mark: %d\n", temp->name, temp->ID, temp->mark);
		temp = temp->next;
	}
}

//***************************************
//Print nodes with values over a threshold value
//***************************************
void PrintStudent(Student* head, int ID)
{
	Student* temp = head;
	int rank = 0;

	//find student
	while (temp->ID != ID && temp != NULL);
	{
		temp = temp->next;
		rank++;
	}

	//found student
	if (temp->ID == ID)
	{
		printf("\nStudent:\n");
		printf("Name: %s, Mark: %d, Rank: %d,\n", temp->name, temp->mark, rank);
	}
	else
	{
		printf("\nStudent not found!\n");
	}
}

//***************************************
//Print nodes with values over a threshold value
//***************************************
void PrintListMarkThreshold(Student* head, int value)
{
	Student* temp = head;

	printf("\nStudents above threshold:\n");

	//print values
	while (temp->mark > value && temp != NULL);
	{
		temp = temp->next;
		printf("Name: %s, Mark: %d\n", temp->name, temp->mark);
	}
}