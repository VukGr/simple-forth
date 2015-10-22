#include "HLinkedList.h"

struct HNode *HNode_init(HNodeType data) {
	struct HNode *node = (struct HNode *)malloc(sizeof(struct HNode));
	node->data = data;
	node->next = NULL;
	return node;
}

//Frees the node and returns the next node in the list
struct HNode *HNode_cleanup(struct HNode *node) {
	struct HNode *next = node->next;
	free(node);
	return next;
}

struct HLinkedList *HLinkedList_init(void) {
	struct HLinkedList *list = (struct HLinkedList *)malloc(sizeof(struct HLinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void HLinkedList_add(struct HLinkedList *list, struct HNode *node) {
	if(list->head != NULL)
		list->tail->next = node;
	else
		list->head = node;

	list->tail = node;
	list->size++;
}

void HLinkedList_cleanup(struct HLinkedList *list) {
	struct HNode *node = list->head;
	
	do {
		node = HNode_cleanup(node);
	} while(node != NULL);

	free(list);
}
