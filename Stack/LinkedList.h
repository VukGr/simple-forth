#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

typedef DataType NodeType;

struct Node {
	NodeType data;
	struct Node *next;
};

struct LinkedList {
	struct Node *head;
	int size;
};

struct Node *Node_init(NodeType data);
struct Node *Node_cleanup(struct Node *node);	/*	Returns node->next */

struct LinkedList *LinkedList_init(void);
void LinkedList_add(struct LinkedList *list, struct Node *node);
NodeType LinkedList_pop(struct LinkedList *list);
void LinkedList_cleanup(struct LinkedList *list);

#endif
