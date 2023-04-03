#include "stdio.h"
#include "stdlib.h"

int data_size = 0;
int * data = NULL;

struct Array {
  int size;
  int * data;
};

/**
 * speed O(1)
 * memory O(1)
 */
int at(int index, struct Array * array) {
  if (index < 0 || index >= array->size) {
    printf("Index out of bounds");
    return -1;
  }
  return array->data[index];
}

/**
 * speed O(n)
 * memory O(n)
 */
void delete(int index, struct Array * array) {
  int * new_data = NULL;
  if (index < 0 || index >= array->size) {
    printf("Index out of bounds");
    return;
  }
  new_data = malloc((array->size - 1) * sizeof(int));
  for (int old_i = 0, new_i = 0; old_i < array->size; old_i += 1, new_i += 1) {
    if (old_i != index) {
      new_data[new_i] = array->data[old_i];
    } else {
      new_i -= 1;
    }
  }
  array->size -= 1;
  free(array->data);
  array->data = new_data;
}

/**
 * speed O(1)
 * memory O(1)
 */
void pop(struct Array * array) {
  if (array->size <= 0) {
    printf("Index out of bounds\n");
    return;
  }
  array->data = realloc(array->data, (array->size - 1) * sizeof(int));
  array->size -= 1;
}

/**
 * speed O(n)
 * memory O(n)
 */
void prepend(int value, struct Array * array) {
  int * new_data = NULL;
  new_data = malloc((array->size + 1) * sizeof(int));
  new_data[0] = value;
  for (int i = 0; i < array->size; i += 1) {
    new_data[i + 1] = array->data[i];
  }
  array->size += 1;
  free(array->data);
  array->data = new_data;
}

/**
 * speed O(1)
 * memory O(1)
 */
void append(int value, struct Array * array) {
  array->data = realloc(array->data, (array->size + 1) * sizeof(int));
  array->data[array->size] = value;
  array->size += 1;
}

/**
 * speed O(n)
 * memory O(n)
 */
void insert(int index, int value, struct Array * array) {
  if (index < 0 || index > array->size) {
    printf("Index out of bounds");
    return;
  } else if (index == array->size) {
    append(value, array);
    return;
  } else if (index == 0) {
    prepend(value, array);
    return;
  }
  int * new_data = malloc((array->size + 1) * sizeof(int));
  for (int old_i = 0, new_i = 0; old_i < array->size; old_i += 1, new_i += 1) {
    if (new_i != index) {
      new_data[new_i] = array->data[old_i];
    } else {
      new_data[new_i] = value;
      old_i -= 1;
    }
  }
  array->size += 1;
  free(array->data);
  array->data = new_data;
}

/**
 * speed O(n)
 * memory O(1)
 */
void print(struct Array * array) {
  for (int i = 0; i < array->size; i += 1) {
    printf("%d ", array->data[i]);
  }
  printf("\n");
}

int main(void) {

  data = malloc(data_size * sizeof(int));

  struct Array array = {
    .size = 0,
    .data = NULL
  };

  for (int i = 0; i < 50; i += 1) {
    append(i, &array);
  }
  print(&array);

  for (int i = 0; i < 5; i += 1) {
    prepend(i, &array);
  }
  print(&array);

  for (int i = 0; i < 40; i += 1) {
    pop(&array);
  }
  print(&array);

  printf("at 0: %d\n", at(0, &array));
  printf("at 1: %d\n", at(1, &array));
  printf("at 2: %d\n", at(2, &array));

  return 0;
}
