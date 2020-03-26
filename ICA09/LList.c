#include "LList.h"
#include <stdlib.h>
#include <stdio.h>


//***************************************
//Build an ascending order ID list
//***************************************
Student* BuildListOrderedID(Student* head)
{
	//loop through arrays
	for (int i = 0; i < 10; i++)
	{
		head = AddIDItem(head, i);
	}

	return head;
}

//***************************************
//Build a descending order marks list
//***************************************
Student* BuildListOrderedMarks(Student* head)
{
	//loop through arrays
	for (int i = 0; i < 10; i++)
	{
		head = AddMarksItem(head, i);
	}

	return head;
}

//***************************************
//Add a node to the ordered ID list
//***************************************
Student* AddIDItem(Student* head, int index)
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
	else if (temp->ID >= head->ID)
	{
		current = head;

		//loop until ordered position
		while (current->next != NULL && temp->ID >= current->next->ID )
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

	return head;
}
//***************************************
//Add a node to the ordered marks list
//***************************************
Student* AddMarksItem(Student* head, int index)
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
	else if (temp->mark >= head->mark)
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
		while (current->next != NULL && temp->mark < current->next->mark)
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

	return head;
}

//***************************************
//Print all values in list
//***************************************
void PrintList(Student* head)
{
	printf("\nListing all values:\n");
	while (head != NULL)
	{
		printf("Name: %s, ID: %d, Mark: %d\n", head->name, head->ID, head->mark);
		head = head->next;
	}
}

//***************************************
//Print nodes with values over a threshold value
//***************************************
void PrintStudent(Student* head, int ID)
{
	int rank = 0;
	while (head != NULL)
	{
		if (head->ID == ID)
		{
			printf("\nStudent:\n");
			printf("Name: %s, Mark: %d, Rank: %d,\n", head->name, head->mark, rank);
			return;
		}
		
		head = head->next;

		rank++;
	}
	printf("\nNo student with that ID.\n");
}

//***************************************
//Print nodes with values over a threshold value
//***************************************
void PrintListMarkThreshold(Student* head, int value)
{
	printf("\nStudents above threshold:\n");

	while (head != NULL && head->mark > value)
	{
		printf("Name: %s, Mark: %d\n", head->name, head->mark);
		head = head->next;
	}
}