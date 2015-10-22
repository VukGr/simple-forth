#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Stack *Stack_init(void) {
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->list = LinkedList_init();
	stack->size = 0;
	return stack;
}

DataType Stack_push(struct Stack *stack, DataType data) {
	stack->size++;
	LinkedList_add(stack->list, Node_init(data));
	return data;
}

DataType Stack_pop(struct Stack *stack) {
	if(!stack->size)
		return NULL;
	stack->size--;
	return LinkedList_pop(stack->list);
}

DataType Stack_peek(struct Stack *stack) {
	if(!stack->size)
		return 0;
	return stack->list->head->data;
}

void Stack_cleanup(struct Stack *stack) {
	LinkedList_cleanup(stack->list);
	free(stack);
}
