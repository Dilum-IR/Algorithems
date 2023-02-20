// This Scenario use algorithem is a Linked list.

// heder files  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 10

// define the user's functions

int find_wating_List(char[]);
int isfull();
int iswait();

int find_car(char[]);
int replace_cars();
int move_cars_North(int);

int waiting_line(char[]);
int remove_wait_car(char[]);

void insert_cars(char[]);
void remove_car(char[]);

//////////////////////////////////////////////////////////////

int count = 0, wait_No = 0; // The count of cars in the garage.
char watchList[10][10];

// creating a node for a car containing the plate number and number of moves.
struct car
{
	struct car *next; // pointer to the next car
	struct car *prev; // pointer to the previous car
	int moves;
	char license[10];
};
struct car *head = 0, *last = 0; // pointer to the first car & last car

// Allocate memory and create a node for a car.
struct car *newcar(char Num_plate[])
{
	struct car *temp;

	temp = (struct car *)malloc(sizeof(struct car));

	strcpy(temp->license, Num_plate);
	temp->moves = 0;
	temp->next = 0;
	temp->prev = 0;

	return temp;
}

// Main Function
int main()
{
	char Num_plate[10];
	int choice;

	printf("\n\t************ LAUGHS CAR PARK ************\n");

	// Taking the arrival, departure & Quit User choices......

	printf("\n---------------------------------------------------------------");

	while (true)
	{

		printf("\n\nEnter the Preferance ? \n\n");
		printf("\t1 >> Arrival of a Car\n");
		printf("\t2 >> Departure of a Car\n");
		printf("\t3 >> Quit the Program\n");

		printf("\nEnter the Your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			// Taking the your car's Lisense plate number
			printf("Enter License Plate number of car (XXXX) : ");
			scanf("%s", Num_plate);

			if (isfull() == 1)
			{
				// Add the car into a waiting list
				printf(" No room for your car. \n  Your car added to the waiting list.\n   Please wait....\n");
				waiting_line(Num_plate);
			}
			else
			{
				// Insert the car into the garage
				insert_cars(Num_plate);
			}
			break;
		case 2:
			if (count == 0)
				printf("Garage is Empty");
			else
			{
				printf("Enter License Plate number of car (XXXX) : ");
				scanf("%s", Num_plate);

				// If having a particular number plate then remove the car.
				remove_car(Num_plate);
			}
			break;
		case 3:
			printf("\n\n---------------- Program is End --------------");
			break;

		default:
			printf("\n\nUser choice is Wrong.Plz Try Again.");
			break;
		}
	}
	return 0;
}

// check if the garage is full or empty.
int isfull()
{
	if (count == max)
		return 1;
	else
		return 0;
}
// check if the waiting room has cars then return '1'.
int iswait()
{
	if (wait_No > 0)
		return 1;
	else
		return 0;
}
// moves each car to the north one which is being departed from the garage.
int move_cars_North(int position)
{
	struct car *temp = head;

	int i = 1;
	while (i < (position - 1))
	{
		temp = temp->next;
		i++;
	}
	while (position > 1)
	{
		(temp->moves)++;
		temp = temp->prev;
		position--;
	}
}
// find the positionition of a car according to a particular number plate.
int find_car(char Num_plate[])
{
	struct car *temp = head;

	int l = 1;
	while (temp != 0)
	{
		if ((strcmp(temp->license, Num_plate)) == 0)
		{
			// returns the positionition of the car.
			return l;
		}
		else
		{
			temp = temp->next;
			l++;
		}
	}
	// The car is not available in the garage.
	if (temp == NULL)
	{
		return 0;
	}
}
// find if a specific number plate is available in the waiting list
int find_wating_List(char Num_plate[])
{
	int m;
	for (int i = 0; i < 10; i++)
	{
		m = (strcmp(watchList[i], Num_plate));
		if (m == 0)
			return 1;
	}
	return 0;
}

// moves to the north every cars in the list by 1 place.
int replace_cars()
{
	struct car *temp = head;
	while (temp != 0)
	{
		(temp->moves)++;
		temp = temp->next;
	}
}

// adds any excessive cars to a waiting list array.
int waiting_line(char Num_plate[])
{
	strcpy(watchList[wait_No], Num_plate);
	wait_No++;
}

// removes a car from the waiting list
int remove_wait_car(char Num_plate[])
{
	int i, j;
	for (i = 0; i < 10; i++)
		if ((strcmp(watchList[i], Num_plate)) == 0)
			break;

	for (j = i; j < 10; j++)
	{
		strcpy(watchList[j], watchList[j + 1]);
	}
	wait_No--;
}

// Insert a car in the sourthern for the garage.
void insert_cars(char Num_plate[])
{
	// creates a new node for the new car.
	struct car *temp = head, *newnode;
	newnode = newcar(Num_plate);
	if (head == 0)
	{
		// if the garage is empty.
		head = last = newnode;
	}
	else
	{
		last->next = newnode;
		newnode->prev = last;
		last = last->next;
	}
	// increasing the count of cars in the garage.
	count++;
	printf("Car with number plate %s, Has arrived at the parking lot\n", Num_plate);
}

// main function to remove a car from the garage.
void remove_car(char Num_plate[])
{
	struct car *temp = head, *nextnode;
	int movecount;

	/*if a customer enters a plate number which is in the waiting list
		wants to remove their car.*/
	if (iswait() == 1 && find_car(Num_plate) == 0 && find_wating_List(Num_plate) == 1)
	{
		movecount = 0;
		remove_wait_car(Num_plate);
		printf("The %s plate number car removed\n", Num_plate);
		printf("No of times the car moved: %d\n\n", movecount);
		return;
	}

	if (find_car(Num_plate) == 0 && find_wating_List(Num_plate) == 0)
	{
		printf("Invalid No plate\n");
		return;
	}

	int position = find_car(Num_plate); // finds a car having a particular plate number.
	// replace cars one by one in the garage
	replace_cars();	

	// if the car is the first one.
	if (position == 1)
	{
		head = head->next;
		if (count > 1){
			head->prev = 0;
		}

		movecount = temp->moves;
		free(temp);  // clean the removed node
	}

	// if the car is the last one.
	else if (position == count)
	{
		move_cars_North(position); // moving cars northern of the departing one to make room.
		temp = last;
		last = last->prev;
		last->next = 0;
		movecount = temp->moves;
		free(temp); // clean the removed node
	}

	// any car in the middle of the queue.
	else
	{
		int i = 1;
		while (i < (position - 1))
		{
			temp = temp->next;
			i++;
		}
		move_cars_North(position); 

		temp->next = nextnode->next;
		nextnode->next->prev = temp;
		movecount = nextnode->moves;

		free(nextnode);  // clean the removed node
	}

	count--;

	printf("The %s plate number car removed\n", Num_plate);
	printf("No of times the car moved: %d\n\n", movecount);
	printf(">>> The car park has a enough room for new cars <<<\n");

	/*Inserting a car from the waiting list (if there is any)
	  when there is enough room.*/
	if (iswait() == 1)
	{
		insert_cars(watchList[0]);
		remove_wait_car(watchList[0]);
	}
}
