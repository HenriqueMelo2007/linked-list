#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int num;
  struct Node* next;
} Node;

void initializeList (Node** list);

int main(void)
{
  Node* list = NULL;
  initializeList(&list);

  if ( list == NULL ) return 1;

  printf("List initialized with: %i\n", list->num);

  int userInput;
  do {
    printf("Type:\n");
    printf("1 - to insert at the beggining\n");
    printf("2 - to insert at a specific position\n");
    printf("3 - to insert at the end\n");
    printf("4 - to remove at the beggining\n");
    printf("5 - to remove at a specific position\n");
    printf("6 - to remove at the end\n");
    printf("7 - to count elements of the list\n");
    printf("8 - to print elements of the list\n");
    printf("9 - to leave the program\n");


    scanf("%i", &userInput);
  } while ( userInput != 9 );

  return 0;
}


void initializeList (Node** list) {
  Node* newNode = malloc(sizeof(Node));

  int newNum;
  printf("Type the first value: ");
  scanf("%i", &newNum);

  newNode->num = newNum;
  newNode->next = NULL;

  *list = newNode;
}

void append (Node* list) {}

