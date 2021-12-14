#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct client{
	int serial_id;
	int key;
};


// https://algorithmtutor.com/Data-Structures/Tree/Priority-Queues/

struct client clients[N];

void insertFirst(){
}

void insertSpecific(){
	
}

void removeClient(){
	
}

void displayQueue(){
	
}

int main(){
	int choice;
	
	printf("Priority queue with heap\n");
	printf("1. Insert new customer. (insert)\n");
	printf("2. Assist a client. (remove)\n");
	printf("3. Assist a specific client using a key. (remove specific)\n");
	printf("4. Insert special customer.(key = 0)\n");
	printf("5. Exit. (close program)\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
	while(choice != 5){
		switch(choice){
			case 1:
				// insert
				insertSpecific();
				displayQueue();
				break;
			case 2:
				// remove first
				removeClient();
				displayQueue();
				break;
			case 3:
				// remove x (where x is a specific key)
	
				//removeSpecific(x);
				displayQueue();
				break;
			case 4:
				// add client with key = 0;
				insertFirst();
				displayQueue();
				break;
			case 5:
				break;
			default:
				printf("\nInvalid input. Try again: ");
				scanf("%d", &choice);
		}
	}
}
