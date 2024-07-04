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

  printf("List initialized with: %i", list->num);

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

