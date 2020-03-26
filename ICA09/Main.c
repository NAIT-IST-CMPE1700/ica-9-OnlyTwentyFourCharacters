#include "LList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	int userChoice; //the user's choice
	int userParam;  //extra user value
	Student* IDHead = NULL;
	Student* MarksHead = NULL;

	//generate lists
	IDHead = BuildListOrderedID(IDHead);
	MarksHead = BuildListOrderedMarks(MarksHead);

	do
	{
		//display menu
		printf("\nMenu:\n");
		printf("1.Display list in order of ID's\n");
		printf("2.Display list in descending order of Marks\n");
		printf("3.Display the names, marks and rank of a person given the ID\n");
		printf("4.Display the names and marks of all person above a threshold marks value\n");
		printf("5.Exit\n");

		printf("\nChoice: ");
		//get choice
		scanf_s("%d", &userChoice);

		//perform action
		switch (userChoice)
		{
			case 1:
				PrintList(IDHead);
				break;
			case 2:
				PrintList(MarksHead);
				break;
			case 3:
				printf("\nID: ");
				scanf_s("%d", &userParam);
				PrintStudent(IDHead, userParam);
				break;
			case 4:
				printf("\nMark Threshold: ");
				scanf_s("%d", &userParam);
				PrintListMarkThreshold(MarksHead, userParam);
				break;
		}
	} while (userChoice != 5);
	//loop until exit
	
	exit(EXIT_SUCCESS);
}