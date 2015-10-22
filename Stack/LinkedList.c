#include "LinkedList.h"

struct Node *Node_init(NodeType data) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//Frees the node and returns the next node in the list
struct Node *Node_cleanup(struct Node *node) {
	struct Node *next = node->next;
	free(node);
	return next;
}

struct LinkedList *LinkedList_init(void) {
	struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
	list->head = NULL;
	list->size = 0;
	return list;
}

void LinkedList_add(struct LinkedList *list, struct Node *node) {
	if(list->head != NULL) {
		node->next = list->head;
		list->head = node;
	}
	else {
		list->head = node;
	}

	list->size++;
}

NodeType LinkedList_pop(struct LinkedList *list) {
	struct Node *node = list->head;
	list->head = node->next;
	NodeType data = node->data;
	Node_cleanup(node);
	return data;
}

void LinkedList_cleanup(struct LinkedList *list) {
	struct Node *node = list->head;
	
	while(node != NULL) {
		node = Node_cleanup(node);
	} 

	free(list);
}
