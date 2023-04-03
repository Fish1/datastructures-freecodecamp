#include "stdio.h"
#include "stdlib.h"

struct Node {
  struct Node * next;
  int value;
};

void insert(int index, int value, struct Node * node);
void append(int value, struct Node * node);
void appendFront(int value, struct Node * node);

void removeAt(int index, struct Node * node);
void pop(struct Node * node);
void popFront(struct Node * node);

void print(struct Node * node);

struct Node * getPrevTail(struct Node * node);
struct Node * getTail(struct Node * node);

void insert(int index, int value, struct Node * node) {
  if (index < 0) {
    printf("Index out of bounds\n");
    return;
  } else if (index == 0) {
    appendFront(value, node);
    return;
  }

  struct Node * newNode = malloc(sizeof(struct Node));
  newNode->value = value;

  int currentIndex = 0;
  int toIndex = index - 1;
  struct Node * currentNode = node;
  while (currentIndex < toIndex && currentNode->next != NULL) {
    currentNode = currentNode->next;
    currentIndex += 1;
  }
  if (currentIndex < toIndex) {
    printf("Index out of bounds\n");
    return;
  }
  newNode->next = currentNode->next;
  currentNode->next = newNode;
}

void append(int value, struct Node * node) {
  struct Node * newNode = malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->value = value;
  struct Node * end = getTail(node);
  end->next = newNode;
}

void appendFront(int value, struct Node * node) {
  struct Node * newNode = malloc(sizeof(struct Node));
  newNode->next = node->next;
  newNode->value = node->value;
  node->next = newNode;
  node->value = value;
}

void removeAt(int index, struct Node * node) {
  if (index < 0) {
    printf("Index out of bounds\n");
    return;
  } else if (index == 0) {
    popFront(node);
    return;
  }

  int currentIndex = 0;
  int toIndex = index - 1;
  struct Node * currentNode = node;
  while (currentIndex < toIndex && currentNode->next != NULL) {
    currentNode = currentNode->next;
    currentIndex += 1;
  }

  if (currentIndex < toIndex || currentNode->next == NULL) {
    printf("Index out of bounds\n");
    return;
  }

  struct Node * toFree = currentNode->next;
  currentNode->next = currentNode->next->next;
  free(toFree);
}

void pop(struct Node * node) {
  struct Node * prevTail = getPrevTail(node);
  if (prevTail->next == NULL) {
    printf("Cannot pop empty list\n");
    return;
  }
  free(prevTail->next);
  prevTail->next = NULL;
}

void popFront(struct Node * node) {
  if (node->next == NULL) {
    printf("Cannot pop head of empty list\n");
    return;
  }
  struct Node * toFree = node->next;
  node->value = node->next->value;
  node->next = node->next->next;
  free(toFree);
}

void print(struct Node * node) {
  struct Node * current = node;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

struct Node * getTail(struct Node * node) {
  struct Node * current = node;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

struct Node * getPrevTail(struct Node * node) {
  struct Node * current = node;
  if (current->next == NULL) {
    return current;
  }
  while (current->next->next != NULL) {
    current = current->next;
  }
  return current;
}

int main(void) {
  struct Node linkedList = {
    .next = NULL,
    .value = 1
  };

  append(2, &linkedList);
  append(3, &linkedList);
  appendFront(7, &linkedList);

  print(&linkedList);

  removeAt(1, &linkedList);

  print(&linkedList);

  return 0;
}

