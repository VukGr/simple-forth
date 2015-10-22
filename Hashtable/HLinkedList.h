#ifndef HLINKEDLIST_H
#define HLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Hashtable.h"

typedef struct Cell HNodeType;

struct HNode {
	HNodeType data;
	struct HNode *next;
};

struct HLinkedList {
	struct HNode *head;
	struct HNode *tail;
	int size;
};

struct HNode *HNode_init(HNodeType data);
struct HNode *HNode_cleanup(struct HNode *node);	/*	Returns node->next */

struct HLinkedList *HLinkedList_init(void);
void HLinkedList_add(struct HLinkedList *list, struct HNode *node);
void HLinkedList_cleanup(struct HLinkedList *list);

#endif
