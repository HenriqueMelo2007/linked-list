#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int num;
  struct Node* next;
} Node;

void initializeList (Node** list);
void prepend (Node** list);
void append (Node** list);
void deleteHead (Node** list);
void deleteTail (Node** list);
void countingElements (Node *list);
void printingElements (Node* list);

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

    if ( userInput == 1 ) {
      prepend(&list);
    } else if ( userInput == 3 ) {
      append(&list);
    } else if ( userInput == 4 ) {
      deleteHead(&list);
    } else if ( userInput == 7 ) {
      countingElements(list);
    } else if ( userInput == 8 ) {
      printingElements(list);
    }

  } while ( userInput != 9 );

  return 0;
}


void initializeList (Node** list) {
  Node* firstNode = malloc(sizeof(Node));

  int firstNum;
  printf("Type the first value: ");
  scanf("%i", &firstNum);

  firstNode->num = firstNum;
  firstNode->next = NULL;

  *list = firstNode;
}

void prepend (Node** list) {
  Node* newNode = malloc(sizeof(Node));

  int newNum;
  printf("Type the new value: ");
  scanf("%i", &newNum);

  newNode->num = newNum;
  newNode->next = *list;

  *list = newNode;
}

void append (Node** list) {
  Node* newNode = malloc(sizeof(Node));

  int newNum;
  printf("Type the new value: ");
  scanf("%i", &newNum);

  newNode->num = newNum;
  newNode->next = NULL;

  Node* actualNode = *list;
  while ( actualNode->next != NULL ) {
    actualNode = actualNode->next;
  }

  actualNode->next = newNode;
}

void countingElements (Node *list) {
  int num = 0;
  printf("[");
  for ( Node* actualNode = list; actualNode != NULL; actualNode = actualNode->next ) {
    num++;
  }
  printf(" %i ", num);
  printf("]\n");
}

void printingElements (Node* list) {
  printf("[");

  for ( Node* actualNode = list;  actualNode != NULL; actualNode = actualNode->next) {
    printf(" %i ", actualNode->num);
  }

  printf("]\n");
}

void deleteHead (Node** list) {
  Node* head = *list;

  if ( head->next != NULL ) {
    Node* tmpNode = malloc(sizeof(Node));
    tmpNode = head->next;
    free(list);
    *list = tmpNode;
  } else printf("Only 1 element in list, add more elements to delete\n");
}

void deleteTail (Node** list) {}