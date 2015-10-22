#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

#include "LinkedList.h"

struct Stack {
	struct LinkedList *list;
	int size;
};

struct Stack *Stack_init(void);
DataType Stack_push(struct Stack *stack, DataType data);
DataType Stack_pop(struct Stack *stack);
DataType Stack_peek(struct Stack *stack);
void Stack_cleanup(struct Stack *stack);

#endif
