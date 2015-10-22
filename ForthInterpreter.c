#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Stack/Stack.h"
#include "Hashtable/Hashtable.h"

//TODO: ERROR CHECKING
//TODO: CLEAN UP LEAK REGARDING FUNCTIONS NOT BEING FREED

struct Hashtable *functions;

int eval(struct Stack *stack, char *token);

int is_number(char *token) {
	if(!token)
		return 0;

	for(; *token != '\0'; token++)
		if(!isdigit(*token))
			return 0;
	return 1;
}

char *read(char *input) {
	if(input != NULL) {
		input[strlen(input)-1] = '\0';
	}
	return strtok(input, " ");	
}

void defun(void) {
	char *function = (char *)malloc(sizeof(char)*2048);
	char *token = read(NULL);
	char *name = (char *)malloc(sizeof(char)*strlen(token));
	strcpy(name, token);

	for(;;) {
		if(!(token = read(NULL)))
			break;
		else if(strcmp(token, ";") == 0)
			break;	

		strcat(function, token);
		strcat(function, " ");
	}

	Hashtable_add(functions, name, function);
}

int function(struct Stack *stack, char *token) {
	char *function = Hashtable_get(functions, token);
	if(function != NULL) {
		printf("-%s-\n", function);
		char *ftoken = read(function);
		
		do {
			eval(stack, ftoken);
		} while((ftoken = read(NULL)) != NULL);
		
		return 1;
	}
	return -1;
}

int builtin_op(struct Stack *stack, char *token) {
	if(strcmp(token, "+") == 0)
		Stack_push(stack, Stack_pop(stack) + Stack_pop(stack));	
	else if(strcmp(token, "-") == 0)
		Stack_push(stack, Stack_pop(stack) - Stack_pop(stack));
	else if(strcmp(token, "*") == 0)
		Stack_push(stack, Stack_pop(stack) * Stack_pop(stack));
	else if(strcmp(token, "/") == 0)
		Stack_push(stack, Stack_pop(stack) / Stack_pop(stack));
	else if(strcmp(token, "%") == 0)
		Stack_push(stack, Stack_pop(stack) % Stack_pop(stack));
	else if(strcmp(token, "^") == 0)
		Stack_push(stack, Stack_pop(stack) ^ Stack_pop(stack));
	else if(strcmp(token, ".") == 0)
		printf("%d", Stack_pop(stack));
	else if(strcmp(token, "DUP") == 0)
		Stack_push(stack, Stack_peek(stack));
	else if(strcmp(token, ":") == 0) {
		defun();
	}
	else if(strcmp(token, "stack") == 0) {
		printf("\n-------\nStack:\n");
		struct Node *node;
		for(node = stack->list->head; node != NULL; node = node->next)
			printf("%d ", node->data);
		printf("\n-------\n");
	}
	else
		return -1;
	return 1;
}

int eval(struct Stack *stack, char *token) {
	if(is_number(token)) {
		Stack_push(stack, atoi(token));
	}
	else {
		if(function(stack, token) <= 0)
			return builtin_op(stack, token);
		else
			read(token);	
	}
	return 1;	
}

int repl(void) {
	struct Stack *stack = Stack_init();	
	char input[2048];
	char *token;

	for(;;) {
		fgets(input, 2048, stdin);
		token = read(input); 
		do {	
			eval(stack, token);
		} while (token = read(NULL)); 
		printf("\n");
	}

	return 0;
}

int main(void) {
	functions = Hashtable_init();
	repl();

	return 0;
}
